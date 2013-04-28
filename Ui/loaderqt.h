#ifndef LOADERQT_H
#define LOADERQT_H

#include <QWidget>

namespace Ui {
class LoaderQt;
}

class LoaderQt : public QWidget
{
    Q_OBJECT
    
public:
    explicit LoaderQt(QWidget *parent = 0);
    ~LoaderQt();
    
private:
    Ui::LoaderQt *ui;
};

#endif // LOADERQT_H
