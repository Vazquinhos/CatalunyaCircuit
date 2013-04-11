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
    // ================= Constructores/Destructores ======================
    explicit CarsWindowQt(QWidget *parent = 0);
    ~CarsWindowQt();
    
private slots:
    // ============================ Slots ===============================
    void on_pushButton_4_clicked();

private:
    Ui::CarsWindowQt *ui;
    // ============================ Methods ===============================
};

#endif // CARSWINDOWQT_H
