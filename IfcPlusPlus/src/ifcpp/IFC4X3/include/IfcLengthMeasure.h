/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcBendingParameterSelect.h"
#include "IfcMeasureValue.h"
#include "IfcSizeSelect.h"

namespace IFC4X3
{
	// TYPE IfcLengthMeasure = REAL;
	class IFCQUERY_EXPORT IfcLengthMeasure : public IfcBendingParameterSelect, public IfcMeasureValue, public IfcSizeSelect
	{
	public:
		IfcLengthMeasure() = default;
		IfcLengthMeasure( double value );
		virtual uint32_t classID() const { return 1243674935; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcLengthMeasure> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		double m_value;
	};
}

