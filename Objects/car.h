/*
 * Archivo: carinstance.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: CarInstance
 * Descripcion: Representa cada una de las instancias de los posibles coches en carrera.
 */

#ifndef CARINSTANCE_H
#define CARINSTANCE_H

#include "Utils/util.h"
#include "Utils/vector3D.h"
#include "Objects/object3DFile.h"
#include "Objects/absModel.h"

class Car : public AbsModels
{
public:
    // ================= Constructores/Destructores ======================
    Car(QString folderPath, Point3D * position, btDiscreteDynamicsWorld* dynamicsWorld);
    Car(const Car& car);
    ~Car();

    // ============================ Inherited Methods ===============================
    void displayModels();
    vector<GLuint> checkVisibility(Point3D *pointCamera, int distance);

private:
    // ========================== Data Members ============================
    Object3DFile *_chasisObj;
    Object3DFile *_wheelObj;
    Object3DFile *_wheelFrontRight;
    Object3DFile *_wheelFrontLeft;
    Object3DFile *_wheelRearRight;
    Object3DFile *_wheelRearLeft;

    // ========================== Bullet Phisics Members ==================
    btRigidBody* _fallRigidBody;
    btCollisionShape* _chassisCollisionShape;

    // ============================ Methods ===============================

};

#endif // CARINSTANCE_H
