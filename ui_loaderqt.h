/********************************************************************************
** Form generated from reading UI file 'loaderqt.ui'
**
** Created: Sat May 4 12:49:26 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADERQT_H
#define UI_LOADERQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoaderQt
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *image;
    QProgressBar *progressBar;
    QLabel *out;

    void setupUi(QWidget *LoaderQt)
    {
        if (LoaderQt->objectName().isEmpty())
            LoaderQt->setObjectName(QString::fromUtf8("LoaderQt"));
        LoaderQt->resize(400, 300);
        LoaderQt->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(LoaderQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        image = new QLabel(LoaderQt);
        image->setObjectName(QString::fromUtf8("image"));

        verticalLayout->addWidget(image);

        progressBar = new QProgressBar(LoaderQt);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"     border-radius: 2px;\n"
"     background-color: #33CCFF;\n"
"     width: 10px;\n"
"     margin: 0.5px;\n"
" }\n"
"\n"
"QProgressBar {\n"
"     border: 2px solid grey;\n"
"	 background-color: #black;\n"
"     border-radius: 5px;\n"
" }"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        out = new QLabel(LoaderQt);
        out->setObjectName(QString::fromUtf8("out"));

        verticalLayout->addWidget(out);


        retranslateUi(LoaderQt);

        QMetaObject::connectSlotsByName(LoaderQt);
    } // setupUi

    void retranslateUi(QWidget *LoaderQt)
    {
        LoaderQt->setWindowTitle(QApplication::translate("LoaderQt", "Form", 0, QApplication::UnicodeUTF8));
        image->setText(QApplication::translate("LoaderQt", "TextLabel", 0, QApplication::UnicodeUTF8));
        out->setText(QApplication::translate("LoaderQt", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoaderQt: public Ui_LoaderQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADERQT_H