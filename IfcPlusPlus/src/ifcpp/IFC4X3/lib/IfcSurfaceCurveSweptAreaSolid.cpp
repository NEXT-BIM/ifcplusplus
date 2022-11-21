/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcAxis2Placement3D.h"
#include "ifcpp/IFC4X3/include/IfcCurve.h"
#include "ifcpp/IFC4X3/include/IfcCurveMeasureSelect.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcProfileDef.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"
#include "ifcpp/IFC4X3/include/IfcSurface.h"
#include "ifcpp/IFC4X3/include/IfcSurfaceCurveSweptAreaSolid.h"

// ENTITY IfcSurfaceCurveSweptAreaSolid 
IFC4X3::IfcSurfaceCurveSweptAreaSolid::IfcSurfaceCurveSweptAreaSolid( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcSurfaceCurveSweptAreaSolid::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcSurfaceCurveSweptAreaSolid> copy_self( new IfcSurfaceCurveSweptAreaSolid() );
	if( m_SweptArea )
	{
		if( options.shallow_copy_IfcProfileDef ) { copy_self->m_SweptArea = m_SweptArea; }
		else { copy_self->m_SweptArea = dynamic_pointer_cast<IfcProfileDef>( m_SweptArea->getDeepCopy(options) ); }
	}
	if( m_Position ) { copy_self->m_Position = dynamic_pointer_cast<IfcAxis2Placement3D>( m_Position->getDeepCopy(options) ); }
	if( m_Directrix ) { copy_self->m_Directrix = dynamic_pointer_cast<IfcCurve>( m_Directrix->getDeepCopy(options) ); }
	if( m_StartParam ) { copy_self->m_StartParam = dynamic_pointer_cast<IfcCurveMeasureSelect>( m_StartParam->getDeepCopy(options) ); }
	if( m_EndParam ) { copy_self->m_EndParam = dynamic_pointer_cast<IfcCurveMeasureSelect>( m_EndParam->getDeepCopy(options) ); }
	if( m_ReferenceSurface ) { copy_self->m_ReferenceSurface = dynamic_pointer_cast<IfcSurface>( m_ReferenceSurface->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcSurfaceCurveSweptAreaSolid::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCSURFACECURVESWEPTAREASOLID" << "(";
	if( m_SweptArea ) { stream << "#" << m_SweptArea->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Position ) { stream << "#" << m_Position->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Directrix ) { stream << "#" << m_Directrix->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_StartParam ) { m_StartParam->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_EndParam ) { m_EndParam->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_ReferenceSurface ) { stream << "#" << m_ReferenceSurface->m_tag; } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcSurfaceCurveSweptAreaSolid::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcSurfaceCurveSweptAreaSolid::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcSurfaceCurveSweptAreaSolid, expecting 6, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_SweptArea, map, errorStream );
	readEntityReference( args[1], m_Position, map, errorStream );
	readEntityReference( args[2], m_Directrix, map, errorStream );
	m_StartParam = IfcCurveMeasureSelect::createObjectFromSTEP( args[3], map, errorStream );
	m_EndParam = IfcCurveMeasureSelect::createObjectFromSTEP( args[4], map, errorStream );
	readEntityReference( args[5], m_ReferenceSurface, map, errorStream );
}
void IFC4X3::IfcSurfaceCurveSweptAreaSolid::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcDirectrixCurveSweptAreaSolid::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "ReferenceSurface", m_ReferenceSurface ) );
}
void IFC4X3::IfcSurfaceCurveSweptAreaSolid::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcDirectrixCurveSweptAreaSolid::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcSurfaceCurveSweptAreaSolid::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcDirectrixCurveSweptAreaSolid::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcSurfaceCurveSweptAreaSolid::unlinkFromInverseCounterparts()
{
	IfcDirectrixCurveSweptAreaSolid::unlinkFromInverseCounterparts();
}
