#ifndef CARSWINDOWQT_H
#define CARSWINDOWQT_H

#include <QDialog>

namespace Ui {
class CarsWindowQt;
}

class CarsWindowQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit CarsWindowQt(QWidget *parent = 0);
    ~CarsWindowQt();
    
private slots:
    void on_pushButton_4_clicked();

private:
    Ui::CarsWindowQt *ui;
};

#endif // CARSWINDOWQT_H