#ifndef THOTHWINDOW_H
#define THOTHWINDOW_H

#include <QMainWindow>

namespace Ui {
class ThothWindow;
}

class OpenGLwindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit OpenGLwindow(QWidget *parent = 0);
    ~OpenGLwindow();
    
private:
    Ui::ThothWindow *ui;
};

#endif // THOTHWINDOW_H
