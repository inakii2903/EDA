/*****************************************
 * Nombre: InsertarListaIzquierda
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Izquierda
 * Reglas de uso: 
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador:
 *****************************************/

#include "Listas.h"

int InsertarListaIzquierda(LISTA *Lista, void *Elemento)
{

    // Alocar espacio para un nuevo nodo
    // Si no se ha podido alocar espacio, devolver -1
    // Inicializar el nodo con el elemento dado
    // El nodo final apunta al nuevo nodo
    // Si la lista está vacía, la cabecera apunta al nuevo nodo
    // Si no, el nodo final apunta al nuevo nodo
    
    NODO *NodoAux;
    
    if (Lista == NULL) {
        return -1;
    }
    
    NodoAux=(NODO *)malloc(sizeof(NODO));
    if (NodoAux == NULL) {
        return -1;
    }
    
    NodoAux->Elemento=Elemento;
    NodoAux->Siguiente=Lista->Primero;
    
    Lista->Primero=NodoAux;
    
    if (Lista->Ultimo == NULL) {
        Lista->Ultimo=NodoAux;
    }
    
    return 0;
    
}