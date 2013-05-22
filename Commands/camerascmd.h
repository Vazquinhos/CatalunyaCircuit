/*
 * Archivo: camerascmd.h
 * Fecha: 15/04/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: CamerasCmd
 * Descripcion: Clase
 */
#ifndef CAMERASCMD_H
#define CAMERASCMD_H

#include "Utils/util.h"
#include "Ui/camerawindowqt.h"
#include <QObject>

class CamerasCmd : public QObject
{
    Q_OBJECT

public:
    // ================= Constructores/Destructores ======================
    CamerasCmd();
    ~CamerasCmd();
    void process();
private:
    // ========================== Data Members ============================
    CameraWindowQt* _p_camera_qt;

    // ============================ Methods ===============================
private slots:
    void updateCamerasSettings();

};

#endif // CAMERASCMD_H
