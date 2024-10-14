#ifndef NCOMUN
    #define NCOMUN

// Includes de las librerías estándar de C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <string.h>

//Include de Curses
#include <ncursesw/curses.h>

//Estructura de Ficha de Libro
typedef struct _libro {
    char *Titulo;
    char *ApellAutor;
    char *NomAutor;
    char *Genero;
    char *Editorial;
    char *Coleccion;
} LIBRO;

//Protoripos de funciones comunes
void InitGlobal();
int DifTiempo(struct timeval,struct timeval);

// Variables globales
extern struct _Estadisticas {
            char *Fichero;
            int NumeroFichas;
            int MaxFichas;
            int TiempoCarga;
            int TiempoSeleccion;
            int TiempoBurbuja;
            int TiempoInsercion;
            int TiempoQuicksort;
            int TiempoBusquedaSecuencial;
            int TiempoBusquedaBinaria;
            int TiempoBusquedaArbol;
        } Estadisticas;

//Defines de la aplicación
#define KEY_ESC 27

#endif