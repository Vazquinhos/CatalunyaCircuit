#ifndef IMPORTSETTINGSQT_H
#define IMPORTSETTINGSQT_H

#include <QDialog>

namespace Ui {
class ImportSettingsQt;
}

class ImportSettingsQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImportSettingsQt(QWidget *parent = 0);
    ~ImportSettingsQt();
    
private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::ImportSettingsQt *ui;
};

#endif // IMPORTSETTINGSQT_H
