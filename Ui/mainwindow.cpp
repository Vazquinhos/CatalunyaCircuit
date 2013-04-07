#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "importsettingsqt.h"
#include "lightswindowqt.h"
#include "exportsettingsqt.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Catalunya Circuit");

    //--------------- Importer------------------

    // Setting the icon
    QIcon icon;
    icon.addFile("Media/Images/1364338876_sign-in.png");
    ui->actionImport->setIcon(icon);
    _p_imp_qt = new ImportSettingsQt();

    //--------------- Exporter ------------------
    // Setting the icon
    QIcon icon2;
    icon2.addFile("Media/Images/1364339241_sign-out.png");
    ui->actionExport->setIcon(icon2);
    _p_exp_qt = new ExportSettingsQt();

    //--------------- Light Settings ------------------
    // Setting the icon
    QIcon icon3;
    icon3.addFile("Media/Images/1364340391_lightbulb.png");
    ui->actionLight->setIcon(icon3);
    _p_light_qt = new LightsWidowQt();
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
