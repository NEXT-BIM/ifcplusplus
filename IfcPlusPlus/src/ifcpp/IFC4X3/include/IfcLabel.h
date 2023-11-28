/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcSimpleValue.h"

namespace IFC4X3
{
	// TYPE IfcLabel = STRING(255);
	class IFCQUERY_EXPORT IfcLabel : public IfcSimpleValue
	{
	public:
		IfcLabel() = default;
		IfcLabel( std::string value );
		virtual uint32_t classID() const { return 3258342251; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcLabel> createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		std::string m_value;
	};
}
