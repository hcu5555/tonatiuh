/***************************************************************************
Copyright (C) 2008 by the Ekhi Software Development Team.

This file is part of Ekhi.

Ekhi program is free software: you can redistribute it and/or modify
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

The development of Ekhi was started on 2004 by Dr. Manuel J. Blanco,
then Chair of the Department of Engineering of the University of Texas at
Brownsville. From May 2004 to July 2008, it was supported by the Department
of Energy (DOE) and the National Renewable Energy Laboratory (NREL) under
the Minority Research Associate (MURA) Program Subcontract ACQ-4-33623-06.
During 2007, NREL also contributed to the validation of Ekhi under the
framework of the Memorandum of Understanding signed with the Spanish
National Renewable Energy Centre (CENER) on February, 20, 2007 (MOU#NREL-07-117).
Since June 2006, the development of Ekhi is being led by the CENER, under the
direction of Dr. Blanco, now Director of CENER Solar Thermal Energy Department.

Developers: Manuel J. Blanco (mblanco@cener.com), Amaia Mutuberria, Victor Martin.

Contributors: Javier Garcia-Barberena, I�aki Perez, Inigo Pagola,  Gilda Jimenez,
Juana Amieva, Azael Mancillas, Cesar Cantu.
***************************************************************************/

#ifndef BEZIERPATCH_H_
#define BEZIERPATCH_H_

#include <Inventor/fields/SoMFVec3f.h>
#include <Inventor/nodes/SoNurbsSurface.h>

#include "TShape.h"

class Vector3D;

class SoMFVec3d;

class BezierPatch : public SoNurbsSurface
{
	SO_NODE_HEADER(BezierPatch);

public:
	BezierPatch();

    static void initClass();

    SbBox3f GetComputeBBox();
    SoMFVec3f GetControlPoints( );
    void SetControlPoints( QVector< Point3D > boundedPoints );
    void SetControlPoints( SoMFVec3f controlPoints );

    void GeneratePrimitives( SoAction *action );
    void GLRender (SoGLRenderAction* action);

    bool IntersectP( const Ray& objectRay ) const;
    bool Intersect( const Ray& objectRay, double* tHit, DifferentialGeometry* dg ) const;

protected:
	Point3D GetPoint3D (double u, double v) const;
	NormalVector GetNormal( double u, double v ) const;

    void computeBBox(SoAction*, SbBox3f& box, SbVec3f& /*center*/ );
	void generatePrimitives( SoAction *action );

    virtual ~BezierPatch();

private:
	QVector< Vector3D > CornerDerivates( QVector< Point3D > boundedPoints );

	Vector3D DPDU( double u, double v, SoMFVec3d& controlPoints  ) const;
	Vector3D DPDV( double u, double v, SoMFVec3d& controlPoints  ) const;
	Vector3D D2PDUU( double u, double v, SoMFVec3d& controlPoints ) const;
	Vector3D D2PDUV( double u, double v, SoMFVec3d& controlPoints  ) const;
	Vector3D D2PDVV( double u, double v, SoMFVec3d& controlPoints  ) const;

	void HullSplitU( const SoMFVec3d& p, SoMFVec3d* q, SoMFVec3d* r ) const;
	void HullSplitV( const SoMFVec3d& p, SoMFVec3d* q, SoMFVec3d* r) const;

	int m_order;
    SoMFVec3f m_controlPoints;
};

#endif /* BEZIERPATCH_H_ */
