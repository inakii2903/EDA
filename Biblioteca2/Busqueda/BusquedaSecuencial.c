/*****************************************
 * Nombre: BusquedaSecuencial
 * Argumentos: LIBRO *Fichas:       Array de las fichas de libros
 * Descripción: Después de capturar los apellidos de un autor, busca las fichas de libros de ese autor
 *              por el método de búsqueda por selección.
 *              La comparación de los apellidos se hace en mayúsculas. 
 *              Después se muestran los resultados en una pantalla de scroll.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Busqueda.h"

void BusquedaSecuencial(LIBRO *Fichas)
{
    char *Autor;
    LIBRO **Resultado=NULL;
    int Hallados=0;
    struct timeval inicio, fin;

    // Añadir aquí la definición del resto de variables usadas
    
    if ((Autor=LeerAutor()) == NULL)
        return;

    gettimeofday(&inicio,NULL);

    //Código del Alumno del Algoritmo de Búsqueda por Selección

    gettimeofday(&fin,NULL);
    Estadisticas.TiempoBusquedaSecuencial=DifTiempo(inicio,fin);

    if (Hallados == 0) {
        VentanaError("No hay autores que cumplan el criterio");
        return;
    }
    Listado1(Resultado,Hallados,Fichas);
    free(Resultado);
    return;
    
}