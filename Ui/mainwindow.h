#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "importsettingsqt.h"
#include "lightswindowqt.h"
#include "exportsettingsqt.h"

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

private:
    Ui::MainWindow *ui;
    ImportSettingsQt*     _p_imp_qt;
    ExportSettingsQt*     _p_exp_qt;
    LightsWidowQt*        _p_light_qt;
};

#endif // MAINWINDOW_H