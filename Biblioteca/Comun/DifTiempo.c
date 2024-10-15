/*****************************************
 * Nombre: DifTiempo
 * Argumentos: struct timeval inicio:   Tiempo de inicio
 *             struct timeval fin:      Tiempo de fin
 * Descripción: Calcula los microsegundos de diferencia entre ambos tiempos
 * Reglas de uso: 
 * Código de Retorno: Microsegundos de diferencia
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Comun.h"

int DifTiempo(struct timeval inicio,struct timeval fin)
{
    
    // Codigo del alumno

    int t_final, t_inicial;

    // Devuelve la diferencia en microsegundos
    
    t_final = fin.tv_sec * 1000000 + fin.tv_usec;
    t_inicial = inicio.tv_sec * 1000000 + inicio.tv_usec;
    return t_final - t_inicial;
    
}