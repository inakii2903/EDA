/*****************************************
 * Nombre: Burbuja
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de la burbuja.
 * Reglas de uso: 
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Biblioteca.h"

LIBRO **Burbuja(LIBRO *Ficha,int Campo)
{
    LIBRO **Orden;
    struct timeval inicio, fin;

    gettimeofday(&inicio,NULL);
    Orden=InitOrden(Ficha);

    //Código del Alumno del método de ordenación de la Burbuja
    
    gettimeofday(&fin,NULL);
    Estadisticas.TiempoBurbuja=DifTiempo(inicio,fin);

    return(Orden);
}