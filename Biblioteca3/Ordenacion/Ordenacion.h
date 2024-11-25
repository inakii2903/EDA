#ifndef NORDENACION
    #define NORDENACION

//Include de Curses
#include <ncursesw/curses.h>

//Include para dibujar los menus
#include "..\Ventanas\Ventanas.h"

//Prototipos de funciones de Ordenacion
LIBRO **Seleccion(LIBRO *, int);
LIBRO **Burbuja(LIBRO *, int);
LIBRO **Insercion(LIBRO *, int);
LIBRO **Quicksort(LIBRO *, int);
LIBRO **InitOrden(LIBRO *);

#endif