#ifndef OBJECT3DINSTANCE_H
#define OBJECT3DINSTANCE_H

#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet
#include <Utils/point3D.h>
#include <Objects/model3D.h>

class PhysicsObject3D:  public btMotionState
{
public:
    PhysicsObject3D();
    PhysicsObject3D(Model3D *model, btTransform transform);

    void display();
    void checkVisibility();
    bool isVisible();

    // ============== Inherited Bullet Physics methods ===============================
    virtual void getWorldTransform(btTransform &transform) const;
    virtual void setWorldTransform(const btTransform &transform);

    float _xTranslateRotation;
    float _yTranslateRotation;
    float _zTranslateRotation;

    //float _xAngle;
    //float _yAngle;
    float _zAngle;
private:
    bool _isVisible;
    Model3D *_model;

    // ========================== Bullet Phisics Members ==================
    btTransform _transform;
};

#endif // OBJECT3DINSTANCE_H
