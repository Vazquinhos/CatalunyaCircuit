#include "carautomatic.h"
#include "Objects/bsplinemanager.h"

CarAutomatic::CarAutomatic(QString folderPath, QString splinePath, int updateInterval) : Updatable(updateInterval), Car(folderPath, new Point3D())
{
    _spline = BSplineManager::getBSplineManager()->getBspline(splinePath);
    setPosition(_spline->getPoint(0));
    _currentPoint = 0;

    // Rotating the car towards the traject
    Vector3D splineVector(_spline->getPoint( 1 ), _spline->getPoint( 2 ));

    btVector3 btsplineVector( splineVector.getX(),splineVector.getY(),splineVector.getZ() );

    btScalar angle = btsplineVector.angle( btVector3(1,0,0) );

    _firstRotation = -angle  + 1.57;

    btTransform transform;
    _chasisObj->getWorldTransform(transform);
    transform.setRotation(btQuaternion(btVector3(0,0,1), _firstRotation ));
    _chasisObj->setWorldTransform(transform);
}

CarAutomatic::~CarAutomatic(){

}

void CarAutomatic::update(){
    int numPoints = _spline->getNumPoints();
    Point3D *point;

    if(_currentPoint < numPoints){
        point = _spline->getPoint(_currentPoint);
        setPosition(point);
        ++_currentPoint;
    }else{
        _currentPoint = 0;
    }

    // Rotating the car towards the traject
    Vector3D splineVector(_spline->getPoint( _currentPoint ), _spline->getPoint( _currentPoint + 1 ));

    btVector3 btsplineVector( splineVector.getX(),splineVector.getY(),splineVector.getZ() );

    btScalar angle = btsplineVector.angle( btVector3(0,1,0) );

    btTransform transform;
    _chasisObj->getWorldTransform(transform);
    transform.setRotation(btQuaternion(btVector3(0,0,1),  angle + PI ));
    _chasisObj->setWorldTransform(transform);

}
