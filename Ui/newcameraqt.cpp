#include "newcameraqt.h"
#include "errorwindow.h"
#include "Cameras/cameramanager.h"
#include "Utils/util.h"

NewCameraQt::NewCameraQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCameraQt)
{
    ui->setupUi(this);
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

void NewCameraQt::errorAcepted( void )
{
    // The error has been confirmed show again the window
    show();
}

CameraAbs* NewCameraQt::getNewCamera( void )
{
    CameraAbs* p_camera_to_rtn;
    switch (ui->comboBox->currentIndex())
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
    mode_projection mode;
    if( ui->cb_mode->currentIndex() == 0)
    {
        mode = PERSPECTIVE;
    } else {
        mode = ORTOGONAL;
    }
    p_camera_to_rtn->setModeProjection( mode );
    p_camera_to_rtn->setYawPitch(ui->sb_yaw->value(),ui->sb_pitch->value());
    p_camera_to_rtn->setZoom(ui->cb_zoom->value());

    return p_camera_to_rtn;
}
