#include "Objects/physicsObject3D.h"


PhysicsObject3D::PhysicsObject3D()
{
}

PhysicsObject3D::PhysicsObject3D(Model3D *model, btTransform transform)
{
    _model = model;
    _transform = transform;

    _xTranslateRotation = -1;
    _yTranslateRotation = -0.5;
    _zTranslateRotation = 0;
    //_xAngle = 0;
    //_yAngle = 0;
    _zAngle = 45;
}

/*-------------------------------------------------------------------
|  Function display
|  Purpose: Displays the object with the current transformation
*-------------------------------------------------------------------*/
void PhysicsObject3D::display(){
    btScalar transformation[16];


    glPushMatrix();

    _transform.getOpenGLMatrix(transformation);

    glMultMatrixd(transformation);



    _model->display();
    glPopMatrix();
}

/*-------------------------------------------------------------------
|  Function isVisible
|  Purpose: Checks de visibility of the entire object, updates and returns it
|  Returns: The visibility of the entire object
*-------------------------------------------------------------------*/
bool PhysicsObject3D::isVisible(){
    return this->_isVisible;
}

/*-------------------------------------------------------------------
|  Function checkVisibility
|  Purpose: Checks de visibility of the entire object, updates and returns it
|  Returns: The visibility of the entire object
*-------------------------------------------------------------------*/
void PhysicsObject3D::checkVisibility(){
    CameraAbs* p_camera = CameraManager::getCameraManager()->getActiveCamera();
    Vector3D* vCamera = p_camera->getDirectionVector();
    Point3D*  posCamera = p_camera->getPosition();

    Vector3D* vObject;
    Point3D *pObject;

    pObject = _model->getCenter();
    vObject = pObject->resta(posCamera);

    //float direction = (*vCamera)^(*vObject);
    //if(direction >= 0){
    //if(vObject->module() < 400){
        _isVisible = true;
    //}else{
      //  _isVisible = false;
    //}

}

// ============== Inherited Bullet Physics methods ===============================
/*-------------------------------------------------------------------
 |  Function getWorldTransform
 |
 |  Purpose: Gets the model transformation that must be applied to the object
 |  Parameters: btTransform &worldTrans: Transformation of the model generated by the motion state
 *-------------------------------------------------------------------*/
void PhysicsObject3D::getWorldTransform(btTransform &transform) const{
    transform = _transform;
}

/*-------------------------------------------------------------------
 |  Function setWorldTransform
 |
 |  Purpose: Sets the model transformation that must be applied to the object. This function is AUTOMATICALLY called
 |           when a movement of the object is done
 |  Parameters: btTransform &worldTrans: Transformation of the model generated by the motion state
 *-------------------------------------------------------------------*/
void PhysicsObject3D::setWorldTransform(const btTransform &transform){
    _transform = transform;
}
