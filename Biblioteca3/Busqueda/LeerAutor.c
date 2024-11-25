/*****************************************
 * Nombre: LeerAutor
 * Argumentos: N/A
 * Descripción: Captura los apellidos del Autor a buscar en una ventana curses
 * Reglas de uso: 
 * Código de Retorno: String a los apellidos capturados (char *)
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Busqueda.h"

char *LeerAutor()
{
    static char Autor[256];
    static WINDOW *Wautor=NULL;
    int i;

    if (Estadisticas.NumeroFichas == 0) {
        VentanaError("No hay fichas de libros");
        return(NULL);
    }
    if (Wautor == NULL) {
        Wautor=newwin(4,76,5,2);
        DibujarLeerAutor(Wautor);
    }
    mvwprintw(Wautor,2,23,"                                                    ");
    touchwin(Wautor);
    wrefresh(Wautor);
    curs_set(1);
    nocbreak();
    echo();
    Autor[0]=0;
    mvwscanw(Wautor,2,23,"%s",Autor);
    noecho();
    cbreak();
    curs_set(0);
    if (Autor[0] == 0)
        return(NULL);
    for(i=0;Autor[i] != 0;i++)
        if (Autor[i] < 'a')
            Autor[i]+=' ';
    return(Autor);
}