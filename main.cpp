#include <QApplication>
#include "openGLwindow.h"
#include "Utils/util.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLwindow w;

    glutInit(&argc, argv);

    w.show();
    
    return a.exec();
}
