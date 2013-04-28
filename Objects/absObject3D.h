/*
 * Archivo: absObject.h
 * Fecha: 23/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *  Clase: AbsObject3D
 * Descripcion: Clase Abstracta que engloba todas las operaciones basicas para cualquier objeto 3D independientemente
 * de su estructura o implementacion
 */

#ifndef ABSOBJECT3D_H_
#define ABSOBJECT3D_H_

#include "Utils/util.h"
#include <string>
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet

using namespace std;

class AbsObject3D{

public:
    // ================= Constructores/Destructores ======================
    AbsObject3D();
    virtual ~AbsObject3D();


    // ============================ Methods ==============================
    void               setTranslation(Point3D * translation);
    Point3D          * getTranslation();
    void               setRotation(Point3D * rotation);
    Point3D          * getRotation();
    void               setScale(Point3D * scale);
    Point3D          * getScale();
    void               setMinVertex(Point3D * minVertex);
    Point3D          * getMinVertex();
    void               setMaxVertex(Point3D * maxVertex);
    Point3D          * getMaxVertex();
    Point3D          * getCenter();
    void               setCenter(Point3D *center);


    void setName(QString name);
    QString getName();
    void setVisibility(bool visibility);
    bool getVisibility();
    void setMovable(bool isMovable);
    bool isMovable();

protected:
    virtual void render(){}

private:
    // ========================== Data Members ===========================
    QString        _name;
    Point3D     * _p_translation;
    Point3D     * _p_rotation;
    Point3D     * _p_scale;
    Point3D     * _p_minVertex;
    Point3D     * _p_maxVertex;
    Point3D     * _p_center;

    bool _isVisible;
    bool _isMovable;
    // ============================ Methods ==============================
};

#endif /* ABSOBJECT3D_H_ */
