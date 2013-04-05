#include "openGLwindow.h"
#include "ui_thothwindow.h"

OpenGLwindow::OpenGLwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThothWindow)
{
    ui->setupUi(this);
    // ALERT! Use the following code to get keyboard focus at your OpenGL widget
    ui->contextGL->setFocusPolicy(Qt::StrongFocus);
}

OpenGLwindow::~OpenGLwindow()
{
    delete ui;
}
