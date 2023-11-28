/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcRelConnects.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcRelConnects 
IFC4X3::IfcRelConnects::IfcRelConnects( int tag ) { m_tag = tag; }
void IFC4X3::IfcRelConnects::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCRELCONNECTS" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcRelConnects::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcRelConnects::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){readEntityReference( args[1], m_OwnerHistory, map, errorStream );}
	if( num_args > 2 ){m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream );}
	if( num_args > 3 ){m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream );}
	if( num_args != 4 ){ errorStream << "Wrong parameter count for entity IfcRelConnects, expecting 4, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcRelConnects::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcRelationship::getAttributes( vec_attributes );
}
void IFC4X3::IfcRelConnects::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcRelationship::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcRelConnects::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelationship::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcRelConnects::unlinkFromInverseCounterparts()
{
	IfcRelationship::unlinkFromInverseCounterparts();
}
