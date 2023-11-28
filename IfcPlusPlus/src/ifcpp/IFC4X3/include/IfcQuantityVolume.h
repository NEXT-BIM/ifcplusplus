/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcPhysicalSimpleQuantity.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcVolumeMeasure;
	class IFCQUERY_EXPORT IfcLabel;
	//ENTITY
	class IFCQUERY_EXPORT IfcQuantityVolume : public IfcPhysicalSimpleQuantity
	{
	public:
		IfcQuantityVolume() = default;
		IfcQuantityVolume( int id );
		virtual void getStepLine( std::stringstream& stream, size_t precision ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 5; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 2405470396; }

		// IfcPhysicalQuantity -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcLabel>										m_Name;
		//  shared_ptr<IfcText>											m_Description;				//optional
		// inverse attributes:
		//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
		//  std::vector<weak_ptr<IfcPhysicalComplexQuantity> >			m_PartOfComplex_inverse;

		// IfcPhysicalSimpleQuantity -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcNamedUnit>									m_Unit;						//optional

		// IfcQuantityVolume -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcVolumeMeasure>								m_VolumeValue;
		shared_ptr<IfcLabel>										m_Formula;					//optional
	};
}
