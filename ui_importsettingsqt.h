/********************************************************************************
** Form generated from reading UI file 'importsettingsqt.ui'
**
** Created: Thu Apr 11 20:06:03 2013
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
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImportSettingsQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImportSettingsQt)
    {
        if (ImportSettingsQt->objectName().isEmpty())
            ImportSettingsQt->setObjectName(QString::fromUtf8("ImportSettingsQt"));
        ImportSettingsQt->resize(400, 141);
        verticalLayout = new QVBoxLayout(ImportSettingsQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(ImportSettingsQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("../Images/1364339878_hire-me.png")));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(ImportSettingsQt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
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
        label->setText(QString());
        label_2->setText(QApplication::translate("ImportSettingsQt", "Select the settings to import...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImportSettingsQt: public Ui_ImportSettingsQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTSETTINGSQT_H
