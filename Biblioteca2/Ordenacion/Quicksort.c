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
    int i,j;
    LIBRO *Pivote,*Auxiliar;

    i=izquierda;
    j=derecha;
    Pivote=Orden[(izquierda+derecha)/2];

    do {
        if (Campo == ORDEN_POR_TITULO) {
            while (strcmp(Orden[i]->Titulo,Pivote->Titulo) < 0)
                i++;
            while (strcmp(Orden[j]->Titulo,Pivote->Titulo) > 0)
                j--;
        }
        else {
            while (strcmp(Orden[i]->Autor,Pivote->Autor) < 0)
                i++;
            while (strcmp(Orden[j]->Autor,Pivote->Autor) > 0)
                j--;
        }
        if (i <= j) {
            Auxiliar=Orden[i];
            Orden[i]=Orden[j];
            Orden[j]=Auxiliar;
            i++;
            j--;
        }
    } while (i <= j);

    if (izquierda < j)
        QSort(Orden,izquierda,j,Campo);
    if (i < derecha)
        QSort(Orden,i,derecha,Campo);

    return;

}

// Función de comparación para el método Quicksort
static int Qcmp(LIBRO *orden1, LIBRO *orden2, int Campo){
    if (Campo == ORDEN_POR_TITULO){
        return strcmp(orden1->Titulo, orden2->Titulo);
    } else {
        return strcmp(orden1->Autor, orden2->Autor);
    }

}

// Función de ordenación Quicksort

static void Qsort(LIBRO *Ficha, int izquierda, int derecha, int Campo){
    int i, j;
    LIBRO *Pivote, Auxiliar;

    i = izquierda;
    j = derecha;
    Pivote = Ficha[(izquierda + derecha) / 2];

    do {
        while (Qcmp(&Ficha[i], Pivote, Campo) < 0)
            i++;
        while (Qcmp(&Ficha[j], Pivote, Campo) > 0)
            j--;
        if (i <= j){
            Auxiliar = Ficha[i];
            Ficha[i] = Ficha[j];
            Ficha[j] = Auxiliar;
            i++;
            j--;
        }
    } while (i <= j);

    if (izquierda < j)
        Qsort(Ficha, izquierda, j, Campo);
    if (i < derecha)
        Qsort(Ficha, i, derecha, Campo);

    return;

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