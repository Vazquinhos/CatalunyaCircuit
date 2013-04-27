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
    // ================= Constructores/Destructores ======================
    explicit ErrorWindow(QWidget *parent = 0);
    ~ErrorWindow();
    void SetErrorMsg( QString a_error_msg );
    void ShowWindow( void );
    
private slots:
    // ============================ Slots ===============================
    void on_buttonBox_accepted();

private:
    // ========================== Data Members ============================
    Ui::ErrorWindow *ui;

signals:
    void ErrorAcepted( void );
};

#endif // ERRORWINDOW_H
