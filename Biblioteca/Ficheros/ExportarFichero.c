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

typedef struct {
    char *titulo;
    char *autor;
    int paginas;
} LIBRO;

void MostrarError(WINDOW *Wfichero, const char *mensaje); // Prototipo para mostrar errores

void ExportarFichero(LIBRO **Fichas, WINDOW *Wfichero)
{
    // 1. Comprobar si hay libros para exportar
    if (*Fichas == NULL)
    {
        MostrarError(Wfichero, "No hay libros para exportar.");
        return;
    }

    // 2. Capturar el nombre del fichero
    char nombreFichero[256];
    wclear(Wfichero);
    mvwprintw(Wfichero, 1, 1, "Introduzca el nombre del fichero a exportar:");
    echo(); // Habilitar la visualización de la entrada del usuario
    mvwgetnstr(Wfichero, 2, 1, nombreFichero, 255);
    noecho(); // Deshabilitar la visualización de la entrada del usuario

    // 3. Abrir el fichero en escritura
    FILE *fichero = fopen(nombreFichero, "w");
    if (fichero == NULL)
    {
        MostrarError(Wfichero, "Error al abrir el fichero.");
        return;
    }

    // 4. Escribir la cabecera en el fichero
    fprintf(fichero, "Titulo;Autor;Paginas\n");

    // 5. Para cada libro, escribir los datos en el fichero
    int i = 0;
    int librosExportados = 0;
    while (Fichas[i] != NULL)
    {
        // 5.1 Escribir los datos del libro separados por ';'
        fprintf(fichero, "%s;%s;%d\n", Fichas[i]->titulo, Fichas[i]->autor, Fichas[i]->paginas);
        librosExportados++;
        i++;
    }

    // 6. Cerrar el fichero
    fclose(fichero);

    // 7. Mostrar el número de libros exportados
    wclear(Wfichero);
    mvwprintw(Wfichero, 1, 1, "Se han exportado %d libros.", librosExportados);
    wrefresh(Wfichero);

    // 8. Informar que los libros se han exportado correctamente
    mvwprintw(Wfichero, 2, 1, "Los libros se han exportado correctamente a %s.", nombreFichero);
    wrefresh(Wfichero);
    wgetch(Wfichero); // Esperar a que el usuario presione una tecla
}

void MostrarError(WINDOW *Wfichero, const char *mensaje)
{
    wclear(Wfichero);
    mvwprintw(Wfichero, 1, 1, "%s", mensaje);
    wrefresh(Wfichero);
    wgetch(Wfichero); // Esperar a que el usuario presione una tecla
}