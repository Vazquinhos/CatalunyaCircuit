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
    // ================= Constructores/Destructores ======================
    explicit CameraWindowQt(QWidget *parent = 0);
    ~CameraWindowQt();
    
private:
    // ========================== Data Members ============================
    Ui::CameraWindowQt *ui;
    // ============================ Methods ===============================
};

#endif // CAMERAWINDOWQT_H
