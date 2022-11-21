/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcDerivedMeasureValue.h"

namespace IFC4X3
{
	// TYPE IfcThermalTransmittanceMeasure = REAL;
	class IFCQUERY_EXPORT IfcThermalTransmittanceMeasure : public IfcDerivedMeasureValue
	{
	public:
		IfcThermalTransmittanceMeasure() = default;
		IfcThermalTransmittanceMeasure( double value );
		virtual uint32_t classID() const { return 2016195849; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcThermalTransmittanceMeasure> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		double m_value;
	};
}

