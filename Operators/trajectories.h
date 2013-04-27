//******** PRACTICA GRAFICS PER COMPUTADOR 2 (Codi Pr�ctica 4)
//********  Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� (Abril 2009)
// trajectories.h : Interf�cie de trajectories.cpp
//		Definici� de les funcions per la traject�ria spline:
//                    * spline:  Calcula les coordenades del punt (x,y,z) segons t.
//                    * Dspline: Calcula la tangent segonst t.
//					  * Pts:     Punts de control de la traject�ria.
//                    * A:       Matriu dels splines.

#ifndef TRAJECT_H
#define TRAJECT_H

#include "Utils/util.h"

Point3D spline(float t, Point3D * ctr);
Vector3D Dspline(float t, Point3D * ctr);

// ComputeAngleZ:	C�lcul de l'angle de rotaci� Z entre els vectors
//					eix i tangent projectats sobre el pla X-Y,
float ComputeAngleZ(Vector3D eix,Vector3D tangent);

// ComputeAngleX:	C�lcul de l'angle de rotaci� X entre els vectors
//					eix i tangent projectats sobre el pla Y-Z.
float ComputeAngleX(Vector3D eix,Vector3D tangent);

//Matriu dels Splines
const double A[4][4] =
    {
     {-1.0/6.0,   0.5,  -0.5,  1.0/6.0 },
     {   0.5, -1.0,   0.0,  4.0/6.0 },
     {  -0.5,  0.5,   0.5,  1.0/6.0 },
     { 1.0/6.0,   0.0,   0.0,    0.0   }
    };

    //Vector dels punts de control3D
    /*const Point3D Pts[ ]={(256+16,256,30),(-256,256,-10),(-256,0,30),(-128-16,0,75),
    (-16,64+32+32,150),(256-32,64-32,75),(256+16,256,30),(-256,256,-10),(-256,0,30)};*/

//Numero Pts control
const int npts=9;
#endif
