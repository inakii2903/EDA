/*****************************************
 * Nombre: CreaLista
 * Argumentos: N/A
 * Descripción: Crea una Lista vacía
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Lista creada (vacía)
 * Programador:
 *****************************************/

#include "Listas.h"

LISTA *CrearLista()
{
    
    // Alocar espacio para la lista
    // Inicializar la cabecera y el final a NULL
    // Devolver la lista creada
    

    LISTA *NuevaLista;
    
    NuevaLista=(LISTA *)malloc(sizeof(LISTA));
    if (NuevaLista == NULL) {
        return NULL;
    }
    
    NuevaLista->Primero=NULL;
    NuevaLista->Ultimo=NULL;
    
    return NuevaLista;
    
}