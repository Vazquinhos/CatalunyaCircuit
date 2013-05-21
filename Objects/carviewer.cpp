#include "carviewer.h"

/*-------------------------------------------------------------------
 |  Function CarViewer
 |  Purpose: Creator. Default creator
 *-------------------------------------------------------------------*/
CarViewer::CarViewer()
{
    QStringList carFolders;
    ObjectManager *manager = ObjectManager::getObjectManager();
    Car *car;

    _cam = dynamic_cast<FixedCamera*>(CameraManager::getCameraManager()->getCamera("CarsCamera"));

    carFolders<< "Ferrari/"<<"Hrt/"<<"India/"<<"Lotus/"<<"Mclaren/"<<"Mercedes/"<<"RedBull/"<<"Renault/"<<"Sauber/"<<"Virgin/"<<"Williams/";
    _numCars = carFolders.size();
    _carActualIndex = 0;

    for(int i = 0; i < _numCars; i++){
        car = new Car("Cars/" + carFolders[i], new Point3D(150,160+i*10,-76.85));
        manager->addCar(car);
    }

}

/*-------------------------------------------------------------------
 |  Function shiftNextCar
 |  Purpose: Goes to next car
 *-------------------------------------------------------------------*/
void CarViewer::shiftNextCar(){
    Point3D *point;

    if((_carActualIndex < _numCars) && (_cam)){
        _carActualIndex++;
        point = _cam->getPosition();
        point->setCoordinates(point->getX(), point->getY()  + 10, point->getZ());
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
        point->setCoordinates(point->getX(), point->getY()  - 10, point->getZ());
    }
}
