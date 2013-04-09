#include "camerawindowqt.h"
#include "ui_camerawindowqt.h"

CameraWindowQt::CameraWindowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraWindowQt)
{
    ui->setupUi(this);
    setWindowTitle("Camera Settings");
}

CameraWindowQt::~CameraWindowQt()
{
    delete ui;
}
