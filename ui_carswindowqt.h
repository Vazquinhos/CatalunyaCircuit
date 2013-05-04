/********************************************************************************
** Form generated from reading UI file 'carswindowqt.ui'
**
** Created: Sat May 4 12:49:26 2013
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CarsWindowQt
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QListView *listView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QFrame *line;
    QLabel *label_7;
    QSpinBox *spinBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_3;
    QFrame *line_3;
    QFrame *line_2;
    QPushButton *pushButton_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CarsWindowQt)
    {
        if (CarsWindowQt->objectName().isEmpty())
            CarsWindowQt->setObjectName(QString::fromUtf8("CarsWindowQt"));
        CarsWindowQt->resize(350, 427);
        verticalLayout_3 = new QVBoxLayout(CarsWindowQt);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(CarsWindowQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(frame);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 100));

        verticalLayout_2->addWidget(pushButton_3);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout_2->addWidget(spinBox);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(frame);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout->addWidget(doubleSpinBox_2, 3, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 2, 1, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(frame);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        gridLayout->addWidget(doubleSpinBox_3, 4, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addWidget(frame);

        buttonBox = new QDialogButtonBox(CarsWindowQt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
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
        label->setText(QApplication::translate("CarsWindowQt", "Name", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CarsWindowQt", "Add Car", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("CarsWindowQt", "Delete Car", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CarsWindowQt", "Model", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("CarsWindowQt", "PushButton", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CarsWindowQt", "Race Position", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CarsWindowQt", "Z", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CarsWindowQt", "X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CarsWindowQt", "Y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CarsWindowQt", "Space Position", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("CarsWindowQt", "Cameras", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CarsWindowQt: public Ui_CarsWindowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSWINDOWQT_H
