/*****************************************
 * Nombre: Inserción
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de Inserción.
 * Reglas de uso: 
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Biblioteca.h"

LIBRO **Insercion(LIBRO *Ficha,int Campo)
{
    LIBRO **Orden;
    struct timeval inicio, fin;
    int i,j,k;
    LIBRO *auxiliar;
    char Autor1[256], Autor2[256];

    gettimeofday(&inicio,NULL);
    Orden=InitOrden(Ficha);

    for (i=1;i<Estadisticas.NumeroFichas;i++) {
        auxiliar=Orden[i];
        if (Campo == ORDEN_POR_TITULO) {
            j=i-1;
            while ((j>=0) && (strcmp(Orden[j]->Titulo,auxiliar->Titulo) > 0)) {
                Orden[j+1]=Orden[j];
                j--;
            }
        }
        else {
            j=i-1;
            while ((j>=0) && (strcmp(Orden[j]->NomAutor,auxiliar->NomAutor) > 0)) {
                Orden[j+1]=Orden[j];
                j--;
            }
        }
        Orden[j+1]=auxiliar;
    }


    
    
    gettimeofday(&fin,NULL);
    Estadisticas.TiempoInsercion=DifTiempo(inicio,fin);

    return(Orden);
}