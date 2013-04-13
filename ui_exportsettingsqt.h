/********************************************************************************
** Form generated from reading UI file 'exportsettingsqt.ui'
**
** Created: Sat Apr 13 17:23:05 2013
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
    QCheckBox *_cameras;
    QLabel *cameralab;
    QFrame *line;
    QCheckBox *_cars;
    QLabel *carlab;
    QFrame *line_2;
    QCheckBox *_lights;
    QLabel *lightlab;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExportSettingsQt)
    {
        if (ExportSettingsQt->objectName().isEmpty())
            ExportSettingsQt->setObjectName(QString::fromUtf8("ExportSettingsQt"));
        ExportSettingsQt->resize(323, 278);
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
        _cameras = new QCheckBox(frame);
        _cameras->setObjectName(QString::fromUtf8("_cameras"));

        horizontalLayout_2->addWidget(_cameras);

        cameralab = new QLabel(frame);
        cameralab->setObjectName(QString::fromUtf8("cameralab"));
        cameralab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(cameralab);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        _cars = new QCheckBox(frame);
        _cars->setObjectName(QString::fromUtf8("_cars"));

        horizontalLayout_2->addWidget(_cars);

        carlab = new QLabel(frame);
        carlab->setObjectName(QString::fromUtf8("carlab"));
        carlab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(carlab);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        _lights = new QCheckBox(frame);
        _lights->setObjectName(QString::fromUtf8("_lights"));

        horizontalLayout_2->addWidget(_lights);

        lightlab = new QLabel(frame);
        lightlab->setObjectName(QString::fromUtf8("lightlab"));
        lightlab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lightlab);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(ExportSettingsQt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
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
        _cameras->setText(QString());
        cameralab->setText(QApplication::translate("ExportSettingsQt", "ico", 0, QApplication::UnicodeUTF8));
        _cars->setText(QString());
        carlab->setText(QApplication::translate("ExportSettingsQt", "ico", 0, QApplication::UnicodeUTF8));
        _lights->setText(QString());
        lightlab->setText(QApplication::translate("ExportSettingsQt", "ico", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExportSettingsQt: public Ui_ExportSettingsQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTSETTINGSQT_H
