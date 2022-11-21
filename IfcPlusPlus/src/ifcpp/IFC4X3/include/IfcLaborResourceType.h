/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcConstructionResourceType.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcLaborResourceTypeEnum;
	//ENTITY
	class IFCQUERY_EXPORT IfcLaborResourceType : public IfcConstructionResourceType
	{ 
	public:
		IfcLaborResourceType() = default;
		IfcLaborResourceType( int id );
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepLine( std::stringstream& stream ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 12; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 428585644; }

		// IfcRoot -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcGloballyUniqueId>						m_GlobalId;
		//  shared_ptr<IfcOwnerHistory>							m_OwnerHistory;				//optional
		//  shared_ptr<IfcLabel>								m_Name;						//optional
		//  shared_ptr<IfcText>									m_Description;				//optional

		// IfcObjectDefinition -----------------------------------------------------------
		// inverse attributes:
		//  std::vector<weak_ptr<IfcRelAssigns> >				m_HasAssignments_inverse;
		//  std::vector<weak_ptr<IfcRelNests> >					m_Nests_inverse;
		//  std::vector<weak_ptr<IfcRelNests> >					m_IsNestedBy_inverse;
		//  std::vector<weak_ptr<IfcRelDeclares> >				m_HasContext_inverse;
		//  std::vector<weak_ptr<IfcRelAggregates> >			m_IsDecomposedBy_inverse;
		//  std::vector<weak_ptr<IfcRelAggregates> >			m_Decomposes_inverse;
		//  std::vector<weak_ptr<IfcRelAssociates> >			m_HasAssociations_inverse;

		// IfcTypeObject -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcIdentifier>							m_ApplicableOccurrence;		//optional
		//  std::vector<shared_ptr<IfcPropertySetDefinition> >	m_HasPropertySets;			//optional
		// inverse attributes:
		//  std::vector<weak_ptr<IfcRelDefinesByType> >			m_Types_inverse;

		// IfcTypeResource -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcIdentifier>							m_Identification;			//optional
		//  shared_ptr<IfcText>									m_LongDescription;			//optional
		//  shared_ptr<IfcLabel>								m_ResourceType;				//optional
		// inverse attributes:
		//  std::vector<weak_ptr<IfcRelAssignsToResource> >		m_ResourceOf_inverse;

		// IfcConstructionResourceType -----------------------------------------------------------
		// attributes:
		//  std::vector<shared_ptr<IfcAppliedValue> >			m_BaseCosts;				//optional
		//  shared_ptr<IfcPhysicalQuantity>						m_BaseQuantity;				//optional

		// IfcLaborResourceType -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcLaborResourceTypeEnum>				m_PredefinedType;
	};
}

