#include "carautomatic.h"
#include "Objects/bsplinemanager.h"
#include <QVector>
#include "Operators/BSplineInterpolatorOp.h"5
#include "Utils/timemanager.h"
#include <math.h>

CarAutomatic::CarAutomatic(QString folderPath, QString splinePath, int updateInterval) : Updatable(updateInterval), Car(folderPath, new Point3D())
{
    _spline = BSplineManager::getBSplineManager()->getBspline(splinePath);
    setPosition(_spline->getPoint(0));
    _currentPoint = 1500;
    _totalTime = 1500;
    _desfase = PI/2;
    // Rotating the car towards the traject
    Vector3D splineVector(_spline->getPoint( 1 ), _spline->getPoint( 2 ));

    btVector3 btsplineVector( splineVector.getX(),splineVector.getY(),splineVector.getZ() );
    _lastDirection =  btVector3(0,1,0);

    btScalar angle = btsplineVector.angle( btVector3(1,0,0) );

    _firstRotation = -angle  + 1.57;

    btTransform transform;
    _chasisObj->getWorldTransform(transform);
    transform.setRotation(btQuaternion(btVector3(0,0,1), _firstRotation ));
    _chasisObj->setWorldTransform(transform);

    axis = 1;

    file = new QFile("out.txt");

    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    out = new QTextStream(file);
}

CarAutomatic::~CarAutomatic(){

}

void CarAutomatic::update(){
    int numPoints = _spline->getNumPoints();

    float vel = 10.0f;
    _totalTime += ((float) TimeManager::getTimeManager()->getElapsedTime()*vel/1000);

    if(_totalTime - _currentPoint > 1)
        ++_currentPoint;

    QVector<Point3D*> vPoints;

    vPoints.append( _spline->getPoint(_currentPoint  ));
    vPoints.append( _spline->getPoint(_currentPoint + 1 ));
    vPoints.append( _spline->getPoint(_currentPoint + 2 ));
    vPoints.append( _spline->getPoint(_currentPoint + 3 ));

    Point3D * position = spline(_totalTime - _currentPoint, vPoints);

    setPosition(position);

    CameraManager::getCameraManager()->getActiveCamera()->setPosition( new Point3D(position->getX() + 8, position->getY() + 8, position->getZ() + 8) );


    // Rotating the car towards the traject

    Vector3D splineVector(_spline->getPoint( trunc(_totalTime) ), _spline->getPoint( trunc(_totalTime + 1) ));

    btVector3 btsplineVector( splineVector.getX(),splineVector.getY(), 0 );


    //comprobar el quadrante del vector director.
    if(btsplineVector.getY() < 0 )
    {
        axis = -1;
        _desfase = 3*PI/2;
    }
    else
    {
        axis = 1;
        _desfase = PI/2;
    }

    btScalar angle = btsplineVector.angle( btVector3(axis,0,0) );

    btTransform transform;
    _chasisObj->getWorldTransform(transform);
    transform.setRotation(btQuaternion(btVector3(0,0,1),  angle + _desfase));
    _chasisObj->setWorldTransform(transform);
}
