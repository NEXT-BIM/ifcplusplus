/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
#include "IfcTaskTime.h"
namespace IFC4X3
{
	class IFCQUERY_EXPORT IfcRecurrencePattern;
	//ENTITY
	class IFCQUERY_EXPORT IfcTaskTimeRecurring : public IfcTaskTime
	{ 
	public:
		IfcTaskTimeRecurring() = default;
		IfcTaskTimeRecurring( int id );
		virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
		virtual void getStepLine( std::stringstream& stream ) const;
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
		virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream );
		virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
		virtual uint8_t getNumAttributes() const { return 21; }
		virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
		virtual void unlinkFromInverseCounterparts();
		virtual uint32_t classID() const { return 2771591690; }

		// IfcSchedulingTime -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcLabel>				m_Name;						//optional
		//  shared_ptr<IfcDataOriginEnum>		m_DataOrigin;				//optional
		//  shared_ptr<IfcLabel>				m_UserDefinedDataOrigin;	//optional

		// IfcTaskTime -----------------------------------------------------------
		// attributes:
		//  shared_ptr<IfcTaskDurationEnum>		m_DurationType;				//optional
		//  shared_ptr<IfcDuration>				m_ScheduleDuration;			//optional
		//  shared_ptr<IfcDateTime>				m_ScheduleStart;			//optional
		//  shared_ptr<IfcDateTime>				m_ScheduleFinish;			//optional
		//  shared_ptr<IfcDateTime>				m_EarlyStart;				//optional
		//  shared_ptr<IfcDateTime>				m_EarlyFinish;				//optional
		//  shared_ptr<IfcDateTime>				m_LateStart;				//optional
		//  shared_ptr<IfcDateTime>				m_LateFinish;				//optional
		//  shared_ptr<IfcDuration>				m_FreeFloat;				//optional
		//  shared_ptr<IfcDuration>				m_TotalFloat;				//optional
		//  shared_ptr<IfcBoolean>				m_IsCritical;				//optional
		//  shared_ptr<IfcDateTime>				m_StatusTime;				//optional
		//  shared_ptr<IfcDuration>				m_ActualDuration;			//optional
		//  shared_ptr<IfcDateTime>				m_ActualStart;				//optional
		//  shared_ptr<IfcDateTime>				m_ActualFinish;				//optional
		//  shared_ptr<IfcDuration>				m_RemainingTime;			//optional
		//  shared_ptr<IfcPositiveRatioMeasure>	m_Completion;				//optional

		// IfcTaskTimeRecurring -----------------------------------------------------------
		// attributes:
		shared_ptr<IfcRecurrencePattern>	m_Recurrence;
	};
}

