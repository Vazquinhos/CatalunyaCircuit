/*
 * Archivo: enviroment.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: Enviroment
 * Descripcion: Clase que representa el Escenario del circuito, compuesto tanto por la calzada
 * como por los aspectos visuales estaticos que pueda haber en escena.
 */

#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include "Objects/model3D.h"

#include <string>
#include <map>
#include "Utils/util.h"
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet
#include "BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h"
#include "Objects/semaphore.h"


class Enviroment
{
public:
    // ================= Constructores/Destructores ======================
    Enviroment(btDiscreteDynamicsWorld *dynamicsWorld);
    ~Enviroment();
    // ============================ Methods ===============================
    void checkVisibility(vector<GLuint> *displayLists);
    Semaphore * getSemaphore();

private:
    // ========================== Data Members ============================
    Model3D *_sky;
    Model3D *_terrain;
    Model3D *_advertisement;
    Model3D *_objects;
    Model3D *_fences;
    Model3D *_pneumatic_fences;
    Model3D *_walls;
    Model3D *_forest;
    Model3D *_buildings1;
    Model3D *_buildings2;
    Model3D *_buildings3;
    Model3D *_buildings4;
    Model3D *_buildings5;
    Model3D *_buildings6;
    Semaphore *_semNormal;


    // ========================== Phisics Bullet Members =================
    //btHeightfieldTerrainShape* _groundShape;
    btCollisionShape* _groundShape;
    btDefaultMotionState* _groundMotionState;
    btRigidBody* _groundRigidBody;

    // ============================ Methods ===============================
};

#endif // ENVIROMENT_H
