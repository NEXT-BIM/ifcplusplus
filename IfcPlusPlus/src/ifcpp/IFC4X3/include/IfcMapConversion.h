/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcCoordinateOperation.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcLengthMeasure;
	class IFCQUERY_EXPORT IfcReal;
	//ENTITY
	class IFCQUERY_EXPORT IfcMapConversion : public IfcCoordinateOperation
	{ 
	public:
		IfcMapConversion() = default;
		IfcMapConversion( int id );
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepLine( std::stringstream& stream ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 10; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 3057273783; }

		// IfcCoordinateOperation -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcCoordinateReferenceSystemSelect>	m_SourceCRS;
		//  shared_ptr<IfcCoordinateReferenceSystem>		m_TargetCRS;

		// IfcMapConversion -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcLengthMeasure>					m_Eastings;
		shared_ptr<IfcLengthMeasure>					m_Northings;
		shared_ptr<IfcLengthMeasure>					m_OrthogonalHeight;
		shared_ptr<IfcReal>								m_XAxisAbscissa;			//optional
		shared_ptr<IfcReal>								m_XAxisOrdinate;			//optional
		shared_ptr<IfcReal>								m_Scale;					//optional
		shared_ptr<IfcReal>								m_ScaleY;					//optional
		shared_ptr<IfcReal>								m_ScaleZ;					//optional
	};
}

