/*****************************************
 * Nombre: LongitudLista
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Calcula el número de elementos de Lista
 * Reglas de uso: 
 * Código de Retorno: el número de elementos de Lista
 * Programador:
 *****************************************/

#include "Listas.h"

int LongitudLista(LISTA *Lista)
{
    
    NODO *NodoAux;
    int Longitud=0;
    
    NodoAux=Lista->Primero;
    
    while (NodoAux != NULL) {
        Longitud++;
        NodoAux=NodoAux->Siguiente;
    }
    
    return Longitud;
    
}