#ifndef CAMERAWINDOWQT_H
#define CAMERAWINDOWQT_H

#include <QDialog>
#include <QListWidgetItem>

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
    void LoadWindow();
private slots:
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    // ========================== Data Members ============================
    Ui::CameraWindowQt *ui;
    // ============================ Methods ===============================
};

#endif // CAMERAWINDOWQT_H
