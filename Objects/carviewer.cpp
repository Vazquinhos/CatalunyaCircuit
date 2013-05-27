#include "carviewer.h"
#include "Lights/lightmanager.h"
#include "Lights/swivellight.h"
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

    _cam = dynamic_cast<FreeCamera*>(_cameraManager->getCamera("CarViewerCamera"));

    _carFolders<< "Ferrari/"<<"Hrt/"<<"India/"<<"Lotus/"<<"Mclaren/"<<"Mercedes/"<<"RedBull/"<<"Renault/"<<"Sauber/"<<"Virgin/"<<"Williams/";
    _numCars = _carFolders.size();
    _carActualIndex = 0;
    _isInCarViewerMode = false;

    float zIncrement = 0.00;
    for(int i = 0; i < _numCars; i++){
        if(i > 4){
            zIncrement += 0.032;
        }
        car = new Car("Cars/" + _carFolders[i], new Point3D(150,140+i*10,-76.85+zIncrement));
        manager->addCar(car);
    }

    // Setting up the position of the camera at the positon of the viewer
    _currentViewedCarPosition = new Point3D(152.742,137.498,-74.439);
    counter = 0;
    _timerMovementNext = new QTimer(this);
    connect(_timerMovementNext, SIGNAL(timeout()), this, SLOT( shiftCarToNext() ));
    _timerMovementPrevious = new QTimer(this);
    connect(_timerMovementPrevious, SIGNAL(timeout()), this, SLOT( shiftCarToPrevious() ));
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
    LightManager * lightManager = LightManager::getLightManager();
    _cameraManager->setActiveCamera("CarViewerCamera");
    lightManager->setActiveLight("swivelLight0");
    ((SwivelLight*)lightManager->getActiveLight())->startAnimation();
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
    _timerMovementNext->start(10);
}

/*-------------------------------------------------------------------
 |  Function shiftPreviousCar
 |  Purpose: Goes to the previous car
 *-------------------------------------------------------------------*/
void CarViewer::shiftPreviousCar(){
    _timerMovementPrevious->start(10);
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

void CarViewer::shiftCarToPrevious()
{
    Point3D *point = CameraManager::getCameraManager()->getActiveCamera()->getPosition();

    if(( counter < 10) && (_carActualIndex > 0)){
        point->setCoordinates(point->getX(), point->getY()  - 1, point->getZ());
        counter++;
    } else  if( _carActualIndex == 0 ){
        _timerMovementPrevious->stop();
        counter = 0;
    } else {
        _currentViewedCarPosition = point;
        _timerMovementPrevious->stop();
        _carActualIndex--;
        counter = 0;
    }
}

void CarViewer::shiftCarToNext()
{
    Point3D *point = CameraManager::getCameraManager()->getActiveCamera()->getPosition();

    if(( counter < 10) && (_carActualIndex < _numCars)){
        point->setCoordinates(point->getX(), point->getY()  + 1, point->getZ());
        counter++;
    } else  if( _carActualIndex == _numCars ){
        _timerMovementNext->stop();
        counter = 0;
    } else {
        _currentViewedCarPosition = point;
        _timerMovementNext->stop();
        _carActualIndex++;
        counter = 0;
    }
}


