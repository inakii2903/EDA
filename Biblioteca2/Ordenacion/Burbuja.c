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

    for (int i=0;i<Estadisticas.NumeroFichas-1;i++) {
        for (int j=0;j<Estadisticas.NumeroFichas-1;j++) {
            if (Campo == ORDEN_POR_TITULO) {
                if (strcmp(Orden[j]->Titulo,Orden[j+1]->Titulo) > 0) {
                    LIBRO *auxiliar=Orden[j];
                    Orden[j]=Orden[j+1];
                    Orden[j+1]=auxiliar;
                }
            }
            else {
                if (strcmp(Orden[j]->NomAutor,Orden[j+1]->NomAutor) > 0) {
                    LIBRO *auxiliar=Orden[j];
                    Orden[j]=Orden[j+1];
                    Orden[j+1]=auxiliar;
                }
            }
        }
    }
    
    gettimeofday(&fin,NULL);
    Estadisticas.TiempoBurbuja=DifTiempo(inicio,fin);

    return(Orden);
}