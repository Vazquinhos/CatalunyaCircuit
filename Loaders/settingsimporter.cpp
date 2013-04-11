#include "settingsimporter.h".h"

#include <QTextStream>
#include <QFile>
#include "Cameras/cameramanager.h"
#include "Lights/lightmanager.h"

SettingsImporter::SettingsImporter( QString a_fileName )
{
    _fileName = a_fileName;
    _cameras = false;
    _cars = false;
    _lights = false;
}

SettingsImporter::~SettingsImporter( void )
{
}

void
SettingsImporter::SetParameters( bool a_cameras,
                                 bool a_cars,
                                 bool a_lights)
{
    _cameras = a_cameras;
    _cars = a_cars;
    _lights = a_lights;
}

void
SettingsImporter::Execute( void )
{
    QTextStream in(&_fileName);
    while (!in.atEnd())
    {
        QString line = in.readLine();

        if(line == "<Catalunya Circuit Settings>")
        {
            while(line != "</Catalunya Circuit Settings>" )
            {
                line = in.readLine();
                //TODO: Leer tag <camera>, si _cameras == true, leer las camaras del ccs
                // Crear objeto camara e ir leyendo los atributos de la camara.
                // Hasta que haya un </camera>
            }
        }

    }
}
