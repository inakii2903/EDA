/*****************************************
 * Nombre: Apilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void *Elemento:  Puntero al elemento a apilar
 * Descripción: Apila el elemento Elemento al comienzo de la Pila
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *Apilar(PILA *Pila,void *Elemento)
{

    //Crear un nuevo nodo
    //Insertar el elemento en el nodo
    //Enlazar el nuevo nodo al comienzo de la pila

    NODO *NodoAux = NULL;
    NodoAux=(NODO *)malloc(sizeof(NODO));
    NodoAux->Elemento=Elemento;
    NodoAux->Siguiente=Pila;
    return NodoAux;
    
}