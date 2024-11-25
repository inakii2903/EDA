/*****************************************
 * Nombre: Quicksort
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de Quicksort.
 * Reglas de uso: 
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Biblioteca.h"

static void QSort(LIBRO **Orden,int izquierda, int derecha, int Campo)
{

//Código del alumno para el Algoritmo de ordenación por el método Quicksort

}

LIBRO **Quicksort(LIBRO *Ficha, int Campo)
{
    LIBRO **Orden;
    struct timeval inicio, fin;

    gettimeofday(&inicio,NULL);
    Orden=InitOrden(Ficha);

    QSort(Orden,0,Estadisticas.NumeroFichas-1,Campo);
    
    gettimeofday(&fin,NULL);
    Estadisticas.TiempoQuicksort=DifTiempo(inicio,fin);

    return(Orden);
}