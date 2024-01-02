/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcDerivedMeasureValue.h"
#include "ifcpp/IFC4X3/include/IfcModulusOfSubgradeReactionSelect.h"
#include "ifcpp/IFC4X3/include/IfcModulusOfSubgradeReactionMeasure.h"

// TYPE IfcModulusOfSubgradeReactionMeasure = REAL;
IFC4X3::IfcModulusOfSubgradeReactionMeasure::IfcModulusOfSubgradeReactionMeasure( double value ) { m_value = value; }
void IFC4X3::IfcModulusOfSubgradeReactionMeasure::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCMODULUSOFSUBGRADEREACTIONMEASURE("; }
	appendRealWithoutTrailingZeros( stream, m_value, precision );
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcModulusOfSubgradeReactionMeasure> IFC4X3::IfcModulusOfSubgradeReactionMeasure::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcModulusOfSubgradeReactionMeasure>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcModulusOfSubgradeReactionMeasure>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcModulusOfSubgradeReactionMeasure>(); }
	shared_ptr<IfcModulusOfSubgradeReactionMeasure> type_object( new IfcModulusOfSubgradeReactionMeasure() );
	readReal( arg, type_object->m_value );
	return type_object;
}
