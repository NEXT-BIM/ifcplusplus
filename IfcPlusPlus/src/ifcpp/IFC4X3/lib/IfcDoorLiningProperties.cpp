/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcDoorLiningProperties.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcNonNegativeLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcPositiveLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcRelAssociates.h"
#include "ifcpp/IFC4X3/include/IfcRelDeclares.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByTemplate.h"
#include "ifcpp/IFC4X3/include/IfcShapeAspect.h"
#include "ifcpp/IFC4X3/include/IfcText.h"
#include "ifcpp/IFC4X3/include/IfcTypeObject.h"

// ENTITY IfcDoorLiningProperties 
IFC4X3::IfcDoorLiningProperties::IfcDoorLiningProperties( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcDoorLiningProperties::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcDoorLiningProperties> copy_self( new IfcDoorLiningProperties() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = make_shared<IfcGloballyUniqueId>( createBase64Uuid().data() ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_LiningDepth ) { copy_self->m_LiningDepth = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_LiningDepth->getDeepCopy(options) ); }
	if( m_LiningThickness ) { copy_self->m_LiningThickness = dynamic_pointer_cast<IfcNonNegativeLengthMeasure>( m_LiningThickness->getDeepCopy(options) ); }
	if( m_ThresholdDepth ) { copy_self->m_ThresholdDepth = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_ThresholdDepth->getDeepCopy(options) ); }
	if( m_ThresholdThickness ) { copy_self->m_ThresholdThickness = dynamic_pointer_cast<IfcNonNegativeLengthMeasure>( m_ThresholdThickness->getDeepCopy(options) ); }
	if( m_TransomThickness ) { copy_self->m_TransomThickness = dynamic_pointer_cast<IfcNonNegativeLengthMeasure>( m_TransomThickness->getDeepCopy(options) ); }
	if( m_TransomOffset ) { copy_self->m_TransomOffset = dynamic_pointer_cast<IfcLengthMeasure>( m_TransomOffset->getDeepCopy(options) ); }
	if( m_LiningOffset ) { copy_self->m_LiningOffset = dynamic_pointer_cast<IfcLengthMeasure>( m_LiningOffset->getDeepCopy(options) ); }
	if( m_ThresholdOffset ) { copy_self->m_ThresholdOffset = dynamic_pointer_cast<IfcLengthMeasure>( m_ThresholdOffset->getDeepCopy(options) ); }
	if( m_CasingThickness ) { copy_self->m_CasingThickness = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_CasingThickness->getDeepCopy(options) ); }
	if( m_CasingDepth ) { copy_self->m_CasingDepth = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_CasingDepth->getDeepCopy(options) ); }
	if( m_ShapeAspectStyle ) { copy_self->m_ShapeAspectStyle = dynamic_pointer_cast<IfcShapeAspect>( m_ShapeAspectStyle->getDeepCopy(options) ); }
	if( m_LiningToPanelOffsetX ) { copy_self->m_LiningToPanelOffsetX = dynamic_pointer_cast<IfcLengthMeasure>( m_LiningToPanelOffsetX->getDeepCopy(options) ); }
	if( m_LiningToPanelOffsetY ) { copy_self->m_LiningToPanelOffsetY = dynamic_pointer_cast<IfcLengthMeasure>( m_LiningToPanelOffsetY->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcDoorLiningProperties::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCDOORLININGPROPERTIES" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_LiningDepth ) { m_LiningDepth->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_LiningThickness ) { m_LiningThickness->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ThresholdDepth ) { m_ThresholdDepth->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ThresholdThickness ) { m_ThresholdThickness->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_TransomThickness ) { m_TransomThickness->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_TransomOffset ) { m_TransomOffset->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_LiningOffset ) { m_LiningOffset->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ThresholdOffset ) { m_ThresholdOffset->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_CasingThickness ) { m_CasingThickness->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_CasingDepth ) { m_CasingDepth->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ShapeAspectStyle ) { stream << "#" << m_ShapeAspectStyle->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_LiningToPanelOffsetX ) { m_LiningToPanelOffsetX->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_LiningToPanelOffsetY ) { m_LiningToPanelOffsetY->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcDoorLiningProperties::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcDoorLiningProperties::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 17 ){ std::stringstream err; err << "Wrong parameter count for entity IfcDoorLiningProperties, expecting 17, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );
	readEntityReference( args[1], m_OwnerHistory, map, errorStream );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );
	m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );
	m_LiningDepth = IfcPositiveLengthMeasure::createObjectFromSTEP( args[4], map, errorStream );
	m_LiningThickness = IfcNonNegativeLengthMeasure::createObjectFromSTEP( args[5], map, errorStream );
	m_ThresholdDepth = IfcPositiveLengthMeasure::createObjectFromSTEP( args[6], map, errorStream );
	m_ThresholdThickness = IfcNonNegativeLengthMeasure::createObjectFromSTEP( args[7], map, errorStream );
	m_TransomThickness = IfcNonNegativeLengthMeasure::createObjectFromSTEP( args[8], map, errorStream );
	m_TransomOffset = IfcLengthMeasure::createObjectFromSTEP( args[9], map, errorStream );
	m_LiningOffset = IfcLengthMeasure::createObjectFromSTEP( args[10], map, errorStream );
	m_ThresholdOffset = IfcLengthMeasure::createObjectFromSTEP( args[11], map, errorStream );
	m_CasingThickness = IfcPositiveLengthMeasure::createObjectFromSTEP( args[12], map, errorStream );
	m_CasingDepth = IfcPositiveLengthMeasure::createObjectFromSTEP( args[13], map, errorStream );
	readEntityReference( args[14], m_ShapeAspectStyle, map, errorStream );
	m_LiningToPanelOffsetX = IfcLengthMeasure::createObjectFromSTEP( args[15], map, errorStream );
	m_LiningToPanelOffsetY = IfcLengthMeasure::createObjectFromSTEP( args[16], map, errorStream );
}
void IFC4X3::IfcDoorLiningProperties::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcPreDefinedPropertySet::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "LiningDepth", m_LiningDepth ) );
	vec_attributes.emplace_back( std::make_pair( "LiningThickness", m_LiningThickness ) );
	vec_attributes.emplace_back( std::make_pair( "ThresholdDepth", m_ThresholdDepth ) );
	vec_attributes.emplace_back( std::make_pair( "ThresholdThickness", m_ThresholdThickness ) );
	vec_attributes.emplace_back( std::make_pair( "TransomThickness", m_TransomThickness ) );
	vec_attributes.emplace_back( std::make_pair( "TransomOffset", m_TransomOffset ) );
	vec_attributes.emplace_back( std::make_pair( "LiningOffset", m_LiningOffset ) );
	vec_attributes.emplace_back( std::make_pair( "ThresholdOffset", m_ThresholdOffset ) );
	vec_attributes.emplace_back( std::make_pair( "CasingThickness", m_CasingThickness ) );
	vec_attributes.emplace_back( std::make_pair( "CasingDepth", m_CasingDepth ) );
	vec_attributes.emplace_back( std::make_pair( "ShapeAspectStyle", m_ShapeAspectStyle ) );
	vec_attributes.emplace_back( std::make_pair( "LiningToPanelOffsetX", m_LiningToPanelOffsetX ) );
	vec_attributes.emplace_back( std::make_pair( "LiningToPanelOffsetY", m_LiningToPanelOffsetY ) );
}
void IFC4X3::IfcDoorLiningProperties::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcPreDefinedPropertySet::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcDoorLiningProperties::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPreDefinedPropertySet::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcDoorLiningProperties::unlinkFromInverseCounterparts()
{
	IfcPreDefinedPropertySet::unlinkFromInverseCounterparts();
}
