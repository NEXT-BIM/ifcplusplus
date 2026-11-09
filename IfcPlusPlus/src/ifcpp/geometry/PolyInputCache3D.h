/* -*-c++-*- IfcQuery www.ifcquery.com
*
MIT License

Copyright (c) 2017 Fabian Gerold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <map>
#include <vector>
#include <unordered_set>
#include "IncludeCarveHeaders.h"

class PolyInputCache3D {
public:

	// NEXT-BIM: points are merged with the nested ordered maps upstream replaced in 78f382462 by a hash of the exact
	// coordinates divided by epsilon, which merged no near points (only bit identical ones) and, on a 32 bit hash
	// collision, added a duplicate vertex, at places that differ between standard libraries
	std::map<double, std::map<double, std::map<double, size_t> > > m_existing_vertices_coords;
	shared_ptr<carve::input::PolyhedronData> m_poly_data;
	double epsilon;

	PolyInputCache3D(double eps = 1e-6) : epsilon(eps) {
		m_poly_data = shared_ptr<carve::input::PolyhedronData>(new carve::input::PolyhedronData());
	}

	size_t addPointZ(const vec3& pt, std::map<double, size_t>& map_z)
	{
		double vertex_z = pt.z;

		auto low = map_z.lower_bound(vertex_z);
		if (low == map_z.end())
		{
			if (map_z.size() > 0)
			{
				double lastElement = map_z.rbegin()->first;
				double dz = lastElement - vertex_z;
				if (std::abs(dz) <= epsilon)
				{
					size_t existingIndex = map_z.rbegin()->second;
					return existingIndex;
				}
			}

			size_t vertex_index = m_poly_data->addVertex(pt);
			map_z.insert({ { vertex_z, vertex_index } });
			return vertex_index;
		}
		else if (low == map_z.begin())
		{
			double existingZ = low->first;
			double dz = existingZ - vertex_z;
			if (std::abs(dz) <= epsilon)
			{
				size_t& existingIndex = low->second;
				return existingIndex;
			}
			else
			{
				size_t vertex_index = m_poly_data->addVertex(pt);
				map_z.insert({ { vertex_z, vertex_index } });
				return vertex_index;
			}
		}
		else
		{
			auto prev = std::prev(low);
			double dzPrev = vertex_z - prev->first;
			double dzLow = low->first - vertex_z;
			if (std::abs(dzPrev) < std::abs(dzLow))
			{
				if (std::abs(dzPrev) <= epsilon)
				{
					size_t& existingIndex = prev->second;
					return existingIndex;
				}
				else
				{
					size_t vertex_index = m_poly_data->addVertex(pt);
					map_z.insert({ { vertex_z, vertex_index } });
					return vertex_index;
				}
			}
			else
			{
				if (std::abs(dzLow) <= epsilon)
				{
					size_t& existingIndex = low->second;
					return existingIndex;
				}
				else
				{
					size_t vertex_index = m_poly_data->addVertex(pt);
					map_z.insert({ { vertex_z, vertex_index } });
					return vertex_index;
				}
			}
		}
	}

	size_t addPointYZ(const vec3& pt, std::map<double, std::map<double, size_t> >& map_yz)
	{
		double vertex_y = pt.y;
		double vertex_z = pt.z;

		auto low = map_yz.lower_bound(vertex_y);
		if (low == map_yz.end())
		{
			if (map_yz.size() > 0)
			{
				double lastElement = map_yz.rbegin()->first;
				double dy = lastElement - vertex_y;
				if (std::abs(dy) < epsilon)
				{
					auto& map_z = map_yz.rbegin()->second;
					return addPointZ(pt, map_z);
				}
			}

			size_t vertex_index = m_poly_data->addVertex(pt);
			map_yz.insert({ { vertex_y, {{ vertex_z, vertex_index }} } });
			return vertex_index;
		}
		else if (low == map_yz.begin())
		{
			double existingY = low->first;
			double dy = existingY - vertex_y;
			if (std::abs(dy) <= epsilon)
			{
				std::map<double, size_t>& map_z = low->second;
				return addPointZ(pt, map_z);
			}
			else
			{
				size_t vertex_index = m_poly_data->addVertex(pt);
				map_yz.insert({ {  vertex_y, {{ vertex_z, vertex_index }} } });
				return vertex_index;
			}
		}
		else
		{
			auto prev = std::prev(low);
			double dyPrev = vertex_y - prev->first;
			double dyLow = low->first - vertex_y;
			if (std::abs(dyPrev) <= std::abs(dyLow))
			{
				if (std::abs(dyPrev) <= epsilon)
				{
					std::map<double, size_t>& map_z = prev->second;
					return addPointZ(pt, map_z);
				}
				else
				{
					size_t vertex_index = m_poly_data->addVertex(pt);
					map_yz.insert({ { vertex_y, {{ vertex_z, vertex_index }} } });
					return vertex_index;
				}
			}
			else
			{
				if (std::abs(dyLow) <= epsilon)
				{
					std::map<double, size_t>& map_z = low->second;
					return addPointZ(pt, map_z);
				}
				else
				{
					size_t vertex_index = m_poly_data->addVertex(pt);
					map_yz.insert({ { vertex_y, {{ vertex_z, vertex_index }} } });
					return vertex_index;
				}
			}
		}
	}

	uint32_t addPoint(const vec3& pt)
	{
		return static_cast<uint32_t>(addPointMerged(pt));
	}

	size_t addPointMerged(const vec3& pt)
	{
		double vertex_x = pt.x;
		double vertex_y = pt.y;
		double vertex_z = pt.z;

		if (epsilon > EPS_M16)
		{
			if (m_existing_vertices_coords.size() > 0)
			{
				// std::map::lower_bound returns an iterator pointing to the first element that is equal or greater than key
				auto low = m_existing_vertices_coords.lower_bound(vertex_x);
				if (low == m_existing_vertices_coords.end())
				{
					if (m_existing_vertices_coords.size() > 0)
					{
						double lastElement = m_existing_vertices_coords.rbegin()->first;
						double dx = lastElement - vertex_x;
						if (std::abs(dx) <= epsilon)
						{
							auto& map_yz = m_existing_vertices_coords.rbegin()->second;
							return addPointYZ(pt, map_yz);
						}
					}

					size_t vertex_index = m_poly_data->addVertex(pt);
					m_existing_vertices_coords.insert({ vertex_x, {{ vertex_y, {{ vertex_z, vertex_index }} } } });
					return vertex_index;
				}
				else if (low == m_existing_vertices_coords.begin())
				{
					double existingX = low->first;
					double dx = existingX - vertex_x;
					if (std::abs(dx) <= epsilon)
					{
						std::map<double, std::map<double, size_t> >& map_yz = low->second;
						return addPointYZ(pt, map_yz);
					}
					else
					{
						size_t vertex_index = m_poly_data->addVertex(pt);
						m_existing_vertices_coords.insert({ vertex_x, {{ vertex_y, {{ vertex_z, vertex_index }} } } });
						return vertex_index;
					}
				}
				else
				{
					auto prev = std::prev(low);
					double dxPrev = vertex_x - prev->first;
					double dxLow = low->first - vertex_x;
					if (std::abs(dxPrev) < std::abs(dxLow))
					{
						if (std::abs(dxPrev) <= epsilon)
						{
							std::map<double, std::map<double, size_t> >& map_yz = prev->second;
							return addPointYZ(pt, map_yz);
						}
						else
						{
							size_t vertex_index = m_poly_data->addVertex(pt);
							m_existing_vertices_coords.insert({ vertex_x, {{ vertex_y, {{ vertex_z, vertex_index }} } } });
							return vertex_index;
						}
					}
					else
					{
						if (std::abs(dxLow) <= epsilon)
						{
							std::map<double, std::map<double, size_t> >& map_yz = low->second;
							return addPointYZ(pt, map_yz);
						}
						else
						{
							size_t vertex_index = m_poly_data->addVertex(pt);
							m_existing_vertices_coords.insert({ vertex_x, {{ vertex_y, {{ vertex_z, vertex_index }} } } });
							return vertex_index;
						}
					}
				}
			}
		}

		// add point to polyhedron
		size_t vertex_index = m_poly_data->addVertex(pt);
		m_existing_vertices_coords.insert({ vertex_x, {{ vertex_y, {{ vertex_z, vertex_index }} } } });
		return vertex_index;
	}

	void clearPointCache()
	{
		m_existing_vertices_coords.clear();
		m_poly_data->points.clear();
	}

	void copyOtherPolyData(shared_ptr<carve::input::PolyhedronData>& other)
	{
		shared_ptr<carve::mesh::MeshSet<3> > meshset(other->createMesh(carve::input::opts(), epsilon));

		for (size_t i = 0; i < meshset->meshes.size(); ++i)
		{
			carve::mesh::Mesh<3>* mesh = meshset->meshes[i];
			for (size_t j = 0; j < mesh->faces.size(); ++j)
			{
				carve::mesh::Face<3>* face = mesh->faces[j];
				carve::mesh::Edge<3>* edge = face->edge;
				std::vector<int> faceIndices;
				for (size_t k = 0; k < face->nVertices(); ++k)
				{
					const vec3& vertex = edge->vert->v;
					int pointIndex = addPoint(vertex);
					faceIndices.push_back(pointIndex);
					edge = edge->next;
				}

				m_poly_data->addFace(faceIndices.begin(), faceIndices.end());
			}
		}
	}

	void addFaceCheckIndexes(uint32_t idxA, uint32_t idxB, uint32_t idxC, uint32_t idxD,
		const vec3& v0, const vec3& v1, const vec3& v2, const vec3& v3, double eps)
	{
		std::unordered_set<uint32_t> setIndices = { idxA, idxB, idxC, idxD };

		if (setIndices.size() == 3)
		{
			auto it = setIndices.begin();
			idxA = *it;
			++it;
			idxB = *it;
			++it;
			idxC = *it;
			m_poly_data->addFace(idxA, idxB, idxC);
			return;
		}

		addTriangleCheckDegenerate(idxA, idxB, idxC, v0, v1, v2, eps);
		addTriangleCheckDegenerate(idxA, idxC, idxD, v0, v2, v3, eps);
	}

	void addFaceCheckIndexes(const vec3& v0, const vec3& v1, const vec3& v2, double eps)
	{
		uint32_t idxA = addPoint(v0);
		uint32_t idxB = addPoint(v1);
		uint32_t idxC = addPoint(v2);
		addTriangleCheckDegenerate(idxA, idxB, idxC, v0, v1, v2, eps);
	}

	void addFaceCheckIndexes(const vec3& v0, const vec3& v1, const vec3& v2, const vec3& v3, double eps)
	{
		uint32_t idxA = addPoint(v0);
		uint32_t idxB = addPoint(v1);
		uint32_t idxC = addPoint(v2);
		uint32_t idxD = addPoint(v3);

		addTriangleCheckDegenerate(idxA, idxB, idxC, v0, v1, v2, eps);
		addTriangleCheckDegenerate(idxA, idxC, idxD, v0, v2, v3, eps);
	}

	void addTriangleCheckDegenerate(uint32_t idxA, uint32_t idxB, uint32_t idxC,
		const vec3& pointA, const vec3& pointB, const vec3& pointC, double eps)
	{
		if (idxA == idxB || idxA == idxC || idxB == idxC)
		{
#ifdef _DEBUG
			std::cout << "skipping degenerate triangle: " << idxA << "/" << idxB << "/" << idxC << std::endl;
#endif
			return;
		}

		double lengthAB = (pointB - pointA).length2();
		if (lengthAB < eps * eps * 10)
		{
#ifdef _DEBUG
			std::cout << "skipping degenerate triangle: " << idxA << "/" << idxB << "/" << idxC << std::endl;
#endif
			return;
		}

		double lengthAC = (pointC - pointA).length2();
		if (lengthAC < eps * eps * 10)
		{
#ifdef _DEBUG
			std::cout << "skipping degenerate triangle: " << idxA << "/" << idxB << "/" << idxC << std::endl;
#endif
			return;
		}

		double lengthBC = (pointC - pointB).length2();
		if (lengthBC < eps * eps * 10)
		{
#ifdef _DEBUG
			std::cout << "skipping degenerate triangle: " << idxA << "/" << idxB << "/" << idxC << std::endl;
#endif
			return;
		}

#ifdef _CHECK_INDICES
		bool confirmDone = false;
		size_t numFaceIndices = m_poly_data->faceIndices.size();
		if (m_poly_data->points.size() >= 71805) {
			if (m_poly_data->faceIndices.size() > 574200) {

				std::cout << ": m_poly_data->points.size() == 71805 " << std::endl;
				std::cout << ": m_poly_data->faceIndices.size() = " << m_poly_data->faceIndices.size() << std::endl;
				if (m_poly_data->faceIndices.size() == 574252) {
					std::cout << "adding face indices: " << " A " << idxA << ": B " << idxB << ": C ... " << idxC;
					confirmDone = true;
				}
			}
		}
#endif

		m_poly_data->addFace(idxA, idxB, idxC);

#ifdef _CHECK_INDICES
		if (numFaceIndices + 4 != m_poly_data->faceIndices.size()) {
			std::cout << " addFace failed, incorrect faceIndices count" << std::endl;
		}

		if (m_poly_data->points.size() >= 71805) {

			if (confirmDone) {
				std::cout << " done" << std::endl;


			}

			if (m_poly_data->faceIndices.size() >= 574252) {
				std::cout << ": m_poly_data->faceIndices.size() = " << m_poly_data->faceIndices.size() << std::endl;
			}
		}
#endif
	}
};
