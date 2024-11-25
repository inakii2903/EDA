/*****************************************
 * Nombre: main (a compilar como Biblioteca.exe)
 * Argumentos: N/A
 * Descripción: Programa principal de la aplicación de Gestión de Biblioteca.
 *              Implementa el flujo del menú principal, sus opciones e invoca
 *              a las funciones principales.
 * Reglas de uso: Ejecutar sobre una ventana de "cmd" con al menos 20 filas y
 *                80 columnas. No es necesario privilegio de administración.
 * Código de Retorno: '0' si no ha habido errores. -1 en otro caso y el mensaje
 *                    de error se muestra en stderr.
 * Programador: JMSM (Sept-24)
 *****************************************/

//Include general
#include "Biblioteca.h"

// Programa principal de Gestión de Biblioteca

void main()
{
    int OpcionMenu;
    char Tecla;
    WINDOW *Wauxiliar;

    //Arrays para almacenar los libros
    LIBRO *Fichas=NULL;
    LIBRO **Orden=NULL;

    //Inicializacion Variables GLobales
    InitGlobal();

    // Inicializar Curses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    
    // Comprobación si la ventana es suficientemente grande
    if (LINES < 20) {
        endwin();
        fprintf(stderr,"La ventana tiene %d líneas\n",LINES);
        fprintf(stderr, "Se necesitan al menos 20 líneas. Por favor agrande la ventana\n");
        fprintf(stderr,"Pulse una tecla para finalizar.\n");
        getch();
        exit(0);
    }

    // Inicializar colores
    if (has_colors()) {
       start_color();
       init_pair(1,COLOR_BLUE,COLOR_BLACK);
       init_pair(2,COLOR_CYAN,COLOR_BLACK);
       init_pair(3,COLOR_GREEN,COLOR_BLACK);
       init_pair(4,COLOR_WHITE,COLOR_RED);
       init_pair(5,COLOR_BLACK,COLOR_YELLOW);
       init_pair(6,COLOR_YELLOW,COLOR_BLACK);
       init_pair(7,COLOR_YELLOW,COLOR_CYAN);
       init_pair(8,COLOR_CYAN,COLOR_BLUE);
       init_pair(9,COLOR_YELLOW,COLOR_BLUE);
    }

    //Bucle infinito capturando la opción de menu deseada
    while(true) {
        OpcionMenu=Menu(false);

        /* La opción devuelta por menú será:
            - Opción principal,si no hay subopciones
            - (Opción principal)*10 + Subopción, si solo hay un submenú
            - (Opción principal)*100 + (Subopción_1)*10 + Subopción_2, sin hay dos submenús
        */

        switch(OpcionMenu) {
            case 1:     //Gestión de Fichas de Libros
                Libros(&Fichas);
                break;
            case 21:    //Importar fichero
                Fichero(&Fichas,OpcionMenu);
                break;
            case 22:    //Sumar fichero
                Fichero(&Fichas,OpcionMenu);
                break;
            case 23:    //Exportar fichero
                Fichero(&Fichas,OpcionMenu);
                break;
            case 24:    //Descartar fichero
                Fichero(&Fichas,OpcionMenu);
                break;
            case 25:    //Salir
                break;
            case 310:   //Listado por número (Método 1)
                if (Estadisticas.NumeroFichas == 0) {
                    VentanaError("No hay fichas de libros");
                    break;
                }
                Orden=InitOrden(Fichas);
                
                Listado1(Orden,Estadisticas.NumeroFichas,Fichas);
                free(Orden);
                break;
            case 321:   //Listado por título. Orden Selección. (Método 1)
            case 322:   //Listado por título. Orden Burbuja. (Método 1)
            case 323:   //Listado por título. Orden Inserción. (Método 1)
            case 324:   //Listado por título. Orden Quicksort. (Método 1)
            case 331:   //Listado por autor. Orden Selección. (Método 1)
            case 332:   //Listado por autor. Orden Burbuja. (Método 1)
            case 333:   //Listado por autor. Orden Inserción. (Método 1)
            case 334:   //Listado por autor. Orden Quicksort. (Método 1)
            case 340:   //Listado por número. (Método 2)
                if (Estadisticas.NumeroFichas == 0) {
                    VentanaError("No hay fichas de libros");
                    break;
                }
                Orden=InitOrden(Fichas);
                Listado2(Orden,Estadisticas.NumeroFichas,Fichas);
                free(Orden);
                break;
            case 352:   //Listado por título. Orden Burbuja. (Método 2)
            case 353:   //Listado por título. Orden Inserción. (Método 2)
            case 354:   //Listado por título. Orden Quicksort. (Método 2)
            case 361:   //Listado por autor. Orden Selección. (Método 2)
            case 362:   //Listado por autor. Orden Burbuja. (Método 2)
            case 363:   //Listado por autor. Orden Inserción. (Método 2)
            case 364:   //Listado por autor. Orden Quicsort. (Método 2)
                Wauxiliar=newwin(16,76,2,2);
                DibujarScroll(Wauxiliar);
                wrefresh(Wauxiliar);
                VentanaError("Opcion no implementada");
                delwin(Wauxiliar);
                break;
            case 325:   //Salir
            case 335:
            case 355:
            case 365:
            case 370:
                break;
            case 41:    //Busqueda Secuencial por autor
            case 42:    //Busqueda Binaria por autor
            case 43:    //Busqueda Arbol binario por autor
                Wauxiliar=newwin(4,76,5,2);
                DibujarLeerAutor(Wauxiliar);
                wrefresh(Wauxiliar);
                VentanaError("Opcion no implementada");
                delwin(Wauxiliar);
                break;
            case 44:    //Salir
                break;
            case 5:     //Ver Estadísticas
                VerEstadisticas();
                break;
            case 6:     //Refrescar pantalla
                OpcionMenu=Menu(true);
                VentanaError("Las Ventanas han sido Refrescadas");
                break;
            case 7:     //Salir de la aplicación
                Tecla=VentanaSN("Esta seguro de querer salir de la aplicacion (S/N)?");
                if (Tecla == 'S') {
                    endwin();
                    exit(0);
                }
                break;
            default:
                VentanaError("Opcion Incorrecta");
                break;
        }
    }

    exit(0);
}