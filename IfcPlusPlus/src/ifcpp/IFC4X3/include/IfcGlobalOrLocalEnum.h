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
	// TYPE IfcGlobalOrLocalEnum = ENUMERATION OF	(GLOBAL_COORDS	,LOCAL_COORDS);
	class IFCQUERY_EXPORT IfcGlobalOrLocalEnum : virtual public BuildingObject
	{
	public:
		enum IfcGlobalOrLocalEnumEnum
		{
			ENUM_GLOBAL_COORDS,
			ENUM_LOCAL_COORDS
		};

		IfcGlobalOrLocalEnum() = default;
		IfcGlobalOrLocalEnum( IfcGlobalOrLocalEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 3637616042; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcGlobalOrLocalEnum> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcGlobalOrLocalEnumEnum m_enum;
	};
}
