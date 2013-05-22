#ifndef CARVIEWER_H
#define CARVIEWER_H

#include "Objects/model3D.h"
#include "Objects/objectManager.h"
#include "Cameras/cameramanager.h"
#include "Cameras/fixedcamera.h"
#include "Utils/point3D.h"
#include <QStringList>

class CarViewer
{
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
private:
    FixedCamera *_cam;
    std::vector<Model3D*> _vCars;
    QStringList _carFolders;
    int _numCars;
    int _carActualIndex;
    bool _isInCarViewerMode;
    CameraManager *_cameraManager;
};

#endif // CARVIEWER_H
