/********************************************************************************
** Form generated from reading UI file 'errorwindow.ui'
**
** Created: Sat Apr 13 17:23:05 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORWINDOW_H
#define UI_ERRORWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ErrorWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *icon;
    QSpacerItem *horizontalSpacer_2;
    QLabel *error_msg;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ErrorWindow)
    {
        if (ErrorWindow->objectName().isEmpty())
            ErrorWindow->setObjectName(QString::fromUtf8("ErrorWindow"));
        ErrorWindow->resize(427, 171);
        verticalLayout = new QVBoxLayout(ErrorWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(ErrorWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        icon = new QLabel(frame);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(icon);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        error_msg = new QLabel(frame);
        error_msg->setObjectName(QString::fromUtf8("error_msg"));

        horizontalLayout->addWidget(error_msg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(ErrorWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ErrorWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ErrorWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ErrorWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(ErrorWindow);
    } // setupUi

    void retranslateUi(QDialog *ErrorWindow)
    {
        ErrorWindow->setWindowTitle(QApplication::translate("ErrorWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        icon->setText(QApplication::translate("ErrorWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        error_msg->setText(QApplication::translate("ErrorWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ErrorWindow: public Ui_ErrorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORWINDOW_H
