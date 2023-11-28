/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcBinary.h"
#include "ifcpp/IFC4X3/include/IfcBoolean.h"
#include "ifcpp/IFC4X3/include/IfcCartesianTransformationOperator2D.h"
#include "ifcpp/IFC4X3/include/IfcIdentifier.h"
#include "ifcpp/IFC4X3/include/IfcInteger.h"
#include "ifcpp/IFC4X3/include/IfcPixelTexture.h"
#include "ifcpp/IFC4X3/include/IfcSurfaceStyleWithTextures.h"
#include "ifcpp/IFC4X3/include/IfcTextureCoordinate.h"

// ENTITY IfcPixelTexture 
IFC4X3::IfcPixelTexture::IfcPixelTexture( int tag ) { m_tag = tag; }
void IFC4X3::IfcPixelTexture::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCPIXELTEXTURE" << "(";
	if( m_RepeatS ) { m_RepeatS->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_RepeatT ) { m_RepeatT->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Mode ) { m_Mode->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_TextureTransform ) { stream << "#" << m_TextureTransform->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Parameter.size() > 0 )
	{
		stream << "(";
		for( size_t ii = 0; ii < m_Parameter.size(); ++ii )
		{
			if( ii > 0 )
			{
				stream << ",";
			}
			const shared_ptr<IfcIdentifier>& type_object = m_Parameter[ii];
			if( type_object )
			{
				type_object->getStepParameter( stream, false, precision );
			}
			else
			{
				stream << "$";
			}
		}
		stream << ")";
	}
	else { stream << "$"; }
	stream << ",";
	if( m_Width ) { m_Width->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Height ) { m_Height->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ColourComponents ) { m_ColourComponents->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	stream << "(";
	for( size_t ii = 0; ii < m_Pixel.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcBinary>& type_object = m_Pixel[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, false, precision );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ");";
}
void IFC4X3::IfcPixelTexture::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcPixelTexture::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_RepeatS = IfcBoolean::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){m_RepeatT = IfcBoolean::createObjectFromSTEP( args[1], map, errorStream );}
	if( num_args > 2 ){m_Mode = IfcIdentifier::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){readEntityReference( args[3], m_TextureTransform, map, errorStream );}
	if( num_args > 4 ){readTypeOfStringList( args[4], m_Parameter );}
	if( num_args > 5 ){m_Width = IfcInteger::createObjectFromSTEP( args[5], map, errorStream );}
	if( num_args > 6 ){m_Height = IfcInteger::createObjectFromSTEP( args[6], map, errorStream );}
	if( num_args > 7 ){m_ColourComponents = IfcInteger::createObjectFromSTEP( args[7], map, errorStream );}
	if( num_args > 8 ){readTypeOfStringList( args[8], m_Pixel );}
	if( num_args != 9 ){ errorStream << "Wrong parameter count for entity IfcPixelTexture, expecting 9, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcPixelTexture::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcSurfaceTexture::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "Width", m_Width ) );
	vec_attributes.emplace_back( std::make_pair( "Height", m_Height ) );
	vec_attributes.emplace_back( std::make_pair( "ColourComponents", m_ColourComponents ) );
	shared_ptr<AttributeObjectVector> Pixel_vec_object( new AttributeObjectVector() );
	std::copy( m_Pixel.begin(), m_Pixel.end(), std::back_inserter( Pixel_vec_object->m_vec ) );
	vec_attributes.emplace_back( std::make_pair( "Pixel", Pixel_vec_object ) );
}
void IFC4X3::IfcPixelTexture::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcSurfaceTexture::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcPixelTexture::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcSurfaceTexture::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcPixelTexture::unlinkFromInverseCounterparts()
{
	IfcSurfaceTexture::unlinkFromInverseCounterparts();
}
