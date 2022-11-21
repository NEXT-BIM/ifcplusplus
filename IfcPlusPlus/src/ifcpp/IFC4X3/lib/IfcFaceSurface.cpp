/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcBoolean.h"
#include "ifcpp/IFC4X3/include/IfcFaceBound.h"
#include "ifcpp/IFC4X3/include/IfcFaceSurface.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"
#include "ifcpp/IFC4X3/include/IfcSurface.h"
#include "ifcpp/IFC4X3/include/IfcTextureMap.h"

// ENTITY IfcFaceSurface 
IFC4X3::IfcFaceSurface::IfcFaceSurface( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcFaceSurface::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcFaceSurface> copy_self( new IfcFaceSurface() );
	for( size_t ii=0; ii<m_Bounds.size(); ++ii )
	{
		auto item_ii = m_Bounds[ii];
		if( item_ii )
		{
			copy_self->m_Bounds.emplace_back( dynamic_pointer_cast<IfcFaceBound>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_FaceSurface ) { copy_self->m_FaceSurface = dynamic_pointer_cast<IfcSurface>( m_FaceSurface->getDeepCopy(options) ); }
	if( m_SameSense ) { copy_self->m_SameSense = dynamic_pointer_cast<IfcBoolean>( m_SameSense->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcFaceSurface::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCFACESURFACE" << "(";
	writeEntityList( stream, m_Bounds );
	stream << ",";
	if( m_FaceSurface ) { stream << "#" << m_FaceSurface->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcFaceSurface::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcFaceSurface::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcFaceSurface, expecting 3, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReferenceList( args[0], m_Bounds, map, errorStream );
	readEntityReference( args[1], m_FaceSurface, map, errorStream );
	m_SameSense = IfcBoolean::createObjectFromSTEP( args[2], map, errorStream );
}
void IFC4X3::IfcFaceSurface::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcFace::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "FaceSurface", m_FaceSurface ) );
	vec_attributes.emplace_back( std::make_pair( "SameSense", m_SameSense ) );
}
void IFC4X3::IfcFaceSurface::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcFace::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcFaceSurface::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcFace::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcFaceSurface::unlinkFromInverseCounterparts()
{
	IfcFace::unlinkFromInverseCounterparts();
}
