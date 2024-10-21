/*****************************************
 * Nombre: CrearPila
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 * Descripción: Función canónica para crear la Pila. NO es necesaria
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila = NULL
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *CrearPila()
{

    PILA *nuevaPila = (PILA *)malloc(sizeof(PILA));
    if (nuevaPila == NULL) {
        return NULL;
    }
    nuevaPila->Elemento = NULL;
    return nuevaPila;


  
}