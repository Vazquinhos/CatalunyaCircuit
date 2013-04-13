/*
 * Archivo: camerasloader.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "camerascmd.h"
#include "Cameras/cameramanager.h"
#include "Ui/camerawindowqt.h"
#include <QObject>

// ================= Constructores/Destructores ======================

CamerasCmd::CamerasCmd() : QObject()
{

}

CamerasCmd::~CamerasCmd(){}

void
CamerasCmd::updateCamerasSettings( void )
{
    int i = 0;

    // TODO:

    // Pedirle a la ventana  las camaras modificadas y decirle al cameramanager que ha sido modificado
}

void
CamerasCmd::process( void )
{
    _p_camera_qt = new CameraWindowQt();
    _p_camera_qt->LoadWindow( CameraManager::getCameraManager()->getCameras());
    CameraWindowQt::connect(_p_camera_qt, SIGNAL(EditionFinished()), this , SLOT(updateCamerasSettings()));
    _p_camera_qt->show();
}

