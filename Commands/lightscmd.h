#ifndef LIGHTSCMD_H
#define LIGHTSCMD_H

#include "Utils/util.h"
#include "Ui/lightwindowqt.h"
#include <QObject>

class LightsCmd : public QObject
{
public:
    LightsCmd();
    ~LightsCmd();
    void process();

private:
    // ========================== Data Members ============================
    LightWindowQt* _p_light_qt;
};

#endif // LIGHTSCMD_H
