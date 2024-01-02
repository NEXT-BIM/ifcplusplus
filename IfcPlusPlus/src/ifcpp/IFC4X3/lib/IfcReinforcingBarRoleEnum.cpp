/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcReinforcingBarRoleEnum.h"

// TYPE IfcReinforcingBarRoleEnum = ENUMERATION OF	(ANCHORING	,EDGE	,LIGATURE	,MAIN	,PUNCHING	,RING	,SHEAR	,STUD	,USERDEFINED	,NOTDEFINED);
void IFC4X3::IfcReinforcingBarRoleEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCREINFORCINGBARROLEENUM("; }
	switch( m_enum )
	{
		case ENUM_ANCHORING:	stream << ".ANCHORING."; break;
		case ENUM_EDGE:	stream << ".EDGE."; break;
		case ENUM_LIGATURE:	stream << ".LIGATURE."; break;
		case ENUM_MAIN:	stream << ".MAIN."; break;
		case ENUM_PUNCHING:	stream << ".PUNCHING."; break;
		case ENUM_RING:	stream << ".RING."; break;
		case ENUM_SHEAR:	stream << ".SHEAR."; break;
		case ENUM_STUD:	stream << ".STUD."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcReinforcingBarRoleEnum> IFC4X3::IfcReinforcingBarRoleEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcReinforcingBarRoleEnum>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcReinforcingBarRoleEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcReinforcingBarRoleEnum>(); }
	shared_ptr<IfcReinforcingBarRoleEnum> type_object( new IfcReinforcingBarRoleEnum() );
	if( std_iequal( arg, ".ANCHORING." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_ANCHORING;
	}
	else if( std_iequal( arg, ".EDGE." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_EDGE;
	}
	else if( std_iequal( arg, ".LIGATURE." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_LIGATURE;
	}
	else if( std_iequal( arg, ".MAIN." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_MAIN;
	}
	else if( std_iequal( arg, ".PUNCHING." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_PUNCHING;
	}
	else if( std_iequal( arg, ".RING." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_RING;
	}
	else if( std_iequal( arg, ".SHEAR." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_SHEAR;
	}
	else if( std_iequal( arg, ".STUD." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_STUD;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcReinforcingBarRoleEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
