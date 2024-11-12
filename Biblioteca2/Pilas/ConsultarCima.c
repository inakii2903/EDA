/*****************************************
 * Nombre: ConsultarCima
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 * Descripción: Devuelve el puntero al primer elemento de la Pila
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento Cima
 * Programador:
 *****************************************/

#include "Pilas.h"

void *ConsultarCima(PILA *Pila)
{
    //Devolver el puntero al primer elemento de la pila
    //Si la pila está vacía devolver NULL

    if (Pila == NULL) {
        return NULL;
    }

    return Pila->Elemento;
         
}