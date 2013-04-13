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

class Enviroment : AbsModels
{
public:
    // ================= Constructores/Destructores ======================
    Enviroment(std::string circuitFolder, std::string skyFolder);
    Enviroment(const Enviroment& enviroment);
    ~Enviroment();
    // ============================ Methods ===============================

    // ============================ Inherited Methods ===============================
    virtual void loadModels();
    virtual void loadModelsTextures();
    virtual void renderModels();
    virtual void displayModels();

    void checkVisibility(Point3D *pointCamera, int distance);

private:
    // ========================== Data Members ============================
    std::string _circuitFolder;
    std::string _skyFolder;

    Object3DFile *_circuit3D;
    Object3DFile *_sky3D;
    Object3DFile *_forest13D;
    Object3DFile *_forest23D;
    Object3DFile *_forest33D;
    Object3DFile *_forest43D;

    // ============================ Methods ===============================
};

#endif // ENVIROMENT_H
