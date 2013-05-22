/********************************************************************************
** Form generated from reading UI file 'camerawindowqt.ui'
**
** Created: Wed May 22 12:41:09 2013
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
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraWindowQt
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pb_add;
    QPushButton *pb_delete;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QDoubleSpinBox *sb_pitch;
    QDoubleSpinBox *cb_zoom;
    QLineEdit *line_name;
    QComboBox *cb_mode;
    QLabel *label;
    QLabel *label_10;
    QLabel *label_6;
    QDoubleSpinBox *sb_yaw;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *x;
    QLabel *label_4;
    QDoubleSpinBox *y;
    QLabel *label_5;
    QDoubleSpinBox *z;
    QLabel *label_3;
    QComboBox *cb_type;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CameraWindowQt)
    {
        if (CameraWindowQt->objectName().isEmpty())
            CameraWindowQt->setObjectName(QString::fromUtf8("CameraWindowQt"));
        CameraWindowQt->resize(791, 371);
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
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(200, 150));

        horizontalLayout_10->addWidget(widget);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
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

        horizontalLayout_2->addWidget(listWidget);

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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, -1, 10, 10);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        sb_pitch = new QDoubleSpinBox(frame);
        sb_pitch->setObjectName(QString::fromUtf8("sb_pitch"));
        sb_pitch->setMaximum(1000);

        gridLayout->addWidget(sb_pitch, 3, 1, 1, 1);

        cb_zoom = new QDoubleSpinBox(frame);
        cb_zoom->setObjectName(QString::fromUtf8("cb_zoom"));
        cb_zoom->setMaximum(1000);

        gridLayout->addWidget(cb_zoom, 5, 1, 1, 1);

        line_name = new QLineEdit(frame);
        line_name->setObjectName(QString::fromUtf8("line_name"));

        gridLayout->addWidget(line_name, 0, 1, 1, 1);

        cb_mode = new QComboBox(frame);
        cb_mode->setObjectName(QString::fromUtf8("cb_mode"));

        gridLayout->addWidget(cb_mode, 1, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        sb_yaw = new QDoubleSpinBox(frame);
        sb_yaw->setObjectName(QString::fromUtf8("sb_yaw"));
        sb_yaw->setMaximum(1000);

        gridLayout->addWidget(sb_yaw, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        x = new QDoubleSpinBox(frame);
        x->setObjectName(QString::fromUtf8("x"));
        x->setMaximum(1000);

        horizontalLayout_3->addWidget(x);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        y = new QDoubleSpinBox(frame);
        y->setObjectName(QString::fromUtf8("y"));
        y->setMaximum(1000);

        horizontalLayout_3->addWidget(y);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        z = new QDoubleSpinBox(frame);
        z->setObjectName(QString::fromUtf8("z"));
        z->setMaximum(1000);

        horizontalLayout_3->addWidget(z);


        gridLayout->addLayout(horizontalLayout_3, 6, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        cb_type = new QComboBox(frame);
        cb_type->setObjectName(QString::fromUtf8("cb_type"));

        gridLayout->addWidget(cb_type, 4, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        horizontalLayout_5->addLayout(horizontalLayout);


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
        label_9->setText(QApplication::translate("CameraWindowQt", "Zoom", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CameraWindowQt", "Pich", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CameraWindowQt", "Yaw", 0, QApplication::UnicodeUTF8));
        cb_mode->clear();
        cb_mode->insertItems(0, QStringList()
         << QApplication::translate("CameraWindowQt", "PERSPECTIVE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWindowQt", "ORTOGONAL", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("CameraWindowQt", "Name", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CameraWindowQt", "Mode", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CameraWindowQt", "Type", 0, QApplication::UnicodeUTF8));
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
    } // retranslateUi

};

namespace Ui {
    class CameraWindowQt: public Ui_CameraWindowQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWINDOWQT_H
