/*
 * Archivo: xmlParser.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "fileParser.h"

// ================= Constructores/Destructores ======================

FILEParser::FILEParser()
{

}

FILEParser::FILEParser(std::string a_filename)
{
    _filename = a_filename;
}

FILEParser::~FILEParser()
{

}

// ============================ Methods ===============================

int FILEParser::Parse()
{
    // TODO: Lectura del fichero i separación de los datos en Tag i Atributes.
    // Cuando se lea un tag, se llamara a la funcion virtual OnTagRecived.
    FILE * file;
    bool finalElement = false;
    std::map<QString, QString> atributes;

    file = fopen(_filename.c_str(), "r");
    if(file == NULL)
        return -1;

    char bufferInput[50];

    while(true)
    {
        fscanf(file,"%s", bufferInput);
        QString tag (bufferInput);

        if(bufferInput[0] == '/' || bufferInput[1] == '/')
            break;

        finalElement = false;
        while(!finalElement)
        {
            fscanf(file, "%s", bufferInput);

            if(bufferInput[0] == '/')
            {
                finalElement = true;
            }
            else
            {
                char c = -1;
                int i = 0;
                while(c != '=')
                {
                    i++;
                    c = bufferInput[i];
                }
                QString key (std::string(bufferInput,0,i).c_str());
                QString value (std::string(bufferInput,i+1,49-i).c_str());
                atributes[key] = value;
            }
        }
        OnTagRecived(tag, atributes);
    }
    return 0;
}

std::string FILEParser::getFilename()
{
    return _filename;
}

void FILEParser::setFilename(std::string filename)
{
    _filename = filename;
}

//DEBUG: BASE PARA PRUEVAS. Esta clase sera puramente virtual, igual que la clase sera virtual.

void FILEParser::OnTagRecived(QString tag, std::map<QString, QString> atributes )
{
    //WITH EXAMPLE DATA/config/exampleCamera.txt

    qDebug() << "holamundo";
    qDebug() << tag << "\n";
    if(tag == "FixedCamera")
    {
        qDebug() << "name " << atributes["name"] << "\n";
        qDebug() << "dir " << atributes["dir"] << "\n";
        qDebug() << "pos " << atributes["pos"] << "\n";
    }
    else if(tag == "SphericalCamera")
    {
        qDebug() << "name " << atributes["name"] << "\n";
        qDebug() << "pos " << atributes["pos"] << "\n";
    }
}
