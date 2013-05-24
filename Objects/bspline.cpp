#include "bspline.h"
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QStringList>

BSpline::BSpline(QString filePath)
{
    const aiScene* pScene = _importer.ReadFile(filePath.toAscii().data(), 0); //Loads and optmizes object

    if (!pScene) {
        qDebug() << "Error before loading SPLINE: " << _importer.GetErrorString();
    }

    //ImportBSpline(filePath);
   int numVertex = pScene->mMeshes[0]->mNumVertices;
   for(int i = 0; i < numVertex; ++i){
        _vPoints.push_back(new Point3D(pScene->mMeshes[0]->mVertices[i].x , pScene->mMeshes[0]->mVertices[i].y, pScene->mMeshes[0]->mVertices[i].z));
    }
}

void
BSpline::ImportBSpline( QString a_filename ){
    QFile file( a_filename );
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
     QString line = in.readLine();
     QStringList line_list = line.split(" ");

    if(line_list[0] == QString("v")){
        _vPoints.push_back(new Point3D(line_list[1].toFloat(),line_list[2].toFloat(),line_list[3].toFloat()));
    }

    }
}

void BSpline::render(){
    Point3D *point;
    if (glIsList(_displayList)) { //If we already have a display list, we delete it
        glDeleteLists(_displayList, 1);
    }
    _displayList = glGenLists(1); //Generate new display list identifier
    glNewList(_displayList, GL_COMPILE); //Starting rendering in memory

    glPushMatrix();


    for(int i = 0; i < _vPoints.size(); ++i){
        point = _vPoints[i];
        glutSolidSphere(20, 20, 20);
        glTranslatef(point->getX(), point->getY(), point->getZ());
    }

    glPopMatrix();
    glEndList();
}
void BSpline::display(){
    glCallList(_displayList);
}
