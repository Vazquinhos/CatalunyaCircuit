#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color();
    Color(float r, float g, float b);
    float getRed();
    float getGreen();
    float getBlue();

private:
    float _r;
    float _g;
    float _b;
};

#endif // COLOR_H
