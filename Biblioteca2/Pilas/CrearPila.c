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
    //Crear un nuevo nodo
    //Devolver el puntero al nuevo nodo
    //Si no se puede crear devolver NULL

    PILA *nuevaPila = (PILA *)malloc(sizeof(PILA));
    nuevaPila->Elemento = NULL;
    return nuevaPila;
 
}