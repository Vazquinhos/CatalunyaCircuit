/********************************************************************************
** Form generated from reading UI file 'carsviewerqt.ui'
**
** Created: Mon May 20 19:11:59 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARSVIEWERQT_H
#define UI_CARSVIEWERQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include "./Scene/contextgl.h"

QT_BEGIN_NAMESPACE

class Ui_CarsViewerQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    GLWidget *widget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CarsViewerQt)
    {
        if (CarsViewerQt->objectName().isEmpty())
            CarsViewerQt->setObjectName(QString::fromUtf8("CarsViewerQt"));
        CarsViewerQt->resize(400, 300);
        CarsViewerQt->setStyleSheet(QString::fromUtf8("QFrame,QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout = new QVBoxLayout(CarsViewerQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(CarsViewerQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new GLWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(CarsViewerQt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CarsViewerQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), CarsViewerQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CarsViewerQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(CarsViewerQt);
    } // setupUi

    void retranslateUi(QDialog *CarsViewerQt)
    {
        CarsViewerQt->setWindowTitle(QApplication::translate("CarsViewerQt", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CarsViewerQt: public Ui_CarsViewerQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSVIEWERQT_H
