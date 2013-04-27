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

#include "Objects/object3DFile.h"
#include "Objects/absModels.h"

#include <string>
#include <map>
#include "Utils/util.h"


class Enviroment : AbsModels
{
public:
    // ================= Constructores/Destructores ======================
    Enviroment();
    Enviroment(const Enviroment& enviroment);
    ~Enviroment();
    // ============================ Methods ===============================

    // ============================ Inherited Methods ===============================
    virtual void displayModels();
    vector<GLuint> checkVisibility(Point3D *pointCamera, int distance);

private:
    // ========================== Data Members ============================
    Object3DFile *_sky;
    Object3DFile *_terrain;
    Object3DFile *_advertisement;
    Object3DFile *_flags;
    Object3DFile *_objects;
    Object3DFile *_fences;
    Object3DFile *_pneumatic_fences;
    Object3DFile *_walls;
    Object3DFile *_forest;
    Object3DFile *_buildings1;
    Object3DFile *_buildings2;
    Object3DFile *_buildings3;
    Object3DFile *_buildings4;
    Object3DFile *_buildings5;
    Object3DFile *_buildings6;
    // ============================ Methods ===============================
};

#endif // ENVIROMENT_H
