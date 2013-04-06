/********************************************************************************
** Form generated from reading UI file 'lightswindowqt.ui'
**
** Created: Sat Apr 6 20:35:36 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTSWINDOWQT_H
#define UI_LIGHTSWINDOWQT_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LightsWidowQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QTableView *lightview;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *_lineEdit_name;
    QVBoxLayout *verticalLayout_3;
    QPushButton *add_pb;
    QPushButton *delete_pb;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *x_sb;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QSpinBox *y_sb;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QSpinBox *z_sb;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_3;
    QSpinBox *specular_sb3;
    QCheckBox *specular_cb;
    QSpinBox *specular_sb4;
    QSpinBox *specular_sb2;
    QSpinBox *specular_sb1;
    QFrame *line;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *ambient_cb;
    QGridLayout *gridLayout_2;
    QSpinBox *ambient_sb2;
    QSpinBox *ambient_sb1;
    QSpinBox *ambient_sb3;
    QSpinBox *ambient_sb4;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QSpinBox *colors_sb2;
    QSpinBox *colors_sb1;
    QSpinBox *colors_sb3;
    QSpinBox *colors_sb4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LightsWidowQt)
    {
        if (LightsWidowQt->objectName().isEmpty())
            LightsWidowQt->setObjectName(QString::fromUtf8("LightsWidowQt"));
        LightsWidowQt->resize(731, 387);
        verticalLayout = new QVBoxLayout(LightsWidowQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(LightsWidowQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lightview = new QTableView(frame);
        lightview->setObjectName(QString::fromUtf8("lightview"));
        lightview->horizontalHeader()->setVisible(true);

        horizontalLayout_6->addWidget(lightview);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        _lineEdit_name = new QLineEdit(frame);
        _lineEdit_name->setObjectName(QString::fromUtf8("_lineEdit_name"));

        horizontalLayout->addWidget(_lineEdit_name);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        add_pb = new QPushButton(frame);
        add_pb->setObjectName(QString::fromUtf8("add_pb"));

        verticalLayout_3->addWidget(add_pb);

        delete_pb = new QPushButton(frame);
        delete_pb->setObjectName(QString::fromUtf8("delete_pb"));

        verticalLayout_3->addWidget(delete_pb);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_8->addLayout(horizontalLayout);

        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        x_sb = new QSpinBox(frame);
        x_sb->setObjectName(QString::fromUtf8("x_sb"));

        horizontalLayout_2->addWidget(x_sb);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_7);

        y_sb = new QSpinBox(frame);
        y_sb->setObjectName(QString::fromUtf8("y_sb"));

        horizontalLayout_3->addWidget(y_sb);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_8);

        z_sb = new QSpinBox(frame);
        z_sb->setObjectName(QString::fromUtf8("z_sb"));

        horizontalLayout_4->addWidget(z_sb);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_3);


        horizontalLayout_6->addLayout(verticalLayout_8);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        specular_sb3 = new QSpinBox(frame);
        specular_sb3->setObjectName(QString::fromUtf8("specular_sb3"));

        gridLayout_3->addWidget(specular_sb3, 2, 0, 1, 1);

        specular_cb = new QCheckBox(frame);
        specular_cb->setObjectName(QString::fromUtf8("specular_cb"));

        gridLayout_3->addWidget(specular_cb, 0, 0, 1, 1);

        specular_sb4 = new QSpinBox(frame);
        specular_sb4->setObjectName(QString::fromUtf8("specular_sb4"));

        gridLayout_3->addWidget(specular_sb4, 2, 1, 1, 1);

        specular_sb2 = new QSpinBox(frame);
        specular_sb2->setObjectName(QString::fromUtf8("specular_sb2"));

        gridLayout_3->addWidget(specular_sb2, 1, 1, 1, 1);

        specular_sb1 = new QSpinBox(frame);
        specular_sb1->setObjectName(QString::fromUtf8("specular_sb1"));

        gridLayout_3->addWidget(specular_sb1, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_4);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        ambient_cb = new QCheckBox(frame);
        ambient_cb->setObjectName(QString::fromUtf8("ambient_cb"));

        verticalLayout_5->addWidget(ambient_cb);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ambient_sb2 = new QSpinBox(frame);
        ambient_sb2->setObjectName(QString::fromUtf8("ambient_sb2"));

        gridLayout_2->addWidget(ambient_sb2, 0, 1, 1, 1);

        ambient_sb1 = new QSpinBox(frame);
        ambient_sb1->setObjectName(QString::fromUtf8("ambient_sb1"));

        gridLayout_2->addWidget(ambient_sb1, 0, 0, 1, 1);

        ambient_sb3 = new QSpinBox(frame);
        ambient_sb3->setObjectName(QString::fromUtf8("ambient_sb3"));

        gridLayout_2->addWidget(ambient_sb3, 1, 0, 1, 1);

        ambient_sb4 = new QSpinBox(frame);
        ambient_sb4->setObjectName(QString::fromUtf8("ambient_sb4"));

        gridLayout_2->addWidget(ambient_sb4, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_5);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        colors_sb2 = new QSpinBox(frame);
        colors_sb2->setObjectName(QString::fromUtf8("colors_sb2"));

        gridLayout->addWidget(colors_sb2, 0, 1, 1, 1);

        colors_sb1 = new QSpinBox(frame);
        colors_sb1->setObjectName(QString::fromUtf8("colors_sb1"));

        gridLayout->addWidget(colors_sb1, 0, 0, 1, 1);

        colors_sb3 = new QSpinBox(frame);
        colors_sb3->setObjectName(QString::fromUtf8("colors_sb3"));

        gridLayout->addWidget(colors_sb3, 1, 0, 1, 1);

        colors_sb4 = new QSpinBox(frame);
        colors_sb4->setObjectName(QString::fromUtf8("colors_sb4"));

        gridLayout->addWidget(colors_sb4, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(LightsWidowQt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(LightsWidowQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), LightsWidowQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LightsWidowQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(LightsWidowQt);
    } // setupUi

    void retranslateUi(QDialog *LightsWidowQt)
    {
        LightsWidowQt->setWindowTitle(QApplication::translate("LightsWidowQt", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LightsWidowQt", "Name", 0, QApplication::UnicodeUTF8));
        add_pb->setText(QApplication::translate("LightsWidowQt", " Add Light", 0, QApplication::UnicodeUTF8));
        delete_pb->setText(QApplication::translate("LightsWidowQt", "Delete Light", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LightsWidowQt", "Position", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LightsWidowQt", "X", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LightsWidowQt", "Y", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LightsWidowQt", "Z", 0, QApplication::UnicodeUTF8));
        specular_cb->setText(QApplication::translate("LightsWidowQt", "Specular", 0, QApplication::UnicodeUTF8));
        ambient_cb->setText(QApplication::translate("LightsWidowQt", "Ambient", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LightsWidowQt", "Color", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LightsWidowQt: public Ui_LightsWidowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTSWINDOWQT_H
