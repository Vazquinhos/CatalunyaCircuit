#ifndef INSTANCE_H
#define INSTANCE_H
#include "Utils/util.h"

class Instance
{
public:
    Instance();
    Instance(Point3D * minVertex, Point3D *maxVertex, Point3D *center, GLuint displayListId);
    Point3D*     getMinVertex();
    Point3D*     getMaxVertex();
    Point3D*     getCenter();
    GLuint       getDisplayList();

private:
    Point3D     *_p_minVertex; //Min vertex of the instance
    Point3D     *_p_maxVertex; //Max vertex of the instance
    Point3D     *_p_center; //Center of the instance
    GLuint       _gi_displayListId; //Display list of the instance
};

#endif // INSTANCE_H
