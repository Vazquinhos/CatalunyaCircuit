/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 22 21:33:54 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "./Scene/contextgl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport;
    QAction *actionExport;
    QAction *actionLight;
    QAction *actionCamera;
    QAction *actionCars;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *play;
    QPushButton *pause;
    QPushButton *cars;
    QPushButton *cameras;
    QPushButton *import_2;
    QPushButton *export_2;
    QPushButton *about;
    GLWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(668, 722);
        MainWindow->setStyleSheet(QString::fromUtf8(" QToolBar {\n"
"     background: white;\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
" }\n"
"\n"
"QMainWindow{\n"
"	background:black;\n"
"}"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionCamera = new QAction(MainWindow);
        actionCamera->setObjectName(QString::fromUtf8("actionCamera"));
        actionCars = new QAction(MainWindow);
        actionCars->setObjectName(QString::fromUtf8("actionCars"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(200, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"     background-color: #333333;\n"
"	 color:white;\n"
"	\n"
"}\n"
"\n"
"QPushButton {\n"
"     background-color: #333333;\n"
"	 border: 1px solid white;\n"
"	 color:white;\n"
" }\n"
"\n"
"QPushButton:pressed {\n"
"     background-color: #FFFFFF\n"
"     border-style: inset;\n"
"	 color:black;\n"
" }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        play = new QPushButton(frame);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(180, 70));
        play->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(play);

        pause = new QPushButton(frame);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setMinimumSize(QSize(180, 70));
        pause->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(pause);

        cars = new QPushButton(frame);
        cars->setObjectName(QString::fromUtf8("cars"));
        cars->setMinimumSize(QSize(180, 70));
        cars->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(cars);

        cameras = new QPushButton(frame);
        cameras->setObjectName(QString::fromUtf8("cameras"));
        cameras->setMinimumSize(QSize(180, 70));
        cameras->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(cameras);

        import_2 = new QPushButton(frame);
        import_2->setObjectName(QString::fromUtf8("import_2"));
        import_2->setMinimumSize(QSize(180, 70));
        import_2->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(import_2);

        export_2 = new QPushButton(frame);
        export_2->setObjectName(QString::fromUtf8("export_2"));
        export_2->setMinimumSize(QSize(180, 70));
        export_2->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(export_2);

        about = new QPushButton(frame);
        about->setObjectName(QString::fromUtf8("about"));
        about->setMinimumSize(QSize(180, 70));
        about->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(about);


        horizontalLayout->addWidget(frame);

        widget = new GLWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 668, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0, QApplication::UnicodeUTF8));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
        actionLight->setText(QApplication::translate("MainWindow", "Light", 0, QApplication::UnicodeUTF8));
        actionCamera->setText(QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        actionCars->setText(QApplication::translate("MainWindow", "Cars", 0, QApplication::UnicodeUTF8));
        play->setText(QApplication::translate("MainWindow", "PLAY", 0, QApplication::UnicodeUTF8));
        pause->setText(QApplication::translate("MainWindow", "PAUSE", 0, QApplication::UnicodeUTF8));
        cars->setText(QApplication::translate("MainWindow", "CARS", 0, QApplication::UnicodeUTF8));
        cameras->setText(QApplication::translate("MainWindow", "CAMERAS", 0, QApplication::UnicodeUTF8));
        import_2->setText(QApplication::translate("MainWindow", "IMPORT...", 0, QApplication::UnicodeUTF8));
        export_2->setText(QApplication::translate("MainWindow", "EXPORT..", 0, QApplication::UnicodeUTF8));
        about->setText(QApplication::translate("MainWindow", "ABOUT US", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
