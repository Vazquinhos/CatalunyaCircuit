#include "trajectselectionqt.h"
#include "ui_trajectselectionqt.h"

#include <QFileDialog>

TrajectSelectionQt::TrajectSelectionQt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrajectSelectionQt)
{
    ui->setupUi(this);
    setWindowTitle("Traject selection..");
}

TrajectSelectionQt::~TrajectSelectionQt()
{
    delete ui;
}

void TrajectSelectionQt::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Select..."), "/home/", tr("Traject Files (*.obj *.txt)"));
    ui->lineEdit->setText(fileName);
}
