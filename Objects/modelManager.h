#ifndef MODELMANAGER_H
#define MODELMANAGER_H

using namespace std;
#include <string>
#include <vector>
#include <QStringList>
#include <QString>
#include <IL/il.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <QMutex>

#include "Objects/model3D.h"
#include "Objects/physicsObject3D.h"

class ModelManager : public QObject
{
    Q_OBJECT
private:
    ModelManager();
    ~ModelManager();

public:
    static ModelManager	* getModelManager();

    Model3D *getModel(QString modelName);
    void render();
    PhysicsObject3D * getPyisicsObject(QString modelName, btTransform transform);

    void setFolderToLoad(QString folderPath, QStringList modelFilters, QStringList textureFilters);
public slots:
    void loadModels();

 signals:
    void finish( void );
    void error(QString err);
    void NewModel(QString model, int val);
    void NModels( int );

private:
    static ModelManager * _p_modelManager;
    QString _folderPath;
    QStringList _modelFilters;
    QStringList _textureFilters;
    map<QString, Model3D*> _models;
    QMutex* _p_mutex;

    map<QString, GLuint> loadTextures(QString folderName, QStringList filter);
    QStringList listFilesInFolder(QString fullFolderPath, QStringList fileFilters);
};

#endif // MODELMANAGER_H
