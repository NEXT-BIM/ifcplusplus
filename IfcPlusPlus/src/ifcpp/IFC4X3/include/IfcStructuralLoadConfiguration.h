/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcStructuralLoad.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcStructuralLoadOrResult;
	class IFCQUERY_EXPORT IfcLengthMeasure;
	//ENTITY
	class IFCQUERY_EXPORT IfcStructuralLoadConfiguration : public IfcStructuralLoad
	{
	public:
		IfcStructuralLoadConfiguration() = default;
		IfcStructuralLoadConfiguration( int id );
		virtual void getStepLine( std::stringstream& stream, size_t precision ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 3; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 3478079324; }

		// IfcStructuralLoad -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcLabel>								m_Name;						//optional

		// IfcStructuralLoadConfiguration -----------------------------------------------------------
		// attributes:
		std::vector<shared_ptr<IfcStructuralLoadOrResult> >	m_Values;
		std::vector<std::vector<shared_ptr<IfcLengthMeasure> > >	m_Locations;				//optional
	};
}
