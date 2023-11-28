/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcAxis2Placement3D.h"
#include "ifcpp/IFC4X3/include/IfcBlock.h"
#include "ifcpp/IFC4X3/include/IfcPositiveLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"

// ENTITY IfcBlock 
IFC4X3::IfcBlock::IfcBlock( int tag ) { m_tag = tag; }
void IFC4X3::IfcBlock::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCBLOCK" << "(";
	if( m_Position ) { stream << "#" << m_Position->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_XLength ) { m_XLength->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_YLength ) { m_YLength->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ZLength ) { m_ZLength->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcBlock::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcBlock::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){readEntityReference( args[0], m_Position, map, errorStream );}
	if( num_args > 1 ){m_XLength = IfcPositiveLengthMeasure::createObjectFromSTEP( args[1], map, errorStream );}
	if( num_args > 2 ){m_YLength = IfcPositiveLengthMeasure::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){m_ZLength = IfcPositiveLengthMeasure::createObjectFromSTEP( args[3], map, errorStream );}
	if( num_args != 4 ){ errorStream << "Wrong parameter count for entity IfcBlock, expecting 4, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcBlock::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcCsgPrimitive3D::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "XLength", m_XLength ) );
	vec_attributes.emplace_back( std::make_pair( "YLength", m_YLength ) );
	vec_attributes.emplace_back( std::make_pair( "ZLength", m_ZLength ) );
}
void IFC4X3::IfcBlock::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcCsgPrimitive3D::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcBlock::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcCsgPrimitive3D::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcBlock::unlinkFromInverseCounterparts()
{
	IfcCsgPrimitive3D::unlinkFromInverseCounterparts();
}
