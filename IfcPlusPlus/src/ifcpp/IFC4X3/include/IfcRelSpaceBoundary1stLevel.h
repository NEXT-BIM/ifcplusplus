/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcRelSpaceBoundary.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcRelSpaceBoundary1stLevel;
	//ENTITY
	class IFCQUERY_EXPORT IfcRelSpaceBoundary1stLevel : public IfcRelSpaceBoundary
	{ 
	public:
		IfcRelSpaceBoundary1stLevel() = default;
		IfcRelSpaceBoundary1stLevel( int id );
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepLine( std::stringstream& stream ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 10; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 3523091289; }

		// IfcRoot -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcGloballyUniqueId>						m_GlobalId;
		//  shared_ptr<IfcOwnerHistory>							m_OwnerHistory;				//optional
		//  shared_ptr<IfcLabel>								m_Name;						//optional
		//  shared_ptr<IfcText>									m_Description;				//optional

		// IfcRelationship -----------------------------------------------------------

		// IfcRelConnects -----------------------------------------------------------

		// IfcRelSpaceBoundary -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcSpaceBoundarySelect>					m_RelatingSpace;
		//  shared_ptr<IfcElement>								m_RelatedBuildingElement;
		//  shared_ptr<IfcConnectionGeometry>					m_ConnectionGeometry;		//optional
		//  shared_ptr<IfcPhysicalOrVirtualEnum>				m_PhysicalOrVirtualBoundary;
		//  shared_ptr<IfcInternalOrExternalEnum>				m_InternalOrExternalBoundary;

		// IfcRelSpaceBoundary1stLevel -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcRelSpaceBoundary1stLevel>				m_ParentBoundary;			//optional
		// inverse attributes:
		std::vector<weak_ptr<IfcRelSpaceBoundary1stLevel> >	m_InnerBoundaries_inverse;
	};
}

