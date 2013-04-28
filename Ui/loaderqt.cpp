#include "loaderqt.h"
#include "ui_loaderqt.h"
#include <QDesktopWidget>
LoaderQt::LoaderQt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoaderQt)
{
    ui->setupUi(this);
    setWindowFlags( Qt::CustomizeWindowHint ); // Hide window borders

    QPixmap pix3("Media/Images/circuit-de-catalunya.jpg");
    setWindowTitle("");
    ui->image->setPixmap(pix3);


    //Move window to center of screen
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());
}

LoaderQt::~LoaderQt()
{
    delete ui;
}
