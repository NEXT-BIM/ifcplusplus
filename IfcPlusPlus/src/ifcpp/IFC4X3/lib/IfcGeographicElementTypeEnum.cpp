/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcGeographicElementTypeEnum.h"

// TYPE IfcGeographicElementTypeEnum = ENUMERATION OF	(SOIL_BORING_POINT	,TERRAIN	,VEGETATION	,USERDEFINED	,NOTDEFINED);
void IFC4X3::IfcGeographicElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCGEOGRAPHICELEMENTTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_SOIL_BORING_POINT:	stream << ".SOIL_BORING_POINT."; break;
		case ENUM_TERRAIN:	stream << ".TERRAIN."; break;
		case ENUM_VEGETATION:	stream << ".VEGETATION."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcGeographicElementTypeEnum> IFC4X3::IfcGeographicElementTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcGeographicElementTypeEnum>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcGeographicElementTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcGeographicElementTypeEnum>(); }
	shared_ptr<IfcGeographicElementTypeEnum> type_object( new IfcGeographicElementTypeEnum() );
	if( std_iequal( arg, ".SOIL_BORING_POINT." ) )
	{
		type_object->m_enum = IfcGeographicElementTypeEnum::ENUM_SOIL_BORING_POINT;
	}
	else if( std_iequal( arg, ".TERRAIN." ) )
	{
		type_object->m_enum = IfcGeographicElementTypeEnum::ENUM_TERRAIN;
	}
	else if( std_iequal( arg, ".VEGETATION." ) )
	{
		type_object->m_enum = IfcGeographicElementTypeEnum::ENUM_VEGETATION;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcGeographicElementTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcGeographicElementTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
