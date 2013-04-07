#include <QApplication>
#include "Utils/util.h"
#include "Ui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    glutInit(&argc, argv);

    w.show();
    
    return a.exec();
}
