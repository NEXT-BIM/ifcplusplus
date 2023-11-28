/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcProjectOrderTypeEnum.h"

// TYPE IfcProjectOrderTypeEnum = ENUMERATION OF	(CHANGEORDER	,MAINTENANCEWORKORDER	,MOVEORDER	,PURCHASEORDER	,WORKORDER	,USERDEFINED	,NOTDEFINED);
void IFC4X3::IfcProjectOrderTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCPROJECTORDERTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_CHANGEORDER:	stream << ".CHANGEORDER."; break;
		case ENUM_MAINTENANCEWORKORDER:	stream << ".MAINTENANCEWORKORDER."; break;
		case ENUM_MOVEORDER:	stream << ".MOVEORDER."; break;
		case ENUM_PURCHASEORDER:	stream << ".PURCHASEORDER."; break;
		case ENUM_WORKORDER:	stream << ".WORKORDER."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcProjectOrderTypeEnum> IFC4X3::IfcProjectOrderTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProjectOrderTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcProjectOrderTypeEnum>(); }
	shared_ptr<IfcProjectOrderTypeEnum> type_object( new IfcProjectOrderTypeEnum() );
	if( std_iequal( arg, ".CHANGEORDER." ) )
	{
		type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_CHANGEORDER;
	}
	else if( std_iequal( arg, ".MAINTENANCEWORKORDER." ) )
	{
		type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_MAINTENANCEWORKORDER;
	}
	else if( std_iequal( arg, ".MOVEORDER." ) )
	{
		type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_MOVEORDER;
	}
	else if( std_iequal( arg, ".PURCHASEORDER." ) )
	{
		type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_PURCHASEORDER;
	}
	else if( std_iequal( arg, ".WORKORDER." ) )
	{
		type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_WORKORDER;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
