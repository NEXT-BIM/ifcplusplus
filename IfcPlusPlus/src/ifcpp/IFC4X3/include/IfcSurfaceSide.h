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
	// TYPE IfcSurfaceSide = ENUMERATION OF	(BOTH	,NEGATIVE	,POSITIVE);
	class IFCQUERY_EXPORT IfcSurfaceSide : virtual public BuildingObject
	{
	public:
		enum IfcSurfaceSideEnum
		{
			ENUM_BOTH,
			ENUM_NEGATIVE,
			ENUM_POSITIVE
		};

		IfcSurfaceSide() = default;
		IfcSurfaceSide( IfcSurfaceSideEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 2785408664; }
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		static shared_ptr<IfcSurfaceSide> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		IfcSurfaceSideEnum m_enum;
	};
}

