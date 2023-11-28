/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcDerivedMeasureValue.h"
#include "ifcpp/IFC4X3/include/IfcCompoundPlaneAngleMeasure.h"

// TYPE IfcCompoundPlaneAngleMeasure = LIST [3:4] OF INTEGER;
void IFC4X3::IfcCompoundPlaneAngleMeasure::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCCOMPOUNDPLANEANGLEMEASURE("; }
	writeIntList( stream, m_vec );
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcCompoundPlaneAngleMeasure> IFC4X3::IfcCompoundPlaneAngleMeasure::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCompoundPlaneAngleMeasure>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcCompoundPlaneAngleMeasure>(); }
	shared_ptr<IfcCompoundPlaneAngleMeasure> type_object( new IfcCompoundPlaneAngleMeasure() );
	readIntegerList( arg, type_object->m_vec );
	return type_object;
}
