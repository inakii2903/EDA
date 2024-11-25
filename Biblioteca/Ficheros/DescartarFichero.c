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

void DescartarFichero(LIBRO **Fichas, WINDOW *Wfichero) {
    // Variables
    int i;

    // Limpiar la ventana
    wclear(Wfichero);
    wrefresh(Wfichero);

    // Liberar la memoria
    for (i = 0; i < Estadisticas.NumeroFichas; i++) {
        free((*Fichas)[i].Titulo);
        free((*Fichas)[i].ApellAutor);
        free((*Fichas)[i].NomAutor);
        free((*Fichas)[i].Genero);
        free((*Fichas)[i].Editorial);
        free((*Fichas)[i].Coleccion);
    }
    free(*Fichas);
    *Fichas = NULL;

    // Actualizar estadísticas
    Estadisticas.NumeroFichas = 0;

    // Mostrar mensaje de éxito
    VentanaError("Fichero descartado correctamente.");
    wrefresh(Wfichero);
    getch();
    return;
}
