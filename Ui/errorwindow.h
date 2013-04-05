#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QDialog>

namespace Ui {
class ErrorWindow;
}

class ErrorWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit ErrorWindow(QWidget *parent = 0);
    ~ErrorWindow();
    void SetErrorMsg( QString a_error_msg );
    void ShowWindow( void );
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::ErrorWindow *ui;
    QWidget* _p_parent;
};

#endif // ERRORWINDOW_H
