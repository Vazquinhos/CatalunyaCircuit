/********************************************************************************
** Form generated from reading UI file 'montmelocircuit.ui'
**
** Created: Sat Apr 6 20:35:36 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTMELOCIRCUIT_H
#define UI_MONTMELOCIRCUIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "./Scene/contextgl.h"

QT_BEGIN_NAMESPACE

class Ui_MontmeloCircuit
{
public:
    QAction *actionImport_Settings;
    QAction *actionExport_Settings;
    QAction *actionExit;
    QWidget *centralWidget;
    ContextGL *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MontmeloCircuit)
    {
        if (MontmeloCircuit->objectName().isEmpty())
            MontmeloCircuit->setObjectName(QString::fromUtf8("MontmeloCircuit"));
        MontmeloCircuit->resize(820, 544);
        actionImport_Settings = new QAction(MontmeloCircuit);
        actionImport_Settings->setObjectName(QString::fromUtf8("actionImport_Settings"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Images/1364338876_sign-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_Settings->setIcon(icon);
        actionImport_Settings->setMenuRole(QAction::NoRole);
        actionExport_Settings = new QAction(MontmeloCircuit);
        actionExport_Settings->setObjectName(QString::fromUtf8("actionExport_Settings"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Images/1364339241_sign-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_Settings->setIcon(icon1);
        actionExit = new QAction(MontmeloCircuit);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../Images/1364339322_logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        centralWidget = new QWidget(MontmeloCircuit);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new ContextGL(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-1, -1, 16777215, 16777215));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        MontmeloCircuit->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MontmeloCircuit);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 25));
        MontmeloCircuit->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MontmeloCircuit);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MontmeloCircuit->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MontmeloCircuit);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MontmeloCircuit->setStatusBar(statusBar);

        mainToolBar->addAction(actionImport_Settings);
        mainToolBar->addAction(actionExport_Settings);
        mainToolBar->addAction(actionExit);

        retranslateUi(MontmeloCircuit);

        QMetaObject::connectSlotsByName(MontmeloCircuit);
    } // setupUi

    void retranslateUi(QMainWindow *MontmeloCircuit)
    {
        MontmeloCircuit->setWindowTitle(QApplication::translate("MontmeloCircuit", "MontmeloCircuit", 0, QApplication::UnicodeUTF8));
        actionImport_Settings->setText(QApplication::translate("MontmeloCircuit", "Import Settings", 0, QApplication::UnicodeUTF8));
        actionExport_Settings->setText(QApplication::translate("MontmeloCircuit", "Export_Settings", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MontmeloCircuit", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MontmeloCircuit: public Ui_MontmeloCircuit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTMELOCIRCUIT_H
