#ifndef NEWCAMERAQT_H
#define NEWCAMERAQT_H

#include <QDialog>
#include <Cameras/cameraabs.h>
#include <Cameras/fixedcamera.h>
#include <Cameras/freecamera.h>
#include <Cameras/sphericalcamera.h>
#include "ui_newcameraqt.h"

namespace Ui {
class NewCameraQt;
}

class NewCameraQt : public QDialog, public Ui::NewCameraQt
{
    Q_OBJECT
    
public:
    explicit NewCameraQt(QWidget *parent = 0);
    ~NewCameraQt();
    CameraAbs* getNewCamera( void );
    
private slots:
    void on_buttonBox_accepted();
    void errorAcepted( void );

private:
    Ui::NewCameraQt *ui;

signals:
    void NewCameraCreated( CameraAbs* );
};

#endif // NEWCAMERAQT_H
