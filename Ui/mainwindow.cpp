#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "importsettingsqt.h"
#include "exportsettingsqt.h"
#include "Cameras/cameramanager.h"
#include "Commands/camerascmd.h"
#include "about.h"
#include "Sound/SoundManager.h"
#include "Commands/lightscmd.h"

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


    //--------------- Camera Settings --------
    QIcon icon9;
    icon9.addFile("Media/Images/camera.png");
    ui->cameras->setIcon(icon9);
    _p_camera_qt = new CameraWindowQt();

    //--------------- Lights Settings ---------
    QIcon icon4;
    icon4.addFile("Media/Images/1365553596_idea.png");
    ui->lights->setIcon(icon4);

    //--------------- Spline Settings ---------
    QIcon icon3;
    icon3.addFile("Media/Images/bspline.png");
    ui->trajects->setIcon(icon3);
    _p_traject_qt = new TrajectSelectionQt();

    //--------------- About  -----------------
    QIcon icon10;
    icon10.addFile("Media/Images/about.png");
    ui->about->setIcon(icon10);
    _p_about = new About();

    QObject::connect(ui->widget, SIGNAL(MPushed()), this, SLOT(Menu()));
    QObject::connect(ui->widget, SIGNAL(LoadingFinished()),this, SLOT(showMySelf()));
    QObject::connect(ui->widget, SIGNAL(CarFinishEditing()),this, SLOT(CarEditingFinish()));
    menuVisible = true;

    ui->frame->setMinimumHeight(ui->widget->height());

    CarEditing = false;
    ui->pause->hide();
    ui->play->show();
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

void MainWindow::showMySelf()
{
    show();
}
void MainWindow::on_import_2_clicked()
{
    if(!CarEditing){
    if(_p_imp_qt)
    {
        _p_imp_qt->show();
        SoundManager::getSoundManager()->PlayAction("cursorSelect");
    }
    }
}

void MainWindow::on_export_2_clicked()
{
    if(!CarEditing){
    if(_p_exp_qt)
    {
        _p_exp_qt->show();
        SoundManager::getSoundManager()->PlayAction("cursorSelect");
    }
    }
}

void MainWindow::on_cars_clicked()
{
    ui->widget->CarViewerShow();
    ui->widget->changeCarModel();
    ui->frame->hide();
    CarEditing = true;
    ui->widget->CarViewerShow();
    SoundManager::getSoundManager()->PlayAction("cursorSelect");
}

void MainWindow::CarEditingFinish()
{
    CarEditing = false;
}

void MainWindow::on_about_clicked()
{
    if(!CarEditing){
    if(_p_about)
        SoundManager::getSoundManager()->PlayAction("cursorSelect");
        _p_about->show();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "CERRANDO";
    //SoundManager::getSoundManager()->Stop();
    //SoundManager::getSoundManager()->CleanUP();
}

void MainWindow::on_play_clicked()
{
    ui->pause->show();
    ui->play->hide();

    ui->widget->StartAnimation();
    SoundManager::getSoundManager()->PlayAction("cursorSelect");
}

void MainWindow::on_pause_clicked()
{
    ui->pause->hide();
    ui->play->show();
    ui->widget->StopAnimation();
    SoundManager::getSoundManager()->PlayAction("cursorSelect");
}

void MainWindow::on_trajects_clicked()
{
    if(_p_traject_qt)
    {
        _p_traject_qt->show();
        SoundManager::getSoundManager()->PlayAction("cursorSelect");
    }
}

void MainWindow::on_lights_clicked()
{
    LightsCmd* light_cmd = new LightsCmd();
    light_cmd->process();
    SoundManager::getSoundManager()->PlayAction("cursorSelect");
}
