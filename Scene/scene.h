/*
 * Archivo: scene.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: Scene
 * Descripcion: Clase que encapsula el pintado de cada uno de los fragmentos, el tamaño de estos,
 */


#ifndef SCENE_H
#define SCENE_H

#include "Objects/objectmanager.h"
#include "Objects/absObject3D.h"
#include "Objects/object3DFile.h"
#include <QDir>
#include <Objects/enviroment.h>

class Scene
{
public:
    // ================= Constructores/Destructores ======================
    Scene();
    Scene(const Scene& scene);
    ~Scene();
    // ============================ Methods ===============================
    void display();

private:
    // ========================== Data Members ============================
    ObjectManager *_objectManager;
    // ============================ Methods ===============================
};

#endif // SCENE_H
