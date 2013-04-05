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

class Enviroment
{
public:
    // ================= Constructores/Destructores ======================
    Enviroment();
    Enviroment(const Enviroment& enviroment);
    ~Enviroment();
    // ============================ Methods ===============================
    void render();
    Object3DFile* getRepresentation();
    void setRepresentation(Object3DFile *object);
private:
    // ========================== Data Members ============================
    Object3DFile *_object3D;
    // ============================ Methods ===============================
};

#endif // ENVIROMENT_H
