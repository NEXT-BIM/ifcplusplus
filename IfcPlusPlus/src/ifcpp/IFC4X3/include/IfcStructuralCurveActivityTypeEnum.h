/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"

namespace IFC4X3
{
	// TYPE IfcStructuralCurveActivityTypeEnum = ENUMERATION OF	(CONST	,DISCRETE	,EQUIDISTANT	,LINEAR	,PARABOLA	,POLYGONAL	,SINUS	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcStructuralCurveActivityTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcStructuralCurveActivityTypeEnumEnum
		{
			ENUM_CONST,
			ENUM_DISCRETE,
			ENUM_EQUIDISTANT,
			ENUM_LINEAR,
			ENUM_PARABOLA,
			ENUM_POLYGONAL,
			ENUM_SINUS,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcStructuralCurveActivityTypeEnum() = default;
		IfcStructuralCurveActivityTypeEnum( IfcStructuralCurveActivityTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 3876018962; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcStructuralCurveActivityTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcStructuralCurveActivityTypeEnumEnum m_enum;
	};
}

