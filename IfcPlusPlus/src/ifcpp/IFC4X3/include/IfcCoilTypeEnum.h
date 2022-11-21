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
	// TYPE IfcCoilTypeEnum = ENUMERATION OF	(DXCOOLINGCOIL	,ELECTRICHEATINGCOIL	,GASHEATINGCOIL	,HYDRONICCOIL	,STEAMHEATINGCOIL	,WATERCOOLINGCOIL	,WATERHEATINGCOIL	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcCoilTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcCoilTypeEnumEnum
		{
			ENUM_DXCOOLINGCOIL,
			ENUM_ELECTRICHEATINGCOIL,
			ENUM_GASHEATINGCOIL,
			ENUM_HYDRONICCOIL,
			ENUM_STEAMHEATINGCOIL,
			ENUM_WATERCOOLINGCOIL,
			ENUM_WATERHEATINGCOIL,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcCoilTypeEnum() = default;
		IfcCoilTypeEnum( IfcCoilTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 1760651496; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcCoilTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcCoilTypeEnumEnum m_enum;
	};
}

