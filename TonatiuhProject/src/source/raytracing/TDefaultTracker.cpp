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

#include <iostream>
#include <Inventor/engines/SoSubEngine.h>
#include <Inventor/fields/SoSFRotation.h>
#include <Inventor/fields/SoSFVec3f.h>

#include <QString>

#include "TDefaultTracker.h"

SO_NODEENGINE_SOURCE( TDefaultTracker );

/**
 * Sets up initialization for data common to all instances of this class, like submitting necessary information to the Coin type system.
 *
 */
void TDefaultTracker::initClass()
{
	SO_NODEENGINE_INIT_CLASS( TDefaultTracker, TTracker, "TTracker" );
}

/**
 * TDefaultTracker constructor
 */
TDefaultTracker::TDefaultTracker()
{
	SO_NODEENGINE_CONSTRUCTOR(TDefaultTracker);

	// Define input fields and their default values
	SO_NODEENGINE_ADD_OUTPUT( outputTranslation, SoSFVec3f);
	SO_NODEENGINE_ADD_OUTPUT( outputRotation, SoSFRotation);
	SO_NODEENGINE_ADD_OUTPUT( outputScaleFactor, SoSFVec3f);
	SO_NODEENGINE_ADD_OUTPUT( outputScaleOrientation, SoSFRotation);
	SO_NODEENGINE_ADD_OUTPUT( outputCenter, SoSFVec3f);
}

/**
 * TDefaultTracker destructor
 */
TDefaultTracker::~TDefaultTracker()
{

}

/**
 * Returns the icon that represents the TDefaultTracker.
 */
QString TDefaultTracker::getIcon()
{
	return QString(":/icons/HorizontalTracker.png");
}

/**
 * Computes the rotation ouput.
 */
void TDefaultTracker::evaluate()
{
	if( !m_azimuth.isConnected() ) return;
	if( !m_zenith.isConnected() ) return;

	SO_ENGINE_OUTPUT( outputTranslation, SoSFVec3f, setValue( 0.0, 0.0, 0.0 ) );
	SO_ENGINE_OUTPUT( outputRotation, SoSFRotation, setValue( 0.0, 0.0, 1.0, 0.0 ) );
	SO_ENGINE_OUTPUT( outputScaleFactor, SoSFVec3f, setValue( 1.0, 1.0, 1.0 ) );
	SO_ENGINE_OUTPUT( outputScaleOrientation, SoSFRotation, setValue( 0.0, 0.0, 1.0, 0.0 ) );
	SO_ENGINE_OUTPUT( outputCenter, SoSFVec3f, setValue( 0.0, 0.0, 0.0 ) );

}