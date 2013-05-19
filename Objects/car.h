/*
 * Archivo: carmeshInstance.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: CarMeshInstance
 * Descripcion: Representa cada una de las instancias de los posibles coches en carrera.
 */

#ifndef CARMeshInstance_H
#define CARMeshInstance_H

#include "Utils/util.h"
#include "Utils/vector3D.h"
#include "Objects/physicsObject3D.h"
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet

class Car
{
public:
    // ================= Constructores/Destructores ======================
    Car(QString folderPath, Point3D * position, btDiscreteDynamicsWorld* dynamicsWorld);
    Car(const Car& car);
    ~Car();

    Point3D * getPosition();
    // ============================ Inherited Methods ===============================
    void displayModels();
    vector<GLuint> checkVisibility();

private:
    // ========================== Data Members ============================
    PhysicsObject3D *_chasisObj;
    PhysicsObject3D *_wheelObj;
    PhysicsObject3D *_wheelFrontRight;
    PhysicsObject3D *_wheelFrontLeft;
    PhysicsObject3D *_wheelRearRight;
    PhysicsObject3D *_wheelRearLeft;

    // ========================== Bullet Phisics Members ==================
    btRigidBody* _fallRigidBody;
    btCollisionShape* _chassisCollisionShape;

    // ============================ Methods ===============================

};

#endif // CARMeshInstance_H
