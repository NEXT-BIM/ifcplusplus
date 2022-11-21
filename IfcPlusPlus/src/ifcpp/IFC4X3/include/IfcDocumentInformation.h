/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcDocumentSelect.h"
#include "IfcExternalInformation.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcIdentifier;
	class IFCQUERY_EXPORT IfcLabel;
	class IFCQUERY_EXPORT IfcText;
	class IFCQUERY_EXPORT IfcURIReference;
	class IFCQUERY_EXPORT IfcActorSelect;
	class IFCQUERY_EXPORT IfcDateTime;
	class IFCQUERY_EXPORT IfcDate;
	class IFCQUERY_EXPORT IfcDocumentConfidentialityEnum;
	class IFCQUERY_EXPORT IfcDocumentStatusEnum;
	class IFCQUERY_EXPORT IfcRelAssociatesDocument;
	class IFCQUERY_EXPORT IfcDocumentReference;
	class IFCQUERY_EXPORT IfcDocumentInformationRelationship;
	//ENTITY
	class IFCQUERY_EXPORT IfcDocumentInformation : virtual public IfcDocumentSelect, public IfcExternalInformation
	{ 
	public:
		IfcDocumentInformation() = default;
		IfcDocumentInformation( int id );
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepLine( std::stringstream& stream ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 17; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 1154170062; }

		// IfcExternalInformation -----------------------------------------------------------

		// IfcDocumentInformation -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcIdentifier>									m_Identification;
		shared_ptr<IfcLabel>										m_Name;
		shared_ptr<IfcText>											m_Description;				//optional
		shared_ptr<IfcURIReference>									m_Location;					//optional
		shared_ptr<IfcText>											m_Purpose;					//optional
		shared_ptr<IfcText>											m_IntendedUse;				//optional
		shared_ptr<IfcText>											m_Scope;					//optional
		shared_ptr<IfcLabel>										m_Revision;					//optional
		shared_ptr<IfcActorSelect>									m_DocumentOwner;			//optional
		std::vector<shared_ptr<IfcActorSelect> >					m_Editors;					//optional
		shared_ptr<IfcDateTime>										m_CreationTime;				//optional
		shared_ptr<IfcDateTime>										m_LastRevisionTime;			//optional
		shared_ptr<IfcIdentifier>									m_ElectronicFormat;			//optional
		shared_ptr<IfcDate>											m_ValidFrom;				//optional
		shared_ptr<IfcDate>											m_ValidUntil;				//optional
		shared_ptr<IfcDocumentConfidentialityEnum>					m_Confidentiality;			//optional
		shared_ptr<IfcDocumentStatusEnum>							m_Status;					//optional
		// inverse attributes:
		std::vector<weak_ptr<IfcRelAssociatesDocument> >			m_DocumentInfoForObjects_inverse;
		std::vector<weak_ptr<IfcDocumentReference> >				m_HasDocumentReferences_inverse;
		std::vector<weak_ptr<IfcDocumentInformationRelationship> >	m_IsPointedTo_inverse;
		std::vector<weak_ptr<IfcDocumentInformationRelationship> >	m_IsPointer_inverse;
	};
}

