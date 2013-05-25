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
#include "Utils/point2D.h"
#include "Utils/vector3D.h"
#include "Objects/physicsObject3D.h"
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet
#include <bullet/btBulletCollisionCommon.h>
#include "Cameras/cameramanager.h"
#include "Cameras/fixedcamera.h"

class Car
{

public:
    static const int FRONTAL_CAMERA = 1;
    static const int REAR_CAMERA    = 2;
    static const int LEFT_CAMERA    = 3;
    static const int RIGHT_CAMERA   = 4;

    // ================= Constructores/Destructores ======================
    Car(QString folderPath, Point3D * position, btDiscreteDynamicsWorld* dynamicsWorld);
    Car(QString folderPath, Point3D * position);
    Car(QString folderPath);
    Car(const Car& car);
    ~Car();

    Point3D * getPosition();
    void      setPosition(Point3D *point);
    Point3D * getRotation();
    void      setRotation(Point3D *point);
    void      setRotationX(float angle);
    void      setRotationY(float angle);
    void      setRotationZ(float angle);
    void      rotateIncX(float angleInc);
    void      rotateIncY(float angleInc);
    void      rotateIncZ(float angleInc);

    // ================= Getter / Setter ==================================
    int getCameraMode();
    void setCameraMode(int mode);

    // ============================ Methods ===============================
    void turnRight();
    void turnLeft();
    void accelerate();
    void brake();
    void viewCurrentCamera();
    void updateCurrentCameraPos();
    void viewCamera(int mode);

    // ============================ Inherited Methods ===============================
    void displayModels();
    vector<GLuint> checkVisibility();

protected:
    struct OffsetYawPitch{
        Point3D *cameraOffset;
        Point2D *cameraYawPitch;
        OffsetYawPitch(){
            cameraOffset = new Point3D();
            cameraYawPitch = new Point2D();
        }
        OffsetYawPitch(Point3D *offset,  Point2D *yawPitch){
            cameraOffset = offset;
            cameraYawPitch = yawPitch;
        }
    };
    // ========================== Data Members ============================
    PhysicsObject3D *_chasisObj;
    PhysicsObject3D *_wheelObj;
    PhysicsObject3D *_wheelFrontRight;
    PhysicsObject3D *_wheelFrontLeft;
    PhysicsObject3D *_wheelRearRight;
    PhysicsObject3D *_wheelRearLeft;

    std::map<int, OffsetYawPitch> _cameraOffsets;

    int _cameraMode;
    // ========================== Bullet Phisics Members ==================
    btRigidBody* _fallRigidBody;
    btCollisionShape* _chassisCollisionShape;
    Vector3D *_orientation;

    // ============================ Methods ===============================
    void setModelsWithPos(QString folderPath, Point3D *position);

    void viewCameraOffeset(OffsetYawPitch offset);
};

#endif // CARMeshInstance_H
