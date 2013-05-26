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
    virtual void      update() = 0;
    virtual void      render();
    virtual void      move(float velocity, bool front){(void) velocity; (void) front;}
    void              setPosition( Point3D * p_position );
    Point3D         * getPosition();
    camera_type       getType();
    virtual QString   getTypeInQString(){return QString("");}
    QString           getSettingsInfo();
    void              setSettingsInfo( QString a_settings );
    void              setName( QString a_name);
    QString           getName();
    void              setYawPitch(float yaw, float pitch);
    void              addYawPitch(float yaw, float pitch);
    void              getYawPitch(float &yaw, float &pitch);
    void              setYaw(float yaw);
    void              setPitch(float pitch);
    float             getYaw(float yaw);
    float             getPitch(float pitch);
    void              setZoom(float zoom);
    float             getZoom();
    virtual Vector3D* getDirectionVector();
    void              setDirectionVector( Vector3D* );
    void              setType( camera_type a_type );


protected:
    // =========================== Data Members ===========================
    Point3D           * _p_position;
    camera_type         _type;
    QString             _name;
    float               _yaw;
    float               _pitch;
    float               _zoom;
    Vector3D*           _dirVec;

    // ============================ Methods ===============================

private:

};

#endif // CAMERAABS_H
