#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "importsettingsqt.h"
#include "exportsettingsqt.h"
#include "camerawindowqt.h"
#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    // ================= Constructores/Destructores ======================
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~MainWindow();
    
private slots:
    // ============================ Slots ==============================
    void on_cameras_clicked();

    void on_import_2_clicked();

    void on_export_2_clicked();

    void on_cars_clicked();

    void Menu( void );

    void showMySelf( void );

    void on_about_clicked();


private:
    // ========================== Data Members ============================
    Ui::MainWindow *ui;
    ImportSettingsQt*     _p_imp_qt;
    ExportSettingsQt*     _p_exp_qt;
    CameraWindowQt*       _p_camera_qt;
    About*                _p_about;

    bool menuVisible;
    // ============================ Methods ===============================
};

#endif // MAINWINDOW_H
