#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "importsettingsqt.h"
#include "lightswindowqt.h"
#include "exportsettingsqt.h"
#include "camerawindowqt.h"
#include "carswindowqt.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Catalunya Circuit");
    ui->widget->setFocusPolicy(Qt::StrongFocus);
    //--------------- Importer------------------

    // Setting the icon
    QIcon icon;
    icon.addFile("Media/Images/1365553346_import.png");
    ui->actionImport->setIcon(icon);
    _p_imp_qt = new ImportSettingsQt();

    //--------------- Exporter ------------------
    // Setting the icon
    QIcon icon2;
    icon2.addFile("Media/Images/1365553386_export.png");
    ui->actionExport->setIcon(icon2);
    _p_exp_qt = new ExportSettingsQt();

    //--------------- Light Settings ------------------
    // Setting the icon
    QIcon icon3;
    icon3.addFile("Media/Images/1365553596_idea.png");
    ui->actionLight->setIcon(icon3);
    _p_light_qt = new LightsWidowQt();

    //--------------- Camera Settings ------------------
    // Setting the icon
    QIcon icon4;
    icon4.addFile("Media/Images/1365553750_film_camera_35mm.png");
    ui->actionCamera->setIcon(icon4);
    _p_camera_qt = new CameraWindowQt();

    //--------------- Cars Settings ------------------
    // Setting the icon
    QIcon icon5;
    icon5.addFile("Media/Images/1365559690_single_seater.png");
    ui->actionCars->setIcon(icon5);
    _p_car_qt = new CarsWindowQt();
}

MainWindow::~MainWindow()
{
    _p_imp_qt->hide();
    _p_imp_qt->deleteLater();
    _p_exp_qt->hide();
    _p_exp_qt->deleteLater();
    _p_light_qt->hide();
    _p_light_qt->deleteLater();
    delete ui;
}

void MainWindow::on_actionImport_triggered()
{
    if(_p_imp_qt)
        _p_imp_qt->show();
}


void MainWindow::on_actionExport_triggered()
{
    if(_p_exp_qt)
        _p_exp_qt->show();
}


void MainWindow::on_actionLight_triggered()
{
    if(_p_light_qt)
        _p_light_qt->show();
}

void MainWindow::on_actionCamera_triggered()
{
    if(_p_camera_qt)
        _p_camera_qt->show();
}

void MainWindow::on_actionCars_triggered()
{
    if(_p_car_qt)
        _p_car_qt->show();
}
