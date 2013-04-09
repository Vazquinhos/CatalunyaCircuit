#include "lightswindowqt.h"
#include "ui_lightswindowqt.h"

LightsWidowQt::LightsWidowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LightsWidowQt)
{
    ui->setupUi(this);
    setWindowTitle("Lights Settings");
}

LightsWidowQt::~LightsWidowQt()
{
    delete ui;
}

void LightsWidowQt::on_ambient_cb_clicked()
{
    if(!ui->ambient_cb->isChecked())
    {
        ui->sb_ambient1->setEnabled(false);
        ui->sb_ambient2->setEnabled(false);
        ui->sb_ambient3->setEnabled(false);
        ui->sb_ambient4->setEnabled(false);
    } else {
        ui->sb_ambient1->setEnabled(true);
        ui->sb_ambient2->setEnabled(true);
        ui->sb_ambient3->setEnabled(true);
        ui->sb_ambient4->setEnabled(true);
    }

}

void LightsWidowQt::on_specular_cb_clicked()
{
    if(!ui->specular_cb->isChecked())
    {
        ui->sb_specular1->setEnabled(false);
        ui->sb_specular2->setEnabled(false);
        ui->sb_specular3->setEnabled(false);
        ui->sb_specular4->setEnabled(false);
    } else {
        ui->sb_specular1->setEnabled(true);
        ui->sb_specular2->setEnabled(true);
        ui->sb_specular3->setEnabled(true);
        ui->sb_specular4->setEnabled(true);
    }
}

void LightsWidowQt::LoadQtWindow( void )
{
    // We set the combo boxes depending on the light selected
    on_ambient_cb_clicked();
    on_specular_cb_clicked();
    on_diffuse_cb_clicked();
}



void LightsWidowQt::on_diffuse_cb_clicked()
{
    if(!ui->diffuse_cb->isChecked())
    {
        ui->sb_diffuse1->setEnabled(false);
        ui->sb_diffuse2->setEnabled(false);
        ui->sb_diffuse3->setEnabled(false);
        ui->sb_diffuse4->setEnabled(false);
    } else {
        ui->sb_diffuse1->setEnabled(true);
        ui->sb_diffuse2->setEnabled(true);
        ui->sb_diffuse3->setEnabled(true);
        ui->sb_diffuse4->setEnabled(true);
    }
}
