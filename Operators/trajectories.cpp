//******** PRACTICA GRAFICS PER COMPUTADOR 2 (Codi Pràctica 4)
//********  marc Vivet, Carme Julià, Débora Gil, Enric Martí (Abril 2009)
// trajectories.cpp: Codi de les funcions per la trajectòria spline:
//                    * spline: Calcula les coordenades del punt (x,y,z) segons t  
//                    * Dspline: Calcula la tangent (tx,ty,tz) segons t

#include "trajectories.h"
#include "Utils/util.h"
#include <math.h>

// spline: Calcul del punt (x,y,z) de l'spline (tangent) en coordenades 3D (CPunt3D)
// Paràmetres:	t: Paràmetre de la corba (t=[0,1])
//				ctr: Punts de control de la corba
Point3D spline(float t, Point3D * ctr)
{
	float coef[4];
	int i,j;
  
//Polinomis que multipliquen els punts de control del patch
	for(i=0;i<4;i++)
	{
		coef[i]=0;
		for(j=0;j<4;j++)
		 coef[i]=coef[i]*t+A[i][j];
	}

    float x = 0.,y = 0.,z = 0.;
    //Càlcul de la Posició
	for(i=0;i<4;i++)
	{
        x+=coef[i]*ctr[i].getX();
        y+=coef[i]*ctr[i].getY();
        z+=coef[i]*ctr[i].getZ();
	}

    return Point3D(x,y,z);
}

// Dspline: Calcul de la derivada de l'spline (tangent) en coordenades 3D (CPunt3D)
// Paràmetres:	t: Paràmetre de la corba (t=[0,1])
//				ctr: Punts de control de la corba
Vector3D Dspline(float t, Point3D * ctr)
{

	float coef[4];
	int i,j;


    //Polinomis que multipliquen els punts de control del patch
	for(i=0;i<4;i++)
	{
		coef[i]=0;
		for(j=0;j<3;j++)
		 coef[i]=coef[i]*t+(3-j)*A[i][j];
	}

    float x = 0.,y = 0.,z = 0.;
    //Càlcul de la Derivada
	for(i=0;i<4;i++)
	{
        x+=coef[i]*ctr[i].getX();
        y+=coef[i]*ctr[i].getY();
        z+=coef[i]*ctr[i].getZ();
	}

    return Vector3D(x,y,z);
}   

// ComputeAngleZ:	Càlcul de l'angle de rotació Z entre els vectors
//					eix i tangent projectats sobre el pla X-Y.
float ComputeAngleZ(Vector3D eix,Vector3D tangent)
{  
	float sinus,cosinus,normeix,normtg,angle;

    sinus=eix.getX()*tangent.getY()-eix.getY()*tangent.getX();
    normeix=sqrt(eix.getX()*eix.getX()+eix.getY()*eix.getY());
    normtg=sqrt(tangent.getX()*tangent.getX()+tangent.getY()*tangent.getY());
    cosinus=(eix.getX()*tangent.getX()+eix.getY()*tangent.getY())/(normeix*normtg);

    if(sinus>=0) angle=180.0*acos(cosinus)/PI;
    if(sinus<0) angle=-180.0*acos(cosinus)/PI;

	return angle;
}

// ComputeAngleX:	Càlcul de l'angle de rotació X entre els vectors
//					eix i tangent projectats sobre el pla Y-Z.
float ComputeAngleX(Vector3D eix,Vector3D tangent)
{  
//	float sinus,cosinus,normeix,normtg
	float angle=0;

	return angle;
}

