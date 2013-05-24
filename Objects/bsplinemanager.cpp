#include <QDir>
#include <QDebug>

#include "bsplinemanager.h"
#include "Utils/fileutils.h"

BSplineManager * BSplineManager::_bSplineManager = NULL;

BSplineManager::BSplineManager()
{
    BSpline *spline;
    QStringList fileNames = FileUtils::listFilesInFolder(QDir::currentPath() + "/Media/BSplines/Correct/");
    QStringList fileNamesCaptured = FileUtils::listFilesInFolder(QDir::currentPath() + "/Media/BSplines/Captured/");
    QString file;

    _isCapturingSpline = false;
    _numSavedSplines = fileNames.size();
    _lastSavedSpline = fileNamesCaptured.size() + 1;

    if(_numSavedSplines > 0){
        for(int i = 0; i < _numSavedSplines; ++i){
            file = fileNames[i];
            spline = new BSpline(file);
            _vBSplines[file] = spline;
            qDebug() << "Loading spline: " << file;
        }
    }else{
        qDebug() << "Any bspline loaded";
    }
    render();
}

BSplineManager* BSplineManager::getBSplineManager(){

    if(!_bSplineManager){
        _bSplineManager = new BSplineManager();
    }
    return _bSplineManager;
}

BSpline* BSplineManager::getBspline(QString fileName){
    return _vBSplines[fileName];
}

BSpline* BSplineManager::getCapturingSpline(){
    return _capturingSpline;
}

void BSplineManager::display(){
    BSpline* bspline;
    for(std::map<QString, BSpline*>::iterator iter =  _vBSplines.begin(); iter !=  _vBSplines.end(); ++iter)
    {
        bspline = iter->second;
        bspline->display();
    }
}

void BSplineManager::render(){
    BSpline* bspline;
    for(std::map<QString, BSpline*>::iterator iter =  _vBSplines.begin(); iter !=  _vBSplines.end(); ++iter)
    {
        bspline = iter->second;
        bspline->render();
    }
}

void BSplineManager::captureNewSpline(){
    cancelCapturingSpline();
    _isCapturingSpline = true;
    QString filename = QDir::currentPath() + "/Media/BSplines/Captured/capturedSpline" + QString::number(_lastSavedSpline) + ".obj";
    _capturingSpline = new BSpline(filename);
    qDebug() << "Capture of spline " << _capturingSpline->getFilename() << " has been started";
}

void BSplineManager::cancelCapturingSpline(){
    if(_capturingSpline){
        _isCapturingSpline = false;
        qDebug() << "Capture of spline " << _capturingSpline->getFilename() << " has been cancelled";
    }
}

void BSplineManager::updateCapturingSpline(){
    if(_isCapturingSpline){
        _capturingSpline->captureCameraPosition();
    }
}

void BSplineManager::saveCapturingSpline(){
    if(_isCapturingSpline){
        _vBSplines[_capturingSpline->getFilename()] = _capturingSpline;
        _capturingSpline->saveCapture();
        _capturingSpline->render();
        _isCapturingSpline = false;
        ++_lastSavedSpline;
        qDebug() << "Bspline: " << _capturingSpline->getFilename() << " saved successfully";
    }
}
