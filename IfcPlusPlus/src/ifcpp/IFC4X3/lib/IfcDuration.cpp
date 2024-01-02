/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcSimpleValue.h"
#include "ifcpp/IFC4X3/include/IfcTimeOrRatioSelect.h"
#include "ifcpp/IFC4X3/include/IfcDuration.h"

// TYPE IfcDuration = STRING;
IFC4X3::IfcDuration::IfcDuration( std::string value ) { m_value = value; }
void IFC4X3::IfcDuration::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCDURATION("; }
	stream << "'" << encodeStepString( m_value ) << "'";
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcDuration> IFC4X3::IfcDuration::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcDuration>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDuration>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcDuration>(); }
	shared_ptr<IfcDuration> type_object( new IfcDuration() );
	readString( arg, type_object->m_value );
	return type_object;
}
