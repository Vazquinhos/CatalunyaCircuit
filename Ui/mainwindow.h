#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "importsettingsqt.h"
#include "lightswindowqt.h"
#include "exportsettingsqt.h"
#include "camerawindowqt.h"
#include "carswindowqt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionImport_triggered();

    void on_actionExport_triggered();

    void on_actionLight_triggered();

    void on_actionCamera_triggered();

    void on_actionCars_triggered();

private:
    Ui::MainWindow *ui;
    ImportSettingsQt*     _p_imp_qt;
    ExportSettingsQt*     _p_exp_qt;
    LightsWidowQt*        _p_light_qt;
    CameraWindowQt*       _p_camera_qt;
    CarsWindowQt*         _p_car_qt;
};

#endif // MAINWINDOW_H
