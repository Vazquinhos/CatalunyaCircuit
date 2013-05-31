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
    QPixmap pix("Media/Images/1365559690_single_seater.png");
    QPixmap pix1("Media/Images/1365560323_Gear.png");
    ui->icon->setPixmap(pix1);
    QPixmap pix2("Media/Images/camera.png");
    ui->camera_icon->setPixmap(pix2);
    QPixmap pix3("Media/Images/1365553596_idea.png");
    ui->light_icon->setPixmap(pix3);
    ui->lineEdit->setEnabled(false);
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
        QObject::connect(p_error_window, SIGNAL(ErrorAcepted()), this, SLOT(errorAcepted()));
        p_error_window->show();
        // Hide the current window
        hide();
    }
    else
    {
        _p_settingsImporter = new SettingsImporter(fileName);
        _p_settingsImporter->SetParameters(ui->camera_chk->isChecked(),
                                           false,//ui->car_chk->isChecked(),
                                           ui->_lights->isChecked());
        _p_settingsImporter->Execute();
    }
}

void ImportSettingsQt::errorAcepted()
{
    // The error has been confirmed show again the window
    show();
}
