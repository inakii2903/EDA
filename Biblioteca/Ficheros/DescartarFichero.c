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

typedef struct {
    char *titulo;
    char *autor;
    int paginas;
} LIBRO;

void ActualizarEstadisticas();                            // Prototipo de la función que actualiza las estadísticas
void MostrarError(WINDOW *Wfichero, const char *mensaje); // Prototipo para mostrar errores

void DescartarFichero(LIBRO **Fichas, WINDOW *Wfichero)
{
    // 1. Comprobar si hay libros
    if (*Fichas == NULL)
    {
        MostrarError(Wfichero, "No hay libros para descartar.");
        return;
    }

    // 2. Confirmar que se quieren descartar todos los libros
    wclear(Wfichero);
    mvwprintw(Wfichero, 1, 1, "¿Desea descartar todos los libros? (y/n)");
    wrefresh(Wfichero);
    char confirm = wgetch(Wfichero);
    if (confirm != 'y' && confirm != 'Y')
    {
        mvwprintw(Wfichero, 2, 1, "Operación cancelada.");
        wrefresh(Wfichero);
        return;
    }

    // 3. Para cada uno de los libros
    for (int i = 0; Fichas[i] != NULL; i++)
    {
        // 3.1. Liberar el espacio asignado para cada campo de la estructura de libros
        free(Fichas[i]->titulo);
        free(Fichas[i]->autor);
        free(Fichas[i]);
    }

    // 4. Liberar el espacio del array de estructuras de libros
    free(*Fichas);

    // 5. Inicializar el array de estructuras de libros a NULL
    *Fichas = NULL;

    // 6. Actualizar las estadísticas
    ActualizarEstadisticas();

    // 7. Informar que los libros han sido descartados
    wclear(Wfichero);
    mvwprintw(Wfichero, 1, 1, "Todos los libros han sido descartados.");
    wrefresh(Wfichero);
    wgetch(Wfichero); // Esperar a que el usuario presione una tecla antes de continuar
}

void MostrarError(WINDOW *Wfichero, const char *mensaje)
{
    wclear(Wfichero);
    mvwprintw(Wfichero, 1, 1, "%s", mensaje);
    wrefresh(Wfichero);
    wgetch(Wfichero); // Esperar a que el usuario presione una tecla
}

void ActualizarEstadisticas()
{
    // Implementación de actualización de estadísticas
    // Aquí podrías actualizar variables globales o escribir en un archivo de registro
}
