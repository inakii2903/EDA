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



void ImportarFichero(LIBRO **Fichas, WINDOW *Wfichero, bool sumar) {
    // Variables
    char nombreFichero[256];
    FILE *fichero;
    char linea[200];
    char *token;
    struct timeval inicio, fin;
    int numLibrosFichero = 0;
    int numLibrosDescartados = 0;

    // Comprobar si hay libros según el valor de 'sumar'
    if (sumar && Estadisticas.NumeroFichas == 0) {
        VentanaError("La lista de libros debe tener al menos un libro.");
        wrefresh(Wfichero);
        return;
    } else if (!sumar && Estadisticas.NumeroFichas != 0) {
        VentanaError("La lista de libros debe estar vacía.");
        wrefresh(Wfichero);
        return;
    }

    // Limpiar la ventana y capturar el nombre del fichero
    
    mvwprintw(Wfichero, 1, 1, "Introduzca el nombre del fichero: ");
    wrefresh(Wfichero);
    echo();
    wgetnstr(Wfichero, nombreFichero, sizeof(nombreFichero) - 1);
    noecho();

    // Guardar el nombre del fichero en una variable
    char *nombreFicheroGuardado = strdup(nombreFichero);

    // Abrir el fichero en lectura
    fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) {
        VentanaError("Error al abrir el fichero.");
        wrefresh(Wfichero);
        free(nombreFicheroGuardado);
        return;
    }

    // Capturar el tiempo de inicio
    gettimeofday(&inicio, NULL);

    // Contar el número de libros del fichero
    while (fgets(linea, sizeof(linea), fichero)) {
        numLibrosFichero++;
    }

    // Si hay 0 o 1 líneas, el fichero no contiene libros
    if (numLibrosFichero <= 1) {
        VentanaError("El fichero no contiene libros.");
        wrefresh(Wfichero);
        fclose(fichero);
        free(nombreFicheroGuardado);
        return;
    }

    // Asignar memoria para el total de libros
    LIBRO *tempFichas = realloc(*Fichas, (Estadisticas.NumeroFichas + numLibrosFichero - 1) * sizeof(LIBRO));
    if (tempFichas == NULL) {
        VentanaError("Error al asignar memoria para los libros.");
        wrefresh(Wfichero);
        fclose(fichero);
        free(nombreFicheroGuardado);
        return;
    }
    *Fichas = tempFichas;

    // Reset the file pointer to the beginning of the file
    rewind(fichero);

    // Descartar la primera línea (cabecera)
    fgets(linea, sizeof(linea), fichero);

    // Leer líneas del fichero hasta EOF
    while (fgets(linea, sizeof(linea), fichero)) {
        LIBRO libro;
        char *line_ptr = linea;

        // Descomponer en tokens
        libro.Titulo = strdup(strsep(&line_ptr, ";"));
        libro.ApellAutor = strdup(strsep(&line_ptr, ";"));
        libro.NomAutor = strdup(strsep(&line_ptr, ";"));
        libro.Genero = strdup(strsep(&line_ptr, ";"));
        libro.Editorial = strdup(strsep(&line_ptr, ";"));
        libro.Coleccion = strdup(strsep(&line_ptr, ";"));

        // Si el 'Título' o 'Apellidos' es NULL, descartar la ficha del libro
        if (libro.Titulo == NULL || libro.ApellAutor == NULL) {
            numLibrosDescartados++;
            free(libro.Titulo);
            free(libro.ApellAutor);
            free(libro.NomAutor);
            free(libro.Genero);
            free(libro.Editorial);
            free(libro.Coleccion);
        } else {
            (*Fichas)[Estadisticas.NumeroFichas] = libro;
            Estadisticas.NumeroFichas++;
        }
    }

    // Mostrar en la ventana el número de libros tratados y descartados
    mvwprintw(Wfichero, 2, 1, "Libros tratados: %d", Estadisticas.NumeroFichas);
    mvwprintw(Wfichero, 3, 1, "Libros descartados: %d", numLibrosDescartados);
    sleep(10);
    wrefresh(Wfichero);

    // Cerrar el fichero
    fclose(fichero);

    // Capturar el tiempo de fin
    gettimeofday(&fin, NULL);

    // Actualizar los datos de Estadisticas
    Estadisticas.TiempoCarga = (fin.tv_sec - inicio.tv_sec) * 1000000 + (fin.tv_usec - inicio.tv_usec);

    // Informar que se ha importado correctamente
    mvwprintw(Wfichero, 4, 1, "Libros importados correctamente.");
    wrefresh(Wfichero);
}