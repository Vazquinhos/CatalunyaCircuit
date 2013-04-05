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
