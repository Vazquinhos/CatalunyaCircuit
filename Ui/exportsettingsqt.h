#ifndef EXPORTSETTINGSQT_H
#define EXPORTSETTINGSQT_H

#include <QDialog>
#include "ui_exportsettingsqt.h"
#include "Loaders/settingsexporter.h"

namespace Ui {
class ExportSettingsQt;
}

class ExportSettingsQt : public QDialog, public Ui::ExportSettingsQt
{
    Q_OBJECT
    
public:
    explicit ExportSettingsQt(QWidget *parent = 0);
    ~ExportSettingsQt();
    
private slots:
    // ============================ Slots ===============================
    void on_buttonBox_accepted();

private:
    // ========================== Data Members ============================
    Ui::ExportSettingsQt *ui;
    bool CheckFileNameSelected();

    SettingsExporter* _p_exporter;

    QString _fileName;
    // ============================ Methods ===============================
    QString GetFileNameWithExtension( QString a_fileName );
signals:
};

#endif // EXPORTSETTINGSQT_H
