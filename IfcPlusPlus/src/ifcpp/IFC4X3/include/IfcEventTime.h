/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcSchedulingTime.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcDateTime;
	//ENTITY
	class IFCQUERY_EXPORT IfcEventTime : public IfcSchedulingTime
	{
	public:
		IfcEventTime() = default;
		IfcEventTime( int id );
		virtual void getStepLine( std::stringstream& stream, size_t precision ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 7; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 211053100; }

		// IfcSchedulingTime -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcLabel>			m_Name;						//optional
		//  shared_ptr<IfcDataOriginEnum>	m_DataOrigin;				//optional
		//  shared_ptr<IfcLabel>			m_UserDefinedDataOrigin;	//optional

		// IfcEventTime -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcDateTime>			m_ActualDate;				//optional
		shared_ptr<IfcDateTime>			m_EarlyDate;				//optional
		shared_ptr<IfcDateTime>			m_LateDate;					//optional
		shared_ptr<IfcDateTime>			m_ScheduleDate;				//optional
	};
}
