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
#include "Objects/absModels.h"
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet

class Car : AbsModels,  public btMotionState
{
public:
    // ================= Constructores/Destructores ======================
    Car(QString folderPath, Point3D * position, btDiscreteDynamicsWorld* dynamicsWorld);
    Car(const Car& car);
    ~Car();

    // ============================ Methods ===============================
    void              setPosition(Point3D * p_position);
    Point3D         * getPosition();
    void              setDirection(Vector3D * p_direction);
    Vector3D        * getDirection();
    void              setBBMin(Point3D * p_bbMin);
    Point3D         * getBBMin();
    void              setBBMax(Point3D * p_bbMax);
    Point3D         * getBBMax();

    // ============================ Inherited Methods ===============================
    void displayModels();
    vector<GLuint> checkVisibility(Point3D *pointCamera, int distance);

    // ============== Inherited Bullet Physics methods ===============================
    virtual void getWorldTransform(btTransform &worldTrans) const;
    virtual void setWorldTransform(const btTransform &worldTrans);

private:
    // ========================== Data Members ============================
    Object3DFile *_chasisObj;
    Object3DFile *_wheelObj;
    Object3DFile *_wheelFrontRight;
    Object3DFile *_wheelFrontLeft;
    Object3DFile *_wheelRearRight;
    Object3DFile *_wheelRearLeft;

    std::string _folder;

    Point3D         * _p_position;
    Vector3D        * _p_direction;

    // ========================== Bullet Phisics Members ==================
    btTransform _worldTrans;
    btRigidBody* _fallRigidBody;
    btCollisionShape* _chassisCollisionShape;
    // ============================ Methods ===============================

};

#endif // CARINSTANCE_H
