#include "carviewer.h"
// ====================================================================
// ============================ CONSTRUCTORS ==========================
// ====================================================================

/*-------------------------------------------------------------------
 |  Function CarViewer
 |  Purpose: Creator. Default creator
 *-------------------------------------------------------------------*/
CarViewer::CarViewer()
{
    ObjectManager *manager = ObjectManager::getObjectManager();
    Car *car;

    _cameraManager = CameraManager::getCameraManager();

    _cam = dynamic_cast<FixedCamera*>(_cameraManager->getCamera("CarViewerCamera"));

    _carFolders<< "Ferrari/"<<"Hrt/"<<"India/"<<"Lotus/"<<"Mclaren/"<<"Mercedes/"<<"RedBull/"<<"Renault/"<<"Sauber/"<<"Virgin/"<<"Williams/";
    _numCars = _carFolders.size();
    _carActualIndex = 0;
    _isInCarViewerMode = false;

    float zIncrement = 0.00;
    for(int i = 0; i < _numCars; i++){
        if(i > 4){
            zIncrement += 0.032;
        }
        car = new Car("Cars/" + _carFolders[i], new Point3D(150,-76.85,-200+i*10+zIncrement));
        manager->addCar(car);
    }

}

// ====================================================================
// ============================ GETTER / SETTER =======================
// ====================================================================

/*-------------------------------------------------------------------
 |  Function changeToViewerMode
 |  Purpose: Starts the car viewer and selector tool
 *-------------------------------------------------------------------*/
bool CarViewer::isActive(){
    return _isInCarViewerMode;
}

// ====================================================================
// ============================ METHODS ===============================
// ====================================================================

/*-------------------------------------------------------------------
 |  Function changeToViewerMode
 |  Purpose: Starts the car viewer and selector tool
 *-------------------------------------------------------------------*/
void CarViewer::changeToViewerMode(){
    _cameraManager->setActiveCamera("CarViewerCamera");
    _isInCarViewerMode = true;
}


/*-------------------------------------------------------------------
 |  Function exitViewer
 |  Purpose: Exits the car viewer and selector tool
 *-------------------------------------------------------------------*/
void CarViewer::exitViewer(){
    _isInCarViewerMode = false;
    _cameraManager->setActiveCamera("free");
}

/*-------------------------------------------------------------------
 |  Function shiftNextCar
 |  Purpose: Goes to next car
 *-------------------------------------------------------------------*/
void CarViewer::shiftNextCar(){
    Point3D *point;

    if((_carActualIndex < _numCars-1) && (_cam)){
        _carActualIndex++;
        point = _cam->getPosition();
        point->setCoordinates(point->getX(), point->getY(), point->getZ()- 10);
    }
}

/*-------------------------------------------------------------------
 |  Function shiftPreviousCar
 |  Purpose: Goes to the previous car
 *-------------------------------------------------------------------*/
void CarViewer::shiftPreviousCar(){
    Point3D *point;

    if((_carActualIndex > 0) && (_cam)){
        _carActualIndex--;
        point = _cam->getPosition();
        point->setCoordinates(point->getX(), point->getY(), point->getZ()+ 10);
    }
}


/*-------------------------------------------------------------------
 |  Function selectCar
 |  Purpose: Adds the current selected car
 *-------------------------------------------------------------------*/
void CarViewer::selectCar(){
    ObjectManager *manager = ObjectManager::getObjectManager();
    Car *lastCar = manager->getActiveDriveCar();
    Car *c1 = new Car("Cars/" + _carFolders[_carActualIndex]);
    int cameraMode = Car::FRONTAL_CAMERA;

    manager->setActiveDriveCar(c1);

    if(lastCar){
        cameraMode = lastCar->getCameraMode();
        c1->setCameraMode(cameraMode);
        c1->updateCurrentCameraPos();
    }else{
         c1->setCameraMode(cameraMode);
         c1->viewCurrentCamera();
    }




    _isInCarViewerMode = false;
}
