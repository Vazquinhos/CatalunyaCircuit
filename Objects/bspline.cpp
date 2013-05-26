#include "bspline.h"
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QStringList>
#include "Utils/color.h"

BSpline::BSpline(QString filePath, int updateTime)
{
    _filename = filePath;
    _currentAngle = 0;
    ImportBSpline(filePath);
}

BSpline::~BSpline(){

}

Point3D* BSpline::getPoint(int pos){
    return _vPoints[pos];
}
int BSpline::getNumPoints(){
    return _vPoints.size();
}

void
BSpline::ImportBSpline( QString a_filename ){


    QFile file( a_filename );
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "BSpline " << a_filename << " could not be loaded";
        return;
    }


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
    Color randColor;
    if (glIsList(_displayList)) { //If we already have a display list, we delete it
        glDeleteLists(_displayList, 1);
    }
    _displayList = glGenLists(1); //Generate new display list identifier
    glNewList(_displayList, GL_COMPILE); //Starting rendering in memory



    for(unsigned int i = 0; i < _vPoints.size(); ++i){
        point = _vPoints[i];
        glPushMatrix();
        glPushAttrib(GL_CURRENT_BIT);
        glColor3f(randColor.getRed(),randColor.getGreen(),randColor.getBlue());

        _currentAngle +=1;
        //_currentAngle /= 360;

        glTranslatef(point->getX(), point->getY(), point->getZ());
        glRotatef(_currentAngle, 0,0,1);
        //glutSolidSphere(0.5, 20, 20);
        glutSolidCube(0.2);

        glPopAttrib();
        glPopMatrix();


    }
    glEndList();


}
void BSpline::display(){
    glCallList(_displayList);
}

void BSpline::update(){
    render();
}

void BSpline::captureCameraPosition(){
        Point3D * point = CameraManager::getCameraManager()->getActiveCamera()->getPosition();
        _vPoints.push_back(point);
        qDebug() << "Bspline: " << getFilename() << " captured point: " << point->getX() << " " << point->getY() << point->getZ();
}

void BSpline::saveCapture( ){

    QFile file(_filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    unsigned int size = _vPoints.size();

    for(unsigned int i = 0; i<size; ++i)
    {
        out << "v " << _vPoints[i]->getX() <<" "<< _vPoints[i]->getY() <<" "<<_vPoints[i]->getZ() << "\n";
    }

    file.close();
}

QString BSpline::getFilename(){
    return _filename;
}
