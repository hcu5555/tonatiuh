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

#include <Inventor/nodekits/SoBaseKit.h>

#include "CmdPaste.h"
#include "SceneModel.h"
#include "InstanceNode.h"
#include "tgf.h"

CmdPaste::CmdPaste( tgc::PasteType type, const QModelIndex& parentModelIndex,  SoNode*& coinClipboard, SceneModel& sceneModel, QUndoCommand* parent )
: QUndoCommand("Paste", parent), m_pasteType( type ), m_parentInstance( 0 ), m_coinChild( coinClipboard ), m_sceneModel( &sceneModel ), m_oldNodeName( 0 ),  m_row( -1 )
{
	if( !parentModelIndex.isValid() ) tgf::SevereError( "CmdPaste called with invalid ModelIndex." );

	//InstanceNode* instanceParent = m_sceneModel->NodeFromIndex( parentModelIndex );
	m_parentInstance = m_sceneModel->NodeFromIndex( parentModelIndex );
	if( !m_parentInstance-> GetNode() ) tgf::SevereError( "CmdPaste NULL m_coinParent." );
	//m_coinParent = static_cast< SoBaseKit* > ( m_parentInstance-> GetNode() );

	m_row = m_parentInstance->children.size();
	m_oldNodeName = QString( coinClipboard->getName().getString() );
}

CmdPaste::~CmdPaste()
{

}

void CmdPaste::undo()
{
	SoBaseKit* coinParent = static_cast< SoBaseKit* > ( m_parentInstance-> GetNode() );
	m_sceneModel->Cut( *coinParent, m_row );
	m_sceneModel->SetNodeName( m_coinChild, m_oldNodeName );
}

void CmdPaste::redo( )
{
	SoBaseKit* coinParent = static_cast< SoBaseKit* > ( m_parentInstance-> GetNode() );
	if( !m_sceneModel->Paste( m_pasteType, *coinParent, *m_coinChild, m_row ) ) return;

	SoNode* newNode = m_parentInstance->children[m_row]->GetNode();

	int count = 0;
	QString newName = m_oldNodeName;
	while ( !m_sceneModel->SetNodeName( newNode, newName ) )
	{
		count++;
		newName = QString( "%1_copy%2").arg( m_oldNodeName, QString::number( count) );
	}
}
