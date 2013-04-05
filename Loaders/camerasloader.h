/*
 * Archivo: camerasloader.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: CamerasLoader
 * Descripcion: Clase que permitirà cargar de un archivo externo la inicialización de las camaras.
 */


#ifndef CAMERASLOADER_H
#define CAMERASLOADER_H

#include "Utils/util.h"

class CamerasLoader
{
    // ================= Constructores/Destructores ======================
private: CamerasLoader();
public: ~CamerasLoader();

public:
    // ============================ Methods ===============================
    static CamerasLoader * getCamerasLoader();

private:
    // ========================== Data Members ============================
    static CamerasLoader * _camerasLoader;

    // ============================ Methods ===============================
};

#endif // CAMERASLOADER_H
