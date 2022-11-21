/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcTimeSeriesDataTypeEnum.h"

// TYPE IfcTimeSeriesDataTypeEnum = ENUMERATION OF	(CONTINUOUS	,DISCRETE	,DISCRETEBINARY	,PIECEWISEBINARY	,PIECEWISECONSTANT	,PIECEWISECONTINUOUS	,NOTDEFINED);
shared_ptr<BuildingObject> IFC4X3::IfcTimeSeriesDataTypeEnum::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcTimeSeriesDataTypeEnum> copy_self( new IfcTimeSeriesDataTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IFC4X3::IfcTimeSeriesDataTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCTIMESERIESDATATYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_CONTINUOUS:	stream << ".CONTINUOUS."; break;
		case ENUM_DISCRETE:	stream << ".DISCRETE."; break;
		case ENUM_DISCRETEBINARY:	stream << ".DISCRETEBINARY."; break;
		case ENUM_PIECEWISEBINARY:	stream << ".PIECEWISEBINARY."; break;
		case ENUM_PIECEWISECONSTANT:	stream << ".PIECEWISECONSTANT."; break;
		case ENUM_PIECEWISECONTINUOUS:	stream << ".PIECEWISECONTINUOUS."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcTimeSeriesDataTypeEnum> IFC4X3::IfcTimeSeriesDataTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTimeSeriesDataTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcTimeSeriesDataTypeEnum>(); }
	shared_ptr<IfcTimeSeriesDataTypeEnum> type_object( new IfcTimeSeriesDataTypeEnum() );
	if( std_iequal( arg, ".CONTINUOUS." ) )
	{
		type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_CONTINUOUS;
	}
	else if( std_iequal( arg, ".DISCRETE." ) )
	{
		type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_DISCRETE;
	}
	else if( std_iequal( arg, ".DISCRETEBINARY." ) )
	{
		type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_DISCRETEBINARY;
	}
	else if( std_iequal( arg, ".PIECEWISEBINARY." ) )
	{
		type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_PIECEWISEBINARY;
	}
	else if( std_iequal( arg, ".PIECEWISECONSTANT." ) )
	{
		type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_PIECEWISECONSTANT;
	}
	else if( std_iequal( arg, ".PIECEWISECONTINUOUS." ) )
	{
		type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_PIECEWISECONTINUOUS;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcTimeSeriesDataTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
