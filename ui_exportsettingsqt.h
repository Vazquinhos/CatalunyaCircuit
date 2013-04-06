/********************************************************************************
** Form generated from reading UI file 'exportsettingsqt.ui'
**
** Created: Sat Apr 6 20:35:36 2013
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
#include <QtGui/QGridLayout>
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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *_cameras;
    QCheckBox *_cars;
    QCheckBox *_lights;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExportSettingsQt)
    {
        if (ExportSettingsQt->objectName().isEmpty())
            ExportSettingsQt->setObjectName(QString::fromUtf8("ExportSettingsQt"));
        ExportSettingsQt->resize(400, 192);
        verticalLayout = new QVBoxLayout(ExportSettingsQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(ExportSettingsQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        _cameras = new QCheckBox(frame);
        _cameras->setObjectName(QString::fromUtf8("_cameras"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Images/1364340396_photography.png"), QSize(), QIcon::Normal, QIcon::Off);
        _cameras->setIcon(icon);

        horizontalLayout->addWidget(_cameras);

        _cars = new QCheckBox(frame);
        _cars->setObjectName(QString::fromUtf8("_cars"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Images/car.png"), QSize(), QIcon::Normal, QIcon::Off);
        _cars->setIcon(icon1);

        horizontalLayout->addWidget(_cars);

        _lights = new QCheckBox(frame);
        _lights->setObjectName(QString::fromUtf8("_lights"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../Images/1364340391_lightbulb.png"), QSize(), QIcon::Normal, QIcon::Off);
        _lights->setIcon(icon2);

        horizontalLayout->addWidget(_lights);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 3);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("../Images/1364339878_hire-me.png")));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 3);


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
        _cameras->setText(QApplication::translate("ExportSettingsQt", "Cameras", 0, QApplication::UnicodeUTF8));
        _cars->setText(QApplication::translate("ExportSettingsQt", "Cars", 0, QApplication::UnicodeUTF8));
        _lights->setText(QApplication::translate("ExportSettingsQt", "Lights", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ExportSettingsQt", "Select a filename to export your settings...", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_3->setText(QApplication::translate("ExportSettingsQt", "Select which setting you want to export...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExportSettingsQt: public Ui_ExportSettingsQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTSETTINGSQT_H
