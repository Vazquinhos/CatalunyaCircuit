#include "loaderqt.h"
#include "ui_loaderqt.h"
#include <QDesktopWidget>
#include "Objects/modelManager.h"
LoaderQt::LoaderQt(QWidget *parent, int a) :
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

    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum( a );
}

LoaderQt::~LoaderQt()
{
    delete ui;
}
void
LoaderQt::PrintModelLoaded(QString model, int val)
{
    ui->progressBar->setValue(val );
    ui->out->setText( model );
}
