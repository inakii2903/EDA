/*****************************************
 * Nombre: Menu
 * Argumentos: bool borrar : flag para pedir el refresco de la pantalla.
 * Descripción: Función para el manejo de los menús. Comenzando con el menú principal, muestra un menú y pide una opción dentro del
 *              rango permitido. Si esa opción corresponde a otro menú, muestra el submenú y vuelve a pedir una opción permitida.
 *              En algunos casos hay un tercer submenu.
 * Reglas de uso: 
 * Código de Retorno: int OpcionMenu: es la opción elegida y se conforma de la siguiente manera, según el número de submenús:
 *                                    1 Submenú:    OpcionMenu1
 *                                    2 Submenús:   OpcionMenu1*10+OpcionMenu2
 *                                    3 Submenús:   OpcionMenu1*100+OpcionMenu2*10+OpcionMenu3
 * Programador: 
 *****************************************/

//Include del módulo funcional
#include "Ventanas.h"

int Menu(bool borrar)
{
    static WINDOW *Wmenu=NULL;
    static WINDOW *WmenuFich=NULL;
    static WINDOW *WmenuOrd=NULL;
    static WINDOW *WmenuListado=NULL;
    static WINDOW *WmenuBusqueda=NULL;
    char *MenuTitulo;
    char *MenuOpciones[24];

    int OpcionMenu, OpcionMenu2;
        
    // Creación de la ventana del Menú principal o
    // Si se ha pedido redibujar la pantalla (se borra y se vuelve a dibujar)
    if ((Wmenu == NULL) || (borrar == true)) {
        Wmenu=stdscr;
        werase(Wmenu);
        //Título de la Ventana
        wcolor_set(Wmenu,3,NULL);
        Cuadrado(Wmenu,2,28,3,25,DOSRAYAS);
        mvwprintw(Wmenu,3,30,"GESTION DE BIBLIOTECA");

        //Marco azul para toda la ventana
        wcolor_set(Wmenu,1,NULL);
        Cuadrado(Wmenu,0,0,20,80,DOSRAYAS);

        MenuTitulo=NULL;
        MenuOpciones[0]="Gestion de Libros";
        MenuOpciones[1]="Gestion de Ficheros de Libros";
        MenuOpciones[2]="Listado de Libros";
        MenuOpciones[3]="Busqueda por Autor";
        MenuOpciones[4]="Estadisticas";
        MenuOpciones[5]="Refrescar ventanas";
        MenuOpciones[6]="Salir";
        MenuOpciones[7]=NULL;
        Wmenu=DibujarMenu(Wmenu,5,22,MenuTitulo,MenuOpciones);

        if (borrar == true) {
            touchwin(Wmenu);
            wrefresh(Wmenu);
            return(0);
        }
    }

    while(true) {
        OpcionMenu=LeeOpcion(Wmenu,7);
        
        switch(OpcionMenu) {
        case 2:
            if (WmenuFich == NULL) {
                MenuTitulo="GESTION DE FICHEROS DE LIBROS";
                MenuOpciones[0]="Importar un fichero";
                MenuOpciones[1]="Sumar a un fichero";
                MenuOpciones[2]="Exportar a un fichero";
                MenuOpciones[3]="Descartar el fichero";
                MenuOpciones[4]="Salir";
                MenuOpciones[5]=NULL;
                WmenuFich=DibujarMenu(WmenuFich,5,40,MenuTitulo,MenuOpciones);
            }
            OpcionMenu=LeeOpcion(WmenuFich,5);
            OpcionMenu+=20;
            return(OpcionMenu);
        case 3:
            if (WmenuListado == NULL) {
                MenuTitulo="Listado de las Fichas";
                MenuOpciones[0]="*Metodo 1";
                MenuOpciones[1]="Listado por numero";
                MenuOpciones[2]="Listado por titulo";
                MenuOpciones[3]="Listado por autor";
                MenuOpciones[4]="*Metodo 2";
                MenuOpciones[5]="Listado por numero";
                MenuOpciones[6]="Listado por titulo";
                MenuOpciones[7]="Listado por autor";
                MenuOpciones[8]="* ";
                MenuOpciones[9]="Salir";
                MenuOpciones[10]=NULL;
                WmenuListado=DibujarMenu(WmenuListado,5,40,MenuTitulo,MenuOpciones);
            }
            OpcionMenu=LeeOpcion(WmenuListado,7);
            OpcionMenu=(OpcionMenu+30)*10;
            if ((OpcionMenu == 310) || (OpcionMenu == 340) || (OpcionMenu == 370))
                return(OpcionMenu);
            if (WmenuOrd == NULL) {
                MenuTitulo="Ordenacion de las Fichas";
                MenuOpciones[0]="Metodo de Seleccion";
                MenuOpciones[1]="Metodo de Burbuja";
                MenuOpciones[2]="Metodo de Insercion";
                MenuOpciones[3]="Metodo de Quicksort";
                MenuOpciones[4]="Salir";
                MenuOpciones[5]=NULL;
                WmenuOrd=DibujarMenu(WmenuOrd,5,40,MenuTitulo,MenuOpciones);
            }
            OpcionMenu2=LeeOpcion(WmenuOrd,5);
            OpcionMenu+=OpcionMenu2;
            return(OpcionMenu);
        case 4:
            if (WmenuBusqueda == NULL) {
                MenuTitulo="Busqueda por Autor";
                MenuOpciones[0]="Busqueda Secuencial";
                MenuOpciones[1]="Busqueda Binaria";
                MenuOpciones[2]="Arbol de Busqueda Binaria";
                MenuOpciones[3]="Salir";
                MenuOpciones[4]=NULL;
                WmenuBusqueda=DibujarMenu(WmenuBusqueda,5,40,MenuTitulo,MenuOpciones);
            }
            OpcionMenu=LeeOpcion(WmenuBusqueda,4);
            OpcionMenu+=40;
            return(OpcionMenu);
        default:
            return(OpcionMenu);
        }
    }
}