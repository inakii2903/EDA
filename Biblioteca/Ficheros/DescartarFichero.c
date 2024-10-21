/*****************************************
 * Nombre: DescartarFichero
 * Argumentos: LIBRO **Fichas:   Puntero al array de libros
 *             WINDOW *Wfichero: Ventana para mostrar el nombre del fichero
 * Descripción: Muestra los datos del fichero y los libros almacenados y descarta todos
 *              los libros en memoria y libera la memoria asignada.
 * Reglas de uso:
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"




void DescartarFichero(LIBRO **Fichas, WINDOW *Wfichero)
{
   
    // Código del alumno
    
    // Variables
    int i;
    
    // Mostrar los libros almacenados
    mvwprintw(Wfichero, 1, 1, "Libros almacenados:");
    for (i = 0; i < Estadisticas.NumeroFichas; i++) {
        mvwprintw(Wfichero, i + 2, 1, "%s;%s;%s;%s;%s;%s", (*Fichas)[i].Titulo, (*Fichas)[i].ApellAutor, (*Fichas)[i].NomAutor, (*Fichas)[i].Genero, (*Fichas)[i].Editorial, (*Fichas)[i].Coleccion);
    }
    wrefresh(Wfichero);
    
    // Liberar la memoria
    free(*Fichas);
    *Fichas = NULL;
    
    // Mostrar mensaje de éxito
    mvwprintw(Wfichero, i + 2, 1, "Fichero descartado correctamente.");
    wrefresh(Wfichero);
    getch();
    return;
}

