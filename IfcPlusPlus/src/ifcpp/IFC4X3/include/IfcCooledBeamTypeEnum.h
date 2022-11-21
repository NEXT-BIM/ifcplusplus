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
	// TYPE IfcCooledBeamTypeEnum = ENUMERATION OF	(ACTIVE	,PASSIVE	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcCooledBeamTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcCooledBeamTypeEnumEnum
		{
			ENUM_ACTIVE,
			ENUM_PASSIVE,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcCooledBeamTypeEnum() = default;
		IfcCooledBeamTypeEnum( IfcCooledBeamTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 3405941096; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcCooledBeamTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcCooledBeamTypeEnumEnum m_enum;
	};
}

