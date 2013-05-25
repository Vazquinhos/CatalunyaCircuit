#ifndef TRAJECT_H
#define TRAJECT_H

#include "Utils/util.h"
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet
#include <bullet/btBulletCollisionCommon.h>
#include "Operators/BSplineInterpolatorOp.h"

Point3D* spline(float time, QVector<Point3D*> ctr);
btVector3 Dspline(float time, QVector<Point3D*> ctr);
float ComputeAngleZ(Vector3D eix,Vector3D tangent);
float ComputeAngleX(Vector3D eix,Vector3D tangent);
const double A[4][4] = { {-1.0/6.0,   0.5,  -0.5,  1.0/6.0 },
                         {   0.5, -1.0,   0.0,  4.0/6.0 },
                         {  -0.5,  0.5,   0.5,  1.0/6.0 },
                         { 1.0/6.0,   0.0,   0.0,    0.0   }};
const int npts=9;

#endif
