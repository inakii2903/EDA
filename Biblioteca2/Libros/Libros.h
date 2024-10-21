#ifndef NLIBROS
    #define NLIBROS

//Include de Curses
#include <ncursesw/curses.h>

//Include para dibujar los menus
#include "..\Ventanas\Ventanas.h"

//Protoripos de funciones de Libro
void Libros(LIBRO **);
void LimpiarLibro(WINDOW *);
void NuevoLibro(WINDOW *, LIBRO **);

#endif