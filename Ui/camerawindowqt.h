#ifndef CAMERAWINDOWQT_H
#define CAMERAWINDOWQT_H

#include <QDialog>
#include <QListWidgetItem>
#include "Cameras/cameraabs.h"
#include <vector>
#include "newcameraqt.h"

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

    void on_pushButton_clicked();

    void on_pb_delete_clicked();

    void on_pb_add_clicked();

    void NewCameraAdded( CameraAbs *ap_camera );

    void on_line_name_editingFinished();

    void on_cb_mode_currentIndexChanged(int index);

    void on_sb_yaw_editingFinished();

    void on_sb_pitch_editingFinished();

    void on_cb_type_currentIndexChanged(int index);

private:
    // ========================== Data Members ============================
    Ui::CameraWindowQt *ui;
    NewCameraQt* _p_new_cam ;

    // ============================ Methods ===============================
    void updateWidgetsWithCamera( CameraAbs* ap_camera );
    CameraAbs* getCameraFromQt( void );
signals:
    void EditionFinished( void );
};

#endif // CAMERAWINDOWQT_H
