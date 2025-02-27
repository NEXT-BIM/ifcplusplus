// Copyright 2006-2015 Tobias Sargeant (tobias.sargeant@gmail.com).
//
// This file is part of the Carve CSG Library (http://carve-csg.com/)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <carve/math.hpp>

namespace carve {
	namespace geom {

		template <unsigned int ndim>
		double vector<ndim>::length2() const {
			return dot(*this, *this);
		}

		template <unsigned int ndim>
		double vector<ndim>::length() const {
			return sqrt(dot(*this, *this));
		}

		template <unsigned int ndim>
		vector<ndim>& vector<ndim>::normalize() {
#if defined(CARVE_DEBUG)
			CARVE_ASSERT(length() > 0.0);
#endif
			if( length2() == 0.0 )
			{
				return *this;
			}
			*this /= length();
			return *this;
		}

		template <unsigned int ndim>
		vector<ndim> vector<ndim>::normalized() const {
#if defined(CARVE_DEBUG)
			CARVE_ASSERT(length() > 0.0);
#endif
			if( length2() == 0.0 )
			{
				return *this;
			}
			return *this / length();
		}

		template <unsigned int ndim>
		bool vector<ndim>::exactlyZero() const {
			for( unsigned int i = 0; i < ndim; ++i ) {
				if( this->v[i] ) {
					return false;
				}
			}
			return true;
		}
		template <unsigned int ndim>
		bool vector<ndim>::isZero(double epsilon) const {
			return length2() < epsilon * epsilon;
		}

		template <unsigned int ndim>
		void vector<ndim>::setZero() {
			for( size_t i = 0; i < ndim; ++i ) {
				this->v[i] = 0.0;
			}
		}

		template <unsigned int ndim>
		void vector<ndim>::fill(double val) {
			for( size_t i = 0; i < ndim; ++i ) {
				this->v[i] = val;
			}
		}

		template <unsigned int ndim>
		vector<ndim>& vector<ndim>::scaleBy(double d) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				this->v[i] *= d;
			}
			return *this;
		}
		template <unsigned int ndim>
		vector<ndim>& vector<ndim>::invscaleBy(double d) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				this->v[i] /= d;
			}
			return *this;
		}

		template <unsigned int ndim>
		vector<ndim> vector<ndim>::scaled(double d) const {
			return *this * d;
		}
		template <unsigned int ndim>
		vector<ndim> vector<ndim>::invscaled(double d) const {
			return *this / d;
		}

		template <unsigned int ndim>
		vector<ndim>& vector<ndim>::negate() {
			for( unsigned int i = 0; i < ndim; ++i ) {
				this->v[i] = -this->v[i];
			}
			return *this;
		}
		template <unsigned int ndim>
		vector<ndim> vector<ndim>::negated() const {
			return -*this;
		}

		template <unsigned int ndim>
		double& vector<ndim>::operator[](unsigned int i) {
			return this->v[i];
		}
		template <unsigned int ndim>
		const double& vector<ndim>::operator[](unsigned int i) const {
			return this->v[i];
		}

		template <unsigned int ndim>
		template <typename assign_t>
		vector<ndim>& vector<ndim>::operator=(const assign_t& t) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				this->v[i] = t[i];
			}
			return *this;
		}

		template <unsigned int ndim>
		std::string vector<ndim>::asStr() const {
			std::ostringstream out;
			out << '<';
			out << std::setprecision(24);
			for( unsigned int i = 0; i < ndim; ++i ) {
				if( i ) {
					out << ',';
				}
				out << this->v[i];
			}
			out << '>';
			return out.str();
		}

		template <unsigned int ndim>
		vector<ndim> operator+(const vector<ndim>& a, const vector<ndim>& b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] + b[i];
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim> operator+(const vector<ndim>& a, double b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] + b;
			}
			return c;
		}

		template <unsigned ndim, typename val_t>
		vector<ndim> operator+(const vector<ndim>& a, const val_t& b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] + b[i];
			}
			return c;
		}

		template <unsigned ndim, typename val_t>
		vector<ndim> operator+(const val_t& a, const vector<ndim>& b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] + b[i];
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim>& operator+=(vector<ndim>& a, const vector<ndim>& b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] += b[i];
			}
			return a;
		}

		template <unsigned int ndim>
		vector<ndim>& operator+=(vector<ndim>& a, double b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] += b;
			}
			return a;
		}

		template <unsigned ndim, typename val_t>
		vector<ndim>& operator+=(vector<ndim>& a, const val_t& b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] += b[i];
			}
			return a;
		}

		template <unsigned int ndim>
		vector<ndim> operator-(const vector<ndim>& a) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = -a[i];
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim> operator-(const vector<ndim>& a, double b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] - b;
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim> operator-(const vector<ndim>& a, const vector<ndim>& b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] - b[i];
			}
			return c;
		}

		template <unsigned ndim, typename val_t>
		vector<ndim> operator-(const vector<ndim>& a, const val_t& b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] - b[i];
			}
			return c;
		}

		template <unsigned ndim, typename val_t>
		vector<ndim> operator-(const val_t& a, const vector<ndim>& b) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] - b[i];
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim>& operator-=(vector<ndim>& a, const vector<ndim>& b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] -= b[i];
			}
			return a;
		}

		template <unsigned int ndim>
		vector<ndim>& operator-=(vector<ndim>& a, double b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] -= b;
			}
			return a;
		}

		template <unsigned ndim, typename val_t>
		vector<ndim>& operator-=(vector<ndim>& a, const val_t& b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] -= b[i];
			}
			return a;
		}

		template <unsigned int ndim>
		vector<ndim> operator*(const vector<ndim>& a, double s) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] * s;
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim> operator*(double s, const vector<ndim>& a) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] * s;
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim>& operator*=(vector<ndim>& a, double s) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] *= s;
			}
			return a;
		}

		template <unsigned int ndim>
		vector<ndim> operator/(const vector<ndim>& a, double s) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = a[i] / s;
			}
			return c;
		}

		template <unsigned int ndim>
		vector<ndim>& operator/=(vector<ndim>& a, double s) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] /= s;
			}
			return a;
		}

		template <unsigned int ndim>
		bool operator==(const vector<ndim>& a, const vector<ndim>& b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				if( a[i] != b[i] ) {
					return false;
				}
			}
			return true;
		}

		template <unsigned int ndim>
		bool operator!=(const vector<ndim>& a, const vector<ndim>& b) {
			return !(a == b);
		}

		template <unsigned int ndim>
		bool operator<(const vector<ndim>& a, const vector<ndim>& b) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				if( a[i] < b[i] ) {
					return true;
				}
				if( a[i] > b[i] ) {
					return false;
				}
			}
			return false;
		}

		template <unsigned int ndim>
		bool operator<=(const vector<ndim>& a, const vector<ndim>& b) {
			return !(b < a);
		}

		template <unsigned int ndim>
		bool operator>(const vector<ndim>& a, const vector<ndim>& b) {
			return b < a;
		}

		template <unsigned int ndim>
		bool operator>=(const vector<ndim>& a, const vector<ndim>& b) {
			return !(a < b);
		}

		template <unsigned int ndim>
		vector<ndim> abs(const vector<ndim>& a) {
			vector<ndim> c(NOINIT);
			for( unsigned int i = 0; i < ndim; ++i ) {
				c[i] = fabs(a[i]);
			}
			return c;
		}

		template <unsigned int ndim>
		double distance2(const vector<ndim>& a, const vector<ndim>& b) {
			return (b - a).length2();
		}

		template <unsigned int ndim>
		double distance(const vector<ndim>& a, const vector<ndim>& b) {
			return (b - a).length();
		}

		template <unsigned int ndim>
		bool equal(const vector<ndim>& a, const vector<ndim>& b, double CARVE_EPSILON) {
			return (b - a).isZero(CARVE_EPSILON);
		}

		template <unsigned int ndim>
		int smallestAxis(const vector<ndim>& a) {
			int idx = 0;
			double lo = fabs(a[0]);
			for( unsigned int i = 1; i < ndim; ++i ) {
				double val = fabs(a[i]);
				if( val <= lo ) {
					lo = val;
					idx = (int)i;
				}
			}
			return idx;
		}

		template <unsigned int ndim>
		int largestAxis(const vector<ndim>& a) {
			int idx = 0;
			double hi = fabs(a[0]);
			for( unsigned int i = 1; i < ndim; ++i ) {
				double val = fabs(a[i]);
				if( val > hi ) {
					hi = val;
					idx = (int)i;
				}
			}
			return idx;
		}

		template <unsigned int ndim>
		vector<2> select(const vector<ndim>& a, int a1, int a2) {
			vector<2> r(NOINIT);
			r.v[0] = a.v[a1];
			r.v[1] = a.v[a2];
			return r;
		}

		template <unsigned int ndim>
		vector<3> select(const vector<ndim>& a, int a1, int a2, int a3) {
			vector<3> r(NOINIT);
			r.v[0] = a.v[a1];
			r.v[1] = a.v[a2];
			r.v[2] = a.v[a3];
			return r;
		}

		template <unsigned ndim, typename assign_t, typename oper_t>
		vector<ndim>& assign_op(vector<ndim>& a, const assign_t& t, oper_t op) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] = op(t[i]);
			}
			return a;
		}

		template <unsigned ndim, typename assign1_t, typename assign2_t,
			typename oper_t>
		vector<ndim>& assign_op(vector<ndim>& a, const assign1_t& t1,
			const assign2_t& t2, oper_t op) {
			for( unsigned int i = 0; i < ndim; ++i ) {
				a[i] = op(t1[i], t2[i]);
			}
			return a;
		}

		template <unsigned ndim, typename iter_t>
		void bounds(iter_t begin, iter_t end, vector<ndim>& min, vector<ndim>& max) {
			if( begin == end ) {
				min.setZero();
				max.setZero();
			}
			else {
				min = max = *begin;
				while( ++begin != end ) {
					vector<ndim> v = *begin;
					assign_op(min, min, v, carve::util::min_functor());
					assign_op(max, max, v, carve::util::max_functor());
				}
			}
		}

		template <unsigned ndim, typename iter_t, typename adapt_t>
		void bounds(iter_t begin, iter_t end, adapt_t adapt, vector<ndim>& min,
			vector<ndim>& max) {
			if( begin == end ) {
				min.setZero();
				max.setZero();
			}
			else {
				min = max = adapt(*begin);
				while( ++begin != end ) {
					vector<ndim> v = adapt(*begin);
					assign_op(min, min, v, carve::util::min_functor());
					assign_op(max, max, v, carve::util::max_functor());
				}
			}
		}

		template <unsigned ndim, typename iter_t>
		void centroid(iter_t begin, iter_t end, vector<ndim>& c) {
			c.setZero();
			int n = 0;
			for( ; begin != end; ++begin, ++n ) {
				c += *begin;
			}
			c /= double(n);
		}

		template <unsigned ndim, typename iter_t, typename adapt_t>
		void centroid(iter_t begin, iter_t end, adapt_t adapt, vector<ndim>& c) {
			c.setZero();
			int n = 0;
			for( ; begin != end; ++begin, ++n ) {
				c += adapt(*begin);
			}
			c /= double(n);
		}

		template <unsigned ndim, typename val_t>
		double dot(const vector<ndim>& a, const val_t& b) {
			double r = 0.0;
			for( unsigned int i = 0; i < ndim; ++i ) {
				r += a[i] * b[i];
			}
			return r;
		}

		static inline vector<3> cross(const vector<3>& a, const vector<3>& b) {
			// Compute a x b
			return VECTOR(+(a.y * b.z - a.z * b.y), -(a.x * b.z - a.z * b.x),
				+(a.x * b.y - a.y * b.x));
		}

		static inline double cross(const vector<2>& a, const vector<2>& b) {
			// Compute a x b
			return a.x * b.y - b.x * a.y;
		}

		static inline double dotcross(const vector<3>& a, const vector<3>& b,
			const vector<3>& c) {
			// Compute a . (b x c)
			return (a.x * b.y * c.z + a.y * b.z * c.x + a.z * b.x * c.y) -
				(a.x * c.y * b.z + a.y * c.z * b.x + a.z * c.x * b.y);
		}

		template <unsigned int ndim>
		double distance(const axis_pos& a, const vector<ndim>& b) {
			return fabs(b[a.axis] - a.pos);
		}

		template <unsigned int ndim>
		double distance2(const axis_pos& a, const vector<ndim>& b) {
			double r = fabs(b[a.axis] - a.pos);
			return r * r;
		}

		template <unsigned int ndim>
		bool operator<(const axis_pos& a, const vector<ndim>& b) {
			return a.pos < b[a.axis];
		}
		template <unsigned int ndim>
		bool operator<(const vector<ndim>& a, const axis_pos& b) {
			return a[b.axis] < b.pos;
		}

		template <unsigned int ndim>
		bool operator<=(const axis_pos& a, const vector<ndim>& b) {
			return a.pos <= b[a.axis];
		}
		template <unsigned int ndim>
		bool operator<=(const vector<ndim>& a, const axis_pos& b) {
			return a[b.axis] <= b.pos;
		}

		template <unsigned int ndim>
		bool operator>(const axis_pos& a, const vector<ndim>& b) {
			return a.pos > b[a.axis];
		}
		template <unsigned int ndim>
		bool operator>(const vector<ndim>& a, const axis_pos& b) {
			return a[b.axis] > b.pos;
		}

		template <unsigned int ndim>
		bool operator>=(const axis_pos& a, const vector<ndim>& b) {
			return a.pos >= b[a.axis];
		}
		template <unsigned int ndim>
		bool operator>=(const vector<ndim>& a, const axis_pos& b) {
			return a[b.axis] >= b.pos;
		}

		template <unsigned int ndim>
		bool operator==(const axis_pos& a, const vector<ndim>& b) {
			return a.pos == b[a.axis];
		}
		template <unsigned int ndim>
		bool operator==(const vector<ndim>& a, const axis_pos& b) {
			return a[b.axis] == b.pos;
		}

		template <unsigned int ndim>
		bool operator!=(const axis_pos& a, const vector<ndim>& b) {
			return a.pos != b[a.axis];
		}
		template <unsigned int ndim>
		bool operator!=(const vector<ndim>& a, const axis_pos& b) {
			return a[b.axis] != b.pos;
		}

		template <unsigned int ndim>
		bool ray<ndim>::OK(double CARVE_EPSILON) const
		{
			return !D.isZero(CARVE_EPSILON);
		}

		template <unsigned int ndim>
		ray<ndim> rayThrough(const vector<ndim>& a, const vector<ndim>& b) {
			return ray<ndim>(b - a, a);
		}

		static inline double distance2(const ray<3>& r, const vector<3>& v) {
			return cross(r.D, v - r.v).length2() / r.D.length2();
		}

		static inline double distance(const ray<3>& r, const vector<3>& v) {
			return sqrt(distance2(r, v));
		}

		static inline double distance2(const ray<2>& r, const vector<2>& v) {
			double t = cross(r.D, v - r.v);
			return (t * t) / r.D.length2();
		}

		static inline double distance(const ray<2>& r, const vector<2>& v) {
			return sqrt(distance2(r, v));
		}

		template <unsigned int ndim>
		void linesegment<ndim>::update() {
			midpoint = (v2 + v1) / 2.0;
			half_length = (v2 - v1) / 2.0;
		}

		template <unsigned int ndim>
		bool linesegment<ndim>::OK(double CARVE_EPSILON) const {
			return !half_length.isZero(CARVE_EPSILON);
		}

		template <unsigned int ndim>
		void linesegment<ndim>::flip() {
			std::swap(v1, v2);
			half_length = (v2 - v1) / 2.0;
		}

		template <unsigned int ndim>
		aabb<ndim> linesegment<ndim>::getAABB() const {
			aabb<ndim> r;
			r.fit(v1, v2);
			return r;
		}

		template <unsigned int ndim>
		linesegment<ndim>::linesegment(const vector_t& _v1, const vector_t& _v2)
			: v1(_v1), v2(_v2) {
			update();
		}

		template <unsigned int ndim>
		double distance2(const linesegment<ndim>& l, const vector<ndim>& v) {
			vector<ndim> D = l.v2 - l.v1;
			double t = dot(v - l.v1, D) / dot(D, D);
			if( t <= 0.0 ) {
				return (v - l.v1).length2();
			}
			if( t >= 1.0 ) {
				return (v - l.v2).length2();
			}
			vector<ndim> vc = D * t + l.v1;
			return (v - vc).length2();
		}

		template <unsigned int ndim>
		double distance(const linesegment<ndim>& l, const vector<ndim>& v) {
			return sqrt(distance2(l, v));
		}

		template <unsigned int ndim>
		void plane<ndim>::negate() {
			N.negate();
			d = -d;
		}

		template <unsigned int ndim>
		plane<ndim>::plane() {
			N.setZero();
			N[0] = 1.0;
			d = 0.0;
		}

		template <unsigned int ndim>
		plane<ndim>::plane(const vector_t& _N, vector_t _p) : N(_N), d(-dot(_p, _N)) {}

		template <unsigned int ndim>
		plane<ndim>::plane(const vector_t& _N, double _d) : N(_N), d(_d) {}

		template <unsigned int ndim>
		plane<ndim> operator-(const plane<ndim>& p) {
			return plane<ndim>(-p.N, -p.d);
		}

		template <unsigned ndim, typename val_t>
		double distance(const plane<ndim>& plane, const val_t& point) {
			return dot(plane.N, point) + plane.d;
		}

		template <unsigned ndim, typename val_t>
		double distance2(const plane<ndim>& plane, const val_t& point) {
			double d = distance(plane, point);
			return d * d;
		}

		template <unsigned int ndim>
		vector<ndim> closestPoint(const plane<ndim>& p, const vector<ndim>& v) {
			return v - p.N * (p.d + dot(p.N, v)) / dot(p.N, p.N);
		}

		template <unsigned int ndim>
		aabb<ndim> sphere<ndim>::getAABB() const {
			aabb<ndim> r;
			r.fit(C - r, C + r);
		}

		template <unsigned int ndim>
		sphere<ndim>::sphere() {
			C.setZero();
			r = 1.0;
		}

		template <unsigned int ndim>
		sphere<ndim>::sphere(const vector_t& _C, double _r) : C(_C), r(_r) {}

		template <unsigned ndim, typename val_t>
		double distance(const sphere<ndim>& sphere, const val_t& point) {
			return std::max(0.0, distance(sphere.C, point) - sphere.r);
		}

		template <unsigned ndim, typename val_t>
		double distance2(const sphere<ndim>& sphere, const val_t& point) {
			return std::max(0.0, distance2(sphere.C, point) - sphere.r * sphere.r);
		}

		template <unsigned int ndim>
		vector<ndim> closestPoint(const sphere<ndim>& sphere,
			const vector<ndim>& point) {
			return (point - sphere.C).normalized() * sphere.r;
		}

		template <unsigned int ndim>
		aabb<ndim> tri<ndim>::getAABB() const {
			aabb<ndim> aabb;
			aabb.fit(v[0], v[1], v[2]);
			return aabb;
		}

		template <unsigned int ndim>
		tri<ndim>::tri(vector_t _v[3]) {
			std::copy(v, v + 3, _v);
		}

		template <unsigned int ndim>
		tri<ndim>::tri(const vector_t& a, const vector_t& b, const vector_t& c) {
			v[0] = a;
			v[1] = b;
			v[2] = c;
		}

		template <unsigned int ndim>
		std::ostream& operator<<(std::ostream& o, const vector<ndim>& v) {
			o << v.asStr();
			return o;
		}

		template <unsigned int ndim>
		std::ostream& operator<<(std::ostream& o, const carve::geom::plane<ndim>& p) {
			o << p.N << ";" << p.d;
			return o;
		}

		template <unsigned int ndim>
		std::ostream& operator<<(std::ostream& o,
			const carve::geom::sphere<ndim>& sphere) {
			o << "{sphere " << sphere.C << ";" << sphere.r << "}";
			return o;
		}

		template <unsigned int ndim>
		std::ostream& operator<<(std::ostream& o, const carve::geom::tri<ndim>& tri) {
			o << "{tri " << tri.v[0] << ";" << tri.v[1] << ";" << tri.v[2] << "}";
			return o;
		}

		template <unsigned int ndim>
		double distance(const tri<ndim>& tri, const vector<ndim>& pt) {
			return distance(closestPoint(tri, pt), pt);
		}

		template <unsigned int ndim>
		double distance2(const tri<ndim>& tri, const vector<ndim>& pt) {
			return distance2(closestPoint(tri, pt), pt);
		}
	}  // namespace geom
}  // namespace carve
