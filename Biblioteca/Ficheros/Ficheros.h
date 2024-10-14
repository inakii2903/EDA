#ifndef NFICHEROS
    #define NFICHEROS

//Include de Curses
#include <ncursesw/curses.h>

//Include para dibujar los menus
#include "..\Ventanas\Ventanas.h"

//Prototipos de funciones de Ficheros
void Fichero(LIBRO **, int);
void ImportarFichero(LIBRO **,WINDOW *,bool);
void ExportarFichero(LIBRO **,WINDOW *);
void DescartarFichero(LIBRO **,WINDOW *);
char *strsep(char **, char *);

#endif