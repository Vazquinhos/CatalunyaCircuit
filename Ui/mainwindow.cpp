#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "importsettingsqt.h"
#include "exportsettingsqt.h"
#include "camerawindowqt.h"
#include "carswindowqt.h"
#include "Cameras/cameramanager.h"
#include "Commands/camerascmd.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    setWindowTitle("Catalunya Circuit");
    ui->widget->setFocusPolicy(Qt::StrongFocus);

    setWindowState((windowState() & ~(Qt::WindowMinimized | Qt::WindowFullScreen))
                       | Qt::WindowMaximized);//Show maximized main window

    // Setting the icon
    QIcon icon;
    icon.addFile("Media/Images/1365553346_import.png");
    ui->import_2->setIcon(icon);
    _p_imp_qt = new ImportSettingsQt();

    //--------------- Exporter ------------------
    // Setting the icon
    QIcon icon2;
    icon2.addFile("Media/Images/1365553386_export.png");
    ui->export_2->setIcon(icon2);
    _p_exp_qt = new ExportSettingsQt();

    //--------------- Play -----------------
    QIcon icon6;
    icon6.addFile("Media/Images/play.png");
    ui->play->setIcon(icon6);


    //--------------- Pause -----------------
    QIcon icon7;
    icon7.addFile("Media/Images/pause.png");
    ui->pause->setIcon(icon7);


    //--------------- Cars -----------------
    QIcon icon8;
    icon8.addFile("Media/Images/car.png");
    ui->cars->setIcon(icon8);


    //--------------- Camera Settings -----------------
    QIcon icon9;
    icon9.addFile("Media/Images/camera.png");
    ui->cameras->setIcon(icon9);
    _p_camera_qt = new CameraWindowQt();


    //--------------- About  -----------------
    QIcon icon10;
    icon10.addFile("Media/Images/about.png");
    ui->about->setIcon(icon10);
    _p_about = new About();

    QObject::connect(ui->widget, SIGNAL(Menu()), this, SLOT(Menu()));
    menuVisible = true;
}

MainWindow::~MainWindow()
{
    _p_imp_qt->hide();
    _p_imp_qt->deleteLater();
    _p_exp_qt->hide();
    _p_exp_qt->deleteLater();
    delete ui;
}

void MainWindow::on_cameras_clicked()
{
    CamerasCmd* p_cmd_cam = new CamerasCmd();
    p_cmd_cam->process();
}

void MainWindow::Menu(){
    if(menuVisible)
    {
        ui->frame->hide();
        menuVisible = false;
    }else{
        ui->frame->show();
        menuVisible = true;
    }
}

void MainWindow::on_import_2_clicked()
{
    if(_p_imp_qt)
        _p_imp_qt->show();
}

void MainWindow::on_export_2_clicked()
{
    if(_p_exp_qt)
        _p_exp_qt->show();
}

void MainWindow::on_cars_clicked()
{
    if(_p_car_qt)
        _p_car_qt->show();
}

void MainWindow::on_about_clicked()
{
    if(_p_about)
        _p_about->show();
}
