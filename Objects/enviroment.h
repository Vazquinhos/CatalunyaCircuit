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
    Enviroment(std::string circuitFolder);
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
    map<string, GLuint> _textureIdMapCircuit;
    std::string _circuitFolder;

    Object3DFile *_terrain3D;
    Object3DFile *_sky3D;

    Object3DFile *_banderas_13D;
    Object3DFile *_banderas_23D;
    Object3DFile *_banderas_33D;
    Object3DFile *_banderas_43D;
    Object3DFile *_banderas_53D;
    Object3DFile *_banderas_63D;
    Object3DFile *_banderas_73D;
    Object3DFile *_banderas_83D;
    Object3DFile *_banderas_93D;
    Object3DFile *_banderas_103D;
    Object3DFile *_banderas_113D;
    Object3DFile *_banderas_123D;
    Object3DFile *_banderas_133D;
    Object3DFile *_banderas_143D;
    Object3DFile *_banderas_153D;
    Object3DFile *_banderas_163D;
    Object3DFile *_banderas_173D;

    Object3DFile *_barreras_13D;
    Object3DFile *_barreras_23D;
    Object3DFile *_barreras_33D;
    Object3DFile *_barreras_43D;
    Object3DFile *_barreras_53D;
    Object3DFile *_barreras_63D;
    Object3DFile *_barreras_73D;
    Object3DFile *_barreras_83D;
    Object3DFile *_barreras_93D;
    Object3DFile *_barreras_103D;
    Object3DFile *_barreras_113D;
    Object3DFile *_barreras_123D;
    Object3DFile *_barreras_133D;
    Object3DFile *_barreras_143D;
    Object3DFile *_barreras_153D;

    Object3DFile *_buildings1_13D;
    Object3DFile *_buildings1_23D;
    Object3DFile *_buildings1_33D;
    Object3DFile *_buildings1_43D;
    Object3DFile *_buildings1_53D;
    Object3DFile *_buildings1_63D;
    Object3DFile *_buildings1_73D;
    Object3DFile *_buildings1_83D;
    Object3DFile *_buildings1_93D;
    Object3DFile *_buildings1_103D;
    Object3DFile *_buildings1_113D;
    Object3DFile *_buildings1_123D;

    Object3DFile *_buildings2_13D;
    Object3DFile *_buildings2_23D;
    Object3DFile *_buildings2_33D;
    Object3DFile *_buildings2_43D;

    Object3DFile *_buildings3_13D;
    Object3DFile *_buildings3_23D;
    Object3DFile *_buildings3_33D;
    Object3DFile *_buildings3_53D;
    Object3DFile *_buildings3_63D;

    Object3DFile *_buildings4_13D;
    Object3DFile *_buildings4_23D;

    Object3DFile *_objects_13D;
    Object3DFile *_objects_23D;
    Object3DFile *_objects_33D;
    Object3DFile *_objects_43D;
    Object3DFile *_objects_53D;
    Object3DFile *_objects_63D;
    Object3DFile *_objects_73D;
    Object3DFile *_objects_83D;
    Object3DFile *_objects_93D;
    Object3DFile *_objects_103D;
    Object3DFile *_objects_113D;
    Object3DFile *_objects_123D;
    Object3DFile *_objects_133D;
    Object3DFile *_objects_143D;
    Object3DFile *_objects_153D;
    Object3DFile *_objects_163D;
    Object3DFile *_objects_173D;
    Object3DFile *_objects_183D;
    Object3DFile *_objects_193D;
    Object3DFile *_objects_203D;

    Object3DFile *_vallas_13D;
    Object3DFile *_vallas_23D;
    Object3DFile *_vallas_33D;
    Object3DFile *_vallas_43D;
    Object3DFile *_vallas_53D;
    Object3DFile *_vallas_63D;
    Object3DFile *_vallas_73D;
    Object3DFile *_vallas_83D;
    Object3DFile *_vallas_93D;
    Object3DFile *_vallas_103D;
    Object3DFile *_vallas_113D;
    Object3DFile *_vallas_123D;
    Object3DFile *_vallas_133D;
    Object3DFile *_vallas_143D;
    Object3DFile *_vallas_153D;
    Object3DFile *_vallas_163D;
    Object3DFile *_vallas_173D;
    Object3DFile *_vallas_183D;
    Object3DFile *_vallas_193D;
    Object3DFile *_vallas_203D;
    Object3DFile *_vallas_213D;
    Object3DFile *_vallas_223D;
    Object3DFile *_vallas_233D;
    Object3DFile *_vallas_243D;
    Object3DFile *_vallas_253D;
    Object3DFile *_vallas_263D;
    Object3DFile *_vallas_273D;
    Object3DFile *_vallas_283D;

    Object3DFile *_vegetacion_13D;
    Object3DFile *_vegetacion_23D;
    Object3DFile *_vegetacion_33D;
    Object3DFile *_vegetacion_43D;
    Object3DFile *_vegetacion_53D;
    Object3DFile *_vegetacion_63D;
    Object3DFile *_vegetacion_73D;
    Object3DFile *_vegetacion_83D;
    Object3DFile *_vegetacion_93D;
    Object3DFile *_vegetacion_103D;
    Object3DFile *_vegetacion_113D;
    Object3DFile *_vegetacion_123D;
    Object3DFile *_vegetacion_133D;
    Object3DFile *_vegetacion_143D;
    Object3DFile *_vegetacion_153D;
    Object3DFile *_vegetacion_163D;
    Object3DFile *_vegetacion_173D;
    Object3DFile *_vegetacion_183D;
    Object3DFile *_vegetacion_193D;
    Object3DFile *_vegetacion_203D;
    Object3DFile *_vegetacion_213D;
    Object3DFile *_vegetacion_223D;
    Object3DFile *_vegetacion_233D;
    Object3DFile *_vegetacion_243D;
    Object3DFile *_vegetacion_253D;

    Object3DFile *_vallasPlastico_13D;
    Object3DFile *_vallasPlastico_23D;
    Object3DFile *_vallasPlastico_33D;
    Object3DFile *_vallasPlastico_43D;
    Object3DFile *_vallasPlastico_53D;
    Object3DFile *_vallasPlastico_63D;
    Object3DFile *_vallasPlastico_73D;
    Object3DFile *_vallasPlastico_83D;
    Object3DFile *_vallasPlastico_93D;
    Object3DFile *_vallasPlastico_103D;
    Object3DFile *_vallasPlastico_113D;
    Object3DFile *_vallasPlastico_123D;
    Object3DFile *_vallasPlastico_133D;
    Object3DFile *_vallasPlastico_143D;
    Object3DFile *_vallasPlastico_153D;
    Object3DFile *_vallasPlastico_163D;
    Object3DFile *_vallasPlastico_173D;
    Object3DFile *_vallasPlastico_183D;
    Object3DFile *_vallasPlastico_193D;
    Object3DFile *_vallasPlastico_203D;
    Object3DFile *_vallasPlastico_213D;
    Object3DFile *_vallasPlastico_223D;
    Object3DFile *_vallasPlastico_233D;
    Object3DFile *_vallasPlastico_243D;
    Object3DFile *_vallasPlastico_253D;
    Object3DFile *_vallasPlastico_263D;
    Object3DFile *_vallasPlastico_273D;
    Object3DFile *_vallasPlastico_283D;
    Object3DFile *_vallasPlastico_293D;
    Object3DFile *_vallasPlastico_303D;
    Object3DFile *_vallasPlastico_313D;
    Object3DFile *_vallasPlastico_323D;
    Object3DFile *_vallasPlastico_333D;
    Object3DFile *_vallasPlastico_343D;
    Object3DFile *_vallasPlastico_353D;
    Object3DFile *_vallasPlastico_363D;
    Object3DFile *_vallasPlastico_373D;
    Object3DFile *_vallasPlastico_383D;
    Object3DFile *_vallasPlastico_393D;
    Object3DFile *_vallasPlastico_403D;



    // ============================ Methods ===============================
};

#endif // ENVIROMENT_H
