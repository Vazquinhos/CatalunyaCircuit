/*
 * Archivo: objectmanager.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: ObjectManager
 * Descripcion: Clase Singelton que nos permite gestionar los diferentes coches en carrera i el escenario.
 */


#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>

#include "car.h"
#include "enviroment.h"
#include "Utils/util.h"

class ObjectManager
{
    // ================= Constructores/Destructores ======================
private: ObjectManager();
public: ~ObjectManager();

public:
    // ============================ Methods ===============================
    static ObjectManager	* getObjectManager();
    Car		                * getCar(int index);
    void			          addCar(Car * car);
    void			          rmvCar(int i);
    void			          setEnviroment(Enviroment * enviroment);
    Enviroment              * getEnviroment();

    void                      displayAll();
    void checkVisibility(Point3D *pointCamera, int distance);

private:
    // ========================== Data Members ============================
    static ObjectManager       * _p_objectManager;
    std::vector<Car*>            _v_cars;
    Enviroment                 * _p_enviroment;
    vector<GLuint>             _displayLists;
    // ============================ Methods ===============================
};

#endif // OBJECTMANAGER_H
