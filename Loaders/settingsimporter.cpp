#include "settingsimporter.h".h"

#include <QTextStream>
#include <QFile>
#include "Cameras/cameramanager.h"
#include "Cameras/freecamera.h"
#include "Cameras/fixedcamera.h"
#include "Cameras/sphericalcamera.h"
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

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Extracts the value between 2 tags (<>value<>)
 |  Parameters[in]: in: input string (<>value<>)
 |                  size: size of input string
 |  Parameters[out]: out: output string (value)
 *-------------------------------------------------------------------*/

void
stractValue(char in[], char out[], int size)
{
    bool value = false;
    int i;
    int j = 0;

    for(i=0; i<size; ++i)
    {
        if(in[i] == '<' && value)
        {
            value = false;
            break;
        }
        if(value)
        {
            out[j] = in[i];
            ++j;
        }
        if(in[i] == '>')
            value = true;
    }
    out[j] = '\0';
}

void
SettingsImporter::Execute( void )
{
    qDebug() << "EXECUTE!";

    char buff[256];

    QFile * file = new QFile(_fileName);
    file->open(QIODevice::ReadOnly);
    int exit = 1;

    while (exit > 0)
    {
        exit = file->readLine(buff, 256);

        if(strcmp(buff,"<Catalunya Circuit Settings>\n")==0)
        {
            exit = file->readLine(buff, 256);
            while( strcmp(buff,"</Catalunya Circuit Settings>\n")!=0 && exit > 0)
            {
                if(_cameras && (strcmp(buff, "<cameras>\n")==0) )
                {
                    qDebug() << "ok!";
                    exit = file->readLine(buff, 256);
                    while(strcmp(buff,"</cameras>\n") != 0 && exit > 0 )
                    {
                        if(strcmp(buff,"<camera>\n") == 0)
                        {
                            CameraAbs *newCamera;
                            //Leyendo Type
                            exit = file->readLine(buff, 256);
                            char type[30];
                            stractValue(buff, type, 256);
                            qDebug() << type;
                            //Leyendo Nombre
                            exit = file->readLine(buff, 256);
                            char name[30];
                            stractValue(buff, name, 256);
                            qDebug() << name;

                            if(strcmp(type, "FreeCamera"))
                                newCamera = new FreeCamera(QString(name));
                            else if(strcmp(type, "FixedCamera"))
                                newCamera = new FixedCamera(QString(name));
                            else if(strcmp(type, "SphericalCamera"))
                                newCamera = new SphericalCamera(QString(name));
                            else
                            {
                                qDebug() << "Camaras con error de formato";
                                break;
                            }

                            char number[30];
                            QString Qnumber;
                            float x,y,z,yaw,pitch,zoom;
                            //Posicion
                            exit = file->readLine(buff, 256);
                            exit = file->readLine(buff, 256);   //x
                            stractValue(buff, number, 256);
                            Qnumber = QString(number);
                            x = Qnumber.toFloat();

                            exit = file->readLine(buff, 256);   //y
                            stractValue(buff, number, 256);
                            Qnumber = QString(number);
                            y = Qnumber.toFloat();

                            exit = file->readLine(buff, 256);   //z
                            stractValue(buff, number, 256);
                            Qnumber = QString(number);
                            z = Qnumber.toFloat();

                            newCamera->setPosition(new Point3D(x,y,z));

                            exit = file->readLine(buff, 256);
                            //Yaw
                            exit = file->readLine(buff, 256);   //yaw
                            stractValue(buff, number, 256);
                            Qnumber = QString(number);
                            yaw = Qnumber.toFloat();

                            newCamera->setYaw(yaw);

                            //Pitch
                            exit = file->readLine(buff, 256);   //pitch
                            stractValue(buff, number, 256);
                            Qnumber = QString(number);
                            pitch = Qnumber.toFloat();

                            newCamera->setPitch(pitch);

                            //Zoom
                            exit = file->readLine(buff, 256);   //Zoom
                            stractValue(buff, number, 256);
                            Qnumber = QString(number);
                            zoom = Qnumber.toFloat();

                            newCamera->setZoom(zoom);
                            CameraManager::getCameraManager()->addCamera(name, newCamera);
                        }
                        exit = file->readLine(buff, 256);
                    }

                } else if(_cars && (strcmp(buff, "<cars>\n")) )
                {
                    exit = file->readLine(buff, 256);
                    while(strcmp(buff,"</cars>\n") != 0 && exit > 0)
                    {

                    }

                } else if(_lights && (strcmp(buff, "<lights>\n")) )
                {
                    exit = file->readLine(buff, 256);
                    while(strcmp(buff,"</lights>\n") != 0 && exit > 0)
                    {

                    }

                }

                exit = file->readLine(buff, 256);
            }
        }

    }
    file->close();
}
