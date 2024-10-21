/*****************************************
 * Nombre: CrearCola
 * Argumentos: N/A
 * Descripción: Crea una cola sin elementos.
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Cola creada (vacía)
 *                    NULL - No se ha podido alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

COLA *CrearCola()
{
    COLA *NuevaCola;

    NuevaCola=(COLA *)malloc(sizeof(COLA));
    if (NuevaCola == NULL) {
        return NULL;
    }

    NuevaCola->Cabecera=NULL;
    NuevaCola->Final=NULL;

    return NuevaCola;
    
}