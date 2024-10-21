/*****************************************
 * Nombre: Libros
 * Argumentos: LIBRO **Fichas:   Puntero al array de libros
 * Descripción: Pantalla de gestión de fichas de libros completos.
 *              Si se introduce un número, se muestra ese número de libro o error
 *              Si se pulsa ENTER se pregunta si se quiere añadir un libro
 *              Si se responde 'S' se introduce un libro nuevo
 *              Si se responde 'N', la función retorna.
 * Reglas de uso: 
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Libros.h"

void Libros(LIBRO **Fichas)
{
    static WINDOW *Wlibro=NULL;
    int NumeroLibro;
    char Tecla;
    int TeclaFuncion;

    // Creación y dibujo de la ventana de gestión de libros
    if (Wlibro == NULL) {
        Wlibro=newwin(12,76,5,2);
        DibujarLibro(Wlibro);
    }

    // Bucle hasta que se desee salir
    while(true) {
        // Limpiar los datos de la ventana de gestión de libros y mensajes de ayuda
        LimpiarLibro(Wlibro);
        wcolor_set(Wlibro,2,NULL);
        mvwprintw(Wlibro,11,17,"Enter=Nuevo/Salir      #-Visualizar Libro");
        wcolor_set(Wlibro,9,NULL);
        touchwin(Wlibro);
        wrefresh(Wlibro);
        curs_set(1);
        echo();

        // Captura del número de libro a visualizar
        NumeroLibro=0;
        mvwscanw(Wlibro,2,23,"%d",&NumeroLibro);
        noecho();
        curs_set(0);

        // Si no es un número válido se pregunta si se desea salir
        if (NumeroLibro <=0 ) {
            Tecla=VentanaSN("Desea dar de alta un nuevo libro (S/N)?");
            touchwin(Wlibro);
            wrefresh(Wlibro);
            // Se quiere introducir un libro nuevo
            if (Tecla == 'S')
                NuevoLibro(Wlibro,Fichas);
            else
                // Se desea salir
                return;
        }
        else {
            // Es un número mayor que los libros que hay
            if (NumeroLibro > Estadisticas.NumeroFichas) {
                VentanaError("No existe esa ficha de libro");
                continue;
            }
            // Leer anterior/siguiente o ESC=salir
            keypad(Wlibro,true);
            while(true) {
                // Visualizar el libro actual
                LimpiarLibro(Wlibro);
                wcolor_set(Wlibro,9,NULL);
                mvwprintw(Wlibro,2,23,"%d",NumeroLibro);
                mvwprintw(Wlibro,3,23,"%.51s",(*Fichas)[NumeroLibro-1].Titulo);
                mvwprintw(Wlibro,4,23,"%.51s",(*Fichas)[NumeroLibro-1].ApellAutor);
                mvwprintw(Wlibro,5,23,"%.51s",(*Fichas)[NumeroLibro-1].NomAutor);
                mvwprintw(Wlibro,6,23,"%.51s",(*Fichas)[NumeroLibro-1].Genero);
                mvwprintw(Wlibro,7,23,"%.51s",(*Fichas)[NumeroLibro-1].Editorial);
                mvwprintw(Wlibro,8,23,"%.51s",(*Fichas)[NumeroLibro-1].Coleccion);
                wrefresh(Wlibro);
                while(true) {
                    // Si ESC salir del bucle
                    if ((TeclaFuncion=wgetch(Wlibro)) == KEY_ESC)
                        break;
                    else {
                        // Si LEFT, libro anterior
                        if (TeclaFuncion == KEY_LEFT) {
                            if (NumeroLibro > 1) {
                                NumeroLibro--;
                                break;
                            }
                            else
                                beep();
                        }
                        else {
                            // SI RIGHT, libro siguiente
                            if ((TeclaFuncion == KEY_RIGHT) && (NumeroLibro < Estadisticas.NumeroFichas)) {
                                NumeroLibro++;
                                break;
                            }
                            else
                                beep();
                        }
                    }
                }
                // Si ESC se vuelve a pedir el número de libro
                if (TeclaFuncion == KEY_ESC)
                    break;
            }
            keypad(Wlibro,false);
        }
    }
    return;
}