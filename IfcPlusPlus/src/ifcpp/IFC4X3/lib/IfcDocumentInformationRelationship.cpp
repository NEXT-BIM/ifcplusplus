/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcDocumentInformation.h"
#include "ifcpp/IFC4X3/include/IfcDocumentInformationRelationship.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcDocumentInformationRelationship 
IFC4X3::IfcDocumentInformationRelationship::IfcDocumentInformationRelationship( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcDocumentInformationRelationship::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcDocumentInformationRelationship> copy_self( new IfcDocumentInformationRelationship() );
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_RelatingDocument ) { copy_self->m_RelatingDocument = dynamic_pointer_cast<IfcDocumentInformation>( m_RelatingDocument->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_RelatedDocuments.size(); ++ii )
	{
		auto item_ii = m_RelatedDocuments[ii];
		if( item_ii )
		{
			copy_self->m_RelatedDocuments.emplace_back( dynamic_pointer_cast<IfcDocumentInformation>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_RelationshipType ) { copy_self->m_RelationshipType = dynamic_pointer_cast<IfcLabel>( m_RelationshipType->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcDocumentInformationRelationship::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCDOCUMENTINFORMATIONRELATIONSHIP" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_RelatingDocument ) { stream << "#" << m_RelatingDocument->m_tag; } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_RelatedDocuments );
	stream << ",";
	if( m_RelationshipType ) { m_RelationshipType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcDocumentInformationRelationship::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcDocumentInformationRelationship::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 5 ){ std::stringstream err; err << "Wrong parameter count for entity IfcDocumentInformationRelationship, expecting 5, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	m_Name = IfcLabel::createObjectFromSTEP( args[0], map, errorStream );
	m_Description = IfcText::createObjectFromSTEP( args[1], map, errorStream );
	readEntityReference( args[2], m_RelatingDocument, map, errorStream );
	readEntityReferenceList( args[3], m_RelatedDocuments, map, errorStream );
	m_RelationshipType = IfcLabel::createObjectFromSTEP( args[4], map, errorStream );
}
void IFC4X3::IfcDocumentInformationRelationship::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcResourceLevelRelationship::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "RelatingDocument", m_RelatingDocument ) );
	if( !m_RelatedDocuments.empty() )
	{
		shared_ptr<AttributeObjectVector> RelatedDocuments_vec_object( new AttributeObjectVector() );
		std::copy( m_RelatedDocuments.begin(), m_RelatedDocuments.end(), std::back_inserter( RelatedDocuments_vec_object->m_vec ) );
		vec_attributes.emplace_back( std::make_pair( "RelatedDocuments", RelatedDocuments_vec_object ) );
	}
	vec_attributes.emplace_back( std::make_pair( "RelationshipType", m_RelationshipType ) );
}
void IFC4X3::IfcDocumentInformationRelationship::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcResourceLevelRelationship::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcDocumentInformationRelationship::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcResourceLevelRelationship::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcDocumentInformationRelationship> ptr_self = dynamic_pointer_cast<IfcDocumentInformationRelationship>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcDocumentInformationRelationship::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_RelatedDocuments.size(); ++i )
	{
		if( m_RelatedDocuments[i] )
		{
			m_RelatedDocuments[i]->m_IsPointedTo_inverse.emplace_back( ptr_self );
		}
	}
	if( m_RelatingDocument )
	{
		m_RelatingDocument->m_IsPointer_inverse.emplace_back( ptr_self );
	}
}
void IFC4X3::IfcDocumentInformationRelationship::unlinkFromInverseCounterparts()
{
	IfcResourceLevelRelationship::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_RelatedDocuments.size(); ++i )
	{
		if( m_RelatedDocuments[i] )
		{
			std::vector<weak_ptr<IfcDocumentInformationRelationship> >& IsPointedTo_inverse = m_RelatedDocuments[i]->m_IsPointedTo_inverse;
			for( auto it_IsPointedTo_inverse = IsPointedTo_inverse.begin(); it_IsPointedTo_inverse != IsPointedTo_inverse.end(); )
			{
				weak_ptr<IfcDocumentInformationRelationship> self_candidate_weak = *it_IsPointedTo_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_IsPointedTo_inverse;
					continue;
				}
				shared_ptr<IfcDocumentInformationRelationship> self_candidate( *it_IsPointedTo_inverse );
				if( self_candidate.get() == this )
				{
					it_IsPointedTo_inverse= IsPointedTo_inverse.erase( it_IsPointedTo_inverse );
				}
				else
				{
					++it_IsPointedTo_inverse;
				}
			}
		}
	}
	if( m_RelatingDocument )
	{
		std::vector<weak_ptr<IfcDocumentInformationRelationship> >& IsPointer_inverse = m_RelatingDocument->m_IsPointer_inverse;
		for( auto it_IsPointer_inverse = IsPointer_inverse.begin(); it_IsPointer_inverse != IsPointer_inverse.end(); )
		{
			weak_ptr<IfcDocumentInformationRelationship> self_candidate_weak = *it_IsPointer_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_IsPointer_inverse;
				continue;
			}
			shared_ptr<IfcDocumentInformationRelationship> self_candidate( *it_IsPointer_inverse );
			if( self_candidate.get() == this )
			{
				it_IsPointer_inverse= IsPointer_inverse.erase( it_IsPointer_inverse );
			}
			else
			{
				++it_IsPointer_inverse;
			}
		}
	}
}
