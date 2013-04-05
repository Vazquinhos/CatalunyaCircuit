#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);
    _p_parent = parent;
    setWindowTitle("ERROR!!!");
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}

void
ErrorWindow::SetErrorMsg( QString a_error_msg)
{
    ui->label->setText(a_error_msg);
}

void
ErrorWindow::ShowWindow( void )
{
    show();
}

void ErrorWindow::on_buttonBox_accepted()
{
    _p_parent->show();
}
