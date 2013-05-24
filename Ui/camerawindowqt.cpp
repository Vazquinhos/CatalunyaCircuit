#include "camerawindowqt.h"
#include "ui_camerawindowqt.h"
#include "newcameraqt.h"
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
}

CameraWindowQt::~CameraWindowQt()
{
    delete ui;
}

void
CameraWindowQt::LoadWindow(std::map<QString,CameraAbs*> a_cameras)
{
    blockSignals(true);
    // Iterator of the map of cameras
    std::map<QString,CameraAbs*>::const_iterator itr;

    // Auxiliar item to add to the list view
    QListWidgetItem* p_item;

    // The icon of the cameras for the list widget
    QIcon icon;
    icon.addFile("Media/Images/1365553750_film_camera_35mm.png");

    // For each element in the map..
    for(itr = a_cameras.begin(); itr != a_cameras.end(); ++itr)
    {
        // We create a item with the name of the camera
        p_item = new QListWidgetItem(icon,(*itr).first);

        // Insert an item in the last positon of the list
        ui->listWidget->addItem(p_item);
    }

    // We need to update the widgets with the current camera
    updateWidgetsWithCamera(
        CameraManager::getCameraManager()->getActiveCamera());

    blockSignals(false);
}


void CameraWindowQt::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem */*previous*/)
{
    updateWidgetsWithCamera(
                CameraManager::getCameraManager()->getCamera(current->text()));
}

void
CameraWindowQt::updateWidgetsWithCamera( CameraAbs* ap_camera )
{
    blockSignals(true);
    QString camera_name = ap_camera->getName();

    ui->line_name->setText(camera_name);

    ui->cb_mode->setCurrentIndex(0);


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

    blockSignals(false);
}

void CameraWindowQt::on_buttonBox_accepted()
{
    emit EditionFinished();
}


void CameraWindowQt::on_pushButton_clicked()
{
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_camera = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    CameraAbs* p_camera = CameraManager::getCameraManager()->getCamera( current_camera );

    if(p_camera)
    {
        // Le decimos que sera la camara activa
        CameraManager::getCameraManager()->setActiveCamera( current_camera );
    }
}

void CameraWindowQt::on_pb_delete_clicked()
{
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_camera = p_item->text();

    if ( current_camera != "")
    {
        // Le pedimos al camera manager que nos elimine la camara seleccionada
        CameraManager::getCameraManager()->deleteCamera( current_camera );
    }

    delete(p_item);
}

void CameraWindowQt::on_pb_add_clicked()
{
    //NewCameraQt* _p_new_cam= new NewCameraQt();

    //QObject::connect((_p_new_cam), SIGNAL(NewCameraCreated(CameraAbs*)), this, SLOT(NewCameraAdded(CameraAbs*)));

    //_p_new_cam->show();

    //hide();
}

void
CameraWindowQt::NewCameraAdded( CameraAbs* ap_camera )
{
    CameraManager::getCameraManager()->addCamera(ap_camera);

    // The icon of the cameras for the list widget
    QIcon icon;
    icon.addFile("Media/Images/1365553750_film_camera_35mm.png");

    // Insert an item in the last positon of the list
    ui->listWidget->addItem(new QListWidgetItem(icon,ap_camera->getName()));

    show();
}

void CameraWindowQt::on_line_name_editingFinished()
{
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    int row = ui->listWidget->currentRow();

    if( !p_item )
        return;

    QString current_camera = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    CameraManager::getCameraManager()->deleteCamera(current_camera);

    // Añadimos la nueva camara
    CameraAbs* p_camera = getCameraFromQt();

    CameraManager::getCameraManager()->addCamera(p_camera);

    // Update the list widget with the new camera
    // The icon of the cameras for the list widget
    QIcon icon;
    icon.addFile("Media/Images/1365553750_film_camera_35mm.png");

    // Insert a item in the last positon of the list
    ui->listWidget->insertItem(row,new QListWidgetItem(icon,p_camera->getName()));

    ui->listWidget->setCurrentRow(row);

    delete(p_item);
}

void CameraWindowQt::on_cb_mode_currentIndexChanged(int index)
{
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_camera = p_item->text();
}

void CameraWindowQt::on_sb_yaw_editingFinished()
{
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_camera = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    CameraManager::getCameraManager()->getCamera(current_camera)->setYaw(ui->sb_yaw->value());
}

void CameraWindowQt::on_sb_pitch_editingFinished()
{
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_camera = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    CameraManager::getCameraManager()->getCamera(current_camera)->setPitch(ui->sb_pitch->value());
}

void CameraWindowQt::on_cb_type_currentIndexChanged(int index)
{
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    int row = ui->listWidget->currentRow();

    if( !p_item )
        return;

    QString current_camera = p_item->text();

    camera_type type = CameraManager::getCameraManager()->getCamera(current_camera)->getType();

    camera_type ui_type;

    switch (ui->cb_type->currentIndex())
    {
        case 0: ui_type = FREE; break;
        case 1: ui_type = SPHERICAL; break;
        case 2: ui_type = FIXED; break;
    }

    if( type != ui_type)
    {
        // Le pedimos al camera manager que nos elimine la camara seleccionada
        CameraManager::getCameraManager()->deleteCamera(current_camera);

        CameraAbs* p_camera = getCameraFromQt();

        CameraManager::getCameraManager()->addCamera(p_camera);

        // Update the list widget with the new camera
        // The icon of the cameras for the list widget
        QIcon icon;
        icon.addFile("Media/Images/1365553750_film_camera_35mm.png");

        // Insert an item in the last positon of the list
        ui->listWidget->insertItem(row,new QListWidgetItem(icon,p_camera->getName()));

        ui->listWidget->setCurrentRow(row);

        delete(p_item);
    }
}

CameraAbs* CameraWindowQt::getCameraFromQt()
{
    CameraAbs* p_camera_to_rtn;
    switch (ui->cb_type->currentIndex())
    {
        case 0: // Free
            p_camera_to_rtn = new FreeCamera();
        break;
        case 1: // Spherical
            p_camera_to_rtn = new SphericalCamera();
        break;
        case 2: // Fixed
            p_camera_to_rtn = new FixedCamera();
        break;
    }

    QString new_camera_name = ui->line_name->text();

    if( CameraManager::getCameraManager()->getCamera(new_camera_name))
        new_camera_name += QString("(1)");

    p_camera_to_rtn->setName( new_camera_name );
    p_camera_to_rtn->setPosition( new Point3D( ui->x->value(), ui->y->value(), ui->z->value()));

    p_camera_to_rtn->setYawPitch(ui->sb_yaw->value(),ui->sb_pitch->value());
    p_camera_to_rtn->setZoom(ui->cb_zoom->value());

    return p_camera_to_rtn;
}

void CameraWindowQt::on_cb_zoom_editingFinished()
{
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_camera = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    CameraManager::getCameraManager()->getCamera(current_camera)->setZoom(ui->cb_zoom->value());
}
