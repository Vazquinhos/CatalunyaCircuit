#ifndef ABSMODELS_H
#define ABSMODELS_H

#include "Utils/point3D.h"

class AbsModels
{
public:
    AbsModels();

    virtual void loadModels(){}
    virtual void loadModelsTextures(){}
    virtual void renderModels(){}
    virtual void displayModels(){}
    virtual void checkVisibility(Point3D *pointCamera, int distance){(void)pointCamera; (void)distance;}
};

#endif // ABSMODELS_H
