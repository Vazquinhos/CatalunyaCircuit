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
    CameraAbs(const CameraAbs& cameraAbs);
    virtual ~CameraAbs();

    // ============================ Methods ===============================
    void              resizeProjection( int w, int h );
    void              update( void );
    void              render( void );
    void              setModeProjection( mode_projection mode );
    mode_projection   getModeProjection(void);
    void              setPosition( Point3D * p_position );
    Point3D         * getPosition( void );
    void              setDirection( Vector3D * p_direction );
    Vector3D        * getDirection( void );
    void              setUp( Vector3D * p_up );
    Vector3D        * getUp( void );
    camera_type       getType( void );
    virtual QString   getTypeInQString( void ){}
    QString           getSettingsInfo( void );
    void              setSettingsInfo( QString a_settings );
    void              setName( QString a_name);
    QString           getName( void );
    void              setYawPitch(float yaw, float pitch);
    void              addYawPitch(float yaw, float pitch);
    void              getYawPitch(float &yae, float &pitch);
    void              setZoom(float zoom);
    float             getZoom();


    // =========================== Data Members ===========================
    mode_projection     _mode;
    Point3D           * _p_position;
    Vector3D          * _p_direction;
    Vector3D          * _p_up;
    camera_type         _type;
    QString             _name;
    float               _yaw;
    float               _pitch;
    float               _zoom;

    // ============================ Methods ===============================

private:

};

#endif // CAMERAABS_H
