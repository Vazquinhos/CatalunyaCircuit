/********************************************************************************
** Form generated from reading UI file 'camerawindowqt.ui'
**
** Created: Fri May 31 19:28:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWINDOWQT_H
#define UI_CAMERAWINDOWQT_H

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

class Ui_CameraWindowQt
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
    QLabel *label_7;
    QDoubleSpinBox *sb_pitch;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *y;
    QLabel *label_2;
    QLabel *label_4;
    QDoubleSpinBox *x;
    QLabel *label_5;
    QDoubleSpinBox *z;
    QLabel *label_3;
    QComboBox *cb_type;
    QLineEdit *line_name;
    QLabel *label;
    QLabel *label_6;
    QDoubleSpinBox *sb_yaw;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CameraWindowQt)
    {
        if (CameraWindowQt->objectName().isEmpty())
            CameraWindowQt->setObjectName(QString::fromUtf8("CameraWindowQt"));
        CameraWindowQt->resize(460, 301);
        CameraWindowQt->setStyleSheet(QString::fromUtf8("QDialog {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }\n"
"\n"
"QFrame {\n"
"     background-color: #333333;\n"
"	 color:white;\n"
" }"));
        verticalLayout_3 = new QVBoxLayout(CameraWindowQt);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(CameraWindowQt);
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

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        sb_pitch = new QDoubleSpinBox(frame);
        sb_pitch->setObjectName(QString::fromUtf8("sb_pitch"));
        sb_pitch->setMaximum(1000);

        gridLayout->addWidget(sb_pitch, 2, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        y = new QDoubleSpinBox(frame);
        y->setObjectName(QString::fromUtf8("y"));
        y->setMinimum(-1e+07);
        y->setMaximum(999999);

        gridLayout_2->addWidget(y, 1, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        x = new QDoubleSpinBox(frame);
        x->setObjectName(QString::fromUtf8("x"));
        x->setMinimum(-99991);
        x->setMaximum(100000);

        gridLayout_2->addWidget(x, 0, 1, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        z = new QDoubleSpinBox(frame);
        z->setObjectName(QString::fromUtf8("z"));
        z->setMinimum(-1e+07);
        z->setMaximum(1e+07);

        gridLayout_2->addWidget(z, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        cb_type = new QComboBox(frame);
        cb_type->setObjectName(QString::fromUtf8("cb_type"));

        gridLayout->addWidget(cb_type, 3, 1, 1, 1);

        line_name = new QLineEdit(frame);
        line_name->setObjectName(QString::fromUtf8("line_name"));

        gridLayout->addWidget(line_name, 0, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        sb_yaw = new QDoubleSpinBox(frame);
        sb_yaw->setObjectName(QString::fromUtf8("sb_yaw"));
        sb_yaw->setMaximum(1000);

        gridLayout->addWidget(sb_yaw, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_3->addWidget(frame);

        buttonBox = new QDialogButtonBox(CameraWindowQt);
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

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(CameraWindowQt);
        QObject::connect(buttonBox, SIGNAL(accepted()), CameraWindowQt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CameraWindowQt, SLOT(reject()));

        QMetaObject::connectSlotsByName(CameraWindowQt);
    } // setupUi

    void retranslateUi(QDialog *CameraWindowQt)
    {
        CameraWindowQt->setWindowTitle(QApplication::translate("CameraWindowQt", "Dialog", 0, QApplication::UnicodeUTF8));
        pb_add->setText(QApplication::translate("CameraWindowQt", "Add Camera", 0, QApplication::UnicodeUTF8));
        pb_delete->setText(QApplication::translate("CameraWindowQt", "Delete Camera", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CameraWindowQt", "Set as Active", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CameraWindowQt", "Pich", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CameraWindowQt", "Yaw", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CameraWindowQt", "X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CameraWindowQt", "Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CameraWindowQt", "Z", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CameraWindowQt", "Position", 0, QApplication::UnicodeUTF8));
        cb_type->clear();
        cb_type->insertItems(0, QStringList()
         << QApplication::translate("CameraWindowQt", "FREE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWindowQt", "SPHERICAL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWindowQt", "FIXED", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("CameraWindowQt", "Name", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CameraWindowQt", "Type", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraWindowQt: public Ui_CameraWindowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWINDOWQT_H
