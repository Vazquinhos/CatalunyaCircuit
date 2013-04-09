#include "exportsettingsqt.h"
#include "Loaders/settingsexporter.h"
#include <QFileDialog>
#include <QString>

ExportSettingsQt::ExportSettingsQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportSettingsQt)
{
    ui->setupUi(this);
    setWindowTitle("Settings Exporter");

    QPixmap pix("Media/Images/1365559690_single_seater.png");
    ui->carlab->setPixmap(pix);
    QPixmap pix1("Media/Images/1365560323_Gear.png");
    ui->settlab->setPixmap(pix1);
    QPixmap pix2("Media/Images/1365553750_film_camera_35mm.png");
    ui->cameralab->setPixmap(pix2);
    QPixmap pix3("Media/Images/1365553596_idea.png");
    ui->lightlab->setPixmap(pix3);

}

ExportSettingsQt::~ExportSettingsQt()
{
    delete ui;
}

void ExportSettingsQt::on_buttonBox_accepted()
{
    _p_exporter = new SettingsExporter( ui->lineEdit->text() );
    _p_exporter->SetParameters( ui->_cameras->isChecked(),
                                ui->_cars->isChecked(),
                                ui->_lights->isChecked());
    _p_exporter->Execute();
}
