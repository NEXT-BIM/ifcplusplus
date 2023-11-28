/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcActorSelect.h"
#include "IfcObjectReferenceSelect.h"
#include "IfcResourceObjectSelect.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcIdentifier;
	class IFCQUERY_EXPORT IfcLabel;
	class IFCQUERY_EXPORT IfcActorRole;
	class IFCQUERY_EXPORT IfcAddress;
	class IFCQUERY_EXPORT IfcPersonAndOrganization;
	//ENTITY
	class IFCQUERY_EXPORT IfcPerson : virtual public IfcActorSelect, virtual public IfcObjectReferenceSelect, virtual public IfcResourceObjectSelect, public BuildingEntity
	{
	public:
		IfcPerson() = default;
		IfcPerson( int id );
		virtual void getStepLine( std::stringstream& stream, size_t precision ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 8; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 2077209135; }

		// IfcPerson -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcIdentifier>							m_Identification;			//optional
		shared_ptr<IfcLabel>								m_FamilyName;				//optional
		shared_ptr<IfcLabel>								m_GivenName;				//optional
		std::vector<shared_ptr<IfcLabel> >					m_MiddleNames;				//optional
		std::vector<shared_ptr<IfcLabel> >					m_PrefixTitles;				//optional
		std::vector<shared_ptr<IfcLabel> >					m_SuffixTitles;				//optional
		std::vector<shared_ptr<IfcActorRole> >				m_Roles;					//optional
		std::vector<shared_ptr<IfcAddress> >				m_Addresses;				//optional
		// inverse attributes:
		std::vector<weak_ptr<IfcPersonAndOrganization> >	m_EngagedIn_inverse;
	};
}
