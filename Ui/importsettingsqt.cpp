#include "importsettingsqt.h"
#include "ui_importsettingsqt.h"
#include "errorwindow.h"
#include <QFileDialog>

ImportSettingsQt::ImportSettingsQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportSettingsQt)
{
    ui->setupUi(this);
    setWindowTitle("Settings Importer");
}

ImportSettingsQt::~ImportSettingsQt()
{
    delete ui;
}

void ImportSettingsQt::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Select..."), "/home/", tr("Catalunya Circuit Settings (*.ccs)"));
    ui->lineEdit->setText(fileName);
}

void ImportSettingsQt::on_buttonBox_accepted()
{
    QString fileName = ui->lineEdit->text();

    if( fileName == "")
    {
        ErrorWindow* p_error_window = new ErrorWindow(this);
        p_error_window->SetErrorMsg("You have not specified a file to load\n"
                                 " the settings, please select one.");
        p_error_window->show();
    }
}
