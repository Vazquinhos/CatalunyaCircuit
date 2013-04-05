/********************************************************************************
** Form generated from reading UI file 'thothwindow.ui'
**
** Created: Wed Mar 27 21:08:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THOTHWINDOW_H
#define UI_THOTHWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "Scene/contextgl.h"

QT_BEGIN_NAMESPACE

class Ui_ThothWindow
{
public:
    QAction *actionUna;
    QAction *actionAlzado;
    QAction *actionPlanta;
    QAction *actionPerfil;
    QAction *actionIsometrica;
    QAction *actionHorizontal;
    QAction *actionVertical;
    QAction *actionQuatro;
    QAction *actionVertical_2_a_la_derecha;
    QAction *actionVertical_2_a_la_izquierda;
    QAction *actionHorizontal_2_arriba;
    QAction *actionHorizontal_2_abajo;
    QAction *actionPerspectiva_2;
    QAction *actionOrtogonal;
    QAction *actionA_adir;
    QAction *actionExit;
    QAction *actionToolBar;
    QAction *actionToolBar_2;
    QAction *actionSelectAll;
    QAction *actionDeseleccionar_todo;
    QAction *actionInvertir_Selecci_n;
    QAction *actionEliminar;
    QAction *actionMover;
    QAction *actionRotar;
    QAction *actionEscalar;
    QAction *actionHacer_invisible;
    QAction *actionHacer_visible;
    QAction *actionLight;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    GLWidget *contextGL;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdici_n;
    QMenu *menuSeleci_n;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *ThothWindow)
    {
        if (ThothWindow->objectName().isEmpty())
            ThothWindow->setObjectName(QString::fromUtf8("ThothWindow"));
        ThothWindow->resize(638, 505);
        ThothWindow->setStyleSheet(QString::fromUtf8(""));
        actionUna = new QAction(ThothWindow);
        actionUna->setObjectName(QString::fromUtf8("actionUna"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icons/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUna->setIcon(icon);
        actionAlzado = new QAction(ThothWindow);
        actionAlzado->setObjectName(QString::fromUtf8("actionAlzado"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Icons/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAlzado->setIcon(icon1);
        actionPlanta = new QAction(ThothWindow);
        actionPlanta->setObjectName(QString::fromUtf8("actionPlanta"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Icons/bottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlanta->setIcon(icon2);
        actionPerfil = new QAction(ThothWindow);
        actionPerfil->setObjectName(QString::fromUtf8("actionPerfil"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("Icons/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPerfil->setIcon(icon3);
        actionIsometrica = new QAction(ThothWindow);
        actionIsometrica->setObjectName(QString::fromUtf8("actionIsometrica"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Icons/iso.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIsometrica->setIcon(icon4);
        actionHorizontal = new QAction(ThothWindow);
        actionHorizontal->setObjectName(QString::fromUtf8("actionHorizontal"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("Icons/dos1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHorizontal->setIcon(icon5);
        actionVertical = new QAction(ThothWindow);
        actionVertical->setObjectName(QString::fromUtf8("actionVertical"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("Icons/dos2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVertical->setIcon(icon6);
        actionQuatro = new QAction(ThothWindow);
        actionQuatro->setObjectName(QString::fromUtf8("actionQuatro"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("Icons/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuatro->setIcon(icon7);
        actionVertical_2_a_la_derecha = new QAction(ThothWindow);
        actionVertical_2_a_la_derecha->setObjectName(QString::fromUtf8("actionVertical_2_a_la_derecha"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("Icons/tres1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVertical_2_a_la_derecha->setIcon(icon8);
        actionVertical_2_a_la_izquierda = new QAction(ThothWindow);
        actionVertical_2_a_la_izquierda->setObjectName(QString::fromUtf8("actionVertical_2_a_la_izquierda"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("Icons/tres2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVertical_2_a_la_izquierda->setIcon(icon9);
        actionHorizontal_2_arriba = new QAction(ThothWindow);
        actionHorizontal_2_arriba->setObjectName(QString::fromUtf8("actionHorizontal_2_arriba"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("Icons/tres4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHorizontal_2_arriba->setIcon(icon10);
        actionHorizontal_2_abajo = new QAction(ThothWindow);
        actionHorizontal_2_abajo->setObjectName(QString::fromUtf8("actionHorizontal_2_abajo"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("Icons/tres3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHorizontal_2_abajo->setIcon(icon11);
        actionPerspectiva_2 = new QAction(ThothWindow);
        actionPerspectiva_2->setObjectName(QString::fromUtf8("actionPerspectiva_2"));
        actionOrtogonal = new QAction(ThothWindow);
        actionOrtogonal->setObjectName(QString::fromUtf8("actionOrtogonal"));
        actionA_adir = new QAction(ThothWindow);
        actionA_adir->setObjectName(QString::fromUtf8("actionA_adir"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("Icons/plus-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionA_adir->setIcon(icon12);
        actionExit = new QAction(ThothWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("Icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon13);
        actionToolBar = new QAction(ThothWindow);
        actionToolBar->setObjectName(QString::fromUtf8("actionToolBar"));
        actionToolBar_2 = new QAction(ThothWindow);
        actionToolBar_2->setObjectName(QString::fromUtf8("actionToolBar_2"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("Icons/tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToolBar_2->setIcon(icon14);
        actionSelectAll = new QAction(ThothWindow);
        actionSelectAll->setObjectName(QString::fromUtf8("actionSelectAll"));
        actionDeseleccionar_todo = new QAction(ThothWindow);
        actionDeseleccionar_todo->setObjectName(QString::fromUtf8("actionDeseleccionar_todo"));
        actionInvertir_Selecci_n = new QAction(ThothWindow);
        actionInvertir_Selecci_n->setObjectName(QString::fromUtf8("actionInvertir_Selecci_n"));
        actionEliminar = new QAction(ThothWindow);
        actionEliminar->setObjectName(QString::fromUtf8("actionEliminar"));
        actionMover = new QAction(ThothWindow);
        actionMover->setObjectName(QString::fromUtf8("actionMover"));
        actionRotar = new QAction(ThothWindow);
        actionRotar->setObjectName(QString::fromUtf8("actionRotar"));
        actionEscalar = new QAction(ThothWindow);
        actionEscalar->setObjectName(QString::fromUtf8("actionEscalar"));
        actionHacer_invisible = new QAction(ThothWindow);
        actionHacer_invisible->setObjectName(QString::fromUtf8("actionHacer_invisible"));
        actionHacer_visible = new QAction(ThothWindow);
        actionHacer_visible->setObjectName(QString::fromUtf8("actionHacer_visible"));
        actionLight = new QAction(ThothWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("Icons/light.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLight->setIcon(icon15);
        centralWidget = new QWidget(ThothWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(400, 400));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        contextGL = new GLWidget(centralWidget);
        contextGL->setObjectName(QString::fromUtf8("contextGL"));
        contextGL->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(contextGL);


        verticalLayout_2->addLayout(horizontalLayout_2);

        ThothWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ThothWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 638, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdici_n = new QMenu(menuBar);
        menuEdici_n->setObjectName(QString::fromUtf8("menuEdici_n"));
        menuSeleci_n = new QMenu(menuBar);
        menuSeleci_n->setObjectName(QString::fromUtf8("menuSeleci_n"));
        ThothWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(ThothWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ThothWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(ThothWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ThothWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(ThothWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        ThothWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(ThothWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        ThothWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdici_n->menuAction());
        menuBar->addAction(menuSeleci_n->menuAction());
        menuFile->addAction(actionA_adir);
        menuFile->addAction(actionToolBar_2);
        menuFile->addAction(actionExit);
        menuEdici_n->addAction(actionSelectAll);
        menuEdici_n->addAction(actionDeseleccionar_todo);
        menuEdici_n->addAction(actionInvertir_Selecci_n);
        menuSeleci_n->addAction(actionEliminar);
        menuSeleci_n->addAction(actionMover);
        menuSeleci_n->addAction(actionRotar);
        menuSeleci_n->addAction(actionEscalar);
        menuSeleci_n->addAction(actionHacer_invisible);
        menuSeleci_n->addAction(actionHacer_visible);
        toolBar->addAction(actionUna);
        toolBar->addAction(actionHorizontal);
        toolBar->addAction(actionVertical_2_a_la_derecha);
        toolBar->addAction(actionVertical_2_a_la_izquierda);
        toolBar->addAction(actionHorizontal_2_arriba);
        toolBar->addAction(actionHorizontal_2_abajo);
        toolBar->addAction(actionQuatro);
        toolBar_2->addAction(actionAlzado);
        toolBar_2->addAction(actionPlanta);
        toolBar_2->addAction(actionPerfil);
        toolBar_2->addAction(actionIsometrica);
        toolBar_3->addAction(actionLight);

        retranslateUi(ThothWindow);
        QObject::connect(actionAlzado, SIGNAL(triggered()), contextGL, SLOT(alsat()));
        QObject::connect(actionPlanta, SIGNAL(triggered()), contextGL, SLOT(planta()));
        QObject::connect(actionPerfil, SIGNAL(triggered()), contextGL, SLOT(perfil()));
        QObject::connect(actionIsometrica, SIGNAL(triggered()), contextGL, SLOT(isometrica()));
        QObject::connect(actionVertical, SIGNAL(triggered()), contextGL, SLOT(ventanasVert()));
        QObject::connect(actionHorizontal, SIGNAL(triggered()), contextGL, SLOT(ventanasHor()));
        QObject::connect(actionVertical_2_a_la_derecha, SIGNAL(triggered()), contextGL, SLOT(ventanasVertDer()));
        QObject::connect(actionVertical_2_a_la_izquierda, SIGNAL(triggered()), contextGL, SLOT(ventanasVertIz()));
        QObject::connect(actionHorizontal_2_arriba, SIGNAL(triggered()), contextGL, SLOT(ventanasHorArr()));
        QObject::connect(actionHorizontal_2_abajo, SIGNAL(triggered()), contextGL, SLOT(ventanasHorAba()));
        QObject::connect(actionPerspectiva_2, SIGNAL(triggered()), contextGL, SLOT(perspectiva()));
        QObject::connect(actionOrtogonal, SIGNAL(triggered()), contextGL, SLOT(ortogonal()));
        QObject::connect(actionUna, SIGNAL(triggered()), contextGL, SLOT(ventana()));
        QObject::connect(actionQuatro, SIGNAL(triggered()), contextGL, SLOT(ventanas4()));
        QObject::connect(actionLight, SIGNAL(triggered()), contextGL, SLOT(showFullScreen()));

        QMetaObject::connectSlotsByName(ThothWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ThothWindow)
    {
        ThothWindow->setWindowTitle(QApplication::translate("ThothWindow", "ThothWindow", 0, QApplication::UnicodeUTF8));
        actionUna->setText(QApplication::translate("ThothWindow", "Una", 0, QApplication::UnicodeUTF8));
        actionAlzado->setText(QApplication::translate("ThothWindow", "Alzado", 0, QApplication::UnicodeUTF8));
        actionPlanta->setText(QApplication::translate("ThothWindow", "Planta", 0, QApplication::UnicodeUTF8));
        actionPerfil->setText(QApplication::translate("ThothWindow", "Perfil", 0, QApplication::UnicodeUTF8));
        actionIsometrica->setText(QApplication::translate("ThothWindow", "Isometrica", 0, QApplication::UnicodeUTF8));
        actionHorizontal->setText(QApplication::translate("ThothWindow", "Horizontal", 0, QApplication::UnicodeUTF8));
        actionVertical->setText(QApplication::translate("ThothWindow", "Vertical", 0, QApplication::UnicodeUTF8));
        actionQuatro->setText(QApplication::translate("ThothWindow", "Quatro", 0, QApplication::UnicodeUTF8));
        actionVertical_2_a_la_derecha->setText(QApplication::translate("ThothWindow", "Vertical 2 a la derecha", 0, QApplication::UnicodeUTF8));
        actionVertical_2_a_la_izquierda->setText(QApplication::translate("ThothWindow", "Vertical 2 a la izquierda", 0, QApplication::UnicodeUTF8));
        actionHorizontal_2_arriba->setText(QApplication::translate("ThothWindow", "Horizontal 2 arriba", 0, QApplication::UnicodeUTF8));
        actionHorizontal_2_abajo->setText(QApplication::translate("ThothWindow", "Horizontal 2 abajo", 0, QApplication::UnicodeUTF8));
        actionPerspectiva_2->setText(QApplication::translate("ThothWindow", "Perspectiva", 0, QApplication::UnicodeUTF8));
        actionOrtogonal->setText(QApplication::translate("ThothWindow", "Ortogonal", 0, QApplication::UnicodeUTF8));
        actionA_adir->setText(QApplication::translate("ThothWindow", "A\303\261adir...", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("ThothWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionToolBar->setText(QApplication::translate("ThothWindow", "herramienta png", 0, QApplication::UnicodeUTF8));
        actionToolBar_2->setText(QApplication::translate("ThothWindow", "ToolBar", 0, QApplication::UnicodeUTF8));
        actionSelectAll->setText(QApplication::translate("ThothWindow", "Seleccionar todo", 0, QApplication::UnicodeUTF8));
        actionDeseleccionar_todo->setText(QApplication::translate("ThothWindow", "Deseleccionar todo", 0, QApplication::UnicodeUTF8));
        actionInvertir_Selecci_n->setText(QApplication::translate("ThothWindow", "Invertir Selecci\303\263n", 0, QApplication::UnicodeUTF8));
        actionEliminar->setText(QApplication::translate("ThothWindow", "Eliminar", 0, QApplication::UnicodeUTF8));
        actionMover->setText(QApplication::translate("ThothWindow", "Mover", 0, QApplication::UnicodeUTF8));
        actionRotar->setText(QApplication::translate("ThothWindow", "Rotar", 0, QApplication::UnicodeUTF8));
        actionEscalar->setText(QApplication::translate("ThothWindow", "Escalar", 0, QApplication::UnicodeUTF8));
        actionHacer_invisible->setText(QApplication::translate("ThothWindow", "Hacer invisible", 0, QApplication::UnicodeUTF8));
        actionHacer_visible->setText(QApplication::translate("ThothWindow", "Hacer visible", 0, QApplication::UnicodeUTF8));
        actionLight->setText(QApplication::translate("ThothWindow", "Light", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ThothWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuEdici_n->setTitle(QApplication::translate("ThothWindow", "Edici\303\263n", 0, QApplication::UnicodeUTF8));
        menuSeleci_n->setTitle(QApplication::translate("ThothWindow", "Seleci\303\263n", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("ThothWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("ThothWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("ThothWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ThothWindow: public Ui_ThothWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THOTHWINDOW_H
