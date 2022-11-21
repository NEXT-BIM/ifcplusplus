/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcLaborResourceTypeEnum.h"

// TYPE IfcLaborResourceTypeEnum = ENUMERATION OF	(ADMINISTRATION	,CARPENTRY	,CLEANING	,CONCRETE	,DRYWALL	,ELECTRIC	,FINISHING	,FLOORING	,GENERAL	,HVAC	,LANDSCAPING	,MASONRY	,PAINTING	,PAVING	,PLUMBING	,ROOFING	,SITEGRADING	,STEELWORK	,SURVEYING	,USERDEFINED	,NOTDEFINED);
shared_ptr<BuildingObject> IFC4X3::IfcLaborResourceTypeEnum::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcLaborResourceTypeEnum> copy_self( new IfcLaborResourceTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IFC4X3::IfcLaborResourceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCLABORRESOURCETYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_ADMINISTRATION:	stream << ".ADMINISTRATION."; break;
		case ENUM_CARPENTRY:	stream << ".CARPENTRY."; break;
		case ENUM_CLEANING:	stream << ".CLEANING."; break;
		case ENUM_CONCRETE:	stream << ".CONCRETE."; break;
		case ENUM_DRYWALL:	stream << ".DRYWALL."; break;
		case ENUM_ELECTRIC:	stream << ".ELECTRIC."; break;
		case ENUM_FINISHING:	stream << ".FINISHING."; break;
		case ENUM_FLOORING:	stream << ".FLOORING."; break;
		case ENUM_GENERAL:	stream << ".GENERAL."; break;
		case ENUM_HVAC:	stream << ".HVAC."; break;
		case ENUM_LANDSCAPING:	stream << ".LANDSCAPING."; break;
		case ENUM_MASONRY:	stream << ".MASONRY."; break;
		case ENUM_PAINTING:	stream << ".PAINTING."; break;
		case ENUM_PAVING:	stream << ".PAVING."; break;
		case ENUM_PLUMBING:	stream << ".PLUMBING."; break;
		case ENUM_ROOFING:	stream << ".ROOFING."; break;
		case ENUM_SITEGRADING:	stream << ".SITEGRADING."; break;
		case ENUM_STEELWORK:	stream << ".STEELWORK."; break;
		case ENUM_SURVEYING:	stream << ".SURVEYING."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcLaborResourceTypeEnum> IFC4X3::IfcLaborResourceTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLaborResourceTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcLaborResourceTypeEnum>(); }
	shared_ptr<IfcLaborResourceTypeEnum> type_object( new IfcLaborResourceTypeEnum() );
	if( std_iequal( arg, ".ADMINISTRATION." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_ADMINISTRATION;
	}
	else if( std_iequal( arg, ".CARPENTRY." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_CARPENTRY;
	}
	else if( std_iequal( arg, ".CLEANING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_CLEANING;
	}
	else if( std_iequal( arg, ".CONCRETE." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_CONCRETE;
	}
	else if( std_iequal( arg, ".DRYWALL." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_DRYWALL;
	}
	else if( std_iequal( arg, ".ELECTRIC." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_ELECTRIC;
	}
	else if( std_iequal( arg, ".FINISHING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_FINISHING;
	}
	else if( std_iequal( arg, ".FLOORING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_FLOORING;
	}
	else if( std_iequal( arg, ".GENERAL." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_GENERAL;
	}
	else if( std_iequal( arg, ".HVAC." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_HVAC;
	}
	else if( std_iequal( arg, ".LANDSCAPING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_LANDSCAPING;
	}
	else if( std_iequal( arg, ".MASONRY." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_MASONRY;
	}
	else if( std_iequal( arg, ".PAINTING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_PAINTING;
	}
	else if( std_iequal( arg, ".PAVING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_PAVING;
	}
	else if( std_iequal( arg, ".PLUMBING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_PLUMBING;
	}
	else if( std_iequal( arg, ".ROOFING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_ROOFING;
	}
	else if( std_iequal( arg, ".SITEGRADING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_SITEGRADING;
	}
	else if( std_iequal( arg, ".STEELWORK." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_STEELWORK;
	}
	else if( std_iequal( arg, ".SURVEYING." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_SURVEYING;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
