/********************************************************************************
** Form generated from reading UI file 'openGLwindow.ui'
**
** Created: Sat Apr 6 20:35:36 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLWINDOW_H
#define UI_OPENGLWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "GLwidget.h"

QT_BEGIN_NAMESPACE

class Ui_ThothWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    GLWidget *contextGL;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *ThothWindow)
    {
        if (ThothWindow->objectName().isEmpty())
            ThothWindow->setObjectName(QString::fromUtf8("ThothWindow"));
        ThothWindow->resize(643, 500);
        ThothWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(ThothWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        contextGL = new GLWidget(centralWidget);
        contextGL->setObjectName(QString::fromUtf8("contextGL"));

        horizontalLayout->addWidget(contextGL);

        ThothWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ThothWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 643, 25));
        ThothWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(ThothWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ThothWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(ThothWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setStyleSheet(QString::fromUtf8(""));
        ThothWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(ThothWindow);

        QMetaObject::connectSlotsByName(ThothWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ThothWindow)
    {
        ThothWindow->setWindowTitle(QApplication::translate("ThothWindow", "ThothWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ThothWindow: public Ui_ThothWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLWINDOW_H
