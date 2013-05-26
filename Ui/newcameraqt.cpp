#include "newcameraqt.h"
#include "errorwindow.h"
#include "Cameras/cameramanager.h"
#include "Utils/util.h"
#include "Cameras/cameraabs.h"

NewCameraQt::NewCameraQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCameraQt)
{
    ui->setupUi(this);
    setWindowTitle("New Camera");

    CameraAbs* cam =  CameraManager::getCameraManager()->getActiveCamera();

    camera_type type = cam->getType();
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
    cam->getYawPitch( yaw, pitch );
    ui->sb_yaw->setValue(yaw);
    ui->sb_pitch->setValue(pitch);

    Point3D* p_point = cam->getPosition();

    ui->x->setValue(p_point->getX());
    ui->y->setValue(p_point->getY());
    ui->z->setValue(p_point->getZ());

}

NewCameraQt::~NewCameraQt()
{
}

void NewCameraQt::on_buttonBox_accepted()
{
    ErrorWindow* p_error_window = new ErrorWindow(this);
    if(ui->line_name->text() == "")
    {
        p_error_window->SetErrorMsg("You have not specified the name of the camera");
        QObject::connect(p_error_window, SIGNAL(ErrorAcepted()), this, SLOT(errorAcepted()));
        p_error_window->show();
        // Hide the current window
        hide();
    } else {
        emit NewCameraCreated( getNewCamera());
        hide();
    }
}

void NewCameraQt::errorAcepted()
{
    // The error has been confirmed show again the window
    show();
}

CameraAbs* NewCameraQt::getNewCamera()
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
    double d  =  ui->x->value();
    p_camera_to_rtn->setPosition( new Point3D( ui->x->value(), ui->y->value(), ui->z->value()));
    p_camera_to_rtn->setYawPitch(ui->sb_yaw->value(),ui->sb_pitch->value());

    return p_camera_to_rtn;
}
