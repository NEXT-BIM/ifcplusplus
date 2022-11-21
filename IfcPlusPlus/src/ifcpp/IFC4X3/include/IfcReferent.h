/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcPositioningElement.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcReferentTypeEnum;
	//ENTITY
	class IFCQUERY_EXPORT IfcReferent : public IfcPositioningElement
	{ 
	public:
		IfcReferent() = default;
		IfcReferent( int id );
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepLine( std::stringstream& stream ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 8; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 4021432810; }

		// IfcRoot -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcGloballyUniqueId>								m_GlobalId;
		//  shared_ptr<IfcOwnerHistory>									m_OwnerHistory;				//optional
		//  shared_ptr<IfcLabel>										m_Name;						//optional
		//  shared_ptr<IfcText>											m_Description;				//optional

		// IfcObjectDefinition -----------------------------------------------------------
		// inverse attributes:
		//  std::vector<weak_ptr<IfcRelAssigns> >						m_HasAssignments_inverse;
		//  std::vector<weak_ptr<IfcRelNests> >							m_Nests_inverse;
		//  std::vector<weak_ptr<IfcRelNests> >							m_IsNestedBy_inverse;
		//  std::vector<weak_ptr<IfcRelDeclares> >						m_HasContext_inverse;
		//  std::vector<weak_ptr<IfcRelAggregates> >					m_IsDecomposedBy_inverse;
		//  std::vector<weak_ptr<IfcRelAggregates> >					m_Decomposes_inverse;
		//  std::vector<weak_ptr<IfcRelAssociates> >					m_HasAssociations_inverse;

		// IfcObject -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcLabel>										m_ObjectType;				//optional
		// inverse attributes:
		//  std::vector<weak_ptr<IfcRelDefinesByObject> >				m_IsDeclaredBy_inverse;
		//  std::vector<weak_ptr<IfcRelDefinesByObject> >				m_Declares_inverse;
		//  std::vector<weak_ptr<IfcRelDefinesByType> >					m_IsTypedBy_inverse;
		//  std::vector<weak_ptr<IfcRelDefinesByProperties> >			m_IsDefinedBy_inverse;

		// IfcProduct -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcObjectPlacement>								m_ObjectPlacement;			//optional
		//  shared_ptr<IfcProductRepresentation>						m_Representation;			//optional
		// inverse attributes:
		//  std::vector<weak_ptr<IfcRelAssignsToProduct> >				m_ReferencedBy_inverse;
		//  std::vector<weak_ptr<IfcRelPositions> >						m_PositionedRelativeTo_inverse;
		//  std::vector<weak_ptr<IfcRelReferencedInSpatialStructure> >	m_ReferencedInStructures_inverse;

		// IfcPositioningElement -----------------------------------------------------------
		// inverse attributes:
		//  std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >	m_ContainedInStructure_inverse;
		//  std::vector<weak_ptr<IfcRelPositions> >						m_Positions_inverse;

		// IfcReferent -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcReferentTypeEnum>								m_PredefinedType;			//optional
	};
}

