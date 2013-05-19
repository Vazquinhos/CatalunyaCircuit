/*
 * Archivo: lightloader.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: LightLoader
 * Descripcion: Clase que permitirá cargar la configuración inicial de las luces desde
 * un archivo externo
 */


#ifndef LIGHTLOADER_H
#define LIGHTLOADER_H

#include "Utils/util.h"

class LightLoader
{
    // ================= Constructores/Destructores ======================
private: LightLoader();
public: ~LightLoader();

public:
    // ============================ Methods ===============================
    static LightLoader * getLightLoader();

private:
    // ========================== Data Members ============================
    static LightLoader * _lightLoader;
    // ============================ Methods ===============================

};

#endif // LIGHTLOADER_H
