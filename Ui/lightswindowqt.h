#ifndef LIGHTSWIDOWQT_H
#define LIGHTSWIDOWQT_H

#include <QDialog>

namespace Ui {
class LightsWidowQt;
}

class LightsWidowQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit LightsWidowQt(QWidget *parent = 0);
    ~LightsWidowQt();
    
private:
    Ui::LightsWidowQt *ui;
};

#endif // LIGHTSWIDOWQT_H
