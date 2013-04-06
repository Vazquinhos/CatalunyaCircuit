#ifndef CAMERA_H
#define CAMERA_H

#include "Utils/util.h"

class Camera
{
public:
    Camera();
    ~Camera();

    void setProjection(int w,int h);
    void update(void);
    void move(float ah, float av);
    void translate(float x, float y, float z);

private:
    float R,angleh,anglev;
    float near,far;
    float x, y, z;
};

#endif // CAMERA_H
