/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcTendonConduitTypeEnum.h"

// TYPE IfcTendonConduitTypeEnum = ENUMERATION OF	(COUPLER	,DIABOLO	,DUCT	,GROUTING_DUCT	,TRUMPET	,USERDEFINED	,NOTDEFINED);
shared_ptr<BuildingObject> IFC4X3::IfcTendonConduitTypeEnum::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcTendonConduitTypeEnum> copy_self( new IfcTendonConduitTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IFC4X3::IfcTendonConduitTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCTENDONCONDUITTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_COUPLER:	stream << ".COUPLER."; break;
		case ENUM_DIABOLO:	stream << ".DIABOLO."; break;
		case ENUM_DUCT:	stream << ".DUCT."; break;
		case ENUM_GROUTING_DUCT:	stream << ".GROUTING_DUCT."; break;
		case ENUM_TRUMPET:	stream << ".TRUMPET."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcTendonConduitTypeEnum> IFC4X3::IfcTendonConduitTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTendonConduitTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcTendonConduitTypeEnum>(); }
	shared_ptr<IfcTendonConduitTypeEnum> type_object( new IfcTendonConduitTypeEnum() );
	if( std_iequal( arg, ".COUPLER." ) )
	{
		type_object->m_enum = IfcTendonConduitTypeEnum::ENUM_COUPLER;
	}
	else if( std_iequal( arg, ".DIABOLO." ) )
	{
		type_object->m_enum = IfcTendonConduitTypeEnum::ENUM_DIABOLO;
	}
	else if( std_iequal( arg, ".DUCT." ) )
	{
		type_object->m_enum = IfcTendonConduitTypeEnum::ENUM_DUCT;
	}
	else if( std_iequal( arg, ".GROUTING_DUCT." ) )
	{
		type_object->m_enum = IfcTendonConduitTypeEnum::ENUM_GROUTING_DUCT;
	}
	else if( std_iequal( arg, ".TRUMPET." ) )
	{
		type_object->m_enum = IfcTendonConduitTypeEnum::ENUM_TRUMPET;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcTendonConduitTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcTendonConduitTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
