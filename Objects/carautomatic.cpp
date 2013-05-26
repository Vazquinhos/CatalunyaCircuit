#include "carautomatic.h"
#include "Objects/bsplinemanager.h"
#include <QVector>
#include "Operators/BSplineInterpolatorOp.h"
#include "Utils/timemanager.h"
#include <math.h>

CarAutomatic::CarAutomatic(QString folderPath, QString splinePath, int updateInterval) : Car(folderPath, new Point3D())
{
    _spline = BSplineManager::getBSplineManager()->getBspline(splinePath);
    setPosition(_spline->getPoint(0));
    _currentPoint = 0;
    _totalTime = 0;
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


    _timerUpdate = new QTimer(this);
    connect(_timerUpdate, SIGNAL(timeout()), this, SLOT(update()));

    out = new QTextStream(file);
}

CarAutomatic::CarAutomatic(QString folderPath,QString splinePath, int updateInterval, btDiscreteDynamicsWorld* dynamicsWorld) : Car(folderPath, new Point3D(), dynamicsWorld)
{
    _spline = BSplineManager::getBSplineManager()->getBspline(splinePath);
    setPosition(_spline->getPoint(0));
    _currentPoint = 0;
    _totalTime = 0;
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


    _timerUpdate = new QTimer(this);
    connect(_timerUpdate, SIGNAL(timeout()), this, SLOT(update()));

    out = new QTextStream(file);
}

CarAutomatic::~CarAutomatic(){

}

void CarAutomatic::startRace()
{
    _timerUpdate->start(100);
}

void CarAutomatic::resetRace()
{
    _timerUpdate->stop();
    _totalTime = 0;
    _currentPoint = 0;
}

void CarAutomatic::update(){
    int numPoints = _spline->getNumPoints();

    float vel = 10.0f;
    _totalTime += ((float) TimeManager::getTimeManager()->getElapsedTime()*vel/1000);

    if(_totalTime - _currentPoint > 1)
        ++_currentPoint;

    QVector<Point3D*> vPoints;

    if(_currentPoint >= numPoints)
        _currentPoint -= numPoints;

    vPoints.append( _spline->getPoint(_currentPoint  ));
    if(_currentPoint + 1 < numPoints)
        vPoints.append( _spline->getPoint(_currentPoint + 1 ));
    else
        vPoints.append( _spline->getPoint(_currentPoint - numPoints + 1 ));

    if(_currentPoint + 2 < numPoints)
        vPoints.append( _spline->getPoint(_currentPoint + 2 ));
    else
        vPoints.append( _spline->getPoint(_currentPoint - numPoints + 2 ));

    if(_currentPoint + 3 < numPoints)
        vPoints.append( _spline->getPoint(_currentPoint + 3 ));
    else
        vPoints.append( _spline->getPoint(_currentPoint - numPoints + 3 ));

    float timeInterpolation = _totalTime;

    while(timeInterpolation > numPoints)
        timeInterpolation -= numPoints;

    Point3D * position = spline(timeInterpolation - _currentPoint, vPoints);

    setPosition(position);

    CameraManager::getCameraManager()->getActiveCamera()->setPosition( new Point3D(position->getX() +4 , position->getY() + 4, position->getZ()) );

    // Rotating the car towards the traject


    float time = _totalTime;
    float time1 = _totalTime+1;

    while(time > numPoints)
        time = time - numPoints;

    while(time1 > numPoints)
        time1 = time1 - numPoints;


    Vector3D splineVector(_spline->getPoint( trunc(time) ), _spline->getPoint( trunc(time1) ));

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

    wheelRotation(_wheelAngle);
    ++_wheelAngle;
    if(_wheelAngle >= 360)
        _wheelAngle = _wheelAngle - 360;

    setAngle(angle, _desfase);
    makeTransform();
}
