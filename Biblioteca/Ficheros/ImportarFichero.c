/*****************************************
 * Nombre: ImortarFichero
 * Argumentos: LIBRO **Fichas:   Puntero al array de libros
 *             WINDOW *Wfichero: Ventana para capturar el nombre del fichero
 *             bool sumar:       Si es true las fichas de libros se añaden a las existentes,
 *                               si es false la lista de libros tiene que estar vacía.
 * Descripción: Lee el nombre del fichero que contendrá los datos a importar. Carga los libros del fichero
 *              en el array de libros, dimensionándolo si es necesario y descartando los que no tengan título o autor.
 * Reglas de uso: 
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"

void ImportarFichero(LIBRO **Fichas,WINDOW *Wfichero,bool sumar)
{
   
    // Código del alumno
    
    // Variables
    FILE *fichero;
    char nombreFichero[80];
    char linea[200];
    char *token;
    int numLibrosFichero = 0;
    LIBRO *aux;
    bool error = false;





    // Abrir el fichero
    fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) {
        mvwprintw(Wfichero, 2, 1, "Error al abrir el fichero.");
        wrefresh(Wfichero);
        endwin();
        return;
    }


    // Leemos los libros del fichero

    while (fgets(linea,200,fichero) != NULL)
    {
        // Separamos los campos del libro
        token = strtok(linea,";");
        if (token == NULL)
        {
            error = true;
            break;
        }
        strcpy((*Fichas)[Estadisticas.NumeroFichas].Titulo,strsep(&token,"\n"));
        token = strtok(NULL,";");
        if (token == NULL)
        {
            error = true;
            break;
        }
        strcpy((*Fichas)[Estadisticas.NumeroFichas].ApellAutor,strsep(&token,"\n"));
        token = strtok(NULL,";");
        if (token == NULL)
        {
            error = true;
            break;
        }
        strcpy((*Fichas)[Estadisticas.NumeroFichas].NomAutor,strsep(&token,"\n"));
        token = strtok(NULL,";");
        if (token == NULL)
        {
            error = true;
            break;
        }
        strcpy((*Fichas)[Estadisticas.NumeroFichas].Genero,strsep(&token,"\n"));
        token = strtok(NULL,";");

        if (token == NULL)
        {
            error = true;
            break;
        }
        strcpy((*Fichas)[Estadisticas.NumeroFichas].Editorial,strsep(&token,"\n"));
        token = strtok(NULL,";");
        if (token == NULL)
        {
            error = true;
            break;
        }
        strcpy((*Fichas)[Estadisticas.NumeroFichas].Coleccion,strsep(&token,"\n"));

        // Comprobamos si el libro tiene título y autor
        if ((*Fichas)[Estadisticas.NumeroFichas].Titulo[0] == '\0' || (*Fichas)[Estadisticas.NumeroFichas].ApellAutor[0] == '\0' || (*Fichas)[Estadisticas.NumeroFichas].NomAutor[0] == '\0')
        {
            error = true;
            break;
        }

        
        Estadisticas.NumeroFichas++;
    }

    // Cerrar el fichero
    fclose(fichero);


    
}