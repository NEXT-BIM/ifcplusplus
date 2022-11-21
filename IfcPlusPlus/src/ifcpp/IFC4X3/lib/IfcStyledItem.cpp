/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcPresentationStyle.h"
#include "ifcpp/IFC4X3/include/IfcRepresentationItem.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"

// ENTITY IfcStyledItem 
IFC4X3::IfcStyledItem::IfcStyledItem( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcStyledItem::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcStyledItem> copy_self( new IfcStyledItem() );
	if( m_Item ) { copy_self->m_Item = dynamic_pointer_cast<IfcRepresentationItem>( m_Item->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_Styles.size(); ++ii )
	{
		auto item_ii = m_Styles[ii];
		if( item_ii )
		{
			copy_self->m_Styles.emplace_back( dynamic_pointer_cast<IfcPresentationStyle>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcStyledItem::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCSTYLEDITEM" << "(";
	if( m_Item ) { stream << "#" << m_Item->m_tag; } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_Styles );
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcStyledItem::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcStyledItem::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcStyledItem, expecting 3, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_Item, map, errorStream );
	readEntityReferenceList( args[1], m_Styles, map, errorStream );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );
}
void IFC4X3::IfcStyledItem::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcRepresentationItem::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "Item", m_Item ) );
	if( !m_Styles.empty() )
	{
		shared_ptr<AttributeObjectVector> Styles_vec_object( new AttributeObjectVector() );
		std::copy( m_Styles.begin(), m_Styles.end(), std::back_inserter( Styles_vec_object->m_vec ) );
		vec_attributes.emplace_back( std::make_pair( "Styles", Styles_vec_object ) );
	}
	vec_attributes.emplace_back( std::make_pair( "Name", m_Name ) );
}
void IFC4X3::IfcStyledItem::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcRepresentationItem::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcStyledItem::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRepresentationItem::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcStyledItem> ptr_self = dynamic_pointer_cast<IfcStyledItem>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcStyledItem::setInverseCounterparts: type mismatch" ); }
	if( m_Item )
	{
		m_Item->m_StyledByItem_inverse.emplace_back( ptr_self );
	}
}
void IFC4X3::IfcStyledItem::unlinkFromInverseCounterparts()
{
	IfcRepresentationItem::unlinkFromInverseCounterparts();
	if( m_Item )
	{
		std::vector<weak_ptr<IfcStyledItem> >& StyledByItem_inverse = m_Item->m_StyledByItem_inverse;
		for( auto it_StyledByItem_inverse = StyledByItem_inverse.begin(); it_StyledByItem_inverse != StyledByItem_inverse.end(); )
		{
			weak_ptr<IfcStyledItem> self_candidate_weak = *it_StyledByItem_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_StyledByItem_inverse;
				continue;
			}
			shared_ptr<IfcStyledItem> self_candidate( *it_StyledByItem_inverse );
			if( self_candidate.get() == this )
			{
				it_StyledByItem_inverse= StyledByItem_inverse.erase( it_StyledByItem_inverse );
			}
			else
			{
				++it_StyledByItem_inverse;
			}
		}
	}
}
