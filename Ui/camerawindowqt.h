#ifndef CAMERAWINDOWQT_H
#define CAMERAWINDOWQT_H

#include <QDialog>

namespace Ui {
class CameraWindowQt;
}

class CameraWindowQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit CameraWindowQt(QWidget *parent = 0);
    ~CameraWindowQt();
    
private:
    Ui::CameraWindowQt *ui;
};

#endif // CAMERAWINDOWQT_H
