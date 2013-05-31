#include "newlightwindowqt.h"
#include "ui_newlightwindowqt.h"
#include "errorwindow.h"
#include "Lights/swivellight.h"

NewLightWindowQt::NewLightWindowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLightWindowQt)
{
    ui->setupUi(this);
    setWindowTitle("New Light");
}

NewLightWindowQt::~NewLightWindowQt()
{
    delete ui;
}

void NewLightWindowQt::on_buttonBox_accepted()
{
    ErrorWindow* p_error_window = new ErrorWindow(this);
    if(ui->line_name->text() == "")
    {
        p_error_window->SetErrorMsg("You have not specified the name of the light");
        QObject::connect(p_error_window, SIGNAL(ErrorAcepted()), this, SLOT(errorAcepted()));
        p_error_window->show();
        // Hide the current window
        hide();
    } else {
        emit NewLightCreated( getNewLight());
        hide();
    }
}

void NewLightWindowQt::errorAcepted()
{
    // The error has been confirmed show again the window
    show();
}


Light* NewLightWindowQt::getNewLight()
{
    Light* light_to_rtn;

    switch(ui->cb_type->currentIndex())
    {
        case NORMAL:
            light_to_rtn = new Light( ui->line_name->text());
        break;
        case SWIVEL:
        light_to_rtn = new SwivelLight( ui->line_name->text());
            break;
    }

    light_to_rtn->setPosition( new Point3D(ui->x->value(), ui->y->value(), ui->z->value() ));

    sfvector sfdiffuse;

    sfdiffuse.push_back( ui->diffuse1->value());
    sfdiffuse.push_back( ui->diffuse2->value());
    sfdiffuse.push_back( ui->diffuse3->value());
    sfdiffuse.push_back( ui->diffuse4->value());

    light_to_rtn->setDiffuse(sfdiffuse);

    sfvector sfambient;

    sfambient.push_back( ui->ambient1->value());
    sfambient.push_back( ui->ambient2->value());
    sfambient.push_back( ui->ambient3->value());
    sfambient.push_back( ui->ambient4->value());

    light_to_rtn->setAmbient(sfambient);

    sfvector sfspecular;

    sfspecular.push_back( ui->specular1->value());
    sfspecular.push_back( ui->specular1->value());
    sfspecular.push_back( ui->specular1->value());
    sfspecular.push_back( ui->specular1->value());

    light_to_rtn->setSpecular(sfspecular);

    return light_to_rtn;
}
