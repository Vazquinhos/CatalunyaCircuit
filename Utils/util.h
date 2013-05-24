/*
 * Archivo: util.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Descripcion: Añade librerias OpenGL i las clases de Utils.
 */


#ifndef _UTIL_H
#define _UTIL_H

#define PI 3.14159

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else
    #ifdef _WIN32
        #include <windows.h>
    #endif

    #include <GL/glew.h>
    #include <GL/gl.h>
    #include <GL/glu.h>

    #ifdef FREEGLUT
        #include <GL/freeglut.h>
    #else
        #include <GL/glut.h>
    #endif
#endif

#include <math.h>
#include <QDebug>

// Geometrical classes
#include "point2D.h"
#include "point3D.h"
#include "vector3D.h"

// Other classes
#include "StdAfx.h"

// ============================= Typedef ==================================
typedef enum e_CameraType {
    FREE,
    FIXED,
    SPHERICAL
}camera_type;

#ifndef PI
#define PI 3.141592653589
#endif

typedef std::vector<float> sfvector;

// ============================== MACROS ===================================
// MACRO para Testear: Si condicion és cierta devuelve el titulo (texto) + OK,
// si es falsa, devuelve el texto FAIL.
#define COND_LOG(cond, text)           \
    if(cond) qDebug() << text << "OK"; \
    else qDebug() << text << "FAIL";

#endif  /* _UTIL_H */
