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
    void on_buttonBox_accepted();

private:
    Ui::ExportSettingsQt *ui;
    bool CheckFileNameSelected();

    SettingsExporter* _p_exporter;

    QString _fileName;
};

#endif // EXPORTSETTINGSQT_H
