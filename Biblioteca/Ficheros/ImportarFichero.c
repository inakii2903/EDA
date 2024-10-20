/*****************************************
 * Nombre: ImortarFichero
 * Argumentos: LIBRO **Fichas:   Puntero al array de libros
 *             WINDOW *Wfichero: Ventana para capturar el nombre del fichero
 *             bool sumar:       Si es true las fichas de libros se añaden a las existentes,
 *                               si es false la lista de libros tiene que estar vacía.
 * Descripción: Lee el nombre del fichero que contendrá los datos a importar. Carga los libros del fichero
 *              en el array de libros, dimensionándolo si es necesario y descartando los que no tengan título o autor.
 * Reglas de uso:
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"

void ImportarFichero(LIBRO **Fichas, WINDOW *Wfichero, bool sumar)
{
    char nombreFichero[256];
    FILE *fichero;
    char linea[200];
    char *token;
    struct timeval inicio, fin;
    int numLibrosFichero = 0;
    int numLibrosDescartados = 0;
    bool error = false;

    // Comprobar si sumar es true o false y validar el estado de Estadisticas.NumeroFichas
    if (sumar)
    {
        if (Estadisticas.NumeroFichas == 0)
        {
            mvwprintw(Wfichero, 2, 1, "Error: No hay libros en la lista existente.");
            wrefresh(Wfichero);
            return;
        }
    }
    else
    {
        if (Estadisticas.NumeroFichas != 0)
        {
            mvwprintw(Wfichero, 2, 1, "Error: La lista no está vacía.");
            wrefresh(Wfichero);
            return;
        }
    }

    // Limpiar la ventana y capturar el nombre del fichero
    
    
    echo();
    mvwscanw(Wfichero, 2, 25, nombreFichero, sizeof(nombreFichero) - 1);
    noecho();

    // Abrir el fichero en modo lectura
    fichero = fopen(nombreFichero, "r");
    if (fichero == NULL)
    {
        mvwprintw(Wfichero, 2, 1, "Error al abrir el fichero.");
        wrefresh(Wfichero);
        return;
    }

    // Capturar el tiempo de inicio
    gettimeofday(&inicio, NULL);

    // Contar el número de libros en el fichero
    while (fgets(linea, sizeof(linea), fichero) != NULL)
    {
        numLibrosFichero++;
    }

    // Asignar memoria para el total de libros
    *Fichas = realloc(*Fichas, (Estadisticas.NumeroFichas + numLibrosFichero - 1) * sizeof(LIBRO));
    if (*Fichas == NULL)
    {
        mvwprintw(Wfichero, 2, 1, "Error al asignar memoria.");
        wrefresh(Wfichero);
        fclose(fichero);
        return;
    }

    // Si hay 0 o 1 líneas, el fichero no contiene libros
    if (numLibrosFichero <= 1)
    {
        mvwprintw(Wfichero, 2, 1, "El fichero no contiene libros.");
        wrefresh(Wfichero);
        fclose(fichero);
        return;
    }

    // Reset the file pointer to the beginning of the file
    rewind(fichero);

    // Process each line in the file
    while (fgets(linea, sizeof(linea), fichero) != NULL)
    {
        char *line_ptr = linea;
        char *token;

        // Use strsep to tokenize the line
        while ((token = strsep(&line_ptr, ",")) != NULL)
        {
            // Process each token
        }
    }

    fclose(fichero);

    // Capturar el tiempo de fin
    gettimeofday(&fin, NULL);

    // Actualizar los datos de Estadisticas
    Estadisticas.TiempoCarga = DifTiempo(inicio, fin);

    return;
}
