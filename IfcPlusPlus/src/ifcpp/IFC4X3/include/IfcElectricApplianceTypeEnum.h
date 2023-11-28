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
	// TYPE IfcElectricApplianceTypeEnum = ENUMERATION OF	(DISHWASHER	,ELECTRICCOOKER	,FREESTANDINGELECTRICHEATER	,FREESTANDINGFAN	,FREESTANDINGWATERCOOLER	,FREESTANDINGWATERHEATER	,FREEZER	,FRIDGE_FREEZER	,HANDDRYER	,KITCHENMACHINE	,MICROWAVE	,PHOTOCOPIER	,REFRIGERATOR	,TUMBLEDRYER	,VENDINGMACHINE	,WASHINGMACHINE	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcElectricApplianceTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcElectricApplianceTypeEnumEnum
		{
			ENUM_DISHWASHER,
			ENUM_ELECTRICCOOKER,
			ENUM_FREESTANDINGELECTRICHEATER,
			ENUM_FREESTANDINGFAN,
			ENUM_FREESTANDINGWATERCOOLER,
			ENUM_FREESTANDINGWATERHEATER,
			ENUM_FREEZER,
			ENUM_FRIDGE_FREEZER,
			ENUM_HANDDRYER,
			ENUM_KITCHENMACHINE,
			ENUM_MICROWAVE,
			ENUM_PHOTOCOPIER,
			ENUM_REFRIGERATOR,
			ENUM_TUMBLEDRYER,
			ENUM_VENDINGMACHINE,
			ENUM_WASHINGMACHINE,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcElectricApplianceTypeEnum() = default;
		IfcElectricApplianceTypeEnum( IfcElectricApplianceTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 1290156191; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcElectricApplianceTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcElectricApplianceTypeEnumEnum m_enum;
	};
}
