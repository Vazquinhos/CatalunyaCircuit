#ifndef CARVIEWER_H
#define CARVIEWER_H

#include "Objects/model3D.h"
#include "Objects/objectManager.h"
#include "Cameras/cameramanager.h"
#include "Cameras/fixedcamera.h"
#include "Utils/point3D.h"
#include <QStringList>
#include <QTimer>
#include <QObject>

class CarViewer: public QObject
{
    Q_OBJECT
public:
    // ============================ Constructors ==========================
    CarViewer();
    // ============================ Getter / Setter =======================
    bool isActive();
    // ============================ Methods ===============================
    void changeToViewerMode();
    void exitViewer();
    void shiftNextCar();
    void shiftPreviousCar();
    void selectCar();

public slots:
    void shiftCarToNext();
    void shiftCarToPrevious();

private:
    FixedCamera *_cam;
    std::vector<Model3D*> _vCars;
    QStringList _carFolders;
    int _numCars;
    int _carActualIndex;
    bool _isInCarViewerMode;
    CameraManager *_cameraManager;
    QTimer* _timerMovementNext;
    QTimer* _timerMovementPrevious;
    Point3D* _currentViewedCarPosition;
    int counter;
};

#endif // CARVIEWER_H
