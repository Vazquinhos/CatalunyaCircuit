/*
 * Archivo: lightmanager.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: LightManager
 * Descripcion: Clase Singelton que nos permitira gestionar las luces del proyecto.
 */


#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include <QString>
#include <map>

#include "light.h"

class LightManager
{
    // ================= Constructores/Destructores ======================
private: LightManager();
public: ~LightManager();

public:
    // ============================ Methods ===============================
    static LightManager		* getLightManager();
    Light			        * getLight(QString light_name);
    void			          setLight(QString light_name, Light *light);
    QString                   getCCSCameraInfoToExport();
private:
    // ========================== Data Members ============================
    static LightManager           * _lightManager;
    std::map<QString, Light*>     _lights;

    // ============================ Methods ===============================

};

#endif // LIGHTMANAGER_H
