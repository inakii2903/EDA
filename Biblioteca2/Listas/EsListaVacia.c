/*****************************************
 * Nombre: EsListaVacia
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Comprueba si la Lista está vacía o tiene elementos
 * Reglas de uso: 
 * Código de Retorno: true  - La lista está vacía
 *                    false - La lista tiene elementos
 * Programador:
 *****************************************/

#include "Listas.h"

bool EsListaVacia(LISTA *Lista)
{
    // Si la lista está vacía, devolver true
    // Si no, devolver false

    if (Lista->Primero == NULL) {
        return true;
    }
    return false;
    
}