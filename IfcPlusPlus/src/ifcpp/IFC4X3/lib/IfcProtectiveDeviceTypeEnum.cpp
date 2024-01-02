/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcProtectiveDeviceTypeEnum.h"

// TYPE IfcProtectiveDeviceTypeEnum = ENUMERATION OF	(ANTI_ARCING_DEVICE	,CIRCUITBREAKER	,EARTHINGSWITCH	,EARTHLEAKAGECIRCUITBREAKER	,FUSEDISCONNECTOR	,RESIDUALCURRENTCIRCUITBREAKER	,RESIDUALCURRENTSWITCH	,SPARKGAP	,VARISTOR	,VOLTAGELIMITER	,USERDEFINED	,NOTDEFINED);
void IFC4X3::IfcProtectiveDeviceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCPROTECTIVEDEVICETYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_ANTI_ARCING_DEVICE:	stream << ".ANTI_ARCING_DEVICE."; break;
		case ENUM_CIRCUITBREAKER:	stream << ".CIRCUITBREAKER."; break;
		case ENUM_EARTHINGSWITCH:	stream << ".EARTHINGSWITCH."; break;
		case ENUM_EARTHLEAKAGECIRCUITBREAKER:	stream << ".EARTHLEAKAGECIRCUITBREAKER."; break;
		case ENUM_FUSEDISCONNECTOR:	stream << ".FUSEDISCONNECTOR."; break;
		case ENUM_RESIDUALCURRENTCIRCUITBREAKER:	stream << ".RESIDUALCURRENTCIRCUITBREAKER."; break;
		case ENUM_RESIDUALCURRENTSWITCH:	stream << ".RESIDUALCURRENTSWITCH."; break;
		case ENUM_SPARKGAP:	stream << ".SPARKGAP."; break;
		case ENUM_VARISTOR:	stream << ".VARISTOR."; break;
		case ENUM_VOLTAGELIMITER:	stream << ".VOLTAGELIMITER."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcProtectiveDeviceTypeEnum> IFC4X3::IfcProtectiveDeviceTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcProtectiveDeviceTypeEnum>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProtectiveDeviceTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcProtectiveDeviceTypeEnum>(); }
	shared_ptr<IfcProtectiveDeviceTypeEnum> type_object( new IfcProtectiveDeviceTypeEnum() );
	if( std_iequal( arg, ".ANTI_ARCING_DEVICE." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_ANTI_ARCING_DEVICE;
	}
	else if( std_iequal( arg, ".CIRCUITBREAKER." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_CIRCUITBREAKER;
	}
	else if( std_iequal( arg, ".EARTHINGSWITCH." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_EARTHINGSWITCH;
	}
	else if( std_iequal( arg, ".EARTHLEAKAGECIRCUITBREAKER." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_EARTHLEAKAGECIRCUITBREAKER;
	}
	else if( std_iequal( arg, ".FUSEDISCONNECTOR." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_FUSEDISCONNECTOR;
	}
	else if( std_iequal( arg, ".RESIDUALCURRENTCIRCUITBREAKER." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_RESIDUALCURRENTCIRCUITBREAKER;
	}
	else if( std_iequal( arg, ".RESIDUALCURRENTSWITCH." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_RESIDUALCURRENTSWITCH;
	}
	else if( std_iequal( arg, ".SPARKGAP." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_SPARKGAP;
	}
	else if( std_iequal( arg, ".VARISTOR." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_VARISTOR;
	}
	else if( std_iequal( arg, ".VOLTAGELIMITER." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_VOLTAGELIMITER;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
