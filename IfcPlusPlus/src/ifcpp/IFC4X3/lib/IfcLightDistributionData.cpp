/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcLightDistributionData.h"
#include "ifcpp/IFC4X3/include/IfcLuminousIntensityDistributionMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPlaneAngleMeasure.h"

// ENTITY IfcLightDistributionData 
IFC4X3::IfcLightDistributionData::IfcLightDistributionData( int tag ) { m_tag = tag; }
void IFC4X3::IfcLightDistributionData::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "= IFCLIGHTDISTRIBUTIONDATA" << "(";
	if( m_MainPlaneAngle ) { m_MainPlaneAngle->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	writeTypeOfRealList( stream, m_SecondaryPlaneAngle, false, precision );
	stream << ",";
	writeTypeOfRealList( stream, m_LuminousIntensity, false, precision );
	stream << ");";
}
void IFC4X3::IfcLightDistributionData::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcLightDistributionData::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_MainPlaneAngle = IfcPlaneAngleMeasure::createObjectFromSTEP( args[0], map, errorStream );}
	if( num_args > 1 ){readTypeOfRealList( args[1], m_SecondaryPlaneAngle );}
	if( num_args > 2 ){readTypeOfRealList( args[2], m_LuminousIntensity );}
	if( num_args != 3 ){ errorStream << "Wrong parameter count for entity IfcLightDistributionData, expecting 3, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcLightDistributionData::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	vec_attributes.emplace_back( std::make_pair( "MainPlaneAngle", m_MainPlaneAngle ) );
	shared_ptr<AttributeObjectVector> SecondaryPlaneAngle_vec_object( new AttributeObjectVector() );
	std::copy( m_SecondaryPlaneAngle.begin(), m_SecondaryPlaneAngle.end(), std::back_inserter( SecondaryPlaneAngle_vec_object->m_vec ) );
	vec_attributes.emplace_back( std::make_pair( "SecondaryPlaneAngle", SecondaryPlaneAngle_vec_object ) );
	shared_ptr<AttributeObjectVector> LuminousIntensity_vec_object( new AttributeObjectVector() );
	std::copy( m_LuminousIntensity.begin(), m_LuminousIntensity.end(), std::back_inserter( LuminousIntensity_vec_object->m_vec ) );
	vec_attributes.emplace_back( std::make_pair( "LuminousIntensity", LuminousIntensity_vec_object ) );
}
void IFC4X3::IfcLightDistributionData::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
}
void IFC4X3::IfcLightDistributionData::setInverseCounterparts( shared_ptr<BuildingEntity> )
{
}
void IFC4X3::IfcLightDistributionData::unlinkFromInverseCounterparts()
{
}
