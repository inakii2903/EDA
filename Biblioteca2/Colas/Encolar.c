/*****************************************
 * Nombre: Encolar
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al Elemento a insertar
 * Descripción: Se inserta el elemento dado al final de la cola.
 *              Se aloca el espacio que sea necesario
 * Reglas de uso: La cola debe estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo 
 * Programador:
 *****************************************/

#include "Colas.h"

int Encolar(COLA *Cola, void *Elemento)
{

    // Alocar espacio para un nuevo nodo
    // Si no se ha podido alocar espacio, devolver -1
    // Inicializar el nodo con el elemento dado
    // Si la cola está vacía, la cabecera apunta al nuevo nodo
    // Si no, el nodo final apunta al nuevo nodo

    NODO *NodoAux;
    
    if (Cola == NULL) {
        return -1;
    }
    
    NodoAux=(NODO *)malloc(sizeof(NODO));
    if (NodoAux == NULL) {
        return -1;
    }
    
    NodoAux->Elemento=Elemento;
    NodoAux->Siguiente=NULL;
    
    if (Cola->Cabecera == NULL) {
        Cola->Cabecera=NodoAux;
    } else {
        Cola->Final->Siguiente=NodoAux;
    }
    
    Cola->Final=NodoAux;
    
    return 0;
    
}