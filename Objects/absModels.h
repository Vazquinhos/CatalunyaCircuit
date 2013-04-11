#ifndef ABSMODELS_H
#define ABSMODELS_H

class AbsModels
{
public:
    AbsModels();

    virtual void loadModels(){}
    virtual void loadModelsTextures(){}
    virtual void renderModels(){}
    virtual void displayModels(){}
};

#endif // ABSMODELS_H
