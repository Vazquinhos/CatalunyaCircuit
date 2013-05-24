#ifndef BSPLINE_H
#define BSPLINE_H


#include <QString>
#include<vector>
#include <Utils/util.h>

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "Utils/point3D.h"
class BSpline
{
public:
    BSpline(QString filePath);
    void render();
    void display();

private:
    GLuint _displayList;
    Assimp::Importer _importer;
    std::vector<Point3D*> _vPoints;
    void ImportBSpline( QString a_filename );
};

#endif // BSPLINE_H
