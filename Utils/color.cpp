#include "color.h"
#include <QTime>

/*-------------------------------------------------------------------
|  Function Color
|  Purpose: Makes a random color
|  Returns: A random color
*-------------------------------------------------------------------*/
Color::Color()
{
    float r = qrand() % (100 + 1);
    float g = qrand() % (100 + 1);
    float b = qrand() % (100 + 1);

    _r = r/100.0f;
    _g = g/100.0f;
    _b = b/100.0f;
}

Color::Color(float r, float g, float b)
{
    this->_r = r;
    this->_g = g;
    this->_b = b;
}

float Color::getRed(){
    return _r;
}
float Color::getGreen(){
    return _g;
}

float Color::getBlue(){
    return _b;
}
