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
#include "ifcpp/IFC4X3/include/IfcProductRepresentation.h"
#include "ifcpp/IFC4X3/include/IfcRepresentationContext.h"
#include "ifcpp/IFC4X3/include/IfcRepresentationItem.h"
#include "ifcpp/IFC4X3/include/IfcRepresentationMap.h"
#include "ifcpp/IFC4X3/include/IfcShapeAspect.h"
#include "ifcpp/IFC4X3/include/IfcShapeRepresentation.h"

// ENTITY IfcShapeRepresentation 
IFC4X3::IfcShapeRepresentation::IfcShapeRepresentation( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcShapeRepresentation::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcShapeRepresentation> copy_self( new IfcShapeRepresentation() );
	if( m_ContextOfItems )
	{
		if( options.shallow_copy_IfcRepresentationContext ) { copy_self->m_ContextOfItems = m_ContextOfItems; }
		else { copy_self->m_ContextOfItems = dynamic_pointer_cast<IfcRepresentationContext>( m_ContextOfItems->getDeepCopy(options) ); }
	}
	if( m_RepresentationIdentifier ) { copy_self->m_RepresentationIdentifier = dynamic_pointer_cast<IfcLabel>( m_RepresentationIdentifier->getDeepCopy(options) ); }
	if( m_RepresentationType ) { copy_self->m_RepresentationType = dynamic_pointer_cast<IfcLabel>( m_RepresentationType->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_Items.size(); ++ii )
	{
		auto item_ii = m_Items[ii];
		if( item_ii )
		{
			copy_self->m_Items.emplace_back( dynamic_pointer_cast<IfcRepresentationItem>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IFC4X3::IfcShapeRepresentation::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCSHAPEREPRESENTATION" << "(";
	if( m_ContextOfItems ) { stream << "#" << m_ContextOfItems->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_RepresentationIdentifier ) { m_RepresentationIdentifier->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_RepresentationType ) { m_RepresentationType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_Items );
	stream << ");";
}
void IFC4X3::IfcShapeRepresentation::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcShapeRepresentation::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcShapeRepresentation, expecting 4, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_ContextOfItems, map, errorStream );
	m_RepresentationIdentifier = IfcLabel::createObjectFromSTEP( args[1], map, errorStream );
	m_RepresentationType = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );
	readEntityReferenceList( args[3], m_Items, map, errorStream );
}
void IFC4X3::IfcShapeRepresentation::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcShapeModel::getAttributes( vec_attributes );
}
void IFC4X3::IfcShapeRepresentation::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcShapeModel::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcShapeRepresentation::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcShapeModel::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcShapeRepresentation::unlinkFromInverseCounterparts()
{
	IfcShapeModel::unlinkFromInverseCounterparts();
}
