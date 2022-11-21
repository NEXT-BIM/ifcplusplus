/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcObjectPlacement.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcProductRepresentation.h"
#include "ifcpp/IFC4X3/include/IfcRelAggregates.h"
#include "ifcpp/IFC4X3/include/IfcRelAssigns.h"
#include "ifcpp/IFC4X3/include/IfcRelAssignsToProduct.h"
#include "ifcpp/IFC4X3/include/IfcRelAssociates.h"
#include "ifcpp/IFC4X3/include/IfcRelContainedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcRelDeclares.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4X3/include/IfcRelInterferesElements.h"
#include "ifcpp/IFC4X3/include/IfcRelNests.h"
#include "ifcpp/IFC4X3/include/IfcRelPositions.h"
#include "ifcpp/IFC4X3/include/IfcRelReferencedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcRelServicesBuildings.h"
#include "ifcpp/IFC4X3/include/IfcSpatialElement.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcSpatialElement 
IFC4X3::IfcSpatialElement::IfcSpatialElement( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcSpatialElement::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcSpatialElement> copy_self( new IfcSpatialElement() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = make_shared<IfcGloballyUniqueId>( createBase64Uuid().data() ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_ObjectType ) { copy_self->m_ObjectType = dynamic_pointer_cast<IfcLabel>( m_ObjectType->getDeepCopy(options) ); }
	if( m_ObjectPlacement ) { copy_self->m_ObjectPlacement = dynamic_pointer_cast<IfcObjectPlacement>( m_ObjectPlacement->getDeepCopy(options) ); }
	if( m_Representation ) { copy_self->m_Representation = dynamic_pointer_cast<IfcProductRepresentation>( m_Representation->getDeepCopy(options) ); }
	if( m_LongName ) { copy_self->m_LongName = dynamic_pointer_cast<IfcLabel>( m_LongName->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcSpatialElement::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCSPATIALELEMENT" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Representation ) { stream << "#" << m_Representation->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_LongName ) { m_LongName->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcSpatialElement::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcSpatialElement::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 8 ){ std::stringstream err; err << "Wrong parameter count for entity IfcSpatialElement, expecting 8, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );
	readEntityReference( args[1], m_OwnerHistory, map, errorStream );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );
	m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );
	m_ObjectType = IfcLabel::createObjectFromSTEP( args[4], map, errorStream );
	readEntityReference( args[5], m_ObjectPlacement, map, errorStream );
	readEntityReference( args[6], m_Representation, map, errorStream );
	m_LongName = IfcLabel::createObjectFromSTEP( args[7], map, errorStream );
}
void IFC4X3::IfcSpatialElement::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcProduct::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "LongName", m_LongName ) );
}
void IFC4X3::IfcSpatialElement::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcProduct::getAttributesInverse( vec_attributes_inverse );
	if( !m_ContainsElements_inverse.empty() )
	{
		shared_ptr<AttributeObjectVector> ContainsElements_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_ContainsElements_inverse.size(); ++i )
		{
			if( !m_ContainsElements_inverse[i].expired() )
			{
				ContainsElements_inverse_vec_obj->m_vec.emplace_back( shared_ptr<IfcRelContainedInSpatialStructure>( m_ContainsElements_inverse[i] ) );
			}
		}
		vec_attributes_inverse.emplace_back( std::make_pair( "ContainsElements_inverse", ContainsElements_inverse_vec_obj ) );
	}
	if( !m_ServicedBySystems_inverse.empty() )
	{
		shared_ptr<AttributeObjectVector> ServicedBySystems_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_ServicedBySystems_inverse.size(); ++i )
		{
			if( !m_ServicedBySystems_inverse[i].expired() )
			{
				ServicedBySystems_inverse_vec_obj->m_vec.emplace_back( shared_ptr<IfcRelServicesBuildings>( m_ServicedBySystems_inverse[i] ) );
			}
		}
		vec_attributes_inverse.emplace_back( std::make_pair( "ServicedBySystems_inverse", ServicedBySystems_inverse_vec_obj ) );
	}
	if( !m_ReferencesElements_inverse.empty() )
	{
		shared_ptr<AttributeObjectVector> ReferencesElements_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_ReferencesElements_inverse.size(); ++i )
		{
			if( !m_ReferencesElements_inverse[i].expired() )
			{
				ReferencesElements_inverse_vec_obj->m_vec.emplace_back( shared_ptr<IfcRelReferencedInSpatialStructure>( m_ReferencesElements_inverse[i] ) );
			}
		}
		vec_attributes_inverse.emplace_back( std::make_pair( "ReferencesElements_inverse", ReferencesElements_inverse_vec_obj ) );
	}
	if( !m_IsInterferedByElements_inverse.empty() )
	{
		shared_ptr<AttributeObjectVector> IsInterferedByElements_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_IsInterferedByElements_inverse.size(); ++i )
		{
			if( !m_IsInterferedByElements_inverse[i].expired() )
			{
				IsInterferedByElements_inverse_vec_obj->m_vec.emplace_back( shared_ptr<IfcRelInterferesElements>( m_IsInterferedByElements_inverse[i] ) );
			}
		}
		vec_attributes_inverse.emplace_back( std::make_pair( "IsInterferedByElements_inverse", IsInterferedByElements_inverse_vec_obj ) );
	}
	if( !m_InterferesElements_inverse.empty() )
	{
		shared_ptr<AttributeObjectVector> InterferesElements_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_InterferesElements_inverse.size(); ++i )
		{
			if( !m_InterferesElements_inverse[i].expired() )
			{
				InterferesElements_inverse_vec_obj->m_vec.emplace_back( shared_ptr<IfcRelInterferesElements>( m_InterferesElements_inverse[i] ) );
			}
		}
		vec_attributes_inverse.emplace_back( std::make_pair( "InterferesElements_inverse", InterferesElements_inverse_vec_obj ) );
	}
}
void IFC4X3::IfcSpatialElement::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcProduct::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcSpatialElement::unlinkFromInverseCounterparts()
{
	IfcProduct::unlinkFromInverseCounterparts();
}
