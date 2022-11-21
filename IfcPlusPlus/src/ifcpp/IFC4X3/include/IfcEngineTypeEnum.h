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
	// TYPE IfcEngineTypeEnum = ENUMERATION OF	(EXTERNALCOMBUSTION	,INTERNALCOMBUSTION	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcEngineTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcEngineTypeEnumEnum
		{
			ENUM_EXTERNALCOMBUSTION,
			ENUM_INTERNALCOMBUSTION,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcEngineTypeEnum() = default;
		IfcEngineTypeEnum( IfcEngineTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 3462168616; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcEngineTypeEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcEngineTypeEnumEnum m_enum;
	};
}

