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

class AbsObject3D {

public:
    // ================= Constructores/Destructores ======================
    AbsObject3D();
    virtual ~AbsObject3D();


    // ============================ Methods ==============================
    void               display();
    void               render();
    void               setDisplayListId(GLuint displayListId);
    GLuint             getDisplayListId();
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

    void setVisibility(bool visibility);
    bool getVisibility();

protected:
    virtual void renderizeObject() = 0;

private:
    // ========================== Data Members ===========================
    GLuint        _gi_displayListId;
    Point3D     * _p_translation;
    Point3D     * _p_rotation;
    Point3D     * _p_scale;
    Point3D     * _p_minVertex;
    Point3D     * _p_maxVertex;
    Point3D     * _p_center;

    bool _isVisible;

    // ============================ Methods ==============================
};

#endif /* ABSOBJECT3D_H_ */
