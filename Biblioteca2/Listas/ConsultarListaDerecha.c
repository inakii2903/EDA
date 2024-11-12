/*****************************************
 * Nombre: ConsultarListaDerecha
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Consulta el elemento de la derecha de Lista. No se elimina de Lista
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento de la derecha de Lista
 * Programador:
 *****************************************/

#include "Listas.h"

void *ConsultarListaDerecha(LISTA *Lista)
{
    
    // Si la lista está vacía, devolver NULL
    // Si no, devolver el último elemento de la lista

    if (Lista->Ultimo == NULL) {
        return NULL;
    }
    
    return Lista->Ultimo->Elemento;
    
}