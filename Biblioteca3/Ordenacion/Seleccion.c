/*****************************************
 * Nombre: Seleccion
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de Selección.
 * Reglas de uso: 
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Biblioteca.h"

LIBRO **Seleccion(LIBRO *Ficha, int Campo)
{
    LIBRO **Orden;
    struct timeval inicio, fin;
    int i,j,k,Minimo;
    LIBRO *auxiliar;
    char Autor1[256], Autor2[256];

    gettimeofday(&inicio,NULL);
    Orden=InitOrden(Ficha);

    for (i=0;i<Estadisticas.NumeroFichas-1;i++) {
        Minimo=i;
        for (j=i+1;j<=Estadisticas.NumeroFichas-1;j++) {
            if (Campo == ORDEN_POR_AUTOR) {
                strcpy(Autor1,Orden[j]->ApellAutor);
                if (Orden[j]->NomAutor != NULL) {
                    strcat(Autor1,", ");
                    strcat(Autor1,Orden[j]->NomAutor);
                }
                strcpy(Autor2,Orden[Minimo]->ApellAutor);
                if (Orden[Minimo]->NomAutor != NULL) {
                    strcat(Autor2,", ");
                    strcat(Autor2,Orden[Minimo]->NomAutor);
                }
                k=strcmp(Autor1,Autor2);
            }
            else
                k=strcmp(Orden[j]->Titulo,Orden[Minimo]->Titulo);
            if (k < 0)
                Minimo=j;
        }
        if (Minimo != i) {
            auxiliar=Orden[i];
            Orden[i]=Orden[Minimo];
            Orden[Minimo]=auxiliar;
        }
    }
    gettimeofday(&fin,NULL);
    Estadisticas.TiempoSeleccion=DifTiempo(inicio,fin);

    return(Orden);
}