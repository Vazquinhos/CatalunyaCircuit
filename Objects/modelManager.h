#ifndef MODELMANAGER_H
#define MODELMANAGER_H

using namespace std;
#include <string>
#include <vector>
#include <QStringList>
#include <QString>
#include <IL/il.h>
#include <assimp/Importer.hpp>      // C++ importer interface

#include "Objects/object3DFile.h"

class ModelManager
{

private:
    ModelManager();
public:
    ~ModelManager();

public:
    static ModelManager	* getModelManager();

    void loadModels(QString folderPath, QStringList modelFilters, QStringList textureFilters);
    Object3DFile* getModel(QString modelName);

private:
    static ModelManager * _p_modelManager;
    map<QString, Object3DFile*> _models;

    map<QString, GLuint> loadTextures(QString folderName, QStringList filter);
};

#endif // MODELMANAGER_H
