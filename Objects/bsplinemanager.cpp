#include <QDir>
#include <QDebug>

#include "bsplinemanager.h"
#include "Utils/fileutils.h"
#include "Objects/modelManager.h"

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

            qDebug() << " BSpline Cargada " << file;

            _vBSplines[file] = spline;


            /*_isCapturingSpline = true;
            _capturingSpline = _vBSplines[file];
            saveCapturingSpline();*/




            qDebug() << "Loading spline: " << file;
        }
    }else{
        qDebug() << "Any bspline loaded";
    }

    _terrainModel = ModelManager::getModelManager()->getModel("Circuit/terrain.3ds");
}

BSplineManager* BSplineManager::getBSplineManager(){

    if(_bSplineManager == NULL){
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

void BSplineManager::startSpin(){
    BSpline* bspline;
    for(std::map<QString, BSpline*>::iterator iter =  _vBSplines.begin(); iter !=  _vBSplines.end(); ++iter)
    {
        bspline = iter->second;
        bspline->startSpin();
    }
}

void BSplineManager::endSpin(){
    BSpline* bspline;
    for(std::map<QString, BSpline*>::iterator iter =  _vBSplines.begin(); iter !=  _vBSplines.end(); ++iter)
    {
        bspline = iter->second;
        bspline->endSpin();
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
        //qDebug() << "Capture of spline " << _capturingSpline->getFilename() << " has been cancelled";
    }
}

void BSplineManager::updateCapturingSpline(){
    if(_isCapturingSpline){
        _capturingSpline->captureCameraPosition();
    }
}

void BSplineManager::saveCapturingSpline(){
    if(_isCapturingSpline){
        correctSpline(_capturingSpline);
        _vBSplines[_capturingSpline->getFilename()] = _capturingSpline;
        _capturingSpline->saveCapture();
        _isCapturingSpline = false;
        ++_lastSavedSpline;
        qDebug() << "Bspline: " << _capturingSpline->getFilename() << " saved successfully";
    }
}


void BSplineManager::correctSpline(BSpline* bspline){
    Point3D *point;

    for(int i = 0; i < bspline->getNumPoints(); ++i){
        point = bspline->getPoint(i);
        point->setZ(_terrainModel->getZofPoint(point));
    }
}
