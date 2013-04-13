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
CameraWindowQt::LoadWindow(std::map<QString,CameraAbs*> a_cameras)
{
    // Iterator of the map of cameras
    std::map<QString,CameraAbs*>::const_iterator itr;

    // Auxiliar item to add to the list view
    QListWidgetItem* p_item;

    // Auxiliar pair to add to the vector of cameras and their edition
    std::pair<CameraAbs*, CameraAbs*> the_camera_pair;
    std::pair<std::pair<CameraAbs*, CameraAbs*>,bool> aux_pair;

    // For each element in the map..
    for(itr = a_cameras.begin(); itr != a_cameras.end(); ++itr)
    {
        // We create a item with the name of the camera
        p_item = new QListWidgetItem((*itr).first);

        // Insert an item in the last positon of the list
        ui->listWidget->addItem(p_item);

        // Filling the vector of cameras and their edition
        the_camera_pair.first = (*itr).second;
        the_camera_pair.second = 0;
        aux_pair.first = the_camera_pair;
        aux_pair.second = false;
        _edition_cameras.push_back(aux_pair);
    }

    // We need to update the widgets with the current camera
    updateWidgetsWithCamera(
        CameraManager::getCameraManager()->getActiveCamera());
}


void CameraWindowQt::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem */*previous*/)
{
    updateWidgetsWithCamera(
                CameraManager::getCameraManager()->getCamera(current->text()));
}

void
CameraWindowQt::updateWidgetsWithCamera( CameraAbs* ap_camera )
{
    QString camera_name = ap_camera->getName();

    ui->line_name->setText(camera_name);

    mode_projection mode = ap_camera->getModeProjection();

    if( mode == ORTOGONAL)
    {
        ui->cb_mode->setCurrentIndex(1);
    } else {
        ui->cb_mode->setCurrentIndex(0);
    }

    camera_type type = ap_camera->getType();
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
    ap_camera->getYawPitch( yaw, pitch );
    ui->sb_yaw->setValue(yaw);
    ui->sb_pitch->setValue(pitch);

    Point3D* p_point = ap_camera->getPosition();

    ui->x->setValue(p_point->getX());
    ui->y->setValue(p_point->getY());
    ui->z->setValue(p_point->getZ());
}

std::vector< std::pair<CameraAbs*,CameraAbs*> >
CameraWindowQt::getEditedCameras( void )
{
    std::vector<std::pair<CameraAbs*, CameraAbs*> > vector_to_rtn;
    std::vector< std::pair<std::pair<CameraAbs*,CameraAbs*>, bool> >::iterator itr;
    std::pair<std::pair<CameraAbs*,CameraAbs*>, bool> aux_pair;
    for (itr = _edition_cameras.begin(); itr != _edition_cameras.end(); ++itr)
    {
        aux_pair = (*itr);
        if(aux_pair.second)
            vector_to_rtn.push_back( (*itr).first );
    }
}

void CameraWindowQt::on_buttonBox_accepted()
{
    emit EditionFinished();
}

