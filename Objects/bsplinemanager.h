#ifndef BSPLINEMANAGER_H
#define BSPLINEMANAGER_H

#include "Objects/bspline.h"
#include <vector>

class BSplineManager
{

public:
    static BSplineManager* getBSplineManager();
    BSpline* getBspline(int i);

    void display();
    void render();

private:
    BSplineManager();
    static BSplineManager *  _bSplineManager;
    BSpline *   bSpline;

    std::vector<BSpline*>  _vBSplines;
};

#endif // BSPLINEMANAGER_H
