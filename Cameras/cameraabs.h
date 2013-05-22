/*
 * Archivo: cameraabs.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: CameraAbs
 * Descripcion: Clase base para el conjunto de camaras que componen el proyecto.
 */

#ifndef CAMERAABS_H
#define CAMERAABS_H

#include "Utils/util.h"

class CameraAbs
{
public:
    // ================= Constructores/Destructores ======================
    CameraAbs();
    CameraAbs(QString a_name);
    CameraAbs(const CameraAbs& cameraAbs);
    virtual ~CameraAbs();

    // ============================ Methods ===============================
    void              resizeProjection( int w, int h );
    virtual void      update();
    void              render();
    virtual void      move(float velocity, bool front){(void) velocity; (void) front;}
    void              setModeProjection( mode_projection mode );
    mode_projection   getModeProjection();
    void              setPosition( Point3D * p_position );
    Point3D         * getPosition();
    void              setPointToLook(Point3D *point);
    Point3D         * getPointToLook();
    camera_type       getType();
    virtual QString   getTypeInQString( void ){return QString("");}
    QString           getSettingsInfo();
    void              setSettingsInfo( QString a_settings );
    void              setName( QString a_name);
    QString           getName();
    void              setYawPitch(float yaw, float pitch);
    void              addYawPitch(float yaw, float pitch);
    void              getYawPitch(float &yaw, float &pitch);
    void              setYaw(float yaw);
    void              setPitch(float pitch);
    void              setZoom(float zoom);
    float             getZoom();


protected:
    // =========================== Data Members ===========================
    mode_projection     _mode;
    Point3D           * _p_position;
    camera_type         _type;
    QString             _name;
    float               _yaw;
    float               _pitch;
    float               _zoom;
    Point3D           * _pointToLook;

    // ============================ Methods ===============================

private:

};

#endif // CAMERAABS_H
