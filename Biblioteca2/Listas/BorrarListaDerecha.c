/*****************************************
 * Nombre: BorrarListaDerecha
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la derecha.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaDerecha(LISTA *Lista)
{
    // Si la lista está vacía, devolver NULL
    // Si no, devolver el último elemento de la lista y eliminarlo de la lista
    // Liberar el nodo desencolado
    // Si la lista se queda vacía, actualizar la cabecera y el final a NULL
    // Devolver el puntero al elemento desencolado
    

    NODO *NodoAux;
    void *Elemento;
    
    if (Lista->Ultimo == NULL) {
        return NULL;
    }
    
    NodoAux=Lista->Ultimo;
    Elemento=NodoAux->Elemento;
    
    if (Lista->Primero == Lista->Ultimo) {
        Lista->Primero=NULL;
        Lista->Ultimo=NULL;
    } else {
        Lista->Ultimo=Lista->Ultimo;
        Lista->Ultimo->Siguiente=NULL;
    }
    
    free(NodoAux);
    
    return Elemento;
    
}