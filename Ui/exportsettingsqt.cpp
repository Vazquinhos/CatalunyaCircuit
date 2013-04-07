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

    QIcon icon;
    icon.addFile("Media/Images/car.png");
    ui->_cars->setIcon(icon);
    QIcon icon2;
    icon2.addFile("Media/Images/1364340396_photography.png");
    ui->_cameras->setIcon(icon2);
    QIcon icon3;
    icon3.addFile("Media/Images/1364340391_lightbulb.png");
    ui->_lights->setIcon(icon3);
    QPixmap pix("Media/Images/1364339878_hire-me.png");
    ui->label->setPixmap(pix);

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
