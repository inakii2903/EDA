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