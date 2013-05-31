#ifndef NEWLIGHTWINDOWQT_H
#define NEWLIGHTWINDOWQT_H

#include <QDialog>
#include "Lights/light.h"

namespace Ui {
class NewLightWindowQt;
}

class NewLightWindowQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewLightWindowQt(QWidget *parent = 0);
    ~NewLightWindowQt();
    
private slots:
    void on_buttonBox_accepted();
    void errorAcepted();

signals:
    void NewLightCreated( Light* light );

private:
    Ui::NewLightWindowQt *ui;

    Light* getNewLight();
};

#endif // NEWLIGHTWINDOWQT_H
