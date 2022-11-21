/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcIdentifier.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcObjectPlacement.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcPile.h"
#include "ifcpp/IFC4X3/include/IfcPileConstructionEnum.h"
#include "ifcpp/IFC4X3/include/IfcPileTypeEnum.h"
#include "ifcpp/IFC4X3/include/IfcProductRepresentation.h"
#include "ifcpp/IFC4X3/include/IfcRelAdheresToElement.h"
#include "ifcpp/IFC4X3/include/IfcRelAggregates.h"
#include "ifcpp/IFC4X3/include/IfcRelAssigns.h"
#include "ifcpp/IFC4X3/include/IfcRelAssignsToProduct.h"
#include "ifcpp/IFC4X3/include/IfcRelAssociates.h"
#include "ifcpp/IFC4X3/include/IfcRelConnectsElements.h"
#include "ifcpp/IFC4X3/include/IfcRelConnectsWithRealizingElements.h"
#include "ifcpp/IFC4X3/include/IfcRelContainedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcRelCoversBldgElements.h"
#include "ifcpp/IFC4X3/include/IfcRelDeclares.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4X3/include/IfcRelFillsElement.h"
#include "ifcpp/IFC4X3/include/IfcRelInterferesElements.h"
#include "ifcpp/IFC4X3/include/IfcRelNests.h"
#include "ifcpp/IFC4X3/include/IfcRelPositions.h"
#include "ifcpp/IFC4X3/include/IfcRelProjectsElement.h"
#include "ifcpp/IFC4X3/include/IfcRelReferencedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcRelSpaceBoundary.h"
#include "ifcpp/IFC4X3/include/IfcRelVoidsElement.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcPile 
IFC4X3::IfcPile::IfcPile( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcPile::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcPile> copy_self( new IfcPile() );
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
	if( m_ObjectType ) { copy_self->m_ObjectType = dynamic_pointer_cast<IfcLabel>( m_ObjectType->getDeepCopy(options) ); }
	if( m_ObjectPlacement ) { copy_self->m_ObjectPlacement = dynamic_pointer_cast<IfcObjectPlacement>( m_ObjectPlacement->getDeepCopy(options) ); }
	if( m_Representation ) { copy_self->m_Representation = dynamic_pointer_cast<IfcProductRepresentation>( m_Representation->getDeepCopy(options) ); }
	if( m_Tag ) { copy_self->m_Tag = dynamic_pointer_cast<IfcIdentifier>( m_Tag->getDeepCopy(options) ); }
	if( m_PredefinedType ) { copy_self->m_PredefinedType = dynamic_pointer_cast<IfcPileTypeEnum>( m_PredefinedType->getDeepCopy(options) ); }
	if( m_ConstructionType ) { copy_self->m_ConstructionType = dynamic_pointer_cast<IfcPileConstructionEnum>( m_ConstructionType->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcPile::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCPILE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Representation ) { stream << "#" << m_Representation->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ConstructionType ) { m_ConstructionType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcPile::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcPile::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 10 ){ std::stringstream err; err << "Wrong parameter count for entity IfcPile, expecting 10, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );
	readEntityReference( args[1], m_OwnerHistory, map, errorStream );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );
	m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );
	m_ObjectType = IfcLabel::createObjectFromSTEP( args[4], map, errorStream );
	readEntityReference( args[5], m_ObjectPlacement, map, errorStream );
	readEntityReference( args[6], m_Representation, map, errorStream );
	m_Tag = IfcIdentifier::createObjectFromSTEP( args[7], map, errorStream );
	m_PredefinedType = IfcPileTypeEnum::createObjectFromSTEP( args[8], map, errorStream );
	m_ConstructionType = IfcPileConstructionEnum::createObjectFromSTEP( args[9], map, errorStream );
}
void IFC4X3::IfcPile::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcDeepFoundation::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "PredefinedType", m_PredefinedType ) );
	vec_attributes.emplace_back( std::make_pair( "ConstructionType", m_ConstructionType ) );
}
void IFC4X3::IfcPile::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcDeepFoundation::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcPile::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcDeepFoundation::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcPile::unlinkFromInverseCounterparts()
{
	IfcDeepFoundation::unlinkFromInverseCounterparts();
}
