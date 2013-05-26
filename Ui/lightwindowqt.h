#ifndef LIGHTWINDOWQT_H
#define LIGHTWINDOWQT_H

#include <QDialog>
#include "Lights/lightmanager.h"
#include "Lights/light.h"
#include <QString>

namespace Ui {
class LightWindowQt;
}

class LightWindowQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit LightWindowQt(QWidget *parent = 0);
    ~LightWindowQt();
    void UpdateWidgetsWithLight( Light* ap_light );
    void LoadWindow(std::map<QString,Light*> a_lights);

private:
    Ui::LightWindowQt *ui;
};

#endif // LIGHTWINDOWQT_H
