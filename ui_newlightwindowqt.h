/********************************************************************************
** Form generated from reading UI file 'newlightwindowqt.ui'
**
** Created: Fri May 31 19:28:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLIGHTWINDOWQT_H
#define UI_NEWLIGHTWINDOWQT_H

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

class Ui_NewLightWindowQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_9;
    QDoubleSpinBox *ambient1;
    QLabel *label_3;
    QDoubleSpinBox *ambient2;
    QDoubleSpinBox *ambient3;
    QLabel *label_7;
    QDoubleSpinBox *ambient4;
    QDoubleSpinBox *specular1;
    QDoubleSpinBox *specular3;
    QDoubleSpinBox *specular4;
    QDoubleSpinBox *diffuse1;
    QDoubleSpinBox *diffuse2;
    QDoubleSpinBox *diffuse3;
    QDoubleSpinBox *diffuse4;
    QComboBox *cb_type;
    QLineEdit *line_name;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *y;
    QLabel *label_2;
    QLabel *label_4;
    QDoubleSpinBox *x;
    QLabel *label_5;
    QDoubleSpinBox *z;
    QDoubleSpinBox *specular2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewLightWindowQt)
    {
        if (NewLightWindowQt->objectName().isEmpty())
            NewLightWindowQt->setObjectName(QString::fromUtf8("NewLightWindowQt"));
        NewLightWindowQt->resize(400, 342);
        NewLightWindowQt->setStyleSheet(QString::fromUtf8("QFrame,QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout = new QVBoxLayout(NewLightWindowQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(NewLightWindowQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, -1, 10, 10);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        ambient1 = new QDoubleSpinBox(frame);
        ambient1->setObjectName(QString::fromUtf8("ambient1"));
        ambient1->setMaximum(1);
        ambient1->setSingleStep(0.1);

        gridLayout->addWidget(ambient1, 2, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        ambient2 = new QDoubleSpinBox(frame);
        ambient2->setObjectName(QString::fromUtf8("ambient2"));
        ambient2->setMaximum(1);
        ambient2->setSingleStep(0.1);

        gridLayout->addWidget(ambient2, 2, 2, 1, 1);

        ambient3 = new QDoubleSpinBox(frame);
        ambient3->setObjectName(QString::fromUtf8("ambient3"));
        ambient3->setMaximum(1);
        ambient3->setSingleStep(0.1);

        gridLayout->addWidget(ambient3, 2, 3, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        ambient4 = new QDoubleSpinBox(frame);
        ambient4->setObjectName(QString::fromUtf8("ambient4"));
        ambient4->setMaximum(1);
        ambient4->setSingleStep(0.1);

        gridLayout->addWidget(ambient4, 2, 4, 1, 1);

        specular1 = new QDoubleSpinBox(frame);
        specular1->setObjectName(QString::fromUtf8("specular1"));
        specular1->setMaximum(1);
        specular1->setSingleStep(0.1);

        gridLayout->addWidget(specular1, 3, 1, 1, 1);

        specular3 = new QDoubleSpinBox(frame);
        specular3->setObjectName(QString::fromUtf8("specular3"));
        specular3->setMaximum(1);
        specular3->setSingleStep(0.1);

        gridLayout->addWidget(specular3, 3, 3, 1, 1);

        specular4 = new QDoubleSpinBox(frame);
        specular4->setObjectName(QString::fromUtf8("specular4"));
        specular4->setMaximum(1);
        specular4->setSingleStep(0.1);

        gridLayout->addWidget(specular4, 3, 4, 1, 1);

        diffuse1 = new QDoubleSpinBox(frame);
        diffuse1->setObjectName(QString::fromUtf8("diffuse1"));
        diffuse1->setMaximum(1);
        diffuse1->setSingleStep(0.1);

        gridLayout->addWidget(diffuse1, 4, 1, 1, 1);

        diffuse2 = new QDoubleSpinBox(frame);
        diffuse2->setObjectName(QString::fromUtf8("diffuse2"));
        diffuse2->setMaximum(1);
        diffuse2->setSingleStep(0.1);

        gridLayout->addWidget(diffuse2, 4, 2, 1, 1);

        diffuse3 = new QDoubleSpinBox(frame);
        diffuse3->setObjectName(QString::fromUtf8("diffuse3"));
        diffuse3->setMaximum(1);
        diffuse3->setSingleStep(0.1);

        gridLayout->addWidget(diffuse3, 4, 3, 1, 1);

        diffuse4 = new QDoubleSpinBox(frame);
        diffuse4->setObjectName(QString::fromUtf8("diffuse4"));
        diffuse4->setMaximum(1);
        diffuse4->setSingleStep(0.1);

        gridLayout->addWidget(diffuse4, 4, 4, 1, 1);

        cb_type = new QComboBox(frame);
        cb_type->setObjectName(QString::fromUtf8("cb_type"));

        gridLayout->addWidget(cb_type, 1, 1, 1, 4);

        line_name = new QLineEdit(frame);
        line_name->setObjectName(QString::fromUtf8("line_name"));

        gridLayout->addWidget(line_name, 0, 1, 1, 4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        y = new QDoubleSpinBox(frame);
        y->setObjectName(QString::fromUtf8("y"));
        y->setMaximum(1000);

        gridLayout_2->addWidget(y, 1, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        x = new QDoubleSpinBox(frame);
        x->setObjectName(QString::fromUtf8("x"));
        x->setMaximum(1000);

        gridLayout_2->addWidget(x, 0, 1, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        z = new QDoubleSpinBox(frame);
        z->setObjectName(QString::fromUtf8("z"));
        z->setMaximum(1000);

        gridLayout_2->addWidget(z, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 1, 1, 4);

        specular2 = new QDoubleSpinBox(frame);
        specular2->setObjectName(QString::fromUtf8("specular2"));
        specular2->setSingleStep(0.1);

        gridLayout->addWidget(specular2, 3, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(NewLightWindowQt);
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


        retranslateUi(NewLightWindowQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewLightWindowQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewLightWindowQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewLightWindowQt);
    } // setupUi

    void retranslateUi(QDialog *NewLightWindowQt)
    {
        NewLightWindowQt->setWindowTitle(QApplication::translate("NewLightWindowQt", "Dialog", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NewLightWindowQt", "Specular", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewLightWindowQt", "Name", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NewLightWindowQt", "Type", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NewLightWindowQt", "Diffuse", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewLightWindowQt", "Position", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NewLightWindowQt", "Ambient", 0, QApplication::UnicodeUTF8));
        cb_type->clear();
        cb_type->insertItems(0, QStringList()
         << QApplication::translate("NewLightWindowQt", "NORMAL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewLightWindowQt", "SWIVEL", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("NewLightWindowQt", "X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewLightWindowQt", "Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewLightWindowQt", "Z", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewLightWindowQt: public Ui_NewLightWindowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLIGHTWINDOWQT_H
