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
	// TYPE IfcDistributionChamberElementTypeEnum = ENUMERATION OF	(FORMEDDUCT	,INSPECTIONCHAMBER	,INSPECTIONPIT	,MANHOLE	,METERCHAMBER	,SUMP	,TRENCH	,VALVECHAMBER	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcDistributionChamberElementTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcDistributionChamberElementTypeEnumEnum
		{
			ENUM_FORMEDDUCT,
			ENUM_INSPECTIONCHAMBER,
			ENUM_INSPECTIONPIT,
			ENUM_MANHOLE,
			ENUM_METERCHAMBER,
			ENUM_SUMP,
			ENUM_TRENCH,
			ENUM_VALVECHAMBER,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcDistributionChamberElementTypeEnum() = default;
		IfcDistributionChamberElementTypeEnum( IfcDistributionChamberElementTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 8322439; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcDistributionChamberElementTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcDistributionChamberElementTypeEnumEnum m_enum;
	};
}
