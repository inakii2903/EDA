/*****************************************
 * Nombre: Desencolar
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve el puntero al primer elemento de la Cola (Cabecera) y lo elimina de la Cola
 * Reglas de uso: El puntero debe ser void *
 * Código de Retorno: Puntero al elemento desencolado
 *                    NULL si la cola no está creada o no tiene elementos
 * Programador:
 *****************************************/

#include "Colas.h"

void* Desencolar(COLA *Cola)
{
    // Si la cola está vacía, devolver NULL
    // Si no, devolver el primer elemento de la cola y eliminarlo de la cola
    // Liberar el nodo desencolado
    // Si la cola se queda vacía, actualizar la cabecera y el final a NULL
    // Devolver el puntero al elemento desencolado

    NODO *NodoAux;
    void *Elemento;
    
    if (Cola->Cabecera == NULL) {
        return NULL;
    }
    
    NodoAux=Cola->Cabecera;
    Elemento=NodoAux->Elemento;
    
    Cola->Cabecera=Cola->Cabecera->Siguiente;
    if (Cola->Cabecera == NULL) {
        Cola->Final=NULL;
    }
    
    free(NodoAux);
    
    return Elemento;
    
}