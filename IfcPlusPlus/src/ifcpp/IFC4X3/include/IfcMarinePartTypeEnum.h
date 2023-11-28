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
	// TYPE IfcMarinePartTypeEnum = ENUMERATION OF	(ABOVEWATERLINE	,ANCHORAGE	,APPROACHCHANNEL	,BELOWWATERLINE	,BERTHINGSTRUCTURE	,CHAMBER	,CILL_LEVEL	,COPELEVEL	,CORE	,CREST	,GATEHEAD	,GUDINGSTRUCTURE	,HIGHWATERLINE	,LANDFIELD	,LEEWARDSIDE	,LOWWATERLINE	,MANUFACTURING	,NAVIGATIONALAREA	,PROTECTION	,SHIPTRANSFER	,STORAGEAREA	,VEHICLESERVICING	,WATERFIELD	,WEATHERSIDE	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcMarinePartTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcMarinePartTypeEnumEnum
		{
			ENUM_ABOVEWATERLINE,
			ENUM_ANCHORAGE,
			ENUM_APPROACHCHANNEL,
			ENUM_BELOWWATERLINE,
			ENUM_BERTHINGSTRUCTURE,
			ENUM_CHAMBER,
			ENUM_CILL_LEVEL,
			ENUM_COPELEVEL,
			ENUM_CORE,
			ENUM_CREST,
			ENUM_GATEHEAD,
			ENUM_GUDINGSTRUCTURE,
			ENUM_HIGHWATERLINE,
			ENUM_LANDFIELD,
			ENUM_LEEWARDSIDE,
			ENUM_LOWWATERLINE,
			ENUM_MANUFACTURING,
			ENUM_NAVIGATIONALAREA,
			ENUM_PROTECTION,
			ENUM_SHIPTRANSFER,
			ENUM_STORAGEAREA,
			ENUM_VEHICLESERVICING,
			ENUM_WATERFIELD,
			ENUM_WEATHERSIDE,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcMarinePartTypeEnum() = default;
		IfcMarinePartTypeEnum( IfcMarinePartTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 1095732595; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcMarinePartTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcMarinePartTypeEnumEnum m_enum;
	};
}
