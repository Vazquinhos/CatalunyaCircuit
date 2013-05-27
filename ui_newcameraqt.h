/********************************************************************************
** Form generated from reading UI file 'newcameraqt.ui'
**
** Created: Mon May 27 02:13:07 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCAMERAQT_H
#define UI_NEWCAMERAQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewCameraQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *cb_type;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *x;
    QLabel *label_4;
    QDoubleSpinBox *y;
    QLabel *label_5;
    QDoubleSpinBox *z;
    QLabel *label_7;
    QDoubleSpinBox *sb_yaw;
    QLabel *label_8;
    QLabel *label_3;
    QDoubleSpinBox *sb_pitch;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *line_name;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewCameraQt)
    {
        if (NewCameraQt->objectName().isEmpty())
            NewCameraQt->setObjectName(QString::fromUtf8("NewCameraQt"));
        NewCameraQt->resize(533, 235);
        NewCameraQt->setStyleSheet(QString::fromUtf8("QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }\n"
"\n"
"QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout = new QVBoxLayout(NewCameraQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(NewCameraQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, -1, 10, 10);
        cb_type = new QComboBox(frame);
        cb_type->setObjectName(QString::fromUtf8("cb_type"));

        gridLayout->addWidget(cb_type, 3, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        x = new QDoubleSpinBox(frame);
        x->setObjectName(QString::fromUtf8("x"));
        x->setMinimum(-1e+08);
        x->setMaximum(1e+08);

        horizontalLayout_3->addWidget(x);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        y = new QDoubleSpinBox(frame);
        y->setObjectName(QString::fromUtf8("y"));
        y->setMinimum(-1e+08);
        y->setMaximum(1e+09);

        horizontalLayout_3->addWidget(y);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        z = new QDoubleSpinBox(frame);
        z->setObjectName(QString::fromUtf8("z"));
        z->setMinimum(-999999);
        z->setMaximum(1e+06);
        z->setValue(0);

        horizontalLayout_3->addWidget(z);


        gridLayout->addLayout(horizontalLayout_3, 4, 2, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        sb_yaw = new QDoubleSpinBox(frame);
        sb_yaw->setObjectName(QString::fromUtf8("sb_yaw"));
        sb_yaw->setMinimum(-99999);
        sb_yaw->setMaximum(999999);

        gridLayout->addWidget(sb_yaw, 1, 2, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        sb_pitch = new QDoubleSpinBox(frame);
        sb_pitch->setObjectName(QString::fromUtf8("sb_pitch"));
        sb_pitch->setMinimum(-99999);
        sb_pitch->setMaximum(9999.99);

        gridLayout->addWidget(sb_pitch, 2, 2, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_name = new QLineEdit(frame);
        line_name->setObjectName(QString::fromUtf8("line_name"));

        gridLayout->addWidget(line_name, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(NewCameraQt);
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


        retranslateUi(NewCameraQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewCameraQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewCameraQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewCameraQt);
    } // setupUi

    void retranslateUi(QDialog *NewCameraQt)
    {
        NewCameraQt->setWindowTitle(QApplication::translate("NewCameraQt", "Dialog", 0, QApplication::UnicodeUTF8));
        cb_type->clear();
        cb_type->insertItems(0, QStringList()
         << QApplication::translate("NewCameraQt", "FREE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewCameraQt", "SPHERICAL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewCameraQt", "FIXED", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("NewCameraQt", "X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewCameraQt", "Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewCameraQt", "Z", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NewCameraQt", "Yaw", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NewCameraQt", "Pitch", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewCameraQt", "Position", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NewCameraQt", "Type", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewCameraQt", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewCameraQt: public Ui_NewCameraQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCAMERAQT_H
