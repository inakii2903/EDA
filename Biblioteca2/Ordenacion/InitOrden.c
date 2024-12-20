/*****************************************
 * Nombre: InitOrden
 * Argumentos: LIBRO *Fichas:   Array de libros
 * Descripción: Genera un array con los punteros a los libros ordenados por
 *              su orden numérico, es decir, el mismo orden el que están en
 *              en array de libros Fichas.
 * Reglas de uso: Hay que alocar el espacio para el array de punteros
 * Código de Retorno: Puntero al array de punteros a los libros ordenados (LIBROS **)
 * Programador:
 *****************************************/

#include "../Biblioteca.h"

LIBRO **InitOrden(LIBRO *Fichas)
{

    LIBRO **Orden = NULL;
    int i;

    Orden = (LIBRO **)malloc(Estadisticas.NumeroFichas * sizeof(LIBRO *));

    /*
        for (i=0;i<Estadisticas.NumeroFichas;i++) {
            Orden[i] = &(Fichas[i]);

            *   &Fichas[i] obtiene la dirección de memoria del elemento Fichas[i].
            *   Orden[i] se está asignando para que contenga la dirección del elemento en Fichas. No se usa jamás de los jamases.
        }
    */
   

    for (i=0;i<Estadisticas.NumeroFichas;i++) {

        Orden[i]= Fichas + i; //NO PONER NUNCA &Fichas[i] ya que = &(*(Fichas+i)) = Fichas+i
    }

    return Orden;
    
    
}