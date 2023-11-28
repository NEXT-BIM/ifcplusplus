/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcBuiltSystem.h"
#include "ifcpp/IFC4X3/include/IfcBuiltSystemTypeEnum.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcRelAggregates.h"
#include "ifcpp/IFC4X3/include/IfcRelAssigns.h"
#include "ifcpp/IFC4X3/include/IfcRelAssignsToGroup.h"
#include "ifcpp/IFC4X3/include/IfcRelAssociates.h"
#include "ifcpp/IFC4X3/include/IfcRelDeclares.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4X3/include/IfcRelNests.h"
#include "ifcpp/IFC4X3/include/IfcRelReferencedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcRelServicesBuildings.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcBuiltSystem 
IFC4X3::IfcBuiltSystem::IfcBuiltSystem( int tag ) { m_tag = tag; }
void IFC4X3::IfcBuiltSystem::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCBUILTSYSTEM" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_LongName ) { m_LongName->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcBuiltSystem::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcBuiltSystem::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){readEntityReference( args[1], m_OwnerHistory, map, errorStream );}
	if( num_args > 2 ){m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );}
	if( num_args > 4 ){m_ObjectType = IfcLabel::createObjectFromSTEP( args[4], map, errorStream );}
	if( num_args > 5 ){m_PredefinedType = IfcBuiltSystemTypeEnum::createObjectFromSTEP( args[5], map, errorStream );}
	if( num_args > 6 ){m_LongName = IfcLabel::createObjectFromSTEP( args[6], map, errorStream );}
	if( num_args != 7 ){ errorStream << "Wrong parameter count for entity IfcBuiltSystem, expecting 7, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcBuiltSystem::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcSystem::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "PredefinedType", m_PredefinedType ) );
	vec_attributes.emplace_back( std::make_pair( "LongName", m_LongName ) );
}
void IFC4X3::IfcBuiltSystem::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcSystem::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcBuiltSystem::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcSystem::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcBuiltSystem::unlinkFromInverseCounterparts()
{
	IfcSystem::unlinkFromInverseCounterparts();
}
