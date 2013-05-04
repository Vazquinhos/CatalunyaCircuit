#ifndef TEXTURE_H
#define TEXTURE_H

#include <Utils/util.h>

class Texture
{
public:
    Texture();
    GLenum _textureTarget; //Texture tarjet ex: TEXTURE_2D
    GLuint _textureBindId; //Texture id bind
};

#endif // TEXTURE_H
