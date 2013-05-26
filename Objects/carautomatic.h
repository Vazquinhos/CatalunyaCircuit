#ifndef CARAUTOMATIC_H
#define CARAUTOMATIC_H

#include "Objects/bspline.h"
#include "Objects/car.h"
#include <QFile>
#include <QTextStream>

class CarAutomatic: public Updatable, public Car
{
public:
    CarAutomatic(QString folderPath,QString splinePath, int updateInterval);
    virtual ~CarAutomatic();

    virtual void update();

private:
    BSpline *_spline;
    int _currentPoint;
    btVector3 _lastDirection;

    int axis;
    float _desfase;
    float _totalTime;
    // This float describes the first rotation that is needed
    // to be applied to the car, in order to put the car towards the
    // first point of the BSpline
    float _firstRotation;

    QFile* file;
    QTextStream* out;

};

#endif // CARAUTOMATIC_H
