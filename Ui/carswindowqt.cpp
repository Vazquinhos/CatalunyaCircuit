#include "carswindowqt.h"
#include "ui_carswindowqt.h"

CarsWindowQt::CarsWindowQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarsWindowQt)
{
    ui->setupUi(this);
}

CarsWindowQt::~CarsWindowQt()
{
    delete ui;
}
