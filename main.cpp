#include <QApplication>
#include "Utils/util.h"
#include "Ui/mainwindow.h"
#include "Ui/loaderqt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
