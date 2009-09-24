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

#include <QString>

#include <Inventor/nodes/SoTransform.h>

#include "TDefaultTracker.h"
#include "Trace.h"
#include "TSeparatorKit.h"

SO_KIT_SOURCE(TSeparatorKit);

void TSeparatorKit::initClass()
{
	SO_KIT_INIT_CLASS(TSeparatorKit, SoSeparatorKit, "SeparatorKit");
}

TSeparatorKit::TSeparatorKit()
{

	SO_KIT_CONSTRUCTOR(TSeparatorKit);
	SO_KIT_INIT_INSTANCE();

	SoTransform* transform = new SoTransform;
	setPart("transform", transform);

}

TSeparatorKit::~TSeparatorKit()
{
    Trace trace("TSeparatorKit exiting destructor", false);
}

QString TSeparatorKit::getIcon()
{
    Trace trace("TSeparatorKit::getIcon", false );

    SoTransform* transformNode = dynamic_cast< SoTransform* > ( getPart( "transform", false ) );
    if( !transformNode  )	return QString(":/icons/separatorKit.png");

    if( !transformNode->rotation.isConnected() ) return QString(":/icons/separatorKit.png");

    SoEngineOutput* outputEngine;
    transformNode->rotation.getConnectedEngine( outputEngine );
    if( !outputEngine  )	return QString(":/icons/separatorKit.png");

    TTracker* trackerNode = dynamic_cast<TTracker* > ( outputEngine->getContainer() );
    if( trackerNode != 0 ) return trackerNode->getIcon();

    return QString(":/icons/separatorKit.png");

}

bool  TSeparatorKit::IsConnected()
{
    Trace trace("TSeparatorKit::IsConnected", false );

    SoTransform* transformNode = dynamic_cast< SoTransform* > ( getPart( "transform", false ) );
    if( !transformNode  )	return false;

    if( !transformNode->rotation.isConnected() ) return false;

    SoEngineOutput* outputEngine;
    transformNode->rotation.getConnectedEngine( outputEngine );
    if( !outputEngine  )	return false;

    return true;
}
