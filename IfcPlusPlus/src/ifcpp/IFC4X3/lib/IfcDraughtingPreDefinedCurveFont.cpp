/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcDraughtingPreDefinedCurveFont.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"

// ENTITY IfcDraughtingPreDefinedCurveFont 
IFC4X3::IfcDraughtingPreDefinedCurveFont::IfcDraughtingPreDefinedCurveFont( int tag ) { m_tag = tag; }
void IFC4X3::IfcDraughtingPreDefinedCurveFont::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCDRAUGHTINGPREDEFINEDCURVEFONT" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcDraughtingPreDefinedCurveFont::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcDraughtingPreDefinedCurveFont::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_Name = IfcLabel::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args != 1 ){ errorStream << "Wrong parameter count for entity IfcDraughtingPreDefinedCurveFont, expecting 1, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcDraughtingPreDefinedCurveFont::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcPreDefinedCurveFont::getAttributes( vec_attributes );
}
void IFC4X3::IfcDraughtingPreDefinedCurveFont::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcPreDefinedCurveFont::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcDraughtingPreDefinedCurveFont::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPreDefinedCurveFont::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcDraughtingPreDefinedCurveFont::unlinkFromInverseCounterparts()
{
	IfcPreDefinedCurveFont::unlinkFromInverseCounterparts();
}
