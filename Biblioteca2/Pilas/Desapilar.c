/*****************************************
 * Nombre: Desapilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void **Elemento: Puntero de referencia al puntero del elemento que se desapila
 * Descripción: Desapila el primer elemento de la pila y guarda el puntero desapilado en *Elemento
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *Desapilar(PILA *Pila,void **Elemento)
{

    //Desapilar el primer elemento de la pila
    //Guardar el puntero al elemento desapilado en *Elemento
    //Devolver el nuevo puntero al TAD Pila

    NODO *NodoAux = NULL;
    NodoAux=Pila;
    *Elemento=NodoAux->Elemento;
    Pila=Pila->Siguiente;

    free(NodoAux);

    return Pila;
    
}