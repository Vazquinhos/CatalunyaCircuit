#ifndef LIGHTWINDOWQT_H
#define LIGHTWINDOWQT_H

#include <QDialog>
#include "Lights/lightmanager.h"
#include "Lights/light.h"
#include <QListWidgetItem>
#include <QString>

namespace Ui {
class LightWindowQt;
}

class LightWindowQt : public QDialog
{
    Q_OBJECT
    
public:
    explicit LightWindowQt(QWidget *parent = 0);
    ~LightWindowQt();
    void UpdateWidgetsWithLight( Light* ap_light );
    void LoadWindow(std::map<QString,Light*> a_lights);

private slots:
    void on_line_name_editingFinished();

    void on_cb_type_currentIndexChanged(const QString &arg1);

    void ambientChanged(double a);

    void specularChanged( double a);

    void diffuseChanged( double a);

    void positionChanged(double a );

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

    void on_pb_add_clicked();

    void NewLightCreated( Light* light );

    void on_pb_delete_clicked();

    void on_pushButton_clicked();

private:
    Ui::LightWindowQt *ui;

    Light* getLightFromQt();
};

#endif // LIGHTWINDOWQT_H
