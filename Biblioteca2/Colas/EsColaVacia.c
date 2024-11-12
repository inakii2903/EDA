/*****************************************
 * Nombre: EsColaVacía
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve 'true' si la Cola está vacía o 'false' si tiene elementos
 * Reglas de uso: 
 * Código de Retorno: true  - La Cola no tiene elementos
 *                    false - La Cola tiene elementos
 * Programador:
 *****************************************/

#include "Colas.h"

bool EsColaVacia(COLA *Cola)
{
    
    // Si la cabecera de la cola es NULL, la cola está vacía
    // Devolver true

    if (Cola->Cabecera == NULL) {
        return true;
    }
    return false;    
}