#ifndef CARAUTOMATIC_H
#define CARAUTOMATIC_H

#include "Objects/bspline.h"
#include "Objects/car.h"
#include <QFile>
#include <QTextStream>
#include <QTimer>

class CarAutomatic: public Car
{
public:
    CarAutomatic(QString folderPath,QString splinePath, int updateInterval);
    CarAutomatic(QString folderPath,QString splinePath, int updateInterval, btDiscreteDynamicsWorld* dynamicsWorld);
    virtual ~CarAutomatic();

    void startRace();
    void resetRace();
private:
    BSpline *_spline;
    int _currentPoint;
    btVector3 _lastDirection;

    int axis;
    float _desfase;
    float _totalTime;
    float _wheelAngle;

    // This float describes the first rotation that is needed
    // to be applied to the car, in order to put the car towards the
    // first point of the BSpline
    float _firstRotation;

    QFile* file;
    QTextStream* out;
    QTimer * _timerUpdate;

    public slots:
        virtual void update();

};

#endif // CARAUTOMATIC_H
