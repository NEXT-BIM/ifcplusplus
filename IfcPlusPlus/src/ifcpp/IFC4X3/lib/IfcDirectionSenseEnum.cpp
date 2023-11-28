/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcDirectionSenseEnum.h"

// TYPE IfcDirectionSenseEnum = ENUMERATION OF	(NEGATIVE	,POSITIVE);
void IFC4X3::IfcDirectionSenseEnum::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCDIRECTIONSENSEENUM("; }
	switch( m_enum )
	{
		case ENUM_NEGATIVE:	stream << ".NEGATIVE."; break;
		case ENUM_POSITIVE:	stream << ".POSITIVE."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcDirectionSenseEnum> IFC4X3::IfcDirectionSenseEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDirectionSenseEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcDirectionSenseEnum>(); }
	shared_ptr<IfcDirectionSenseEnum> type_object( new IfcDirectionSenseEnum() );
	if( std_iequal( arg, ".NEGATIVE." ) )
	{
		type_object->m_enum = IfcDirectionSenseEnum::ENUM_NEGATIVE;
	}
	else if( std_iequal( arg, ".POSITIVE." ) )
	{
		type_object->m_enum = IfcDirectionSenseEnum::ENUM_POSITIVE;
	}
	return type_object;
}
