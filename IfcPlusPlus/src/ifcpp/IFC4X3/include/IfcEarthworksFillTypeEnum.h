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
	// TYPE IfcEarthworksFillTypeEnum = ENUMERATION OF	(BACKFILL	,COUNTERWEIGHT	,EMBANKMENT	,SLOPEFILL	,SUBGRADE	,SUBGRADEBED	,TRANSITIONSECTION	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcEarthworksFillTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcEarthworksFillTypeEnumEnum
		{
			ENUM_BACKFILL,
			ENUM_COUNTERWEIGHT,
			ENUM_EMBANKMENT,
			ENUM_SLOPEFILL,
			ENUM_SUBGRADE,
			ENUM_SUBGRADEBED,
			ENUM_TRANSITIONSECTION,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcEarthworksFillTypeEnum() = default;
		IfcEarthworksFillTypeEnum( IfcEarthworksFillTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 2872680054; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcEarthworksFillTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcEarthworksFillTypeEnumEnum m_enum;
	};
}

