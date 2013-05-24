#include <QDir>

#include "bsplinemanager.h"

BSplineManager * BSplineManager::_bSplineManager = NULL;

BSplineManager::BSplineManager()
{
    BSpline *spline;
    spline = new BSpline(QDir::currentPath() + "/Media/Models/Circuit/bspline.obj");
    _vBSplines.push_back(spline);

    render();
}

BSplineManager* BSplineManager::getBSplineManager(){

    if(!_bSplineManager){
        _bSplineManager = new BSplineManager();
    }
    return _bSplineManager;
}



BSpline* BSplineManager::getBspline(int i){
    return _vBSplines[i];
}

void BSplineManager::display(){
    for(int i=0; i < _vBSplines.size(); ++i){
        _vBSplines[i]->display();
    }
}

void BSplineManager::render(){
    for(int i=0; i < _vBSplines.size(); ++i){
        _vBSplines[i]->render();
    }
}
