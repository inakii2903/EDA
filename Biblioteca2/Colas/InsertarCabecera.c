/*****************************************
 * Nombre: InsertarCabecera
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento dado en la cabecera de la Cola (primer elemento)
 * Reglas de uso: La Cola tiene que estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

int InsertarCabecera(COLA *Cola, void *Elemento)
{
    
    NODO *NodoAux;
    
    if (Cola == NULL) {
        return -1;
    }
    
    NodoAux=(NODO *)malloc(sizeof(NODO));
    if (NodoAux == NULL) {
        return -1;
    }
    
    NodoAux->Elemento=Elemento;
    NodoAux->Siguiente=Cola->Cabecera;
    
    Cola->Cabecera=NodoAux;
    
    if (Cola->Final == NULL) {
        Cola->Final=NodoAux;
    }
    
    return 0;
    
}