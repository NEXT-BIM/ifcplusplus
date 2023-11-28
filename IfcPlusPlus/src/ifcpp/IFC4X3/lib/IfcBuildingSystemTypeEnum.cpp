/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcBuildingSystemTypeEnum.h"

// TYPE IfcBuildingSystemTypeEnum = ENUMERATION OF	(FENESTRATION	,FOUNDATION	,LOADBEARING	,OUTERSHELL	,SHADING	,TRANSPORT	,USERDEFINED	,NOTDEFINED);
void IFC4X3::IfcBuildingSystemTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCBUILDINGSYSTEMTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_FENESTRATION:	stream << ".FENESTRATION."; break;
		case ENUM_FOUNDATION:	stream << ".FOUNDATION."; break;
		case ENUM_LOADBEARING:	stream << ".LOADBEARING."; break;
		case ENUM_OUTERSHELL:	stream << ".OUTERSHELL."; break;
		case ENUM_SHADING:	stream << ".SHADING."; break;
		case ENUM_TRANSPORT:	stream << ".TRANSPORT."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcBuildingSystemTypeEnum> IFC4X3::IfcBuildingSystemTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBuildingSystemTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcBuildingSystemTypeEnum>(); }
	shared_ptr<IfcBuildingSystemTypeEnum> type_object( new IfcBuildingSystemTypeEnum() );
	if( std_iequal( arg, ".FENESTRATION." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_FENESTRATION;
	}
	else if( std_iequal( arg, ".FOUNDATION." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_FOUNDATION;
	}
	else if( std_iequal( arg, ".LOADBEARING." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_LOADBEARING;
	}
	else if( std_iequal( arg, ".OUTERSHELL." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_OUTERSHELL;
	}
	else if( std_iequal( arg, ".SHADING." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_SHADING;
	}
	else if( std_iequal( arg, ".TRANSPORT." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_TRANSPORT;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
