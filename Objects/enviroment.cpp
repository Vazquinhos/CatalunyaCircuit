/*
 * Archivo: enviroment.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "enviroment.h"
#include <QDir>

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(std::string circuitFolder)
{
    _circuitFolder = (QDir::currentPath() + circuitFolder.c_str()).toStdString();
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(const Enviroment &enviroment)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::~Enviroment()
{
}

// ============================ Methods ===============================


// ============================ Inherited Methods ===============================
/*-------------------------------------------------------------------
 |  Function loadModels
 |
 |  Purpose: Loads all models without textures
 *-------------------------------------------------------------------*/
void Enviroment::loadModels(){

#pragma omp parallel sections
    {

#pragma omp section
        {
            _textureIdMapCircuit = this->loadTextures(_circuitFolder.c_str(), "*.dds");
            _terrain3D = new Object3DFile(_circuitFolder, "terrain.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _sky3D = new Object3DFile(_circuitFolder, "sky.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_13D = new Object3DFile(_circuitFolder, "banderas_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_23D = new Object3DFile(_circuitFolder, "banderas_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }


#pragma omp section
        {
            _banderas_33D = new Object3DFile(_circuitFolder, "banderas_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_43D = new Object3DFile(_circuitFolder, "banderas_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_53D = new Object3DFile(_circuitFolder, "banderas_5.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_63D = new Object3DFile(_circuitFolder, "banderas_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_73D = new Object3DFile(_circuitFolder, "banderas_7.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_83D = new Object3DFile(_circuitFolder, "banderas_8.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_93D = new Object3DFile(_circuitFolder, "banderas_9.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _banderas_103D = new Object3DFile(_circuitFolder, "banderas_10.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_113D = new Object3DFile(_circuitFolder, "banderas_11.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_123D = new Object3DFile(_circuitFolder, "banderas_12.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_133D = new Object3DFile(_circuitFolder, "banderas_13.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_143D = new Object3DFile(_circuitFolder, "banderas_14.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_153D = new Object3DFile(_circuitFolder, "banderas_15.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_163D = new Object3DFile(_circuitFolder, "banderas_16.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _banderas_173D = new Object3DFile(_circuitFolder, "banderas_17.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }






#pragma omp section
        {
            _barreras_13D = new Object3DFile(_circuitFolder, "barreras_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_23D = new Object3DFile(_circuitFolder, "barreras_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }


#pragma omp section
        {
            _barreras_33D = new Object3DFile(_circuitFolder, "barreras_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_43D = new Object3DFile(_circuitFolder, "barreras_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_53D = new Object3DFile(_circuitFolder, "barreras_5.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_63D = new Object3DFile(_circuitFolder, "barreras_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_73D = new Object3DFile(_circuitFolder, "barreras_7.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_83D = new Object3DFile(_circuitFolder, "barreras_8.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_93D = new Object3DFile(_circuitFolder, "barreras_9.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _barreras_103D = new Object3DFile(_circuitFolder, "barreras_10.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_113D = new Object3DFile(_circuitFolder, "barreras_11.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_123D = new Object3DFile(_circuitFolder, "barreras_12.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_133D = new Object3DFile(_circuitFolder, "barreras_13.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_143D = new Object3DFile(_circuitFolder, "barreras_14.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _barreras_153D = new Object3DFile(_circuitFolder, "barreras_15.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }





#pragma omp section
        {
            _buildings1_13D = new Object3DFile(_circuitFolder, "buildings1_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings1_23D = new Object3DFile(_circuitFolder, "buildings1_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings1_33D = new Object3DFile(_circuitFolder, "buildings1_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings1_43D = new Object3DFile(_circuitFolder, "buildings1_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings1_53D = new Object3DFile(_circuitFolder, "buildings1_5.3ds", aiProcess_Triangulate |  aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings1_63D = new Object3DFile(_circuitFolder, "buildings1_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings1_73D = new Object3DFile(_circuitFolder, "buildings1_7.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings1_83D = new Object3DFile(_circuitFolder, "buildings1_8.3ds", aiProcess_Triangulate |  aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings1_93D = new Object3DFile(_circuitFolder, "buildings1_9.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings1_103D = new Object3DFile(_circuitFolder, "buildings1_10.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings1_113D = new Object3DFile(_circuitFolder, "buildings1_11.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings1_123D = new Object3DFile(_circuitFolder, "buildings1_12.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings2_13D = new Object3DFile(_circuitFolder, "buildings2_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings2_23D = new Object3DFile(_circuitFolder, "buildings2_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings2_33D = new Object3DFile(_circuitFolder, "buildings2_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings2_43D = new Object3DFile(_circuitFolder, "buildings2_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }


#pragma omp section
        {
            _buildings3_13D = new Object3DFile(_circuitFolder, "buildings3_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings3_23D = new Object3DFile(_circuitFolder, "buildings3_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings3_33D = new Object3DFile(_circuitFolder, "buildings3_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings3_53D = new Object3DFile(_circuitFolder, "buildings3_5.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings3_63D = new Object3DFile(_circuitFolder, "buildings3_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _buildings4_13D = new Object3DFile(_circuitFolder, "buildings4_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _buildings4_23D = new Object3DFile(_circuitFolder, "buildings4_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }






#pragma omp section
        {
            _objects_13D = new Object3DFile(_circuitFolder, "objects_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_23D = new Object3DFile(_circuitFolder, "objects_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }


#pragma omp section
        {
            _objects_33D = new Object3DFile(_circuitFolder, "objects_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_43D = new Object3DFile(_circuitFolder, "objects_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_53D = new Object3DFile(_circuitFolder, "objects_5.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_63D = new Object3DFile(_circuitFolder, "objects_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_73D = new Object3DFile(_circuitFolder, "objects_7.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_83D = new Object3DFile(_circuitFolder, "objects_8.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_93D = new Object3DFile(_circuitFolder, "objects_9.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _objects_103D = new Object3DFile(_circuitFolder, "objects_10.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_113D = new Object3DFile(_circuitFolder, "objects_11.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_123D = new Object3DFile(_circuitFolder, "objects_12.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_133D = new Object3DFile(_circuitFolder, "objects_13.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_143D = new Object3DFile(_circuitFolder, "objects_14.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_153D = new Object3DFile(_circuitFolder, "objects_15.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _objects_163D = new Object3DFile(_circuitFolder, "objects_16.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _objects_173D = new Object3DFile(_circuitFolder, "objects_17.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _objects_183D = new Object3DFile(_circuitFolder, "objects_18.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _objects_193D = new Object3DFile(_circuitFolder, "objects_19.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _objects_203D = new Object3DFile(_circuitFolder, "objects_20.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }



#pragma omp section
        {
            _vallas_13D = new Object3DFile(_circuitFolder, "vallas_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_23D = new Object3DFile(_circuitFolder, "vallas_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_33D = new Object3DFile(_circuitFolder, "vallas_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_43D = new Object3DFile(_circuitFolder, "vallas_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_53D = new Object3DFile(_circuitFolder, "vallas_5.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_63D = new Object3DFile(_circuitFolder, "vallas_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_73D = new Object3DFile(_circuitFolder, "vallas_7.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_83D = new Object3DFile(_circuitFolder, "vallas_8.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_93D = new Object3DFile(_circuitFolder, "vallas_9.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_103D = new Object3DFile(_circuitFolder, "vallas_10.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_113D = new Object3DFile(_circuitFolder, "vallas_11.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_123D = new Object3DFile(_circuitFolder, "vallas_12.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_133D = new Object3DFile(_circuitFolder, "vallas_13.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_143D = new Object3DFile(_circuitFolder, "vallas_14.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_153D = new Object3DFile(_circuitFolder, "vallas_15.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_163D = new Object3DFile(_circuitFolder, "vallas_16.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_173D = new Object3DFile(_circuitFolder, "vallas_17.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_183D = new Object3DFile(_circuitFolder, "vallas_18.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_193D = new Object3DFile(_circuitFolder, "vallas_19.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_203D = new Object3DFile(_circuitFolder, "vallas_20.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_213D = new Object3DFile(_circuitFolder, "vallas_21.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_223D = new Object3DFile(_circuitFolder, "vallas_22.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_233D = new Object3DFile(_circuitFolder, "vallas_23.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_243D = new Object3DFile(_circuitFolder, "vallas_24.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_253D = new Object3DFile(_circuitFolder, "vallas_25.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_263D = new Object3DFile(_circuitFolder, "vallas_26.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_273D = new Object3DFile(_circuitFolder, "vallas_27.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallas_283D = new Object3DFile(_circuitFolder, "vallas_28.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }




#pragma omp section
        {
            _vegetacion_13D = new Object3DFile(_circuitFolder, "vegetacion_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_23D = new Object3DFile(_circuitFolder, "vegetacion_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_33D = new Object3DFile(_circuitFolder, "vegetacion_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_43D = new Object3DFile(_circuitFolder, "vegetacion_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_53D = new Object3DFile(_circuitFolder, "vegetacion_5.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_63D = new Object3DFile(_circuitFolder, "vegetacion_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_73D = new Object3DFile(_circuitFolder, "vegetacion_7.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_83D = new Object3DFile(_circuitFolder, "vegetacion_8.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_93D = new Object3DFile(_circuitFolder, "vegetacion_9.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_103D = new Object3DFile(_circuitFolder, "vegetacion_10.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_113D = new Object3DFile(_circuitFolder, "vegetacion_11.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_123D = new Object3DFile(_circuitFolder, "vegetacion_12.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vegetacion_133D = new Object3DFile(_circuitFolder, "vegetacion_13.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_143D = new Object3DFile(_circuitFolder, "vegetacion_14.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_153D = new Object3DFile(_circuitFolder, "vegetacion_15.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_163D = new Object3DFile(_circuitFolder, "vegetacion_16.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_173D = new Object3DFile(_circuitFolder, "vegetacion_17.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_183D = new Object3DFile(_circuitFolder, "vegetacion_18.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_193D = new Object3DFile(_circuitFolder, "vegetacion_19.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_203D = new Object3DFile(_circuitFolder, "vegetacion_20.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_213D = new Object3DFile(_circuitFolder, "vegetacion_21.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_223D = new Object3DFile(_circuitFolder, "vegetacion_22.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_233D = new Object3DFile(_circuitFolder, "vegetacion_23.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_243D = new Object3DFile(_circuitFolder, "vegetacion_24.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vegetacion_253D = new Object3DFile(_circuitFolder, "vegetacion_25.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }



#pragma omp section
        {
            _vallasPlastico_13D = new Object3DFile(_circuitFolder, "vallasPlastico_1.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_23D = new Object3DFile(_circuitFolder, "vallasPlastico_2.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_33D = new Object3DFile(_circuitFolder, "vallasPlastico_3.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_43D = new Object3DFile(_circuitFolder, "vallasPlastico_4.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_53D = new Object3DFile(_circuitFolder, "vallasPlastico_5.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_63D = new Object3DFile(_circuitFolder, "vallasPlastico_6.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_73D = new Object3DFile(_circuitFolder, "vallasPlastico_7.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_83D = new Object3DFile(_circuitFolder, "vallasPlastico_8.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_93D = new Object3DFile(_circuitFolder, "vallasPlastico_9.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_103D = new Object3DFile(_circuitFolder, "vallasPlastico_10.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_113D = new Object3DFile(_circuitFolder, "vallasPlastico_11.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_123D = new Object3DFile(_circuitFolder, "vallasPlastico_12.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_133D = new Object3DFile(_circuitFolder, "vallasPlastico_13.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_143D = new Object3DFile(_circuitFolder, "vallasPlastico_14.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_153D = new Object3DFile(_circuitFolder, "vallasPlastico_15.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_163D = new Object3DFile(_circuitFolder, "vallasPlastico_16.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_173D = new Object3DFile(_circuitFolder, "vallasPlastico_17.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_183D = new Object3DFile(_circuitFolder, "vallasPlastico_18.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_193D = new Object3DFile(_circuitFolder, "vallasPlastico_19.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_203D = new Object3DFile(_circuitFolder, "vallasPlastico_20.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_213D = new Object3DFile(_circuitFolder, "vallasPlastico_21.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_223D = new Object3DFile(_circuitFolder, "vallasPlastico_22.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_233D = new Object3DFile(_circuitFolder, "vallasPlastico_23.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_243D = new Object3DFile(_circuitFolder, "vallasPlastico_24.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_253D = new Object3DFile(_circuitFolder, "vallasPlastico_25.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_263D = new Object3DFile(_circuitFolder, "vallasPlastico_26.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_273D = new Object3DFile(_circuitFolder, "vallasPlastico_27.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_283D = new Object3DFile(_circuitFolder, "vallasPlastico_28.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_293D = new Object3DFile(_circuitFolder, "vallasPlastico_29.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_303D = new Object3DFile(_circuitFolder, "vallasPlastico_30.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

#pragma omp section
        {
            _vallasPlastico_313D = new Object3DFile(_circuitFolder, "vallasPlastico_31.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_323D = new Object3DFile(_circuitFolder, "vallasPlastico_32.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_333D = new Object3DFile(_circuitFolder, "vallasPlastico_33.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_343D = new Object3DFile(_circuitFolder, "vallasPlastico_34.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_353D = new Object3DFile(_circuitFolder, "vallasPlastico_35.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_363D = new Object3DFile(_circuitFolder, "vallasPlastico_36.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_373D = new Object3DFile(_circuitFolder, "vallasPlastico_37.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_383D = new Object3DFile(_circuitFolder, "vallasPlastico_38.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_393D = new Object3DFile(_circuitFolder, "vallasPlastico_39.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }
#pragma omp section
        {
            _vallasPlastico_403D = new Object3DFile(_circuitFolder, "vallasPlastico_40.3ds", aiProcess_Triangulate | aiProcess_ImproveCacheLocality | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph, false); //Load enviroment representation
        }

    }
}
/*-------------------------------------------------------------------
 |  Function loadModelsTextures
 |
 |  Purpose: Loads textures of all models
 *-------------------------------------------------------------------*/
void Enviroment::loadModelsTextures(){
    _terrain3D->loadTextures(_textureIdMapCircuit);
    _sky3D->loadTextures(_textureIdMapCircuit);

    _banderas_13D->loadTextures(_textureIdMapCircuit);
    _banderas_23D->loadTextures(_textureIdMapCircuit);
    _banderas_33D->loadTextures(_textureIdMapCircuit);
    _banderas_43D->loadTextures(_textureIdMapCircuit);
    _banderas_53D->loadTextures(_textureIdMapCircuit);
    _banderas_63D->loadTextures(_textureIdMapCircuit);
    _banderas_73D->loadTextures(_textureIdMapCircuit);
    _banderas_83D->loadTextures(_textureIdMapCircuit);
    _banderas_93D->loadTextures(_textureIdMapCircuit);
    _banderas_103D->loadTextures(_textureIdMapCircuit);
    _banderas_113D->loadTextures(_textureIdMapCircuit);
    _banderas_123D->loadTextures(_textureIdMapCircuit);
    _banderas_133D->loadTextures(_textureIdMapCircuit);
    _banderas_143D->loadTextures(_textureIdMapCircuit);
    _banderas_153D->loadTextures(_textureIdMapCircuit);
    _banderas_163D->loadTextures(_textureIdMapCircuit);
    _banderas_173D->loadTextures(_textureIdMapCircuit);

    _barreras_13D->loadTextures(_textureIdMapCircuit);
    _barreras_23D->loadTextures(_textureIdMapCircuit);
    _barreras_33D->loadTextures(_textureIdMapCircuit);
    _barreras_43D->loadTextures(_textureIdMapCircuit);
    _barreras_53D->loadTextures(_textureIdMapCircuit);
    _barreras_63D->loadTextures(_textureIdMapCircuit);
    _barreras_73D->loadTextures(_textureIdMapCircuit);
    _barreras_83D->loadTextures(_textureIdMapCircuit);
    _barreras_93D->loadTextures(_textureIdMapCircuit);
    _barreras_103D->loadTextures(_textureIdMapCircuit);
    _barreras_113D->loadTextures(_textureIdMapCircuit);
    _barreras_123D->loadTextures(_textureIdMapCircuit);
    _barreras_133D->loadTextures(_textureIdMapCircuit);
    _barreras_143D->loadTextures(_textureIdMapCircuit);
    _barreras_153D->loadTextures(_textureIdMapCircuit);

    _buildings1_13D->loadTextures(_textureIdMapCircuit);
    _buildings1_23D->loadTextures(_textureIdMapCircuit);
    _buildings1_33D->loadTextures(_textureIdMapCircuit);
    _buildings1_43D->loadTextures(_textureIdMapCircuit);
    _buildings1_53D->loadTextures(_textureIdMapCircuit);
    _buildings1_63D->loadTextures(_textureIdMapCircuit);
    _buildings1_73D->loadTextures(_textureIdMapCircuit);
    _buildings1_83D->loadTextures(_textureIdMapCircuit);
    _buildings1_93D->loadTextures(_textureIdMapCircuit);
    _buildings1_103D->loadTextures(_textureIdMapCircuit);
    _buildings1_113D->loadTextures(_textureIdMapCircuit);
    _buildings1_123D->loadTextures(_textureIdMapCircuit);

    _buildings2_13D->loadTextures(_textureIdMapCircuit);
    _buildings2_23D->loadTextures(_textureIdMapCircuit);
    _buildings2_33D->loadTextures(_textureIdMapCircuit);
    _buildings2_43D->loadTextures(_textureIdMapCircuit);

    _buildings3_13D->loadTextures(_textureIdMapCircuit);
    _buildings3_23D->loadTextures(_textureIdMapCircuit);
    _buildings3_33D->loadTextures(_textureIdMapCircuit);
    _buildings3_53D->loadTextures(_textureIdMapCircuit);
    _buildings3_63D->loadTextures(_textureIdMapCircuit);

    _buildings4_13D->loadTextures(_textureIdMapCircuit);
    _buildings4_23D->loadTextures(_textureIdMapCircuit);

    _objects_13D->loadTextures(_textureIdMapCircuit);
    _objects_23D->loadTextures(_textureIdMapCircuit);
    _objects_33D->loadTextures(_textureIdMapCircuit);
    _objects_43D->loadTextures(_textureIdMapCircuit);
    _objects_53D->loadTextures(_textureIdMapCircuit);
    _objects_63D->loadTextures(_textureIdMapCircuit);
    _objects_73D->loadTextures(_textureIdMapCircuit);
    _objects_83D->loadTextures(_textureIdMapCircuit);
    _objects_93D->loadTextures(_textureIdMapCircuit);
    _objects_103D->loadTextures(_textureIdMapCircuit);
    _objects_113D->loadTextures(_textureIdMapCircuit);
    _objects_123D->loadTextures(_textureIdMapCircuit);
    _objects_133D->loadTextures(_textureIdMapCircuit);
    _objects_143D->loadTextures(_textureIdMapCircuit);
    _objects_153D->loadTextures(_textureIdMapCircuit);
    _objects_163D->loadTextures(_textureIdMapCircuit);
    _objects_173D->loadTextures(_textureIdMapCircuit);
    _objects_183D->loadTextures(_textureIdMapCircuit);
    _objects_193D->loadTextures(_textureIdMapCircuit);
    _objects_203D->loadTextures(_textureIdMapCircuit);

    _vallas_13D->loadTextures(_textureIdMapCircuit);
    _vallas_23D->loadTextures(_textureIdMapCircuit);
    _vallas_33D->loadTextures(_textureIdMapCircuit);
    _vallas_43D->loadTextures(_textureIdMapCircuit);
    _vallas_53D->loadTextures(_textureIdMapCircuit);
    _vallas_63D->loadTextures(_textureIdMapCircuit);
    _vallas_73D->loadTextures(_textureIdMapCircuit);
    _vallas_83D->loadTextures(_textureIdMapCircuit);
    _vallas_93D->loadTextures(_textureIdMapCircuit);
    _vallas_103D->loadTextures(_textureIdMapCircuit);
    _vallas_113D->loadTextures(_textureIdMapCircuit);
    _vallas_123D->loadTextures(_textureIdMapCircuit);
    _vallas_133D->loadTextures(_textureIdMapCircuit);
    _vallas_143D->loadTextures(_textureIdMapCircuit);
    _vallas_153D->loadTextures(_textureIdMapCircuit);
    _vallas_163D->loadTextures(_textureIdMapCircuit);
    _vallas_173D->loadTextures(_textureIdMapCircuit);
    _vallas_183D->loadTextures(_textureIdMapCircuit);
    _vallas_193D->loadTextures(_textureIdMapCircuit);
    _vallas_203D->loadTextures(_textureIdMapCircuit);
    _vallas_213D->loadTextures(_textureIdMapCircuit);
    _vallas_223D->loadTextures(_textureIdMapCircuit);
    _vallas_233D->loadTextures(_textureIdMapCircuit);
    _vallas_243D->loadTextures(_textureIdMapCircuit);
    _vallas_253D->loadTextures(_textureIdMapCircuit);
    _vallas_263D->loadTextures(_textureIdMapCircuit);
    _vallas_273D->loadTextures(_textureIdMapCircuit);
    _vallas_283D->loadTextures(_textureIdMapCircuit);

    _vegetacion_13D->loadTextures(_textureIdMapCircuit);
    _vegetacion_23D->loadTextures(_textureIdMapCircuit);
    _vegetacion_33D->loadTextures(_textureIdMapCircuit);
    _vegetacion_43D->loadTextures(_textureIdMapCircuit);
    _vegetacion_53D->loadTextures(_textureIdMapCircuit);
    _vegetacion_63D->loadTextures(_textureIdMapCircuit);
    _vegetacion_73D->loadTextures(_textureIdMapCircuit);
    _vegetacion_83D->loadTextures(_textureIdMapCircuit);
    _vegetacion_93D->loadTextures(_textureIdMapCircuit);
    _vegetacion_103D->loadTextures(_textureIdMapCircuit);
    _vegetacion_113D->loadTextures(_textureIdMapCircuit);
    _vegetacion_123D->loadTextures(_textureIdMapCircuit);
    _vegetacion_133D->loadTextures(_textureIdMapCircuit);
    _vegetacion_143D->loadTextures(_textureIdMapCircuit);
    _vegetacion_153D->loadTextures(_textureIdMapCircuit);
    _vegetacion_163D->loadTextures(_textureIdMapCircuit);
    _vegetacion_173D->loadTextures(_textureIdMapCircuit);
    _vegetacion_183D->loadTextures(_textureIdMapCircuit);
    _vegetacion_193D->loadTextures(_textureIdMapCircuit);
    _vegetacion_203D->loadTextures(_textureIdMapCircuit);
    _vegetacion_213D->loadTextures(_textureIdMapCircuit);
    _vegetacion_223D->loadTextures(_textureIdMapCircuit);
    _vegetacion_233D->loadTextures(_textureIdMapCircuit);
    _vegetacion_243D->loadTextures(_textureIdMapCircuit);
    _vegetacion_253D->loadTextures(_textureIdMapCircuit);

    _vallasPlastico_13D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_23D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_33D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_43D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_53D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_63D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_73D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_83D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_93D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_103D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_113D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_123D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_133D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_143D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_153D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_163D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_173D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_183D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_193D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_203D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_223D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_213D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_233D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_243D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_253D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_263D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_273D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_283D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_293D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_303D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_313D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_323D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_333D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_343D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_353D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_363D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_373D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_383D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_393D->loadTextures(_textureIdMapCircuit);
    _vallasPlastico_403D->loadTextures(_textureIdMapCircuit);


}

/*-------------------------------------------------------------------
 |  Function renderModels
 |
 |  Purpose: Render all models
 *-------------------------------------------------------------------*/
void Enviroment::renderModels(){

    _terrain3D->render();
    _sky3D->render();

    _banderas_13D->render();
    _banderas_23D->render();
    _banderas_33D->render();
    _banderas_43D->render();
    _banderas_53D->render();
    _banderas_63D->render();
    _banderas_73D->render();
    _banderas_83D->render();
    _banderas_93D->render();
    _banderas_103D->render();
    _banderas_113D->render();
    _banderas_123D->render();
    _banderas_133D->render();
    _banderas_143D->render();
    _banderas_153D->render();
    _banderas_163D->render();
    _banderas_173D->render();

    _barreras_13D->render();
    _barreras_23D->render();
    _barreras_33D->render();
    _barreras_43D->render();
    _barreras_53D->render();
    _barreras_63D->render();
    _barreras_73D->render();
    _barreras_83D->render();
    _barreras_93D->render();
    _barreras_103D->render();
    _barreras_113D->render();
    _barreras_123D->render();
    _barreras_133D->render();
    _barreras_143D->render();
    _barreras_153D->render();

    _buildings1_13D->render();
    _buildings1_23D->render();
    _buildings1_33D->render();
    _buildings1_43D->render();
    _buildings1_53D->render();
    _buildings1_63D->render();
    _buildings1_73D->render();
    _buildings1_83D->render();
    _buildings1_93D->render();
    _buildings1_103D->render();
    _buildings1_113D->render();
    _buildings1_123D->render();

    _buildings2_13D->render();
    _buildings2_23D->render();
    _buildings2_33D->render();
    _buildings2_43D->render();

    _buildings3_13D->render();
    _buildings3_23D->render();
    _buildings3_33D->render();
    _buildings3_53D->render();
    _buildings3_63D->render();

    _buildings4_13D->render();
    _buildings4_23D->render();


    _objects_13D->render();
    _objects_23D->render();
    _objects_33D->render();
    _objects_43D->render();
    _objects_53D->render();
    _objects_63D->render();
    _objects_73D->render();
    _objects_83D->render();
    _objects_93D->render();
    _objects_103D->render();
    _objects_113D->render();
    _objects_123D->render();
    _objects_133D->render();
    _objects_143D->render();
    _objects_153D->render();
    _objects_163D->render();
    _objects_173D->render();
    _objects_183D->render();
    _objects_193D->render();
    _objects_203D->render();


    _vallas_13D->render();
    _vallas_23D->render();
    _vallas_33D->render();
    _vallas_43D->render();
    _vallas_53D->render();
    _vallas_63D->render();
    _vallas_73D->render();
    _vallas_83D->render();
    _vallas_93D->render();
    _vallas_103D->render();
    _vallas_113D->render();
    _vallas_123D->render();
    _vallas_133D->render();
    _vallas_143D->render();
    _vallas_153D->render();
    _vallas_163D->render();
    _vallas_173D->render();
    _vallas_183D->render();
    _vallas_193D->render();
    _vallas_203D->render();
    _vallas_213D->render();
    _vallas_223D->render();
    _vallas_233D->render();
    _vallas_243D->render();
    _vallas_253D->render();
    _vallas_263D->render();
    _vallas_273D->render();
    _vallas_283D->render();

    _vegetacion_13D->render();
    _vegetacion_23D->render();
    _vegetacion_33D->render();
    _vegetacion_43D->render();
    _vegetacion_53D->render();
    _vegetacion_63D->render();
    _vegetacion_73D->render();
    _vegetacion_83D->render();
    _vegetacion_93D->render();
    _vegetacion_103D->render();
    _vegetacion_113D->render();
    _vegetacion_123D->render();
    _vegetacion_133D->render();
    _vegetacion_143D->render();
    _vegetacion_153D->render();
    _vegetacion_163D->render();
    _vegetacion_173D->render();
    _vegetacion_183D->render();
    _vegetacion_193D->render();
    _vegetacion_203D->render();
    _vegetacion_213D->render();
    _vegetacion_223D->render();
    _vegetacion_233D->render();
    _vegetacion_243D->render();
    _vegetacion_253D->render();

    _vallasPlastico_13D->render();
    _vallasPlastico_23D->render();
    _vallasPlastico_33D->render();
    _vallasPlastico_43D->render();
    _vallasPlastico_53D->render();
    _vallasPlastico_63D->render();
    _vallasPlastico_73D->render();
    _vallasPlastico_83D->render();
    _vallasPlastico_93D->render();
    _vallasPlastico_103D->render();
    _vallasPlastico_113D->render();
    _vallasPlastico_123D->render();
    _vallasPlastico_133D->render();
    _vallasPlastico_143D->render();
    _vallasPlastico_153D->render();
    _vallasPlastico_163D->render();
    _vallasPlastico_173D->render();
    _vallasPlastico_183D->render();
    _vallasPlastico_193D->render();
    _vallasPlastico_203D->render();
    _vallasPlastico_223D->render();
    _vallasPlastico_213D->render();
    _vallasPlastico_233D->render();
    _vallasPlastico_243D->render();
    _vallasPlastico_253D->render();
    _vallasPlastico_263D->render();
    _vallasPlastico_273D->render();
    _vallasPlastico_283D->render();
    _vallasPlastico_293D->render();
    _vallasPlastico_303D->render();
    _vallasPlastico_313D->render();
    _vallasPlastico_323D->render();
    _vallasPlastico_333D->render();
    _vallasPlastico_343D->render();
    _vallasPlastico_353D->render();
    _vallasPlastico_363D->render();
    _vallasPlastico_373D->render();
    _vallasPlastico_383D->render();
    _vallasPlastico_393D->render();
    _vallasPlastico_403D->render();


}

/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Enviroment::displayModels(){

    _terrain3D->display();
    _sky3D->display();

    _banderas_13D->display();
    _banderas_23D->display();
    _banderas_33D->display();
    _banderas_43D->display();
    _banderas_53D->display();
    _banderas_63D->display();
    _banderas_73D->display();
    _banderas_83D->display();
    _banderas_93D->display();
    _banderas_103D->display();
    _banderas_113D->display();
    _banderas_123D->display();
    _banderas_133D->display();
    _banderas_143D->display();
    _banderas_153D->display();
    _banderas_163D->display();
    _banderas_173D->display();

    _barreras_13D->display();
    _barreras_23D->display();
    _barreras_33D->display();
    _barreras_43D->display();
    _barreras_53D->display();
    _barreras_63D->display();
    _barreras_73D->display();
    _barreras_83D->display();
    _barreras_93D->display();
    _barreras_103D->display();
    _barreras_113D->display();
    _barreras_123D->display();
    _barreras_133D->display();
    _barreras_143D->display();
    _barreras_153D->display();

    _buildings1_13D->display();
    _buildings1_23D->display();
    _buildings1_33D->display();
    _buildings1_43D->display();
    _buildings1_53D->display();
    _buildings1_63D->display();
    _buildings1_73D->display();
    _buildings1_83D->display();
    _buildings1_93D->display();
    _buildings1_103D->display();
    _buildings1_113D->display();
    _buildings1_123D->display();

    _buildings2_13D->display();
    _buildings2_23D->display();
    _buildings2_33D->display();
    _buildings2_43D->display();

    _buildings3_13D->display();
    _buildings3_23D->display();
    _buildings3_33D->display();
    _buildings3_53D->display();
    _buildings3_63D->display();

    _buildings4_13D->display();
    _buildings4_23D->display();

    _objects_13D->display();
    _objects_23D->display();
    _objects_33D->display();
    _objects_43D->display();
    _objects_53D->display();
    _objects_63D->display();
    _objects_73D->display();
    _objects_83D->display();
    _objects_93D->display();
    _objects_103D->display();
    _objects_113D->display();
    _objects_123D->display();
    _objects_133D->display();
    _objects_143D->display();
    _objects_153D->display();
    _objects_163D->display();
    _objects_173D->display();
    _objects_183D->display();
    _objects_193D->display();
    _objects_203D->display();


    _vallas_13D->display();
    _vallas_23D->display();
    _vallas_33D->display();
    _vallas_43D->display();
    _vallas_53D->display();
    _vallas_63D->display();
    _vallas_73D->display();
    _vallas_83D->display();
    _vallas_93D->display();
    _vallas_103D->display();
    _vallas_113D->display();
    _vallas_123D->display();
    _vallas_133D->display();
    _vallas_143D->display();
    _vallas_153D->display();
    _vallas_163D->display();
    _vallas_173D->display();
    _vallas_183D->display();
    _vallas_193D->display();
    _vallas_203D->display();
    _vallas_213D->display();
    _vallas_223D->display();
    _vallas_233D->display();
    _vallas_243D->display();
    _vallas_253D->display();
    _vallas_263D->display();
    _vallas_273D->display();
    _vallas_283D->display();

    _vegetacion_13D->display();
    _vegetacion_23D->display();
    _vegetacion_33D->display();
    _vegetacion_43D->display();
    _vegetacion_53D->display();
    _vegetacion_63D->display();
    _vegetacion_73D->display();
    _vegetacion_83D->display();
    _vegetacion_93D->display();
    _vegetacion_103D->display();
    _vegetacion_113D->display();
    _vegetacion_123D->display();
    _vegetacion_133D->display();
    _vegetacion_143D->display();
    _vegetacion_153D->display();
    _vegetacion_163D->display();
    _vegetacion_173D->display();
    _vegetacion_183D->display();
    _vegetacion_193D->display();
    _vegetacion_203D->display();
    _vegetacion_213D->display();
    _vegetacion_223D->display();
    _vegetacion_233D->display();
    _vegetacion_243D->display();
    _vegetacion_253D->display();

    _vallasPlastico_13D->display();
    _vallasPlastico_23D->display();
    _vallasPlastico_33D->display();
    _vallasPlastico_43D->display();
    _vallasPlastico_53D->display();
    _vallasPlastico_63D->display();
    _vallasPlastico_73D->display();
    _vallasPlastico_83D->display();
    _vallasPlastico_93D->display();
    _vallasPlastico_103D->display();
    _vallasPlastico_113D->display();
    _vallasPlastico_123D->display();
    _vallasPlastico_133D->display();
    _vallasPlastico_143D->display();
    _vallasPlastico_153D->display();
    _vallasPlastico_163D->display();
    _vallasPlastico_173D->display();
    _vallasPlastico_183D->display();
    _vallasPlastico_193D->display();
    _vallasPlastico_203D->display();
    _vallasPlastico_223D->display();
    _vallasPlastico_213D->display();
    _vallasPlastico_233D->display();
    _vallasPlastico_243D->display();
    _vallasPlastico_253D->display();
    _vallasPlastico_263D->display();
    _vallasPlastico_273D->display();
    _vallasPlastico_283D->display();
    _vallasPlastico_293D->display();
    _vallasPlastico_303D->display();
    _vallasPlastico_313D->display();
    _vallasPlastico_323D->display();
    _vallasPlastico_333D->display();
    _vallasPlastico_343D->display();
    _vallasPlastico_353D->display();
    _vallasPlastico_363D->display();
    _vallasPlastico_373D->display();
    _vallasPlastico_383D->display();
    _vallasPlastico_393D->display();
    _vallasPlastico_403D->display();

}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
void Enviroment::checkVisibility(Point3D *pointCamera, int distance){

    _banderas_13D->checkVisibility(pointCamera, distance);
    _banderas_23D->checkVisibility(pointCamera, distance);
    _banderas_33D->checkVisibility(pointCamera, distance);
    _banderas_43D->checkVisibility(pointCamera, distance);
    _banderas_53D->checkVisibility(pointCamera, distance);
    _banderas_63D->checkVisibility(pointCamera, distance);
    _banderas_73D->checkVisibility(pointCamera, distance);
    _banderas_83D->checkVisibility(pointCamera, distance);
    _banderas_93D->checkVisibility(pointCamera, distance);
    _banderas_103D->checkVisibility(pointCamera, distance);
    _banderas_113D->checkVisibility(pointCamera, distance);
    _banderas_123D->checkVisibility(pointCamera, distance);
    _banderas_133D->checkVisibility(pointCamera, distance);
    _banderas_143D->checkVisibility(pointCamera, distance);
    _banderas_153D->checkVisibility(pointCamera, distance);
    _banderas_163D->checkVisibility(pointCamera, distance);
    _banderas_173D->checkVisibility(pointCamera, distance);

    _barreras_13D->checkVisibility(pointCamera, distance);
    _barreras_23D->checkVisibility(pointCamera, distance);
    _barreras_33D->checkVisibility(pointCamera, distance);
    _barreras_43D->checkVisibility(pointCamera, distance);
    _barreras_53D->checkVisibility(pointCamera, distance);
    _barreras_63D->checkVisibility(pointCamera, distance);
    _barreras_73D->checkVisibility(pointCamera, distance);
    _barreras_83D->checkVisibility(pointCamera, distance);
    _barreras_93D->checkVisibility(pointCamera, distance);
    _barreras_103D->checkVisibility(pointCamera, distance);
    _barreras_113D->checkVisibility(pointCamera, distance);
    _barreras_123D->checkVisibility(pointCamera, distance);
    _barreras_133D->checkVisibility(pointCamera, distance);
    _barreras_143D->checkVisibility(pointCamera, distance);
    _barreras_153D->checkVisibility(pointCamera, distance);

    _buildings1_13D->checkVisibility(pointCamera, distance);
    _buildings1_23D->checkVisibility(pointCamera, distance);
    _buildings1_33D->checkVisibility(pointCamera, distance);
    _buildings1_43D->checkVisibility(pointCamera, distance);
    _buildings1_53D->checkVisibility(pointCamera, distance);
    _buildings1_63D->checkVisibility(pointCamera, distance);
    _buildings1_73D->checkVisibility(pointCamera, distance);
    _buildings1_83D->checkVisibility(pointCamera, distance);
    _buildings1_93D->checkVisibility(pointCamera, distance);
    _buildings1_103D->checkVisibility(pointCamera, distance);
    _buildings1_113D->checkVisibility(pointCamera, distance);
    _buildings1_123D->checkVisibility(pointCamera, distance);

    _buildings2_13D->checkVisibility(pointCamera, distance);
    _buildings2_23D->checkVisibility(pointCamera, distance);
    _buildings2_33D->checkVisibility(pointCamera, distance);
    _buildings2_43D->checkVisibility(pointCamera, distance);

    _buildings3_13D->checkVisibility(pointCamera, distance);
    _buildings3_23D->checkVisibility(pointCamera, distance);
    _buildings3_33D->checkVisibility(pointCamera, distance);
    _buildings3_53D->checkVisibility(pointCamera, distance);
    _buildings3_63D->checkVisibility(pointCamera, distance);

    _buildings4_13D->checkVisibility(pointCamera, distance);
    _buildings4_23D->checkVisibility(pointCamera, distance);


    _objects_13D->checkVisibility(pointCamera, distance);
    _objects_23D->checkVisibility(pointCamera, distance);
    _objects_33D->checkVisibility(pointCamera, distance);
    _objects_43D->checkVisibility(pointCamera, distance);
    _objects_53D->checkVisibility(pointCamera, distance);
    _objects_63D->checkVisibility(pointCamera, distance);
    _objects_73D->checkVisibility(pointCamera, distance);
    _objects_83D->checkVisibility(pointCamera, distance);
    _objects_93D->checkVisibility(pointCamera, distance);
    _objects_103D->checkVisibility(pointCamera, distance);
    _objects_113D->checkVisibility(pointCamera, distance);
    _objects_123D->checkVisibility(pointCamera, distance);
    _objects_133D->checkVisibility(pointCamera, distance);
    _objects_143D->checkVisibility(pointCamera, distance);
    _objects_153D->checkVisibility(pointCamera, distance);
    _objects_163D->checkVisibility(pointCamera, distance);
    _objects_173D->checkVisibility(pointCamera, distance);
    _objects_183D->checkVisibility(pointCamera, distance);
    _objects_193D->checkVisibility(pointCamera, distance);
    _objects_203D->checkVisibility(pointCamera, distance);


    _vallas_13D->checkVisibility(pointCamera, distance);
    _vallas_23D->checkVisibility(pointCamera, distance);
    _vallas_33D->checkVisibility(pointCamera, distance);
    _vallas_43D->checkVisibility(pointCamera, distance);
    _vallas_53D->checkVisibility(pointCamera, distance);
    _vallas_63D->checkVisibility(pointCamera, distance);
    _vallas_73D->checkVisibility(pointCamera, distance);
    _vallas_83D->checkVisibility(pointCamera, distance);
    _vallas_93D->checkVisibility(pointCamera, distance);
    _vallas_103D->checkVisibility(pointCamera, distance);
    _vallas_113D->checkVisibility(pointCamera, distance);
    _vallas_123D->checkVisibility(pointCamera, distance);
    _vallas_133D->checkVisibility(pointCamera, distance);
    _vallas_143D->checkVisibility(pointCamera, distance);
    _vallas_153D->checkVisibility(pointCamera, distance);
    _vallas_163D->checkVisibility(pointCamera, distance);
    _vallas_173D->checkVisibility(pointCamera, distance);
    _vallas_183D->checkVisibility(pointCamera, distance);
    _vallas_193D->checkVisibility(pointCamera, distance);
    _vallas_203D->checkVisibility(pointCamera, distance);
    _vallas_213D->checkVisibility(pointCamera, distance);
    _vallas_223D->checkVisibility(pointCamera, distance);
    _vallas_233D->checkVisibility(pointCamera, distance);
    _vallas_243D->checkVisibility(pointCamera, distance);
    _vallas_253D->checkVisibility(pointCamera, distance);
    _vallas_263D->checkVisibility(pointCamera, distance);
    _vallas_273D->checkVisibility(pointCamera, distance);
    _vallas_283D->checkVisibility(pointCamera, distance);

    _vegetacion_13D->checkVisibility(pointCamera, distance);
    _vegetacion_23D->checkVisibility(pointCamera, distance);
    _vegetacion_33D->checkVisibility(pointCamera, distance);
    _vegetacion_43D->checkVisibility(pointCamera, distance);
    _vegetacion_53D->checkVisibility(pointCamera, distance);
    _vegetacion_63D->checkVisibility(pointCamera, distance);
    _vegetacion_73D->checkVisibility(pointCamera, distance);
    _vegetacion_83D->checkVisibility(pointCamera, distance);
    _vegetacion_93D->checkVisibility(pointCamera, distance);
    _vegetacion_103D->checkVisibility(pointCamera, distance);
    _vegetacion_113D->checkVisibility(pointCamera, distance);
    _vegetacion_123D->checkVisibility(pointCamera, distance);
    _vegetacion_133D->checkVisibility(pointCamera, distance);
    _vegetacion_143D->checkVisibility(pointCamera, distance);
    _vegetacion_153D->checkVisibility(pointCamera, distance);
    _vegetacion_163D->checkVisibility(pointCamera, distance);
    _vegetacion_173D->checkVisibility(pointCamera, distance);
    _vegetacion_183D->checkVisibility(pointCamera, distance);
    _vegetacion_193D->checkVisibility(pointCamera, distance);
    _vegetacion_203D->checkVisibility(pointCamera, distance);
    _vegetacion_213D->checkVisibility(pointCamera, distance);
    _vegetacion_223D->checkVisibility(pointCamera, distance);
    _vegetacion_233D->checkVisibility(pointCamera, distance);
    _vegetacion_243D->checkVisibility(pointCamera, distance);
    _vegetacion_253D->checkVisibility(pointCamera, distance);

    _vallasPlastico_13D->checkVisibility(pointCamera, distance);
    _vallasPlastico_23D->checkVisibility(pointCamera, distance);
    _vallasPlastico_33D->checkVisibility(pointCamera, distance);
    _vallasPlastico_43D->checkVisibility(pointCamera, distance);
    _vallasPlastico_53D->checkVisibility(pointCamera, distance);
    _vallasPlastico_63D->checkVisibility(pointCamera, distance);
    _vallasPlastico_73D->checkVisibility(pointCamera, distance);
    _vallasPlastico_83D->checkVisibility(pointCamera, distance);
    _vallasPlastico_93D->checkVisibility(pointCamera, distance);
    _vallasPlastico_103D->checkVisibility(pointCamera, distance);
    _vallasPlastico_113D->checkVisibility(pointCamera, distance);
    _vallasPlastico_123D->checkVisibility(pointCamera, distance);
    _vallasPlastico_133D->checkVisibility(pointCamera, distance);
    _vallasPlastico_143D->checkVisibility(pointCamera, distance);
    _vallasPlastico_153D->checkVisibility(pointCamera, distance);
    _vallasPlastico_163D->checkVisibility(pointCamera, distance);
    _vallasPlastico_173D->checkVisibility(pointCamera, distance);
    _vallasPlastico_183D->checkVisibility(pointCamera, distance);
    _vallasPlastico_193D->checkVisibility(pointCamera, distance);
    _vallasPlastico_203D->checkVisibility(pointCamera, distance);
    _vallasPlastico_223D->checkVisibility(pointCamera, distance);
    _vallasPlastico_213D->checkVisibility(pointCamera, distance);
    _vallasPlastico_233D->checkVisibility(pointCamera, distance);
    _vallasPlastico_243D->checkVisibility(pointCamera, distance);
    _vallasPlastico_253D->checkVisibility(pointCamera, distance);
    _vallasPlastico_263D->checkVisibility(pointCamera, distance);
    _vallasPlastico_273D->checkVisibility(pointCamera, distance);
    _vallasPlastico_283D->checkVisibility(pointCamera, distance);
    _vallasPlastico_293D->checkVisibility(pointCamera, distance);
    _vallasPlastico_303D->checkVisibility(pointCamera, distance);
    _vallasPlastico_313D->checkVisibility(pointCamera, distance);
    _vallasPlastico_323D->checkVisibility(pointCamera, distance);
    _vallasPlastico_333D->checkVisibility(pointCamera, distance);
    _vallasPlastico_343D->checkVisibility(pointCamera, distance);
    _vallasPlastico_353D->checkVisibility(pointCamera, distance);
    _vallasPlastico_363D->checkVisibility(pointCamera, distance);
    _vallasPlastico_373D->checkVisibility(pointCamera, distance);
    _vallasPlastico_383D->checkVisibility(pointCamera, distance);
    _vallasPlastico_393D->checkVisibility(pointCamera, distance);
    _vallasPlastico_403D->checkVisibility(pointCamera, distance);

}


