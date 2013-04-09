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
    
private slots:
    void on_ambient_cb_clicked();

    void on_specular_cb_clicked();

    void on_diffuse_cb_clicked();

private:
    Ui::LightsWidowQt *ui;
    void LoadQtWindow(void);
};

#endif // LIGHTSWIDOWQT_H
