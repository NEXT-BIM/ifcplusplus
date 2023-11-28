/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcSimplePropertyTemplateTypeEnum.h"

// TYPE IfcSimplePropertyTemplateTypeEnum = ENUMERATION OF	(P_BOUNDEDVALUE	,P_ENUMERATEDVALUE	,P_LISTVALUE	,P_REFERENCEVALUE	,P_SINGLEVALUE	,P_TABLEVALUE	,Q_AREA	,Q_COUNT	,Q_LENGTH	,Q_NUMBER	,Q_TIME	,Q_VOLUME	,Q_WEIGHT);
void IFC4X3::IfcSimplePropertyTemplateTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCSIMPLEPROPERTYTEMPLATETYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_P_BOUNDEDVALUE:	stream << ".P_BOUNDEDVALUE."; break;
		case ENUM_P_ENUMERATEDVALUE:	stream << ".P_ENUMERATEDVALUE."; break;
		case ENUM_P_LISTVALUE:	stream << ".P_LISTVALUE."; break;
		case ENUM_P_REFERENCEVALUE:	stream << ".P_REFERENCEVALUE."; break;
		case ENUM_P_SINGLEVALUE:	stream << ".P_SINGLEVALUE."; break;
		case ENUM_P_TABLEVALUE:	stream << ".P_TABLEVALUE."; break;
		case ENUM_Q_AREA:	stream << ".Q_AREA."; break;
		case ENUM_Q_COUNT:	stream << ".Q_COUNT."; break;
		case ENUM_Q_LENGTH:	stream << ".Q_LENGTH."; break;
		case ENUM_Q_NUMBER:	stream << ".Q_NUMBER."; break;
		case ENUM_Q_TIME:	stream << ".Q_TIME."; break;
		case ENUM_Q_VOLUME:	stream << ".Q_VOLUME."; break;
		case ENUM_Q_WEIGHT:	stream << ".Q_WEIGHT."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcSimplePropertyTemplateTypeEnum> IFC4X3::IfcSimplePropertyTemplateTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSimplePropertyTemplateTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcSimplePropertyTemplateTypeEnum>(); }
	shared_ptr<IfcSimplePropertyTemplateTypeEnum> type_object( new IfcSimplePropertyTemplateTypeEnum() );
	if( std_iequal( arg, ".P_BOUNDEDVALUE." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_BOUNDEDVALUE;
	}
	else if( std_iequal( arg, ".P_ENUMERATEDVALUE." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_ENUMERATEDVALUE;
	}
	else if( std_iequal( arg, ".P_LISTVALUE." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_LISTVALUE;
	}
	else if( std_iequal( arg, ".P_REFERENCEVALUE." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_REFERENCEVALUE;
	}
	else if( std_iequal( arg, ".P_SINGLEVALUE." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_SINGLEVALUE;
	}
	else if( std_iequal( arg, ".P_TABLEVALUE." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_TABLEVALUE;
	}
	else if( std_iequal( arg, ".Q_AREA." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_AREA;
	}
	else if( std_iequal( arg, ".Q_COUNT." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_COUNT;
	}
	else if( std_iequal( arg, ".Q_LENGTH." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_LENGTH;
	}
	else if( std_iequal( arg, ".Q_NUMBER." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_NUMBER;
	}
	else if( std_iequal( arg, ".Q_TIME." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_TIME;
	}
	else if( std_iequal( arg, ".Q_VOLUME." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_VOLUME;
	}
	else if( std_iequal( arg, ".Q_WEIGHT." ) )
	{
		type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_WEIGHT;
	}
	return type_object;
}
