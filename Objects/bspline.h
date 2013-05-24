#ifndef BSPLINE_H
#define BSPLINE_H


#include <QString>
#include<vector>
#include <Utils/util.h>

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "Utils/point3D.h"

#include "Cameras/cameramanager.h"
class BSpline
{
public:
    BSpline(QString filePath);
    QString getFilename();

    void render();
    void display();
    void captureCameraPosition();
    void saveCapture();

private:
QString _filename;
GLuint _displayList;
Assimp::Importer _importer;
std::vector<Point3D*> _vPoints;
void ImportBSpline( QString a_filename );

};

#endif // BSPLINE_H
