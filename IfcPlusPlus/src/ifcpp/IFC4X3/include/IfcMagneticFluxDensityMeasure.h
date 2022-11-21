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
	// TYPE IfcMagneticFluxDensityMeasure = REAL;
	class IFCQUERY_EXPORT IfcMagneticFluxDensityMeasure : public IfcDerivedMeasureValue
	{
	public:
		IfcMagneticFluxDensityMeasure() = default;
		IfcMagneticFluxDensityMeasure( double value );
		virtual uint32_t classID() const { return 286949696; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcMagneticFluxDensityMeasure> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		double m_value;
	};
}

