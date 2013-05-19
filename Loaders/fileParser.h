/*
 * Archivo: fileParser.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: FILEParser
 * Descripcion: Clase abstracta que nos permite encapsular la lectura del fichero XML.
 * Los hijos tansolo tienen que sobreescribir el método OnTagRecived dependiendo lo que
 * quieran hacer y
 */


#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "Utils/util.h"
#include "QString"
#include <stdio.h>
#include <string>

class FILEParser
{
public:
    // ================= Constructores/Destructores ======================
    FILEParser();
    FILEParser( std::string a_filename);
    ~FILEParser();

    // ============================ Methods ===============================
    std::string         getFilename();
    void                setFilename(std::string filename);
    int Parse();
    virtual void OnTagRecived(QString tag, std::map<QString, QString> atributes );

private:
    // ========================== Data Members ============================
    std::string _filename;
    // ============================ Methods ===============================
};

#endif // CAMERASLOADER_H
