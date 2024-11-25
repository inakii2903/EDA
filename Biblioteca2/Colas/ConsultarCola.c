/*****************************************
 * Nombre: ConsultarCola
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve un puntero al primer Elemento de la Cola.
 *              No se modifica la Cola, solo se consulta
 * Reglas de uso: 
 * Código de Retorno: Puntero al primer elemento de la Cola o NULL si la cola está vacía
 * Programador:
 *****************************************/

#include "Colas.h"

void *ConsultarCola(COLA *Cola)
{
    // Si la cola está vacía, devolver NULL
    if (Cola->Cabecera == NULL) {
        return NULL;
    }
    // Devolver el primer elemento de la cola   
    return Cola->Cabecera->Elemento;
    

}