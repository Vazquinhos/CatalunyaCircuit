/********************************************************************************
** Form generated from reading UI file 'lightswindowqt.ui'
**
** Created: Tue Apr 9 22:47:54 2013
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LightsWidowQt
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *_lineEdit_name;
    QFrame *line_5;
    QTableView *lightview;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *add_pb;
    QPushButton *delete_pb;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_3;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QDoubleSpinBox *_color_blue;
    QDoubleSpinBox *_color_alpha;
    QDoubleSpinBox *_color_red;
    QDoubleSpinBox *_color_green;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *ambient_cb;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *sb_ambient3;
    QDoubleSpinBox *sb_ambient4;
    QDoubleSpinBox *sb_ambient1;
    QDoubleSpinBox *sb_ambient2;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_3;
    QCheckBox *specular_cb;
    QDoubleSpinBox *sb_specular3;
    QDoubleSpinBox *sb_specular1;
    QDoubleSpinBox *sb_specular2;
    QDoubleSpinBox *sb_specular4;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *sb_diffuse1;
    QDoubleSpinBox *sb_diffuse3;
    QCheckBox *diffuse_cb;
    QDoubleSpinBox *sb_diffuse2;
    QDoubleSpinBox *sb_diffuse4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LightsWidowQt)
    {
        if (LightsWidowQt->objectName().isEmpty())
            LightsWidowQt->setObjectName(QString::fromUtf8("LightsWidowQt"));
        LightsWidowQt->resize(531, 472);
        verticalLayout = new QVBoxLayout(LightsWidowQt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(LightsWidowQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        _lineEdit_name = new QLineEdit(frame);
        _lineEdit_name->setObjectName(QString::fromUtf8("_lineEdit_name"));

        horizontalLayout->addWidget(_lineEdit_name);


        verticalLayout_3->addLayout(horizontalLayout);

        line_5 = new QFrame(frame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_5);

        lightview = new QTableView(frame);
        lightview->setObjectName(QString::fromUtf8("lightview"));
        lightview->horizontalHeader()->setVisible(false);

        verticalLayout_3->addWidget(lightview);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        add_pb = new QPushButton(frame);
        add_pb->setObjectName(QString::fromUtf8("add_pb"));

        horizontalLayout_5->addWidget(add_pb);

        delete_pb = new QPushButton(frame);
        delete_pb->setObjectName(QString::fromUtf8("delete_pb"));

        horizontalLayout_5->addWidget(delete_pb);


        verticalLayout_3->addLayout(horizontalLayout_5);

        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_6);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        horizontalLayout_7->addWidget(doubleSpinBox);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_7);

        doubleSpinBox_2 = new QDoubleSpinBox(frame);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        horizontalLayout_7->addWidget(doubleSpinBox_2);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_8);

        doubleSpinBox_3 = new QDoubleSpinBox(frame);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        horizontalLayout_7->addWidget(doubleSpinBox_3);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(verticalLayout_3);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        _color_blue = new QDoubleSpinBox(frame);
        _color_blue->setObjectName(QString::fromUtf8("_color_blue"));

        gridLayout->addWidget(_color_blue, 1, 1, 1, 1);

        _color_alpha = new QDoubleSpinBox(frame);
        _color_alpha->setObjectName(QString::fromUtf8("_color_alpha"));

        gridLayout->addWidget(_color_alpha, 1, 3, 1, 1);

        _color_red = new QDoubleSpinBox(frame);
        _color_red->setObjectName(QString::fromUtf8("_color_red"));

        gridLayout->addWidget(_color_red, 0, 1, 1, 1);

        _color_green = new QDoubleSpinBox(frame);
        _color_green->setObjectName(QString::fromUtf8("_color_green"));

        gridLayout->addWidget(_color_green, 0, 3, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);


        verticalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        ambient_cb = new QCheckBox(frame);
        ambient_cb->setObjectName(QString::fromUtf8("ambient_cb"));

        verticalLayout_5->addWidget(ambient_cb);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sb_ambient3 = new QDoubleSpinBox(frame);
        sb_ambient3->setObjectName(QString::fromUtf8("sb_ambient3"));

        gridLayout_2->addWidget(sb_ambient3, 1, 0, 1, 1);

        sb_ambient4 = new QDoubleSpinBox(frame);
        sb_ambient4->setObjectName(QString::fromUtf8("sb_ambient4"));

        gridLayout_2->addWidget(sb_ambient4, 1, 1, 1, 1);

        sb_ambient1 = new QDoubleSpinBox(frame);
        sb_ambient1->setObjectName(QString::fromUtf8("sb_ambient1"));

        gridLayout_2->addWidget(sb_ambient1, 0, 0, 1, 1);

        sb_ambient2 = new QDoubleSpinBox(frame);
        sb_ambient2->setObjectName(QString::fromUtf8("sb_ambient2"));

        gridLayout_2->addWidget(sb_ambient2, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);


        verticalLayout_7->addLayout(verticalLayout_5);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        specular_cb = new QCheckBox(frame);
        specular_cb->setObjectName(QString::fromUtf8("specular_cb"));

        gridLayout_3->addWidget(specular_cb, 0, 0, 1, 2);

        sb_specular3 = new QDoubleSpinBox(frame);
        sb_specular3->setObjectName(QString::fromUtf8("sb_specular3"));

        gridLayout_3->addWidget(sb_specular3, 2, 0, 1, 1);

        sb_specular1 = new QDoubleSpinBox(frame);
        sb_specular1->setObjectName(QString::fromUtf8("sb_specular1"));

        gridLayout_3->addWidget(sb_specular1, 1, 0, 1, 1);

        sb_specular2 = new QDoubleSpinBox(frame);
        sb_specular2->setObjectName(QString::fromUtf8("sb_specular2"));

        gridLayout_3->addWidget(sb_specular2, 1, 1, 1, 1);

        sb_specular4 = new QDoubleSpinBox(frame);
        sb_specular4->setObjectName(QString::fromUtf8("sb_specular4"));

        gridLayout_3->addWidget(sb_specular4, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        sb_diffuse1 = new QDoubleSpinBox(frame);
        sb_diffuse1->setObjectName(QString::fromUtf8("sb_diffuse1"));

        gridLayout_4->addWidget(sb_diffuse1, 1, 0, 1, 1);

        sb_diffuse3 = new QDoubleSpinBox(frame);
        sb_diffuse3->setObjectName(QString::fromUtf8("sb_diffuse3"));

        gridLayout_4->addWidget(sb_diffuse3, 2, 0, 1, 1);

        diffuse_cb = new QCheckBox(frame);
        diffuse_cb->setObjectName(QString::fromUtf8("diffuse_cb"));

        gridLayout_4->addWidget(diffuse_cb, 0, 0, 1, 2);

        sb_diffuse2 = new QDoubleSpinBox(frame);
        sb_diffuse2->setObjectName(QString::fromUtf8("sb_diffuse2"));

        gridLayout_4->addWidget(sb_diffuse2, 1, 1, 1, 1);

        sb_diffuse4 = new QDoubleSpinBox(frame);
        sb_diffuse4->setObjectName(QString::fromUtf8("sb_diffuse4"));

        gridLayout_4->addWidget(sb_diffuse4, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);


        verticalLayout_7->addLayout(verticalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(LightsWidowQt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

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
        label_2->setText(QApplication::translate("LightsWidowQt", "Color", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LightsWidowQt", "R", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LightsWidowQt", "G", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("LightsWidowQt", "B", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("LightsWidowQt", "A", 0, QApplication::UnicodeUTF8));
        ambient_cb->setText(QApplication::translate("LightsWidowQt", "Ambient", 0, QApplication::UnicodeUTF8));
        specular_cb->setText(QApplication::translate("LightsWidowQt", "Specular", 0, QApplication::UnicodeUTF8));
        diffuse_cb->setText(QApplication::translate("LightsWidowQt", "Diffuse", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LightsWidowQt: public Ui_LightsWidowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTSWINDOWQT_H
