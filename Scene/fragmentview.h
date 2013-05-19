/*
 * Archivo: fragmentview.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: FragmentView
 * Descripcion: Clase que permitira dividir la pantalla en varios puntos de vista diferentes.
 */


#ifndef FRAGMENTVIEW_H
#define FRAGMENTVIEW_H

class FragmentView
{
public:
    // ================= Constructores/Destructores ======================
    FragmentView();
    FragmentView(const FragmentView& fragmentView);
    ~FragmentView();
    // ============================ Methods ===============================
    void render();
private:
    // ========================== Data Members ============================
    // ============================ Methods ===============================
};

#endif // FRAGMENTVIEW_H
