/********************************************************************************
** Form generated from reading UI file 'exportsettingsqt.ui'
**
** Created: Fri May 31 19:28:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTSETTINGSQT_H
#define UI_EXPORTSETTINGSQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExportSettingsQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *settlab;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *_light;
    QLabel *light_ico;
    QCheckBox *_cameras;
    QLabel *cameralab;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExportSettingsQt)
    {
        if (ExportSettingsQt->objectName().isEmpty())
            ExportSettingsQt->setObjectName(QString::fromUtf8("ExportSettingsQt"));
        ExportSettingsQt->resize(319, 228);
        ExportSettingsQt->setStyleSheet(QString::fromUtf8("QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }\n"
"\n"
"QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout = new QVBoxLayout(ExportSettingsQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(ExportSettingsQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        settlab = new QLabel(frame);
        settlab->setObjectName(QString::fromUtf8("settlab"));

        horizontalLayout->addWidget(settlab);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        _light = new QCheckBox(frame);
        _light->setObjectName(QString::fromUtf8("_light"));

        horizontalLayout_2->addWidget(_light);

        light_ico = new QLabel(frame);
        light_ico->setObjectName(QString::fromUtf8("light_ico"));

        horizontalLayout_2->addWidget(light_ico);

        _cameras = new QCheckBox(frame);
        _cameras->setObjectName(QString::fromUtf8("_cameras"));

        horizontalLayout_2->addWidget(_cameras);

        cameralab = new QLabel(frame);
        cameralab->setObjectName(QString::fromUtf8("cameralab"));
        cameralab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(cameralab);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(ExportSettingsQt);
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


        retranslateUi(ExportSettingsQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExportSettingsQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExportSettingsQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExportSettingsQt);
    } // setupUi

    void retranslateUi(QDialog *ExportSettingsQt)
    {
        ExportSettingsQt->setWindowTitle(QApplication::translate("ExportSettingsQt", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ExportSettingsQt", "Select a filename to export your settings...", 0, QApplication::UnicodeUTF8));
        settlab->setText(QApplication::translate("ExportSettingsQt", "ico", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExportSettingsQt", ".css", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ExportSettingsQt", "Select which setting you want to export...", 0, QApplication::UnicodeUTF8));
        _light->setText(QString());
        light_ico->setText(QApplication::translate("ExportSettingsQt", "ico", 0, QApplication::UnicodeUTF8));
        _cameras->setText(QString());
        cameralab->setText(QApplication::translate("ExportSettingsQt", "ico", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExportSettingsQt: public Ui_ExportSettingsQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTSETTINGSQT_H
