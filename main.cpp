#include <QApplication>
#include "Utils/util.h"
#include "Ui/mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    glutInit(&argc, argv);
    w.show();
    w.hide();

    return a.exec();
}
