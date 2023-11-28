/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcAnnotation.h"
#include "ifcpp/IFC4X3/include/IfcElement.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcPositioningElement.h"
#include "ifcpp/IFC4X3/include/IfcProduct.h"
#include "ifcpp/IFC4X3/include/IfcRelContainedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcSpatialElement.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcRelContainedInSpatialStructure 
IFC4X3::IfcRelContainedInSpatialStructure::IfcRelContainedInSpatialStructure( int tag ) { m_tag = tag; }
void IFC4X3::IfcRelContainedInSpatialStructure::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCRELCONTAINEDINSPATIALSTRUCTURE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_RelatedElements );
	stream << ",";
	if( m_RelatingStructure ) { stream << "#" << m_RelatingStructure->m_tag; } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcRelContainedInSpatialStructure::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcRelContainedInSpatialStructure::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){readEntityReference( args[1], m_OwnerHistory, map, errorStream );}
	if( num_args > 2 ){m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );}
	if( num_args > 4 ){readEntityReferenceList( args[4], m_RelatedElements, map, errorStream );}
	if( num_args > 5 ){readEntityReference( args[5], m_RelatingStructure, map, errorStream );}
	if( num_args != 6 ){ errorStream << "Wrong parameter count for entity IfcRelContainedInSpatialStructure, expecting 6, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcRelContainedInSpatialStructure::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcRelConnects::getAttributes( vec_attributes );
	shared_ptr<AttributeObjectVector> RelatedElements_vec_object( new AttributeObjectVector() );
	std::copy( m_RelatedElements.begin(), m_RelatedElements.end(), std::back_inserter( RelatedElements_vec_object->m_vec ) );
	vec_attributes.emplace_back( std::make_pair( "RelatedElements", RelatedElements_vec_object ) );
	vec_attributes.emplace_back( std::make_pair( "RelatingStructure", m_RelatingStructure ) );
}
void IFC4X3::IfcRelContainedInSpatialStructure::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcRelConnects::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcRelContainedInSpatialStructure::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelConnects::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelContainedInSpatialStructure> ptr_self = dynamic_pointer_cast<IfcRelContainedInSpatialStructure>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelContainedInSpatialStructure::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_RelatedElements.size(); ++i )
	{
		shared_ptr<IfcAnnotation>  RelatedElements_IfcAnnotation = dynamic_pointer_cast<IfcAnnotation>( m_RelatedElements[i] );
		if( RelatedElements_IfcAnnotation )
		{
			RelatedElements_IfcAnnotation->m_ContainedInStructure_inverse.emplace_back( ptr_self );
		}
		shared_ptr<IfcElement>  RelatedElements_IfcElement = dynamic_pointer_cast<IfcElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcElement )
		{
			RelatedElements_IfcElement->m_ContainedInStructure_inverse.emplace_back( ptr_self );
		}
		shared_ptr<IfcPositioningElement>  RelatedElements_IfcPositioningElement = dynamic_pointer_cast<IfcPositioningElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcPositioningElement )
		{
			RelatedElements_IfcPositioningElement->m_ContainedInStructure_inverse.emplace_back( ptr_self );
		}
	}
	if( m_RelatingStructure )
	{
		m_RelatingStructure->m_ContainsElements_inverse.emplace_back( ptr_self );
	}
}
void IFC4X3::IfcRelContainedInSpatialStructure::unlinkFromInverseCounterparts()
{
	IfcRelConnects::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_RelatedElements.size(); ++i )
	{
		shared_ptr<IfcAnnotation>  RelatedElements_IfcAnnotation = dynamic_pointer_cast<IfcAnnotation>( m_RelatedElements[i] );
		if( RelatedElements_IfcAnnotation )
		{
			std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainedInStructure_inverse = RelatedElements_IfcAnnotation->m_ContainedInStructure_inverse;
			for( auto it_ContainedInStructure_inverse = ContainedInStructure_inverse.begin(); it_ContainedInStructure_inverse != ContainedInStructure_inverse.end(); )
			{
				weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainedInStructure_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_ContainedInStructure_inverse;
					continue;
				}
				shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainedInStructure_inverse );
				if( self_candidate.get() == this )
				{
					it_ContainedInStructure_inverse= ContainedInStructure_inverse.erase( it_ContainedInStructure_inverse );
				}
				else
				{
					++it_ContainedInStructure_inverse;
				}
			}
		}
		shared_ptr<IfcElement>  RelatedElements_IfcElement = dynamic_pointer_cast<IfcElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcElement )
		{
			std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainedInStructure_inverse = RelatedElements_IfcElement->m_ContainedInStructure_inverse;
			for( auto it_ContainedInStructure_inverse = ContainedInStructure_inverse.begin(); it_ContainedInStructure_inverse != ContainedInStructure_inverse.end(); )
			{
				weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainedInStructure_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_ContainedInStructure_inverse;
					continue;
				}
				shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainedInStructure_inverse );
				if( self_candidate.get() == this )
				{
					it_ContainedInStructure_inverse= ContainedInStructure_inverse.erase( it_ContainedInStructure_inverse );
				}
				else
				{
					++it_ContainedInStructure_inverse;
				}
			}
		}
		shared_ptr<IfcPositioningElement>  RelatedElements_IfcPositioningElement = dynamic_pointer_cast<IfcPositioningElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcPositioningElement )
		{
			std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainedInStructure_inverse = RelatedElements_IfcPositioningElement->m_ContainedInStructure_inverse;
			for( auto it_ContainedInStructure_inverse = ContainedInStructure_inverse.begin(); it_ContainedInStructure_inverse != ContainedInStructure_inverse.end(); )
			{
				weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainedInStructure_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_ContainedInStructure_inverse;
					continue;
				}
				shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainedInStructure_inverse );
				if( self_candidate.get() == this )
				{
					it_ContainedInStructure_inverse= ContainedInStructure_inverse.erase( it_ContainedInStructure_inverse );
				}
				else
				{
					++it_ContainedInStructure_inverse;
				}
			}
		}
	}
	if( m_RelatingStructure )
	{
		std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainsElements_inverse = m_RelatingStructure->m_ContainsElements_inverse;
		for( auto it_ContainsElements_inverse = ContainsElements_inverse.begin(); it_ContainsElements_inverse != ContainsElements_inverse.end(); )
		{
			weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainsElements_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_ContainsElements_inverse;
				continue;
			}
			shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainsElements_inverse );
			if( self_candidate.get() == this )
			{
				it_ContainsElements_inverse= ContainsElements_inverse.erase( it_ContainsElements_inverse );
			}
			else
			{
				++it_ContainsElements_inverse;
			}
		}
	}
}
