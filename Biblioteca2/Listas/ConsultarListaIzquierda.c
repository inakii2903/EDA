/*****************************************
 * Nombre: ConsultarListaIzquierda
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Consulta el elemento a la izquierda de Lista. No se elimina el elemento
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento a la izquierda de la Lista 
 * Programador:
 *****************************************/

#include "Listas.h"

void *ConsultarListaIzquierda(LISTA *Lista)
{

    // Si la lista está vacía, devolver NULL
    // Si no, devolver el primer elemento de la lista
    
    if (Lista->Primero == NULL) {
        return NULL;
    }
    
    return Lista->Primero->Elemento;
    
}