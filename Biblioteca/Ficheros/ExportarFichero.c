/*****************************************
 * Nombre: ExportarFichero
 * Argumentos: LIBRO **Fichas:   Puntero al array de libros
 *             WINDOW *Wfichero: Ventana para capturar el nombre del fichero
 * Descripción: Lee el nombre del fichero que contendrá los datos a exportar. Exporta los datos de la estructura
 *              de todos los libros en el fichero.
 * Reglas de uso:
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"


void ExportarFichero(LIBRO **Fichas, WINDOW *Wfichero)
{    
    // Variables
    FILE *fichero;
    char nombreFichero[80];
    int i;
    
    // Leer el nombre del fichero
    mvwprintw(Wfichero, 1, 1, "Introduzca el nombre del fichero: ");
    wrefresh(Wfichero);
    echo();
    mvwscanw(Wfichero, 20, 30, nombreFichero, sizeof(nombreFichero) - 1);
    noecho();
    fichero = fopen(nombreFichero, "w+");
    if (fichero == NULL) {
        VentanaError("Error al abrir el fichero.");
        wrefresh(Wfichero);
        endwin();
        return;
    }
    
    // Escribir los libros en el fichero
    for (i = 0; i < Estadisticas.NumeroFichas; i++) {
        fprintf(fichero, "%s;%s;%s;%s;%s;%s\n", (*Fichas)[i].Titulo, (*Fichas)[i].ApellAutor, (*Fichas)[i].NomAutor, (*Fichas)[i].Genero, (*Fichas)[i].Editorial, (*Fichas)[i].Coleccion);
    }
    
    // Cerrar el fichero
    fclose(fichero);
    
    // Mostrar mensaje de éxito
    mvwprintw(Wfichero, 2, 1, "Fichero exportado correctamente.");
    wrefresh(Wfichero);
    getch();
    return;
}

