/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcAxis2Placement.h"
#include "ifcpp/IFC4X3/include/IfcLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcSeventhOrderPolynomialSpiral.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"

// ENTITY IfcSeventhOrderPolynomialSpiral 
IFC4X3::IfcSeventhOrderPolynomialSpiral::IfcSeventhOrderPolynomialSpiral( int tag ) { m_tag = tag; }
void IFC4X3::IfcSeventhOrderPolynomialSpiral::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCSEVENTHORDERPOLYNOMIALSPIRAL" << "(";
	if( m_Position ) { m_Position->getStepParameter( stream, true, precision ); } else { stream << "$" ; }
	stream << ",";
	if( m_SepticTerm ) { m_SepticTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_SexticTerm ) { m_SexticTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_QuinticTerm ) { m_QuinticTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_QuarticTerm ) { m_QuarticTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_CubicTerm ) { m_CubicTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_QuadraticTerm ) { m_QuadraticTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_LinearTerm ) { m_LinearTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ConstantTerm ) { m_ConstantTerm->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcSeventhOrderPolynomialSpiral::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcSeventhOrderPolynomialSpiral::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_Position = IfcAxis2Placement::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){m_SepticTerm = IfcLengthMeasure::createObjectFromSTEP( args[1], map, errorStream );}
	if( num_args > 2 ){m_SexticTerm = IfcLengthMeasure::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){m_QuinticTerm = IfcLengthMeasure::createObjectFromSTEP( args[3], map, errorStream );}
	if( num_args > 4 ){m_QuarticTerm = IfcLengthMeasure::createObjectFromSTEP( args[4], map, errorStream );}
	if( num_args > 5 ){m_CubicTerm = IfcLengthMeasure::createObjectFromSTEP( args[5], map, errorStream );}
	if( num_args > 6 ){m_QuadraticTerm = IfcLengthMeasure::createObjectFromSTEP( args[6], map, errorStream );}
	if( num_args > 7 ){m_LinearTerm = IfcLengthMeasure::createObjectFromSTEP( args[7], map, errorStream );}
	if( num_args > 8 ){m_ConstantTerm = IfcLengthMeasure::createObjectFromSTEP( args[8], map, errorStream );}
	if( num_args != 9 ){ errorStream << "Wrong parameter count for entity IfcSeventhOrderPolynomialSpiral, expecting 9, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcSeventhOrderPolynomialSpiral::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcSpiral::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "SepticTerm", m_SepticTerm ) );
	vec_attributes.emplace_back( std::make_pair( "SexticTerm", m_SexticTerm ) );
	vec_attributes.emplace_back( std::make_pair( "QuinticTerm", m_QuinticTerm ) );
	vec_attributes.emplace_back( std::make_pair( "QuarticTerm", m_QuarticTerm ) );
	vec_attributes.emplace_back( std::make_pair( "CubicTerm", m_CubicTerm ) );
	vec_attributes.emplace_back( std::make_pair( "QuadraticTerm", m_QuadraticTerm ) );
	vec_attributes.emplace_back( std::make_pair( "LinearTerm", m_LinearTerm ) );
	vec_attributes.emplace_back( std::make_pair( "ConstantTerm", m_ConstantTerm ) );
}
void IFC4X3::IfcSeventhOrderPolynomialSpiral::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcSpiral::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcSeventhOrderPolynomialSpiral::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcSpiral::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcSeventhOrderPolynomialSpiral::unlinkFromInverseCounterparts()
{
	IfcSpiral::unlinkFromInverseCounterparts();
}
