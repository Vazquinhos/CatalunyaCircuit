/********************************************************************************
** Form generated from reading UI file 'importsettingsqt.ui'
**
** Created: Sat May 4 12:49:26 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTSETTINGSQT_H
#define UI_IMPORTSETTINGSQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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

class Ui_ImportSettingsQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *icon;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *camera_chk;
    QLabel *camera_icon;
    QFrame *line_2;
    QCheckBox *light_chk;
    QLabel *light_icon;
    QFrame *line_3;
    QCheckBox *car_chk;
    QLabel *car_icon;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImportSettingsQt)
    {
        if (ImportSettingsQt->objectName().isEmpty())
            ImportSettingsQt->setObjectName(QString::fromUtf8("ImportSettingsQt"));
        ImportSettingsQt->resize(355, 278);
        ImportSettingsQt->setStyleSheet(QString::fromUtf8("QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }\n"
"\n"
"QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout = new QVBoxLayout(ImportSettingsQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(ImportSettingsQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
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

        icon = new QLabel(frame);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setMinimumSize(QSize(50, 0));
        icon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(icon, 1, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        camera_chk = new QCheckBox(frame);
        camera_chk->setObjectName(QString::fromUtf8("camera_chk"));

        horizontalLayout->addWidget(camera_chk);

        camera_icon = new QLabel(frame);
        camera_icon->setObjectName(QString::fromUtf8("camera_icon"));

        horizontalLayout->addWidget(camera_icon);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        light_chk = new QCheckBox(frame);
        light_chk->setObjectName(QString::fromUtf8("light_chk"));

        horizontalLayout->addWidget(light_chk);

        light_icon = new QLabel(frame);
        light_icon->setObjectName(QString::fromUtf8("light_icon"));

        horizontalLayout->addWidget(light_icon);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        car_chk = new QCheckBox(frame);
        car_chk->setObjectName(QString::fromUtf8("car_chk"));

        horizontalLayout->addWidget(car_chk);

        car_icon = new QLabel(frame);
        car_icon->setObjectName(QString::fromUtf8("car_icon"));

        horizontalLayout->addWidget(car_icon);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(ImportSettingsQt);
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


        retranslateUi(ImportSettingsQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImportSettingsQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImportSettingsQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImportSettingsQt);
    } // setupUi

    void retranslateUi(QDialog *ImportSettingsQt)
    {
        ImportSettingsQt->setWindowTitle(QApplication::translate("ImportSettingsQt", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ImportSettingsQt", "Select..", 0, QApplication::UnicodeUTF8));
        icon->setText(QApplication::translate("ImportSettingsQt", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ImportSettingsQt", "Select the settings to import...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ImportSettingsQt", "Select wich settings you want to import..", 0, QApplication::UnicodeUTF8));
        camera_chk->setText(QString());
        camera_icon->setText(QApplication::translate("ImportSettingsQt", "TextLabel", 0, QApplication::UnicodeUTF8));
        light_chk->setText(QString());
        light_icon->setText(QApplication::translate("ImportSettingsQt", "TextLabel", 0, QApplication::UnicodeUTF8));
        car_chk->setText(QString());
        car_icon->setText(QApplication::translate("ImportSettingsQt", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImportSettingsQt: public Ui_ImportSettingsQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTSETTINGSQT_H
