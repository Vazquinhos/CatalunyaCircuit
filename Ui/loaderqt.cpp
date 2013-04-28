#include "loaderqt.h"
#include "ui_loaderqt.h"

LoaderQt::LoaderQt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoaderQt)
{
    ui->setupUi(this);
    QPixmap pix3("Media/Images/circuit-de-catalunya.jpg");
    setWindowTitle("");
    ui->image->setPixmap(pix3);
    move(500,500);
}

LoaderQt::~LoaderQt()
{
    delete ui;
}
