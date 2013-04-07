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
