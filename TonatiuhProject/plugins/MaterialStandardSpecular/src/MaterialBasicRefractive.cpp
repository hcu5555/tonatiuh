/***************************************************************************
Copyright (C) 2008 by the Tonatiuh Software Development Team.

This file is part of Tonatiuh.

Tonatiuh program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


Acknowledgments:

The development of Tonatiuh was started on 2004 by Dr. Manuel J. Blanco,
then Chair of the Department of Engineering of the University of Texas at
Brownsville. From May 2004 to July 2008, it was supported by the Department
of Energy (DOE) and the National Renewable Energy Laboratory (NREL) under
the Minority Research Associate (MURA) Program Subcontract ACQ-4-33623-06.
During 2007, NREL also contributed to the validation of Tonatiuh under the
framework of the Memorandum of Understanding signed with the Spanish
National Renewable Energy Centre (CENER) on February, 20, 2007 (MOU#NREL-07-117).
Since June 2006, the development of Tonatiuh is being led by the CENER, under the
direction of Dr. Blanco, now Director of CENER Solar Thermal Energy Department.

Developers: Manuel J. Blanco (mblanco@cener.com), Amaia Mutuberria, Victor Martin.

Contributors: Javier Garcia-Barberena, I�aki Perez, Inigo Pagola,  Gilda Jimenez,
Juana Amieva, Azael Mancillas, Cesar Cantu.
***************************************************************************/

#include <QString>

#include <Inventor/sensors/SoFieldSensor.h>

#include "DifferentialGeometry.h"
#include "MaterialStandardSpecular.h"
#include "RandomDeviate.h"
#include "Ray.h"
#include "tgc.h"
#include "tgf.h"
#include "Trace.h"
#include "Transform.h"


SO_NODE_SOURCE(MaterialStandardSpecular);

void MaterialBasicRefractive::initClass()
{
	Trace trace( "MaterialBasicRefractive::MaterialStandardSpecular", false );
	 SO_NODE_INIT_CLASS( MaterialStandardSpecular, TMaterial, "Material" );
}

MaterialBasicRefractive::MaterialStandardSpecular()
{
	Trace trace( "MaterialBasicRefractive::MaterialStandardSpecular", false );

	SO_NODE_CONSTRUCTOR( MaterialStandardSpecular );
	SO_NODE_ADD_FIELD( m_reflectivity, (0.0) );
	SO_NODE_ADD_FIELD( m_transmissivity, (0.0) );
	SO_NODE_ADD_FIELD( m_sigmaSlope, (2.0) );
	//SO_NODE_ADD_FIELD( m_sigmaSpecularity, (0.5) );
	SO_NODE_ADD_FIELD( m_ambientColor, (0.2, 0.2, 0.2) );
	SO_NODE_ADD_FIELD( m_diffuseColor, (0.8, 0.8, 0.8) );
	SO_NODE_ADD_FIELD( m_specularColor, (0.0, 0.0, 0.0) );
	SO_NODE_ADD_FIELD( m_emissiveColor, (0.0, 0.0, 0.0) );
	SO_NODE_ADD_FIELD( m_shininess, (0.2) );
	SO_NODE_ADD_FIELD( m_transparency, (0.0) );

	SO_NODE_DEFINE_ENUM_VALUE(Distribution, PILLBOX);
  	SO_NODE_DEFINE_ENUM_VALUE(Distribution, NORMAL);
  	SO_NODE_SET_SF_ENUM_TYPE(m_distribution, Distribution);
	SO_NODE_ADD_FIELD( m_distribution, (PILLBOX) );

	SoFieldSensor* m_reflectivitySensor = new SoFieldSensor( updateReflectivity, this );
	m_reflectivitySensor->attach( &m_reflectivity );
	SoFieldSensor* m_transmissivitySensor = new SoFieldSensor( updateTransmissivity, this );
	m_transmissivitySensor->attach( &m_transmissivity );

	SoFieldSensor* m_ambientColorSensor = new SoFieldSensor( updateAmbientColor, this );
	m_ambientColorSensor->attach( &m_ambientColor );
	SoFieldSensor* m_diffuseColorSensor = new SoFieldSensor( updateDiffuseColor, this );
	m_diffuseColorSensor->attach( &m_diffuseColor );
	SoFieldSensor* m_specularColorSensor = new SoFieldSensor( updateSpecularColor, this );
	m_specularColorSensor->attach( &m_specularColor );
	SoFieldSensor* m_emissiveColorSensor = new SoFieldSensor( updateEmissiveColor, this );
	m_emissiveColorSensor->attach( &m_emissiveColor );
	SoFieldSensor* m_shininessSensor = new SoFieldSensor( updateShininess, this );
	m_shininessSensor->attach( &m_shininess );
	SoFieldSensor* m_transparencySensor = new SoFieldSensor( updateTransparency, this );
	m_transparencySensor->attach( &m_transparency );
}

MaterialBasicRefractive::~MaterialStandardSpecular()
{
	Trace trace( "MaterialBasicRefractive::~MaterialStandardSpecular", false );
}

QString MaterialBasicRefractive::getIcon()
{
	Trace trace( "MaterialBasicRefractive::getIcon", false );
	return QString(":icons/MaterialStandardSpecular.png");
}

void MaterialBasicRefractive::updateReflectivity( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateReflectivity", false );

	MaterialStandardSpecular* material = static_cast< MaterialStandardSpecular* >( data );
	if( material->m_reflectivity.getValue() < 0.0 ) material->m_reflectivity = 0.0;
   	if( material->m_reflectivity.getValue() > 1.0 ) material->m_reflectivity = 1.0;
}

void MaterialBasicRefractive::updateTransmissivity( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateTransmissivity", false );

	MaterialBasicRefractive* material = static_cast< MaterialBasicRefractive* >( data );
	if( material->m_transmissivity.getValue() < 0.0 ) material->m_transmissivity = 0.0;
   	if( material->m_transmissivity.getValue() > 1.0 ) material->m_transmissivity = 1.0;
}

void MaterialBasicRefractive::updateAmbientColor( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateAmbientColor", false );

   	MaterialStandardSpecular* material = static_cast< MaterialStandardSpecular* >( data );
 	material->ambientColor.setValue( material->m_ambientColor[0] );
}

void MaterialBasicRefractive::updateDiffuseColor( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateDiffuseColor", false );

   	MaterialStandardSpecular* material = static_cast< MaterialStandardSpecular* >( data );
 	material->diffuseColor.setValue( material->m_diffuseColor[0] );
}

void MaterialBasicRefractive::updateSpecularColor( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateSpecularColor", false );

   	MaterialStandardSpecular* material = static_cast< MaterialStandardSpecular* >( data );
 	material->specularColor.setValue( material->m_specularColor[0] );
}

void MaterialBasicRefractive::updateEmissiveColor( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateEmissiveColor", false );

   	MaterialStandardSpecular* material = static_cast< MaterialStandardSpecular* >( data );
 	material->emissiveColor.setValue( material->m_emissiveColor[0] );
}

void MaterialBasicRefractive::updateShininess( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateShininess", false );

   	MaterialStandardSpecular* material = static_cast< MaterialStandardSpecular* >( data );
 	material->shininess.setValue( material->m_shininess[0] );
}

void MaterialBasicRefractive::updateTransparency( void* data, SoSensor* )
{
	Trace trace( "MaterialBasicRefractive::updateTransparency", false );

   	MaterialStandardSpecular* material = static_cast< MaterialStandardSpecular* >( data );
 	material->transparency.setValue( material->m_transparency[0] );
}
Ray* MaterialBasicRefractive::OutputRay( const Ray& incident, DifferentialGeometry* dg, RandomDeviate& rand  ) const
{
	Trace trace( "MaterialBasicRefractive::OutputRay", false );
	double randomNumber = rand.RandomDouble();
	if ( randomNumber < m_reflectivity.getValue()  ) return ReflectedRay( incident, dg, rand );
	else if ( randomNumber < ( m_reflectivity.getValue() + m_transmissivity.getValue() ) ) return RefractedRay( incident, dg, rand );
	else return 0;
}

Ray* MaterialBasicRefractive::ReflectedRay( const Ray& incident, DifferentialGeometry* dg, RandomDeviate& rand ) const
{
	Trace trace( "MaterialBasicRefractive::ReflectedRay", false );

	//Compute reflected ray (local coordinates )
	Ray* reflected = new Ray();
	reflected->origin = dg->point;

	NormalVector normalVector;
	double sigmaSlope = m_sigmaSlope.getValue() / 1000;
	if( sigmaSlope > 0.0 )
	{
		NormalVector errorNormal;
		if ( m_distribution.getValue() == 0 )
		{
			double phi = tgc::TwoPi * rand.RandomDouble();
			double theta = sigmaSlope * rand.RandomDouble();

			errorNormal.x = sin( theta ) * sin( phi ) ;
			errorNormal.y = cos( theta );
			errorNormal.z = sin( theta ) * cos( phi );
		 }
		 else if (m_distribution.getValue() == 1 )
		 {
			 errorNormal.x = sigmaSlope * tgf::AlternateBoxMuller( rand );
			 errorNormal.y = 1.0;
			 errorNormal.z = sigmaSlope * tgf::AlternateBoxMuller( rand );

		 }
		Vector3D r = dg->normal;
		Vector3D s = Normalize( dg->dpdu );
		Vector3D t = Normalize( dg->dpdv );
		Transform trasform( s.x, s.y, s.z, 0.0,
								r.x, r.y, r.z, 0.0,
								t.x, t.y, t.z, 0.0,
								0.0, 0.0, 0.0, 1.0);

		NormalVector normalDirection = trasform.GetInverse()( errorNormal );
		normalVector = Normalize( normalDirection );
	}
	else
	{
		normalVector = dg->normal;
	}

	double cosTheta = DotProduct( normalVector, incident.direction );
	reflected->direction = Normalize( incident.direction - 2.0 * normalVector * cosTheta );
	return reflected;

}

Ray* MaterialBasicRefractive::RefractedtRay( const Ray& incident, DifferentialGeometry* dg, RandomDeviate& rand  ) const
{
	Trace trace( "MaterialBasicRefractive::RefractedtRay", false );


}
