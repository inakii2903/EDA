/*****************************************
 * Nombre: LimpiarLibro
 * Argumentos: Window *Wlibro :   Ventana a limpiar
 * Descripción: Limpia los datos de la ventan de gestión de libros
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: (JMSM sept-24)
 *****************************************/

// Include de la unidad funcional
#include "Libros.h"

void LimpiarLibro(WINDOW *Wlibro)
{
    // Limpiar los datos de la ventana
    wcolor_set(Wlibro,9,NULL);
    mvwprintw(Wlibro,2,18,"                                                         ");
    mvwprintw(Wlibro,3,19,"                                                        ");
    mvwprintw(Wlibro,4,22,"                                                     ");
    mvwprintw(Wlibro,5,19,"                                                        ");
    mvwprintw(Wlibro,6,19,"                                                        ");
    mvwprintw(Wlibro,7,22,"                                                     ");
    mvwprintw(Wlibro,8,22,"                                                     ");
    mvwprintw(Wlibro,9,1,"                                                                          ");
    mvwprintw(Wlibro,10,1,"                                                                          ");
    return;
}