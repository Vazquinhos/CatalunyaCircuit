#ifndef ABSMODELS_H
#define ABSMODELS_H

#include "Utils/point3D.h"
#include <QString>
#include <IL/il.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <string>
#include <map>
#include "Utils/util.h"

using namespace std;

class AbsModels
{
public:
    AbsModels();

    virtual void displayModels(){}
    virtual void checkVisibility(Point3D *pointCamera, int distance){(void)pointCamera; (void)distance;}
};

#endif // ABSMODELS_H

