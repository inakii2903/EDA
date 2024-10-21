/*****************************************
 * Nombre: NuevoLibro
 * Argumentos: Window *Wlibro :   Ventana para la captura de los datos del libro nuevo
 *             LIBRO **Fichas:    Puntero al array de libros
 * Descripción: Captura los datos de un nuevo libro y lo añade al final del array de libros
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: (JMSM sept-24)
 *****************************************/

#include "Libros.h"

void NuevoLibro(WINDOW *Wlibro,LIBRO **Fichas)
{
    char linea[256];
    char linea1[256];
    char Tecla;

    // Si no hay espacio para un nuevo libro se reasigna más espacio al array de libros
    if (Estadisticas.NumeroFichas == Estadisticas.MaxFichas) {
        if ((*Fichas=realloc(*Fichas,sizeof(LIBRO)*(Estadisticas.MaxFichas+100))) == NULL) {
            sprintf(linea,"Error %d al alocar %d bytes",errno,sizeof(LIBRO)*(Estadisticas.MaxFichas+100));
            VentanaError(linea);
            return;
        }
        Estadisticas.MaxFichas+=100;
    }
    
    curs_set(1);
    echo();

    // Se imprime el número que tendrá el nuevo libro
    mvwprintw(Wlibro,2,23,"%d",Estadisticas.NumeroFichas+1);

    // Se captura el título del libro. No puede estar en blanco
    while(true) {
        linea[0]=0;
        mvwscanw(Wlibro,3,23,"%s",linea);
        if (strlen(linea) == 0) {
            Tecla=VentanaSN("El titulo no puede esta vacio. Desea continuar (S/N)?");
            if (Tecla == 'N')
                return;
            touchwin(Wlibro);
            wrefresh(Wlibro);
        }
        else
            break;
    }

    // Se captura los apellidos del autor. No puede estar en blanco
    while(true) {
        linea1[0]=0;
        mvwscanw(Wlibro,4,23,"%s",linea1);
        if (strlen(linea1) == 0) {
            Tecla=VentanaSN("El autor no puede esta vacio. Desea continuar (S/N)?");
            if (Tecla == 'N')
                return;
            touchwin(Wlibro);
            wrefresh(Wlibro);
        }
        else
            break;
    }
    // Se guarda el titulo y los apellidos
    (*Fichas)[Estadisticas.NumeroFichas].Titulo=malloc(strlen(linea)+1);
    strcpy((*Fichas)[Estadisticas.NumeroFichas].Titulo,linea);
    (*Fichas)[Estadisticas.NumeroFichas].ApellAutor=malloc(strlen(linea1)+1);
    strcpy((*Fichas)[Estadisticas.NumeroFichas].Titulo,linea1);
    // Se captura el nombre del autor. Si es blanco, se guarda NULL
    linea[0]=0;
    mvwscanw(Wlibro,5,23,"%s",linea);
    if (strlen(linea) == 0)
        (*Fichas)[Estadisticas.NumeroFichas].NomAutor=NULL;
    else {
        (*Fichas)[Estadisticas.NumeroFichas].NomAutor=malloc(strlen(linea)+1);
        strcpy((*Fichas)[Estadisticas.NumeroFichas].NomAutor,linea);
    }
    // Se captura el género del libro. Si es blanco, se guarda NULL
    linea[0]=0;
    mvwscanw(Wlibro,6,23,"%s",linea);
    if (strlen(linea) == 0)
        (*Fichas)[Estadisticas.NumeroFichas].Genero=NULL;
    else {
        (*Fichas)[Estadisticas.NumeroFichas].Genero=malloc(strlen(linea)+1);
        strcpy((*Fichas)[Estadisticas.NumeroFichas].Genero,linea);
    }
    // Se captura la Editorial. Si es blanco, se guarda NULL
    linea[0]=0;
    mvwscanw(Wlibro,7,23,"%s",linea);
    if (strlen(linea) == 0)
        (*Fichas)[Estadisticas.NumeroFichas].Editorial=NULL;
    else {
        (*Fichas)[Estadisticas.NumeroFichas].Editorial=malloc(strlen(linea)+1);
        strcpy((*Fichas)[Estadisticas.NumeroFichas].Editorial,linea);
    }
    // Se captura la Colección del libro. Si es blanco, se guarda NULL
    linea[0]=0;
    mvwscanw(Wlibro,8,23,"%s",linea);
    if (strlen(linea) == 0)
        (*Fichas)[Estadisticas.NumeroFichas].Coleccion=NULL;
    else {
        (*Fichas)[Estadisticas.NumeroFichas].Coleccion=malloc(strlen(linea)+1);
        strcpy((*Fichas)[Estadisticas.NumeroFichas].Coleccion,linea);
    }

    // Se aumenta el número de libros
    Estadisticas.NumeroFichas++;
    noecho();    
    curs_set(0);

    // Mensaje de que se ha hecho bien
    VentanaError("El Libro se ha dado de alta correctamente");
    return;
}