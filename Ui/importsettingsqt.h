#ifndef IMPORTSETTINGSQT_H
#define IMPORTSETTINGSQT_H

#include <QDialog>
#include "Loaders/settingsimporter.h"

namespace Ui {
class ImportSettingsQt;
}

class ImportSettingsQt : public QDialog
{
    Q_OBJECT
    
public:
    // ================= Constructores/Destructores ======================
    explicit ImportSettingsQt(QWidget *parent = 0);
    ~ImportSettingsQt();
    
private slots:
    // ============================ Slots ===============================
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void errorAcepted();

private:
    // ========================== Data Members ============================
    Ui::ImportSettingsQt *ui;
    SettingsImporter * _p_settingsImporter;
    // ============================ Methods ===============================

signals:
};

#endif // IMPORTSETTINGSQT_H
