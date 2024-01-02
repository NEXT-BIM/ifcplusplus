/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcDistributionBoardTypeEnum.h"

// TYPE IfcDistributionBoardTypeEnum = ENUMERATION OF	(CONSUMERUNIT	,DISPATCHINGBOARD	,DISTRIBUTIONBOARD	,DISTRIBUTIONFRAME	,MOTORCONTROLCENTRE	,SWITCHBOARD	,USERDEFINED	,NOTDEFINED);
void IFC4X3::IfcDistributionBoardTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCDISTRIBUTIONBOARDTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_CONSUMERUNIT:	stream << ".CONSUMERUNIT."; break;
		case ENUM_DISPATCHINGBOARD:	stream << ".DISPATCHINGBOARD."; break;
		case ENUM_DISTRIBUTIONBOARD:	stream << ".DISTRIBUTIONBOARD."; break;
		case ENUM_DISTRIBUTIONFRAME:	stream << ".DISTRIBUTIONFRAME."; break;
		case ENUM_MOTORCONTROLCENTRE:	stream << ".MOTORCONTROLCENTRE."; break;
		case ENUM_SWITCHBOARD:	stream << ".SWITCHBOARD."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcDistributionBoardTypeEnum> IFC4X3::IfcDistributionBoardTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcDistributionBoardTypeEnum>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDistributionBoardTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcDistributionBoardTypeEnum>(); }
	shared_ptr<IfcDistributionBoardTypeEnum> type_object( new IfcDistributionBoardTypeEnum() );
	if( std_iequal( arg, ".CONSUMERUNIT." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_CONSUMERUNIT;
	}
	else if( std_iequal( arg, ".DISPATCHINGBOARD." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_DISPATCHINGBOARD;
	}
	else if( std_iequal( arg, ".DISTRIBUTIONBOARD." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_DISTRIBUTIONBOARD;
	}
	else if( std_iequal( arg, ".DISTRIBUTIONFRAME." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_DISTRIBUTIONFRAME;
	}
	else if( std_iequal( arg, ".MOTORCONTROLCENTRE." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_MOTORCONTROLCENTRE;
	}
	else if( std_iequal( arg, ".SWITCHBOARD." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_SWITCHBOARD;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcDistributionBoardTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
