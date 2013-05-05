#ifndef ABSMODELS_H
#define ABSMODELS_H

#include "Utils/point3D.h"
#include <QString>
#include <IL/il.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <string>
#include <map>
#include "Utils/util.h"
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet
#include <Objects/instance.h>
#include <Objects/object3DFile.h>

using namespace std;

class AbsModels:  public btMotionState
{
private:
    bool _isVisible;

protected:
    // ========================== Bullet Phisics Members ==================
    btTransform _worldTrans;

    bool checkIsVisible(Point3D *pointCamera, int distance, btTransform transform);

public:
    AbsModels();

    Point3D *getPosition();
    virtual void displayModels(){}
    virtual vector<GLuint> checkVisibility(Point3D *pointCamera, int distance){vector<GLuint> list; (void)pointCamera; (void)distance; return list;}

    // ============== Inherited Bullet Physics methods ===============================
    virtual void getWorldTransform(btTransform &worldTrans) const;
    virtual void setWorldTransform(const btTransform &worldTrans);

    bool isVisible();
};

#endif // ABSMODELS_H

