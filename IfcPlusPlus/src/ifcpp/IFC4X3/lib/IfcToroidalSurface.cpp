/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcAxis2Placement3D.h"
#include "ifcpp/IFC4X3/include/IfcPositiveLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"
#include "ifcpp/IFC4X3/include/IfcToroidalSurface.h"

// ENTITY IfcToroidalSurface 
IFC4X3::IfcToroidalSurface::IfcToroidalSurface( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcToroidalSurface::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcToroidalSurface> copy_self( new IfcToroidalSurface() );
	if( m_Position ) { copy_self->m_Position = dynamic_pointer_cast<IfcAxis2Placement3D>( m_Position->getDeepCopy(options) ); }
	if( m_MajorRadius ) { copy_self->m_MajorRadius = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_MajorRadius->getDeepCopy(options) ); }
	if( m_MinorRadius ) { copy_self->m_MinorRadius = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_MinorRadius->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcToroidalSurface::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCTOROIDALSURFACE" << "(";
	if( m_Position ) { stream << "#" << m_Position->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_MajorRadius ) { m_MajorRadius->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_MinorRadius ) { m_MinorRadius->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcToroidalSurface::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcToroidalSurface::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcToroidalSurface, expecting 3, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_Position, map, errorStream );
	m_MajorRadius = IfcPositiveLengthMeasure::createObjectFromSTEP( args[1], map, errorStream );
	m_MinorRadius = IfcPositiveLengthMeasure::createObjectFromSTEP( args[2], map, errorStream );
}
void IFC4X3::IfcToroidalSurface::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcElementarySurface::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "MajorRadius", m_MajorRadius ) );
	vec_attributes.emplace_back( std::make_pair( "MinorRadius", m_MinorRadius ) );
}
void IFC4X3::IfcToroidalSurface::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcElementarySurface::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcToroidalSurface::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcElementarySurface::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcToroidalSurface::unlinkFromInverseCounterparts()
{
	IfcElementarySurface::unlinkFromInverseCounterparts();
}
