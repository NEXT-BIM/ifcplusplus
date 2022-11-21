/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcMonthInYearNumber.h"

// TYPE IfcMonthInYearNumber = INTEGER;
IFC4X3::IfcMonthInYearNumber::IfcMonthInYearNumber( int value ) { m_value = value; }
shared_ptr<BuildingObject> IFC4X3::IfcMonthInYearNumber::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcMonthInYearNumber> copy_self( new IfcMonthInYearNumber() );
	copy_self->m_value = m_value;
	return copy_self;
}
void IFC4X3::IfcMonthInYearNumber::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCMONTHINYEARNUMBER("; }
	stream << m_value;
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcMonthInYearNumber> IFC4X3::IfcMonthInYearNumber::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcMonthInYearNumber>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcMonthInYearNumber>(); }
	shared_ptr<IfcMonthInYearNumber> type_object( new IfcMonthInYearNumber() );
	readInteger( arg, type_object->m_value );
	return type_object;
}
