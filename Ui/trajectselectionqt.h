#ifndef TRAJECTSELECTIONQT_H
#define TRAJECTSELECTIONQT_H

#include <QDialog>

namespace Ui {
class TrajectSelectionQt;
}

class TrajectSelectionQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit TrajectSelectionQt(QWidget *parent = 0);
    ~TrajectSelectionQt();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::TrajectSelectionQt *ui;
};

#endif // TRAJECTSELECTIONQT_H
