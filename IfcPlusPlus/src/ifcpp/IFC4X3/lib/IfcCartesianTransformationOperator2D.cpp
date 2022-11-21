/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcCartesianPoint.h"
#include "ifcpp/IFC4X3/include/IfcCartesianTransformationOperator2D.h"
#include "ifcpp/IFC4X3/include/IfcDirection.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcReal.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"

// ENTITY IfcCartesianTransformationOperator2D 
IFC4X3::IfcCartesianTransformationOperator2D::IfcCartesianTransformationOperator2D( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcCartesianTransformationOperator2D::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcCartesianTransformationOperator2D> copy_self( new IfcCartesianTransformationOperator2D() );
	if( m_Axis1 ) { copy_self->m_Axis1 = dynamic_pointer_cast<IfcDirection>( m_Axis1->getDeepCopy(options) ); }
	if( m_Axis2 ) { copy_self->m_Axis2 = dynamic_pointer_cast<IfcDirection>( m_Axis2->getDeepCopy(options) ); }
	if( m_LocalOrigin ) { copy_self->m_LocalOrigin = dynamic_pointer_cast<IfcCartesianPoint>( m_LocalOrigin->getDeepCopy(options) ); }
	if( m_Scale ) { copy_self->m_Scale = dynamic_pointer_cast<IfcReal>( m_Scale->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcCartesianTransformationOperator2D::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCCARTESIANTRANSFORMATIONOPERATOR2D" << "(";
	if( m_Axis1 ) { stream << "#" << m_Axis1->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Axis2 ) { stream << "#" << m_Axis2->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_LocalOrigin ) { stream << "#" << m_LocalOrigin->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Scale ) { m_Scale->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcCartesianTransformationOperator2D::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcCartesianTransformationOperator2D::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcCartesianTransformationOperator2D, expecting 4, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_Axis1, map, errorStream );
	readEntityReference( args[1], m_Axis2, map, errorStream );
	readEntityReference( args[2], m_LocalOrigin, map, errorStream );
	m_Scale = IfcReal::createObjectFromSTEP( args[3], map, errorStream );
}
void IFC4X3::IfcCartesianTransformationOperator2D::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcCartesianTransformationOperator::getAttributes( vec_attributes );
}
void IFC4X3::IfcCartesianTransformationOperator2D::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcCartesianTransformationOperator::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcCartesianTransformationOperator2D::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcCartesianTransformationOperator::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcCartesianTransformationOperator2D::unlinkFromInverseCounterparts()
{
	IfcCartesianTransformationOperator::unlinkFromInverseCounterparts();
}
