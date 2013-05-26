#include "settingsexporter.h"

#include <QTextStream>
#include <QFile>
#include "Cameras/cameramanager.h"
#include "Lights/lightmanager.h"

SettingsExporter::SettingsExporter( QString a_fileName )
{
    _fileName = a_fileName;
    _cameras = false;
    _cars = false;
    _lights = false;
}

SettingsExporter::~SettingsExporter()
{
}

void
SettingsExporter::SetParameters( bool a_cameras,
                                 bool a_cars,
                                 bool a_lights)
{
    _cameras = a_cameras;
    _cars = a_cars;
    _lights = a_lights;
}

void
SettingsExporter::Execute()
{
    QFile file(_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "<Catalunya Circuit Settings>" << endl;
    if( _cameras)
    {
        out << "<cameras>" << endl;

        QString info_cameras = CameraManager::getCameraManager()->getCCSCameraInfoToExport();
        out << info_cameras;
        out << "</cameras>" << endl;
    }
    if( _cars )
    {
        out << "<cars>" << endl;

        out << "</cars>" << endl;
    }
    if( _lights )
    {
        out << "<lights>" << endl;
        QString info_lights = LightManager::getLightManager()->getCCSLightsInfoToExport();
        out << info_lights << endl;
        out << "</lights>" << endl;
    }
    out << "</Catalunya Circuit Settings>" << endl;
}
