#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);
    setWindowTitle("ERROR!!!");
    QPixmap pix("Media/Images/1365728458_Warning.png");
    ui->icon->setPixmap(pix);
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}

void
ErrorWindow::SetErrorMsg( QString a_error_msg)
{
    ui->error_msg->setText(a_error_msg);
}

void
ErrorWindow::ShowWindow()
{
    show();
}

void ErrorWindow::on_buttonBox_accepted()
{
    emit ErrorAcepted();
}
