/*
 * Archivo: CamerasCmd.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "lightscmd.h".h"
#include "Lights/lightmanager.h"
#include "Ui/camerawindowqt.h"
#include <QObject>

// ================= Constructores/Destructores ======================

LightsCmd::LightsCmd() : QObject()
{

}

LightsCmd::~LightsCmd(){}

void
LightsCmd::process(  )
{
    _p_light_qt = new LightWindowQt();
    _p_light_qt->LoadWindow( LightManager::getLightManager()->getLights());
    _p_light_qt->show();
}
