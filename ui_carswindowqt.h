/********************************************************************************
** Form generated from reading UI file 'carswindowqt.ui'
**
** Created: Mon May 20 18:08:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARSWINDOWQT_H
#define UI_CARSWINDOWQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include "./Scene/carsviewer.h"

QT_BEGIN_NAMESPACE

class Ui_CarsWindowQt
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    CarsViewer *widget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CarsWindowQt)
    {
        if (CarsWindowQt->objectName().isEmpty())
            CarsWindowQt->setObjectName(QString::fromUtf8("CarsWindowQt"));
        CarsWindowQt->resize(519, 436);
        CarsWindowQt->setStyleSheet(QString::fromUtf8("QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }\n"
"\n"
"QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout_3 = new QVBoxLayout(CarsWindowQt);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(CarsWindowQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget = new CarsViewer(frame);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_4->addWidget(widget);


        verticalLayout_3->addWidget(frame);

        buttonBox = new QDialogButtonBox(CarsWindowQt);
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

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(CarsWindowQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), CarsWindowQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CarsWindowQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(CarsWindowQt);
    } // setupUi

    void retranslateUi(QDialog *CarsWindowQt)
    {
        CarsWindowQt->setWindowTitle(QApplication::translate("CarsWindowQt", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CarsWindowQt: public Ui_CarsWindowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSWINDOWQT_H
