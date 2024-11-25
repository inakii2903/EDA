/*****************************************
 * Nombre: EsPilaVacia
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 * Descripción: Comprueba si la Pila está vacía
 * Reglas de uso: 
 * Código de Retorno: true  - La Pila está vacía
 *                    false - La Pila tiene elementos
 * Programador:
 *****************************************/

#include "Pilas.h"

bool EsPilaVacia(PILA *Pila)
{

    //Comprobar si la pila está vacía
    //Devolver true si está vacía
    //Devolver false si tiene elementos
    
    if (Pila == NULL) {
        return true;
    }

    return false;
  
}