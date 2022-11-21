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
#include "ifcpp/IFC4X3/include/IfcObject.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcRelDefinesByObject 
IFC4X3::IfcRelDefinesByObject::IfcRelDefinesByObject( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcRelDefinesByObject::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelDefinesByObject> copy_self( new IfcRelDefinesByObject() );
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
	for( size_t ii=0; ii<m_RelatedObjects.size(); ++ii )
	{
		auto item_ii = m_RelatedObjects[ii];
		if( item_ii )
		{
			copy_self->m_RelatedObjects.emplace_back( dynamic_pointer_cast<IfcObject>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_RelatingObject ) { copy_self->m_RelatingObject = dynamic_pointer_cast<IfcObject>( m_RelatingObject->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcRelDefinesByObject::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCRELDEFINESBYOBJECT" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_RelatedObjects );
	stream << ",";
	if( m_RelatingObject ) { stream << "#" << m_RelatingObject->m_tag; } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcRelDefinesByObject::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcRelDefinesByObject::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelDefinesByObject, expecting 6, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );
	readEntityReference( args[1], m_OwnerHistory, map, errorStream );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );
	m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );
	readEntityReferenceList( args[4], m_RelatedObjects, map, errorStream );
	readEntityReference( args[5], m_RelatingObject, map, errorStream );
}
void IFC4X3::IfcRelDefinesByObject::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcRelDefines::getAttributes( vec_attributes );
	if( !m_RelatedObjects.empty() )
	{
		shared_ptr<AttributeObjectVector> RelatedObjects_vec_object( new AttributeObjectVector() );
		std::copy( m_RelatedObjects.begin(), m_RelatedObjects.end(), std::back_inserter( RelatedObjects_vec_object->m_vec ) );
		vec_attributes.emplace_back( std::make_pair( "RelatedObjects", RelatedObjects_vec_object ) );
	}
	vec_attributes.emplace_back( std::make_pair( "RelatingObject", m_RelatingObject ) );
}
void IFC4X3::IfcRelDefinesByObject::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcRelDefines::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcRelDefinesByObject::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelDefines::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelDefinesByObject> ptr_self = dynamic_pointer_cast<IfcRelDefinesByObject>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelDefinesByObject::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_RelatedObjects.size(); ++i )
	{
		if( m_RelatedObjects[i] )
		{
			m_RelatedObjects[i]->m_IsDeclaredBy_inverse.emplace_back( ptr_self );
		}
	}
	if( m_RelatingObject )
	{
		m_RelatingObject->m_Declares_inverse.emplace_back( ptr_self );
	}
}
void IFC4X3::IfcRelDefinesByObject::unlinkFromInverseCounterparts()
{
	IfcRelDefines::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_RelatedObjects.size(); ++i )
	{
		if( m_RelatedObjects[i] )
		{
			std::vector<weak_ptr<IfcRelDefinesByObject> >& IsDeclaredBy_inverse = m_RelatedObjects[i]->m_IsDeclaredBy_inverse;
			for( auto it_IsDeclaredBy_inverse = IsDeclaredBy_inverse.begin(); it_IsDeclaredBy_inverse != IsDeclaredBy_inverse.end(); )
			{
				weak_ptr<IfcRelDefinesByObject> self_candidate_weak = *it_IsDeclaredBy_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_IsDeclaredBy_inverse;
					continue;
				}
				shared_ptr<IfcRelDefinesByObject> self_candidate( *it_IsDeclaredBy_inverse );
				if( self_candidate.get() == this )
				{
					it_IsDeclaredBy_inverse= IsDeclaredBy_inverse.erase( it_IsDeclaredBy_inverse );
				}
				else
				{
					++it_IsDeclaredBy_inverse;
				}
			}
		}
	}
	if( m_RelatingObject )
	{
		std::vector<weak_ptr<IfcRelDefinesByObject> >& Declares_inverse = m_RelatingObject->m_Declares_inverse;
		for( auto it_Declares_inverse = Declares_inverse.begin(); it_Declares_inverse != Declares_inverse.end(); )
		{
			weak_ptr<IfcRelDefinesByObject> self_candidate_weak = *it_Declares_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_Declares_inverse;
				continue;
			}
			shared_ptr<IfcRelDefinesByObject> self_candidate( *it_Declares_inverse );
			if( self_candidate.get() == this )
			{
				it_Declares_inverse= Declares_inverse.erase( it_Declares_inverse );
			}
			else
			{
				++it_Declares_inverse;
			}
		}
	}
}
