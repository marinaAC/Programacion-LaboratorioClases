#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"



int main()
{
    Director directores[500];
    Pelicula peliculas[1000];
    int contadorIdDirector = 0;
    int contadorIdPeliculas = 0;
    int i;
    //Buscar el espacio libre para guardar el ingreso de los datos. Podes declarar una bandera sino podes preguntar si el id es -1

    for(i=0;i<500;i++){
        directores[i].flagLibre=1;
    }

    for(i=0;i<1000;i++){
        peliculas[i].flagLibPelicula=1;
    }


    int opcion = menu();
    switch(opcion){
        case 1:
            contadorIdDirector++;
            int indexVacioDire= buscarLugarVacioListaDirec(directores, 500);
            if(indexVacioDire>=0){
                cargarDIrector(directores,indexVacioDire,contadorIdDirector);
            }
        break;
        case 2:
            contadorIdPeliculas++;
            int indexVacioPeli = buscarLugarVacioListaPeliculas(peliculas, 1000);
            if(indexVacioPeli>=0){
                cargarPelicula(peliculas,indexVacioPeli,contadorIdPeliculas,directores);
            }
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
    }


    return 0;
}
