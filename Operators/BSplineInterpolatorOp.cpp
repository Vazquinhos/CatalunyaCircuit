#include "BSplineInterpolatorOp.h"
#include "Utils/util.h"
#include <math.h>
#include <QVector>

Point3D* spline(float time, QVector<Point3D*> ctr)
{
	float coef[4];
    float x = 0.,y = 0.,z = 0.;

    // Pre-Condition
    unsigned sizeVec = ctr.size();

    if((sizeVec > 0) || ( sizeVec > 4))
    {
        for( unsigned int i=0; i<4; ++i)
        {
            coef[i]=0;
            for( unsigned int j=0; j<4; ++j)
            {
                coef[i]=coef[i]*time+A[i][j];
            }
        }

        for( unsigned int i=0; i<4; ++i)
        {
            if(ctr[i])
            {
                x+=coef[i]*ctr[i]->getX();
                y+=coef[i]*ctr[i]->getY();
                z+=coef[i]*ctr[i]->getZ();
            }
        }
    }

    return new Point3D(x,y,z);
}

btVector3 Dspline(float time, QVector<Point3D*> ctr)
{
    float coef[4];
    float x = 0.,y = 0.,z = 0.;

    // Pre-Condition
    unsigned sizeVec = ctr.size();

    if((sizeVec == 0) || ( sizeVec != 4))
    {
        for(unsigned int i=0; i<4; ++i)
        {
            coef[i]=0;
            for(unsigned int j=0; j<3; ++j)
            coef[i]= (coef[i]*time+(3-j)) * A[i][j];
        }

        for( unsigned int i=0; i<4; ++i)
        {
            x+=coef[i]*ctr[i]->getX();
            y+=coef[i]*ctr[i]->getY();
            z+=coef[i]*ctr[i]->getZ();
        }
    }
    btVector3 pnt(x,y,z);

    return pnt;
}   

float ComputeAngleZ(btVector3 eix,btVector3 tangent)
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

