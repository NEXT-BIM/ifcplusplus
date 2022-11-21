/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcMeasureValue.h"
#include "ifcpp/IFC4X3/include/IfcMassMeasure.h"

// TYPE IfcMassMeasure = REAL;
IFC4X3::IfcMassMeasure::IfcMassMeasure( double value ) { m_value = value; }
shared_ptr<BuildingObject> IFC4X3::IfcMassMeasure::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcMassMeasure> copy_self( new IfcMassMeasure() );
	copy_self->m_value = m_value;
	return copy_self;
}
void IFC4X3::IfcMassMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCMASSMEASURE("; }
	appendRealWithoutTrailingZeros( stream, m_value );
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcMassMeasure> IFC4X3::IfcMassMeasure::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcMassMeasure>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcMassMeasure>(); }
	shared_ptr<IfcMassMeasure> type_object( new IfcMassMeasure() );
	readReal( arg, type_object->m_value );
	return type_object;
}
