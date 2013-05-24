#ifndef BSPLINEMANAGER_H
#define BSPLINEMANAGER_H

#include "Objects/bspline.h"
#include <vector>

class BSplineManager
{

public:
    static BSplineManager* getBSplineManager();
    BSpline* getBspline(QString fileName);
    BSpline* getCapturingSpline();

    void captureNewSpline();
    void cancelCapturingSpline();
    void updateCapturingSpline();
    void saveCapturingSpline();

    void display();
    void render();

private:
    BSplineManager();
    static BSplineManager *  _bSplineManager;
    BSpline *   _capturingSpline;
    bool _isCapturingSpline;
    int _numSavedSplines;
    int _lastSavedSpline;

    std::map<QString, BSpline*>  _vBSplines;
};

#endif // BSPLINEMANAGER_H
