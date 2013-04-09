#include "carswindowqt.h"
#include "ui_carswindowqt.h"
#include "camerawindowqt.h"

CarsWindowQt::CarsWindowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarsWindowQt)
{
    ui->setupUi(this);
    setWindowTitle("Cars Settings");
    QIcon icon5;
    icon5.addFile("Media/Images/1365559690_single_seater.png");
    setWindowIcon(icon5);
}

CarsWindowQt::~CarsWindowQt()
{
    delete ui;
}

void CarsWindowQt::on_pushButton_4_clicked()
{
    CameraWindowQt* p_camera_window = new CameraWindowQt();
    p_camera_window->setWindowTitle("Camera settings: car_name");
    p_camera_window->show();
}
