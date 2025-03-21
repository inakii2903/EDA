/*****************************************
 * Nombre: BusquedaSecuencial
 * Argumentos: LIBRO *Fichas:       Array de las fichas de libros
 * Descripción: Después de capturar los apellidos de un autor, busca las fichas de libros de ese autor
 *              por el método de búsqueda por selección.
 *              La comparación de los apellidos se hace en mayúsculas. 
 *              Después se muestran los resultados en una pantalla de scroll.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Busqueda.h"

void BusquedaSecuencial(LIBRO *Fichas)
{
    char *Autor;
    LIBRO **Resultado=NULL;
    int Hallados=0;
    struct timeval inicio, fin;
    int i;
    
    // Añadir aquí la definición del resto de variables usadas
    
    if ((Autor=LeerAutor()) == NULL)
        return;

    gettimeofday(&inicio,NULL);



    Resultado=(LIBRO **)malloc(sizeof(LIBRO *)*Estadisticas.NumeroFichas);
    if (Resultado == NULL) {
        VentanaError("Error en la asignación de memoria");
        return;
    }

    // Si el autor tiene dos apellidos, solo tomar el primero
    char *space = strchr(Autor, ' ');
    if (space != NULL) {
        *space = '\0';
    }

    for ( i = 1; i < Estadisticas.NumeroFichas; i++) {
        // Si el autor en la ficha tiene dos apellidos, solo tomar el primero
        char *spaceFicha = strchr(Fichas[i].ApellAutor, ' ');
        if (spaceFicha != NULL) {
            *spaceFicha = '\0';
        }

        if (strcasecmp(Fichas[i].ApellAutor, Autor) == 0) {
            Resultado[Hallados] = &Fichas[i];
            Hallados++;
        }

        // Restaurar el apellido completo en la ficha
        if (spaceFicha != NULL) {
            *spaceFicha = ' ';
        }
    }



    gettimeofday(&fin,NULL);
    Estadisticas.TiempoBusquedaSecuencial=DifTiempo(inicio,fin);

    if (Hallados == 0) {
        VentanaError("No hay autores que cumplan el criterio");
        return;
    }
    Listado1(Resultado,Hallados,Fichas);
    free(Resultado);
    return;
    
}





