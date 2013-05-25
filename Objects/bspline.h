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
#include "Utils/updatable.h"

class BSpline : public Updatable
{
public:
    BSpline(QString filePath, int updateTime);
    virtual ~BSpline();
    QString getFilename();
    Point3D* getPoint(int pos);
    int getNumPoints();

    void render();
    void display();
    void captureCameraPosition();
    void saveCapture();

    //************** INHERITED ************
    virtual void update();

private:
QString _filename;
GLuint _displayList;
Assimp::Importer _importer;
std::vector<Point3D*> _vPoints;
int _currentAngle;

void ImportBSpline( QString a_filename );

};

#endif // BSPLINE_H
