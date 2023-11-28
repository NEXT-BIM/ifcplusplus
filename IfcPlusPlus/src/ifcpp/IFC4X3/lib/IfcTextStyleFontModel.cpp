/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcFontStyle.h"
#include "ifcpp/IFC4X3/include/IfcFontVariant.h"
#include "ifcpp/IFC4X3/include/IfcFontWeight.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcSizeSelect.h"
#include "ifcpp/IFC4X3/include/IfcTextFontName.h"
#include "ifcpp/IFC4X3/include/IfcTextStyleFontModel.h"

// ENTITY IfcTextStyleFontModel 
IFC4X3::IfcTextStyleFontModel::IfcTextStyleFontModel( int tag ) { m_tag = tag; }
void IFC4X3::IfcTextStyleFontModel::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCTEXTSTYLEFONTMODEL" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	stream << "(";
	for( size_t ii = 0; ii < m_FontFamily.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcTextFontName>& type_object = m_FontFamily[ii];
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
	stream << ",";
	if( m_FontStyle ) { m_FontStyle->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_FontVariant ) { m_FontVariant->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_FontWeight ) { m_FontWeight->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_FontSize ) { m_FontSize->getStepParameter( stream, true, precision ); } else { stream << "$" ; }
	stream << ");";
}
void IFC4X3::IfcTextStyleFontModel::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcTextStyleFontModel::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_Name = IfcLabel::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){readTypeOfStringList( args[1], m_FontFamily );}
	if( num_args > 2 ){m_FontStyle = IfcFontStyle::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){m_FontVariant = IfcFontVariant::createObjectFromSTEP( args[3], map, errorStream );}
	if( num_args > 4 ){m_FontWeight = IfcFontWeight::createObjectFromSTEP( args[4], map, errorStream );}
	if( num_args > 5 ){m_FontSize = IfcSizeSelect::createObjectFromSTEP( args[5], map, errorStream );}
	if( num_args != 6 ){ errorStream << "Wrong parameter count for entity IfcTextStyleFontModel, expecting 6, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcTextStyleFontModel::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcPreDefinedTextFont::getAttributes( vec_attributes );
	shared_ptr<AttributeObjectVector> FontFamily_vec_object( new AttributeObjectVector() );
	std::copy( m_FontFamily.begin(), m_FontFamily.end(), std::back_inserter( FontFamily_vec_object->m_vec ) );
	vec_attributes.emplace_back( std::make_pair( "FontFamily", FontFamily_vec_object ) );
	vec_attributes.emplace_back( std::make_pair( "FontStyle", m_FontStyle ) );
	vec_attributes.emplace_back( std::make_pair( "FontVariant", m_FontVariant ) );
	vec_attributes.emplace_back( std::make_pair( "FontWeight", m_FontWeight ) );
	vec_attributes.emplace_back( std::make_pair( "FontSize", m_FontSize ) );
}
void IFC4X3::IfcTextStyleFontModel::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcPreDefinedTextFont::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcTextStyleFontModel::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPreDefinedTextFont::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcTextStyleFontModel::unlinkFromInverseCounterparts()
{
	IfcPreDefinedTextFont::unlinkFromInverseCounterparts();
}
