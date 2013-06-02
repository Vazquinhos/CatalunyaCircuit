#include "lightwindowqt.h"
#include "ui_lightwindowqt.h"
#include <QListWidgetItem>
#include "newlightwindowqt.h"

LightWindowQt::LightWindowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LightWindowQt)
{
    ui->setupUi(this);
    setWindowTitle("Light Settings");

    QObject::connect( ui->ambient1, SIGNAL(valueChanged(double)),this, SLOT(ambientChanged(double)));
    QObject::connect( ui->ambient2, SIGNAL(valueChanged(double)),this, SLOT(ambientChanged(double)));
    QObject::connect( ui->ambient3, SIGNAL(valueChanged(double)),this, SLOT(ambientChanged(double)));
    QObject::connect( ui->ambient4, SIGNAL(valueChanged(double)),this, SLOT(ambientChanged(double)));

    QObject::connect( ui->specular1, SIGNAL(valueChanged(double)),this, SLOT(specularChanged(double)));
    QObject::connect( ui->specular2, SIGNAL(valueChanged(double)),this, SLOT(specularChanged(double)));
    QObject::connect( ui->specular3, SIGNAL(valueChanged(double)),this, SLOT(specularChanged(double)));
    QObject::connect( ui->specular4, SIGNAL(valueChanged(double)),this, SLOT(specularChanged(double)));

    QObject::connect( ui->diffuse1, SIGNAL(valueChanged(double)),this, SLOT(diffuseChanged(double)));
    QObject::connect( ui->diffuse1, SIGNAL(valueChanged(double)),this, SLOT(diffuseChanged(double)));
    QObject::connect( ui->diffuse1, SIGNAL(valueChanged(double)),this, SLOT(diffuseChanged(double)));
    QObject::connect( ui->diffuse1, SIGNAL(valueChanged(double)),this, SLOT(diffuseChanged(double)));

    QObject::connect( ui->x, SIGNAL(valueChanged(double)),this, SLOT(positionChanged(double)));
    QObject::connect( ui->y, SIGNAL(valueChanged(double)),this, SLOT(positionChanged(double)));
    QObject::connect( ui->z, SIGNAL(valueChanged(double)),this, SLOT(positionChanged(double)));
}

LightWindowQt::~LightWindowQt()
{
    delete ui;
}

void
LightWindowQt::positionChanged(double a)
{
    (void) a;
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString light_name = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* light = LightManager::getLightManager()->getLight(light_name);

    light->setPosition( new Point3D( ui->x->value(),ui->y->value(),ui->z->value()));

}

void
LightWindowQt::ambientChanged(double a)
{
    (void) a;
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString light_name = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* light = LightManager::getLightManager()->getLight(light_name);
    sfvector sfambient;

    sfambient.push_back( ui->ambient1->value());
    sfambient.push_back( ui->ambient2->value());
    sfambient.push_back( ui->ambient3->value());
    sfambient.push_back( ui->ambient4->value());

    light->setAmbient(sfambient);
}

void
LightWindowQt::specularChanged(double a)
{
    (void) a;
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString light_name = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* light = LightManager::getLightManager()->getLight(light_name);


    sfvector sfspecular;

    sfspecular.push_back( ui->specular1->value());
    sfspecular.push_back( ui->specular1->value());
    sfspecular.push_back( ui->specular1->value());
    sfspecular.push_back( ui->specular1->value());

    light->setSpecular(sfspecular);
}

void
LightWindowQt::diffuseChanged(double a)
{
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString light_name = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* light = LightManager::getLightManager()->getLight(light_name);

    sfvector sfdiffuse;

    sfdiffuse.push_back( ui->diffuse1->value());
    sfdiffuse.push_back( ui->diffuse2->value());
    sfdiffuse.push_back( ui->diffuse3->value());
    sfdiffuse.push_back( ui->diffuse4->value());

    light->setDiffuse(sfdiffuse);
}

void
LightWindowQt::UpdateWidgetsWithLight( Light* ap_light )
{
    blockSignals(true);
    QString light_name = ap_light->getName();

    ui->line_name->setText(light_name);

    light_type type = ap_light->getType();
    switch (type)
    {
        case NORMAL:
            ui->cb_type->setCurrentIndex(0);
        break;
        case SWIVEL:
            ui->cb_type->setCurrentIndex(1);
        break;
    }

    Point3D* p_point = ap_light->getPosition();

    ui->x->setValue(p_point->getX());
    ui->y->setValue(p_point->getY());
    ui->z->setValue(p_point->getZ());

    sfvector sfambient = ap_light->getAmbient();

    ui->ambient1->setValue(sfambient[0]);
    ui->ambient2->setValue(sfambient[1]);
    ui->ambient3->setValue(sfambient[2]);
    ui->ambient4->setValue(sfambient[3]);

    sfvector sfspecular = ap_light->getSpecular();

    ui->specular1->setValue(sfspecular[0]);
    ui->specular2->setValue(sfspecular[1]);
    ui->specular3->setValue(sfspecular[2]);
    ui->specular4->setValue(sfspecular[3]);

    sfvector sfdiffuse = ap_light->getDiffuse();

    ui->diffuse1->setValue(sfdiffuse[0]);
    ui->diffuse2->setValue(sfdiffuse[1]);
    ui->diffuse3->setValue(sfdiffuse[2]);
    ui->diffuse4->setValue(sfdiffuse[3]);

    blockSignals(false);
}

void
LightWindowQt::LoadWindow(std::map<QString,Light*> a_lights)
{
    blockSignals(true);
    // Iterator of the map of cameras
    std::map<QString,Light*>::const_iterator itr;

    // Auxiliar item to add to the list view
    QListWidgetItem* p_item;

    // The icon of the cameras for the list widget
    QIcon icon;
    icon.addFile("Media/Images/1365553596_idea.png");

    // For each element in the map..
    for(itr = a_lights.begin(); itr != a_lights.end(); ++itr)
    {
        // We create a item with the name of the camera
        p_item = new QListWidgetItem(icon,(*itr).first);

        // Insert an item in the last positon of the list
        ui->listWidget->addItem(p_item);
    }

    // We need to update the widgets with the current camera
    UpdateWidgetsWithLight(
        LightManager::getLightManager()->getActiveLight() );

    blockSignals(false);
}

void LightWindowQt::on_line_name_editingFinished()
{
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString light_name = p_item->text();

    int row = ui->listWidget->currentRow();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* light = LightManager::getLightManager()->getLight(light_name);

    light->setName( ui->line_name->text() );

    // Le pedimos al light manager que nos elimine la camara seleccionada
    LightManager::getLightManager()->deleteLight(light_name);

    // Añadimos la nueva camara
    Light* p_light = getLightFromQt();

    LightManager::getLightManager()->addLight(p_light);

    // Update the list widget with the new camera
    // The icon of the cameras for the list widget
    QIcon icon;
    icon.addFile("Media/Images/1365553596_idea.png");

    // Insert a item in the last positon of the list
    ui->listWidget->insertItem(row,new QListWidgetItem(icon,p_light->getName()));

    ui->listWidget->setCurrentRow(row);

    delete(p_item);
}

Light*
LightWindowQt::getLightFromQt()
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

void LightWindowQt::on_cb_type_currentIndexChanged(const QString &arg1)
{
    (void) arg1;
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString light_name = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* light = LightManager::getLightManager()->getLight(light_name);


    switch(ui->cb_type->currentIndex())
    {
        case NORMAL:
            light->setType( NORMAL );
            break;
        case SWIVEL:
            light->setType( SWIVEL );
            break;
    }

    light->setName( ui->line_name->text() );

}

void LightWindowQt::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    UpdateWidgetsWithLight(
                LightManager::getLightManager()->getLight(current->text()));
    (void) previous;
}

void LightWindowQt::on_buttonBox_2_accepted()
{
    hide();
}

void LightWindowQt::on_buttonBox_2_rejected()
{
    hide();
}

void LightWindowQt::on_pb_add_clicked()
{
    NewLightWindowQt* p_light = new NewLightWindowQt();
    QObject::connect((p_light), SIGNAL(NewLightCreated(Light*)), this, SLOT(NewLightCreated(Light*)));
    p_light->show();
    hide();
}

void
LightWindowQt::NewLightCreated( Light* light )
{
    int row = ui->listWidget->currentRow();

    // Update the list widget with the new camera
    // The icon of the cameras for the list widget
    QIcon icon;
    icon.addFile("Media/Images/1365553596_idea.png");

    // Insert a item in the last positon of the list
    ui->listWidget->insertItem(row,new QListWidgetItem(icon,light->getName()));

    LightManager::getLightManager()->addLight(light);

    show();
}

void LightWindowQt::on_pb_delete_clicked()
{
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_light = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* p_light = LightManager::getLightManager()->getLight( current_light );

    if(p_light)
    {
        // Le decimos que sera la camara activa
        LightManager::getLightManager()->setActiveLight( current_light );
    }
}

void LightWindowQt::on_pushButton_clicked()
{
    //Obtenemos el nombre de la camara que esta actualmente seleccionada
    QListWidgetItem* p_item = ui->listWidget->currentItem();

    if( !p_item )
        return;

    QString current_light = p_item->text();

    // Le pedimos al camera manager que nos elimine la camara seleccionada
    Light* p_light = LightManager::getLightManager()->getLight( current_light );

    if(p_light)
    {
        // Le decimos que sera la camara activa
        LightManager::getLightManager()->setActiveLight( current_light );
    }

}
