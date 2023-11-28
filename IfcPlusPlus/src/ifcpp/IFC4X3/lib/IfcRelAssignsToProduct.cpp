/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcObjectDefinition.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcProduct.h"
#include "ifcpp/IFC4X3/include/IfcProductSelect.h"
#include "ifcpp/IFC4X3/include/IfcRelAssignsToProduct.h"
#include "ifcpp/IFC4X3/include/IfcStrippedOptional.h"
#include "ifcpp/IFC4X3/include/IfcText.h"
#include "ifcpp/IFC4X3/include/IfcTypeProduct.h"

// ENTITY IfcRelAssignsToProduct 
IFC4X3::IfcRelAssignsToProduct::IfcRelAssignsToProduct( int tag ) { m_tag = tag; }
void IFC4X3::IfcRelAssignsToProduct::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCRELASSIGNSTOPRODUCT" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_RelatedObjects );
	stream << ",";
	if( m_RelatedObjectsType ) { m_RelatedObjectsType->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_RelatingProduct ) { m_RelatingProduct->getStepParameter( stream, true, precision ); } else { stream << "$" ; }
	stream << ");";
}
void IFC4X3::IfcRelAssignsToProduct::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcRelAssignsToProduct::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){readEntityReference( args[1], m_OwnerHistory, map, errorStream );}
	if( num_args > 2 ){m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );}
	if( num_args > 4 ){readEntityReferenceList( args[4], m_RelatedObjects, map, errorStream );}
	if( num_args > 5 ){m_RelatedObjectsType = IfcStrippedOptional::createObjectFromSTEP( args[5], map, errorStream );}
	if( num_args > 6 ){m_RelatingProduct = IfcProductSelect::createObjectFromSTEP( args[6], map, errorStream );}
	if( num_args != 7 ){ errorStream << "Wrong parameter count for entity IfcRelAssignsToProduct, expecting 7, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcRelAssignsToProduct::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcRelAssigns::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "RelatingProduct", m_RelatingProduct ) );
}
void IFC4X3::IfcRelAssignsToProduct::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcRelAssigns::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcRelAssignsToProduct::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelAssigns::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelAssignsToProduct> ptr_self = dynamic_pointer_cast<IfcRelAssignsToProduct>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelAssignsToProduct::setInverseCounterparts: type mismatch" ); }
	shared_ptr<IfcProduct>  RelatingProduct_IfcProduct = dynamic_pointer_cast<IfcProduct>( m_RelatingProduct );
	if( RelatingProduct_IfcProduct )
	{
		RelatingProduct_IfcProduct->m_ReferencedBy_inverse.emplace_back( ptr_self );
	}
	shared_ptr<IfcTypeProduct>  RelatingProduct_IfcTypeProduct = dynamic_pointer_cast<IfcTypeProduct>( m_RelatingProduct );
	if( RelatingProduct_IfcTypeProduct )
	{
		RelatingProduct_IfcTypeProduct->m_ReferencedBy_inverse.emplace_back( ptr_self );
	}
}
void IFC4X3::IfcRelAssignsToProduct::unlinkFromInverseCounterparts()
{
	IfcRelAssigns::unlinkFromInverseCounterparts();
	shared_ptr<IfcProduct>  RelatingProduct_IfcProduct = dynamic_pointer_cast<IfcProduct>( m_RelatingProduct );
	if( RelatingProduct_IfcProduct )
	{
		std::vector<weak_ptr<IfcRelAssignsToProduct> >& ReferencedBy_inverse = RelatingProduct_IfcProduct->m_ReferencedBy_inverse;
		for( auto it_ReferencedBy_inverse = ReferencedBy_inverse.begin(); it_ReferencedBy_inverse != ReferencedBy_inverse.end(); )
		{
			weak_ptr<IfcRelAssignsToProduct> self_candidate_weak = *it_ReferencedBy_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_ReferencedBy_inverse;
				continue;
			}
			shared_ptr<IfcRelAssignsToProduct> self_candidate( *it_ReferencedBy_inverse );
			if( self_candidate.get() == this )
			{
				it_ReferencedBy_inverse= ReferencedBy_inverse.erase( it_ReferencedBy_inverse );
			}
			else
			{
				++it_ReferencedBy_inverse;
			}
		}
	}
	shared_ptr<IfcTypeProduct>  RelatingProduct_IfcTypeProduct = dynamic_pointer_cast<IfcTypeProduct>( m_RelatingProduct );
	if( RelatingProduct_IfcTypeProduct )
	{
		std::vector<weak_ptr<IfcRelAssignsToProduct> >& ReferencedBy_inverse = RelatingProduct_IfcTypeProduct->m_ReferencedBy_inverse;
		for( auto it_ReferencedBy_inverse = ReferencedBy_inverse.begin(); it_ReferencedBy_inverse != ReferencedBy_inverse.end(); )
		{
			weak_ptr<IfcRelAssignsToProduct> self_candidate_weak = *it_ReferencedBy_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_ReferencedBy_inverse;
				continue;
			}
			shared_ptr<IfcRelAssignsToProduct> self_candidate( *it_ReferencedBy_inverse );
			if( self_candidate.get() == this )
			{
				it_ReferencedBy_inverse= ReferencedBy_inverse.erase( it_ReferencedBy_inverse );
			}
			else
			{
				++it_ReferencedBy_inverse;
			}
		}
	}
}
