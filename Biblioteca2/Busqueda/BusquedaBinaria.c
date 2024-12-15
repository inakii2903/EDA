/*****************************************
 * Nombre: BusquedaBinaria
 * Argumentos: LIBRO *Fichas:       Array de las fichas de libros
 * Descripción: Después de capturar los apellidos de un autor, busca las fichas de libros de ese autor,
 *              por el método de búsqueda binaria
 *              La comparación de los apellidos se hace en mayúsculas. 
 *              Después se muestran los resultados en una pantalla de scroll.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Busqueda.h"


// Función que realiza una búsqueda binaria de libros por el apellido del autor
void BusquedaBinaria(LIBRO *Fichas)
{
    char *Autor;                // Puntero para almacenar el apellido del autor ingresado
    LIBRO **Resultado = NULL;   // Puntero doble para almacenar los resultados encontrados
    LIBRO **Orden = NULL;       // Puntero doble para almacenar las fichas ordenadas por autor
    int Hallados = 0;           // Contador de libros encontrados
    struct timeval inicio, fin; // Variables para medir el tiempo de ejecución
    bool Encontrado = false;    // Bandera para indicar si se encontró al menos una coincidencia
    int izquierda, derecha, medio; // Variables para los índices de la búsqueda binaria
    int cmp;                    // Variable para comparar los apellidos de los autores
    // Solicita al usuario que ingrese el apellido del autor y lo almacena en 'Autor'
    if ((Autor = LeerAutor()) == NULL)
        return; // Si no se ingresa un autor, la función termina

    // Registra el tiempo de inicio de la búsqueda
    gettimeofday(&inicio, NULL);

    // Ordena las fichas de libros por apellido del autor utilizando Quicksort
    Orden = Quicksort(Fichas, ORDEN_POR_AUTOR);

    // Inicializa los índices para la búsqueda binaria
    izquierda = 0;
    derecha = Estadisticas.NumeroFichas - 1;

    // Realiza la búsqueda binaria
    while (izquierda <= derecha) {
        medio = (izquierda + derecha) / 2; // Calcula el índice medio

        // Compara el apellido del autor ingresado con el de la ficha en la posición 'medio'
        cmp = strcasecmp(Autor, Orden[medio]->ApellAutor);

        if (cmp == 0) {
            // Si se encuentra una coincidencia, se almacena en los resultados
            Resultado = realloc(Resultado, (Hallados + 1) * sizeof(LIBRO *));
            Resultado[Hallados] = Orden[medio];
            Hallados++;
            Encontrado = true;

            // Busca más coincidencias hacia la izquierda del índice medio
            int temp = medio - 1;
            while (temp >= 0 && strcasecmp(Autor, Orden[temp]->ApellAutor) == 0) {
                Resultado = realloc(Resultado, (Hallados + 1) * sizeof(LIBRO *));
                Resultado[Hallados] = Orden[temp];
                Hallados++;
                temp--;
            }

            // Busca más coincidencias hacia la derecha del índice medio
            temp = medio + 1;
            while (temp < Estadisticas.NumeroFichas && strcasecmp(Autor, Orden[temp]->ApellAutor) == 0) {
                Resultado = realloc(Resultado, (Hallados + 1) * sizeof(LIBRO *));
                Resultado[Hallados] = Orden[temp];
                Hallados++;
                temp++;
            }
            break; // Termina la búsqueda después de encontrar todas las coincidencias
        } else if (cmp < 0) {
            derecha = medio - 1; // Ajusta el índice derecho para buscar en la mitad izquierda
        } else {
            izquierda = medio + 1; // Ajusta el índice izquierdo para buscar en la mitad derecha
        }
    }

    // Libera la memoria asignada para las fichas ordenadas
    free(Orden);

    // Registra el tiempo de finalización de la búsqueda
    gettimeofday(&fin, NULL);
    // Calcula y almacena la duración de la búsqueda en las estadísticas
    Estadisticas.TiempoBusquedaBinaria = DifTiempo(inicio, fin);

    // Si no se encontraron coincidencias, muestra un mensaje de error
    if (!Encontrado) {
        VentanaError("No hay autores que cumplan el criterio");
        free(Autor); // Libera la memoria asignada para 'Autor'
        return;
    }

    // Muestra la lista de resultados encontrados en una ventana de desplazamiento
    Listado1(Resultado, Hallados, Fichas);
    // Libera la memoria asignada para los resultados y para 'Autor'
    free(Resultado);
    free(Autor);
    return;
}