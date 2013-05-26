#include "lightwindowqt.h"
#include "ui_lightwindowqt.h"
#include <QListWidgetItem>

LightWindowQt::LightWindowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LightWindowQt)
{
    ui->setupUi(this);
    setWindowTitle("Light Settings");
}

LightWindowQt::~LightWindowQt()
{
    delete ui;
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
