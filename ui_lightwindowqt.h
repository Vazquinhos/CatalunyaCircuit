/********************************************************************************
** Form generated from reading UI file 'lightwindowqt.ui'
**
** Created: Mon May 27 02:13:07 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTWINDOWQT_H
#define UI_LIGHTWINDOWQT_H

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
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LightWindowQt
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pb_add;
    QPushButton *pb_delete;
    QPushButton *pushButton;
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
    QDialogButtonBox *buttonBox_2;

    void setupUi(QDialog *LightWindowQt)
    {
        if (LightWindowQt->objectName().isEmpty())
            LightWindowQt->setObjectName(QString::fromUtf8("LightWindowQt"));
        LightWindowQt->resize(617, 342);
        LightWindowQt->setStyleSheet(QString::fromUtf8("QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout_3 = new QVBoxLayout(LightWindowQt);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(LightWindowQt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(200, 0));
        listWidget->setMaximumSize(QSize(16777215, 200));
        listWidget->setStyleSheet(QString::fromUtf8("QListView {\n"
"     show-decoration-selected: 1; /* make the selection span the entire width of the view */\n"
" }\n"
"\n"
" QListView::item:alternate {\n"
"     background: #FFFFFF;\n"
" }\n"
"\n"
" QListView::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
" QListView::item:selected:!active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
" }\n"
"\n"
" QListView::item:selected:active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
" }\n"
"\n"
" QListView::item:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"	 color:black;\n"
" }"));

        verticalLayout->addWidget(listWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pb_add = new QPushButton(frame);
        pb_add->setObjectName(QString::fromUtf8("pb_add"));
        pb_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #333333;\n"
"	 border: 1px solid white;\n"
"	 color:white;\n"
" }\n"
"\n"
"QPushButton:pressed {\n"
"     background-color: #FFFFFF\n"
"     border-style: inset;\n"
"	 color:black;\n"
" }\n"
"\n"
"QFrame {\n"
"     border: 1px solid white;\n"
"	background-color:#333333;\n"
" }"));

        verticalLayout_2->addWidget(pb_add);

        pb_delete = new QPushButton(frame);
        pb_delete->setObjectName(QString::fromUtf8("pb_delete"));
        pb_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(pb_delete);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

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


        verticalLayout_3->addWidget(frame);

        buttonBox_2 = new QDialogButtonBox(LightWindowQt);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox_2);


        retranslateUi(LightWindowQt);

        QMetaObject::connectSlotsByName(LightWindowQt);
    } // setupUi

    void retranslateUi(QDialog *LightWindowQt)
    {
        LightWindowQt->setWindowTitle(QApplication::translate("LightWindowQt", "Dialog", 0, QApplication::UnicodeUTF8));
        pb_add->setText(QApplication::translate("LightWindowQt", "Add Light", 0, QApplication::UnicodeUTF8));
        pb_delete->setText(QApplication::translate("LightWindowQt", "Delete Light", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LightWindowQt", "Set as Active", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LightWindowQt", "Specular", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LightWindowQt", "Name", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LightWindowQt", "Type", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("LightWindowQt", "Diffuse", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LightWindowQt", "Position", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LightWindowQt", "Ambient", 0, QApplication::UnicodeUTF8));
        cb_type->clear();
        cb_type->insertItems(0, QStringList()
         << QApplication::translate("LightWindowQt", "NORMAL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LightWindowQt", "SWIVEL", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("LightWindowQt", "X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LightWindowQt", "Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LightWindowQt", "Z", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LightWindowQt: public Ui_LightWindowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTWINDOWQT_H
