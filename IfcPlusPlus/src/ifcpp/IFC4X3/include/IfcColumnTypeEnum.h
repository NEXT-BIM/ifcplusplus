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
	// TYPE IfcColumnTypeEnum = ENUMERATION OF	(COLUMN	,PIERSTEM	,PIERSTEM_SEGMENT	,PILASTER	,STANDCOLUMN	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcColumnTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcColumnTypeEnumEnum
		{
			ENUM_COLUMN,
			ENUM_PIERSTEM,
			ENUM_PIERSTEM_SEGMENT,
			ENUM_PILASTER,
			ENUM_STANDCOLUMN,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcColumnTypeEnum() = default;
		IfcColumnTypeEnum( IfcColumnTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 1460979143; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcColumnTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcColumnTypeEnumEnum m_enum;
	};
}

