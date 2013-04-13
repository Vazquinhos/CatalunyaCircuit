/*
 * Archivo: absObject.cpp
 * Fecha: 23/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *  Clase: AbsObject3D
 * Descripcion: Clase Abstracta que define las operaciones basicas para cualquier objeto que contenga modelos
 */

#include "absModels.h"
#include "Utils/util.h"

AbsModels::AbsModels()
{
}


bool AbsModels::shouldBeHidden(Point3D *pointModel, Point3D *pointCamera, int distance){
    float d = pointModel->getDistance(pointCamera);
    qDebug() << "DISTANCIA" << d << " TOTAL " << distance;
    return d > distance;
}
