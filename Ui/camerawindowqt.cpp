#include "camerawindowqt.h"
#include "ui_camerawindowqt.h"
#include "Cameras/cameramanager.h"
#include "Cameras/cameraabs.h"
#include  <QListWidgetItem>
#include "Utils/util.h"
CameraWindowQt::CameraWindowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraWindowQt)
{
    ui->setupUi(this);
    setWindowTitle("Camera Settings");
    QPixmap pix2("Media/Images/1365553750_film_camera_35mm.png");
    ui->ico->setPixmap(pix2);
}

CameraWindowQt::~CameraWindowQt()
{
    delete ui;
}

void
CameraWindowQt::LoadWindow()
{
    std::map<QString,CameraAbs*> map_cam =
            CameraManager::getCameraManager()->getCameras();

    std::map<QString,CameraAbs*>::const_iterator itr;

    QListWidgetItem* p_item;
    for(itr = map_cam.begin(); itr != map_cam.end(); ++itr)
    {
        p_item = new QListWidgetItem((*itr).first);
        ui->listWidget->addItem(p_item);
    }
    // TODO, buscar en que row esta la current camera
    p_item = ui->listWidget->takeItem(0);
    QString camera_name = p_item->text();
    ui->listWidget->insertItem(0,p_item);

    ui->line_name->setText(camera_name);

    CameraAbs* p_camera = CameraManager::getCameraManager()->getCamera(camera_name);

    mode_projection mode = p_camera->getModeProjection();

    if( mode == ORTOGONAL)
    {
        ui->cb_mode->setCurrentIndex(1);
    } else {
        ui->cb_mode->setCurrentIndex(0);
    }

    camera_type type = p_camera->getType();
    switch (type)
    {
        case FREE:
            ui->cb_type->setCurrentIndex(0);
        break;
        case SPHERICAL:
            ui->cb_type->setCurrentIndex(1);
        break;
        case FIXED:
            ui->cb_type->setCurrentIndex(2);
        break;
    }

    float yaw, pitch;
    p_camera->getYawPitch( yaw, pitch );
    ui->sb_yaw->setValue(yaw);
    ui->sb_pitch->setValue(pitch);

    Point3D* p_point = p_camera->getPosition();

    ui->x->setValue(p_point->getX());
    ui->y->setValue(p_point->getY());
    ui->z->setValue(p_point->getZ());
}


void CameraWindowQt::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString camera_name = current->text();

    ui->line_name->setText(camera_name);

    CameraAbs* p_camera = CameraManager::getCameraManager()->getCamera(camera_name);

    mode_projection mode = p_camera->getModeProjection();

    if( mode == ORTOGONAL)
    {
        ui->cb_mode->setCurrentIndex(1);
    } else {
        ui->cb_mode->setCurrentIndex(0);
    }

    camera_type type = p_camera->getType();
    switch (type)
    {
        case FREE:
            ui->cb_type->setCurrentIndex(0);
        break;
        case SPHERICAL:
            ui->cb_type->setCurrentIndex(1);
        break;
        case FIXED:
            ui->cb_type->setCurrentIndex(2);
        break;
    }

    float yaw, pitch;
    p_camera->getYawPitch( yaw, pitch );
    ui->sb_yaw->setValue(yaw);
    ui->sb_pitch->setValue(pitch);

    Point3D* p_point = p_camera->getPosition();

    ui->x->setValue(p_point->getX());
    ui->y->setValue(p_point->getY());
    ui->z->setValue(p_point->getZ());
}
