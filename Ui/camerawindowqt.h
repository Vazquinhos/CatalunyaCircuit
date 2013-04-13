#ifndef CAMERAWINDOWQT_H
#define CAMERAWINDOWQT_H

#include <QDialog>
#include <QListWidgetItem>
#include "Cameras/cameraabs.h"
#include <vector>

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
    std::vector< std::pair<CameraAbs*,CameraAbs*> > getEditedCameras( void );
private slots:
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *);

    void on_buttonBox_accepted();

private:
    // ========================== Data Members ============================
    Ui::CameraWindowQt *ui;

    // Vector with the edited cameras
    // The vector contais a pairs with:
    // A pair of CameraAbs with the camera with out editions, and the same camera edited with the new values
    // boolean to know if the camera has been updated
    std::vector< std::pair<std::pair<CameraAbs*,CameraAbs*>, bool> > _edition_cameras;
    // ============================ Methods ===============================
    void updateWidgetsWithCamera( CameraAbs* ap_camera );
signals:
    void EditionFinished( void );
};

#endif // CAMERAWINDOWQT_H
