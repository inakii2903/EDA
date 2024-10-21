/*****************************************
 * Nombre: BorrarListaIzquierda
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la izquierda.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaIzquierda(LISTA *Lista)
{
    
    NODO *NodoAux;
    void *Elemento;
    
    if (Lista->Primero == NULL) {
        return NULL;
    }
    
    NodoAux=Lista->Primero;
    Elemento=NodoAux->Elemento;
    
    if (Lista->Primero == Lista->Ultimo) {
        Lista->Primero=NULL;
        Lista->Ultimo=NULL;
    } else {
        Lista->Primero=Lista->Primero->Siguiente;
    }
    
    free(NodoAux);
    
    return Elemento;
    
}