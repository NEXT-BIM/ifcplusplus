/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcSpecularHighlightSelect.h"
#include "ifcpp/IFC4X3/include/IfcSpecularRoughness.h"

// TYPE IfcSpecularRoughness = REAL;
IFC4X3::IfcSpecularRoughness::IfcSpecularRoughness( double value ) { m_value = value; }
void IFC4X3::IfcSpecularRoughness::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCSPECULARROUGHNESS("; }
	appendRealWithoutTrailingZeros( stream, m_value, precision );
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcSpecularRoughness> IFC4X3::IfcSpecularRoughness::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcSpecularRoughness>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSpecularRoughness>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcSpecularRoughness>(); }
	shared_ptr<IfcSpecularRoughness> type_object( new IfcSpecularRoughness() );
	readReal( arg, type_object->m_value );
	return type_object;
}
