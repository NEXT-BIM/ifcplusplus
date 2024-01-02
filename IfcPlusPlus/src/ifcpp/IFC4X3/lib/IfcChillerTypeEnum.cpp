/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcChillerTypeEnum.h"

// TYPE IfcChillerTypeEnum = ENUMERATION OF	(AIRCOOLED	,HEATRECOVERY	,WATERCOOLED	,USERDEFINED	,NOTDEFINED);
void IFC4X3::IfcChillerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCCHILLERTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_AIRCOOLED:	stream << ".AIRCOOLED."; break;
		case ENUM_HEATRECOVERY:	stream << ".HEATRECOVERY."; break;
		case ENUM_WATERCOOLED:	stream << ".WATERCOOLED."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcChillerTypeEnum> IFC4X3::IfcChillerTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcChillerTypeEnum>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcChillerTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcChillerTypeEnum>(); }
	shared_ptr<IfcChillerTypeEnum> type_object( new IfcChillerTypeEnum() );
	if( std_iequal( arg, ".AIRCOOLED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_AIRCOOLED;
	}
	else if( std_iequal( arg, ".HEATRECOVERY." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_HEATRECOVERY;
	}
	else if( std_iequal( arg, ".WATERCOOLED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_WATERCOOLED;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
