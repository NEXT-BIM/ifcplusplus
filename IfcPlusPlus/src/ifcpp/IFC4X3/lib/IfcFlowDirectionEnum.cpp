/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcFlowDirectionEnum.h"

// TYPE IfcFlowDirectionEnum = ENUMERATION OF	(SINK	,SOURCE	,SOURCEANDSINK	,NOTDEFINED);
void IFC4X3::IfcFlowDirectionEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCFLOWDIRECTIONENUM("; }
	switch( m_enum )
	{
		case ENUM_SINK:	stream << ".SINK."; break;
		case ENUM_SOURCE:	stream << ".SOURCE."; break;
		case ENUM_SOURCEANDSINK:	stream << ".SOURCEANDSINK."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcFlowDirectionEnum> IFC4X3::IfcFlowDirectionEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcFlowDirectionEnum>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFlowDirectionEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcFlowDirectionEnum>(); }
	shared_ptr<IfcFlowDirectionEnum> type_object( new IfcFlowDirectionEnum() );
	if( std_iequal( arg, ".SINK." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_SINK;
	}
	else if( std_iequal( arg, ".SOURCE." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_SOURCE;
	}
	else if( std_iequal( arg, ".SOURCEANDSINK." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_SOURCEANDSINK;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
