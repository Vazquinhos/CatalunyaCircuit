/********************************************************************************
** Form generated from reading UI file 'trajectselectionqt.ui'
**
** Created: Fri May 31 19:28:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAJECTSELECTIONQT_H
#define UI_TRAJECTSELECTIONQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrajectSelectionQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TrajectSelectionQt)
    {
        if (TrajectSelectionQt->objectName().isEmpty())
            TrajectSelectionQt->setObjectName(QString::fromUtf8("TrajectSelectionQt"));
        TrajectSelectionQt->resize(400, 115);
        TrajectSelectionQt->setMaximumSize(QSize(16777215, 500));
        TrajectSelectionQt->setStyleSheet(QString::fromUtf8("QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout = new QVBoxLayout(TrajectSelectionQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(TrajectSelectionQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(TrajectSelectionQt);
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


        retranslateUi(TrajectSelectionQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), TrajectSelectionQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TrajectSelectionQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(TrajectSelectionQt);
    } // setupUi

    void retranslateUi(QDialog *TrajectSelectionQt)
    {
        TrajectSelectionQt->setWindowTitle(QApplication::translate("TrajectSelectionQt", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TrajectSelectionQt", "Select..", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TrajectSelectionQt", "Select a traject to import..", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrajectSelectionQt: public Ui_TrajectSelectionQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAJECTSELECTIONQT_H
