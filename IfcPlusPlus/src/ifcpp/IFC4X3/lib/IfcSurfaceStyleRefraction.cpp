/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcReal.h"
#include "ifcpp/IFC4X3/include/IfcSurfaceStyleRefraction.h"

// ENTITY IfcSurfaceStyleRefraction 
IFC4X3::IfcSurfaceStyleRefraction::IfcSurfaceStyleRefraction( int tag ) { m_tag = tag; }
void IFC4X3::IfcSurfaceStyleRefraction::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCSURFACESTYLEREFRACTION" << "(";
	if( m_RefractionIndex ) { m_RefractionIndex->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_DispersionFactor ) { m_DispersionFactor->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcSurfaceStyleRefraction::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcSurfaceStyleRefraction::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_RefractionIndex = IfcReal::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){m_DispersionFactor = IfcReal::createObjectFromSTEP( args[1], map, errorStream );}
	if( num_args != 2 ){ errorStream << "Wrong parameter count for entity IfcSurfaceStyleRefraction, expecting 2, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcSurfaceStyleRefraction::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcPresentationItem::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "RefractionIndex", m_RefractionIndex ) );
	vec_attributes.emplace_back( std::make_pair( "DispersionFactor", m_DispersionFactor ) );
}
void IFC4X3::IfcSurfaceStyleRefraction::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcPresentationItem::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcSurfaceStyleRefraction::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcSurfaceStyleRefraction::unlinkFromInverseCounterparts()
{
	IfcPresentationItem::unlinkFromInverseCounterparts();
}
