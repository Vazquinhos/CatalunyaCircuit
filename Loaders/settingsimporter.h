#ifndef SETTINGSIMPORTER_H
#define SETTINGSEXPORTER_H

#include <QString>
#include <QTextStream>

class SettingsImporter
{
public:
    // ================= Constructores/Destructores ======================
    SettingsImporter( QString a_fileName );
    ~SettingsImporter();

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

#endif //SETTINGSIMPORTER_H
