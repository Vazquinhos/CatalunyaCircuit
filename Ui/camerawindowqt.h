#ifndef CAMERAWINDOWQT_H
#define CAMERAWINDOWQT_H

#include <QDialog>
#include <QListWidgetItem>
#include "Cameras/cameraabs.h"

namespace Ui {
class CameraWindowQt;
}

class CameraWindowQt : public QDialog
{
    Q_OBJECT
    
public:
    // ================= Constructores/Destructores ======================
    explicit CameraWindowQt(QWidget *parent = 0);
    ~CameraWindowQt();
    void LoadWindow(std::map<QString,CameraAbs*> a_cameras);
private slots:
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *);

private:
    // ========================== Data Members ============================
    Ui::CameraWindowQt *ui;
    // ============================ Methods ===============================
    void updateWidgetsWithCamera( CameraAbs* ap_camera );
};

#endif // CAMERAWINDOWQT_H
