#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    QPixmap pix3("Media/Images/circuit-de-catalunya.jpg");
    setWindowTitle(" About Us...");
    ui->label->setPixmap(pix3);
}

About::~About()
{
    delete ui;
}
