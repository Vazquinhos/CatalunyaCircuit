#ifndef SETTINGSEXPORTER_H
#define SETTINGSEXPORTER_H

#include <QString>
#include <QTextStream>

class SettingsExporter
{
public:
    // ================= Constructores/Destructores ======================
    SettingsExporter( QString a_fileName );
    ~SettingsExporter();

    // ============================ Methods ===============================
    void SetParameters( bool a_cameras,
                        bool a_cars,
                        bool a_lights);
    void Execute( void );

private:
    // ========================== Data Members ============================
    bool _cameras;
    bool _cars;
    bool _lights;
    QString _fileName;

    // ============================ Methods ===============================

};

#endif // SETTINGSEXPORTER_H
