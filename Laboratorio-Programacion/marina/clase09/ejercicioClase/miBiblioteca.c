#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

void cargarDIrector(Director directores[],int index, int id){
    printf("Ingrese el nombre del director: ");
    scanf("%s",directores[index].nombre);

    printf("Ingrese el pais del director: ");
    scanf("%s",directores[index].paisOrigen);

    printf("Ingrese la fecha de nacimiento: ");
    scanf("%s",directores[index].fechNac);


    directores[index].id=id;
}

void cargarPelicula(Pelicula peliculas[],int index, int id, Director directores[]){
    printf("\nIngrese el titulo de la pelicula: ");
    fflush(stdin);
    scanf("%s",peliculas[index].titulo);

    printf("\nIngrese la nacionalidad de la pelicula");
    fflush(stdin);
    scanf("%s",peliculas[index].nacionalidad);

    printf("\nIngrese el año de la pelicula");
    fflush(stdin);
    scanf("%s",peliculas[index].year);

    printf("\nIngresar el id del director");
    fflush(stdin);
    scanf("%s",peliculas[index].idDirector);
    int idAchequear = peliculas[index].idDirector;
    while(buscarDirPorIndice(directores,500,idAchequear)==-1){
        printf("\nError al ingresar el id del director. No existe, ingreselo de nuevo: ");
        fflush(stdin);
        scanf("%s",peliculas[index].idDirector);
    }


    peliculas[index].idPelicula=id;
}

int buscarLugarVacioListaDirec(Director directores[], int largo){
    int i;
    int indice;
    for(i=0;i<largo;i++){
        if(directores[i].flagLibre==1){
            directores[i].flagLibre=0;
            indice = i;
            return indice;
            break;
        }
    }

    return -1;
}

int buscarLugarVacioListaPeliculas(Pelicula peliculas[], int largo){
    int i;
    int indicePel;
    for(i=0;i<largo;i++){
            if(peliculas[i].flagLibPelicula==1){
                peliculas[i].flagLibPelicula=0;
                indicePel = i;
                return i;
                break;
            }
    }

    return -1;

}


int buscarDirPorIndice(Director directores[],int largo, int idBuscado){
    int i;
    for(i=0;i<largo;i++){
        if(directores[i].flagLibre==0 && directores[i].id==idBuscado){
            return i;
            break;
        }
    }
    return -1;
}

int menu(){
    int buffer;
    printf("Elija una opcion del sistema\n\n");
    printf("Opcion 1: Altas de directores\n");
    printf("Opcion 2: ALtas de peliculas\n");
    printf("Opcion 3: Listado de peliculas\n");
    printf("Opcion 4: Baja de peliculas\n");
    printf("Opcion 5: Eliminar director\n");
    printf("\nSeleccione un numero: ");
    fflush(stdin);
    scanf("%d",&buffer);
    return buffer;
}

void listarPeliculas(Pelicula peliculas[],Director directores[], int largoPelis, int largoDir){
    int i;
    for(i=0;i<largoPelis;i++){
        if(peliculas[i].flagLibPelicula==0){
            int idDirector = peliculas[i].idDirector;
            int indexDirector = buscarDirPorIndice(directores,largoDir,idDirector);
            printf("\n%s\t",peliculas[i].titulo);
            printf("\n%s\t",peliculas[i].year);
            printf("\n%s\t",directores[indexDirector].nombre);

        }
    }
}

