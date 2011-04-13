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

Contributors: Javier Garcia-Barberena, Inaki Perez, Inigo Pagola,  Gilda Jimenez,
Juana Amieva, Azael Mancillas, Cesar Cantu.
***************************************************************************/

#include <iostream>
#include <QString>

#include <Inventor/nodekits/SoBaseKit.h>

#include "FieldContainerWidget.h"
#include "ParametersView.h"

/**
 * Creates a new ParametersView with parent \a parent.
 */
ParametersView::ParametersView( QWidget* parent )
: QTabWidget( parent ),
  m_actualCoinNode( 0 )
{
	addTab( new FieldContainerWidget( 0, "" ), tr("Transform") );
	addTab( new FieldContainerWidget( 0, "" ), tr("Shape") );

}
/*!
 * Destroys the parameters view widget.
 */
ParametersView::~ParametersView()
{

}

/*!
 * Changes the parameters view to show \a coinNode \a parts parameters.
 */
void ParametersView::SelectionChanged( SoBaseKit* coinNode, QStringList parts )
{
	clear();

	if( parts.size() == 0 )	parts = ContainerNodeParts( coinNode );

	m_actualCoinNode = coinNode;
	for( int i = 0; i< parts.size(); ++i )
	{
		QString partName = parts[i];
		SoNode* coinPart = coinNode->getPart(partName.toStdString().c_str(), false );
		if( coinPart != 0 ) AddTab( coinPart, partName );
	}

}

/*!
 * Updates selected node parametes views.
 */
void ParametersView::UpdateView()
{
	SelectionChanged(  m_actualCoinNode, QStringList() );
}

/*!
 * Emits a valueModificated signal with \a oldValuesList, the actual node and \a containerName.
 */
void ParametersView::ValueModification( const QStringList& oldValuesList, QString containerName )
{
	emit valueModificated( oldValuesList, m_actualCoinNode, containerName );
}

/*!
 * Adds a new tab to the view with \a coinNode \a partName parameters.
 */
void ParametersView::AddTab( SoNode* coinNode, QString partName )
{
	QString type = coinNode->getTypeId().getName().getString();

	FieldContainerWidget* nodeContainer = new FieldContainerWidget( coinNode, partName, this );
	addTab( nodeContainer, type );
	connect(nodeContainer, SIGNAL( valueModificated( const QStringList& , QString ) ), this, SLOT( ValueModification( const QStringList& , QString ) ) );
}

/*!
 * Returns the names of the parts of the \a coinNode that the view shows.
 *
 * If the \a coinNode is not a container node, return a empty list.
 */
QStringList ParametersView::ContainerNodeParts( SoBaseKit* coinNode )
{
	QStringList parts;
	if( !coinNode && ! coinNode->getTypeId().isDerivedFrom( SoBaseKit::getClassTypeId() ) )	return parts;

	SoBaseKit* nodeKit = static_cast< SoBaseKit* >( coinNode );
	QString type = nodeKit->getTypeId().getName().getString();

	if ( type == "TLightKit" )	parts<<QString( "transform" )<<QString( "icon" )<<QString( "tsunshape" );
	else if( type == "TShapeKit" )	parts<<QString( "shape" )<<QString( "appearance.material" );
	else	parts<<QString( "transform" );

	return parts;
}