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
    char nombreFichero[256];
    FILE *fichero;

    // Comprobar si hay libros
    if (Estadisticas.NumeroFichas == 0) {

        VentanaError("No hay libros para exportar.");
        wrefresh(Wfichero);
        return;
    }

    // Limpiar la ventana y capturar el nombre del fichero
    wclear(Wfichero);
    mvwprintw(Wfichero, 1, 1, "Introduzca el nombre del fichero: ");
    wrefresh(Wfichero);
    echo();
    wgetnstr(Wfichero, nombreFichero, sizeof(nombreFichero) - 1);
    noecho();

    // Abrir el fichero en escritura
    fichero = fopen(nombreFichero, "w");
    if (fichero == NULL) {
        VentanaError("Error al abrir el fichero.");
        wrefresh(Wfichero);
        return;
    }

    // Escribir la cabecera
    fprintf(fichero, "Titulo;ApellAutor;NomAutor;Genero;Editorial;Coleccion\n");

    // Escribir los datos de cada libro
    for (int i = 0; i < Estadisticas.NumeroFichas; i++) {
        fprintf(fichero, "%s;%s;%s;%s;%s;%s\n",
                (*Fichas)[i].Titulo,
                (*Fichas)[i].ApellAutor,
                (*Fichas)[i].NomAutor,
                (*Fichas)[i].Genero,
                (*Fichas)[i].Editorial,
                (*Fichas)[i].Coleccion);
    }

    // Cerrar el fichero
    fclose(fichero);

    // Informar que los libros se han exportado correctamente
    VentanaError("Libros exportados correctamente.");
    wrefresh(Wfichero);
}

