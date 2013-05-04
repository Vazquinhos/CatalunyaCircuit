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

class ModelManager : public QObject
{

private:
    ModelManager();
public:
    ~ModelManager();

public:
    static ModelManager	* getModelManager();

    Object3DFile* getModel(QString modelName);

    void setFolderToLoad(QString folderPath, QStringList modelFilters, QStringList textureFilters);
    void loadModels();

private:
    static ModelManager * _p_modelManager;
    QString _folderPath;
    QStringList _modelFilters;
    QStringList _textureFilters;
    map<QString, Object3DFile*> _models;

    map<QString, GLuint> loadTextures(QString folderName, QStringList filter);
    QStringList listFilesInFolder(QString fullFolderPath, QStringList fileFilters);
};

#endif // MODELMANAGER_H
