#include <stdio.h>
#include <stdlib.h>
#define REGULAR 0
#define URGENTE 1

int obtenerDni(){
    int numero;
    printf("Ingrese su dni \n");
    scanf("%d",&numero);
    return numero;
}

int menu(){
    int buffer;
    printf("Ingrese el tramite que desea realizar\n");
    printf("Opcion 1: TRAMITE URGENTE\n");
    printf("Opcion 2: TRAMITE REGULAR\n");
    printf("Opcion 3: PROXIMO CLIENTE\n");
    printf("Opcion 4: LISTAR\n");
    printf("Opcion 4: INFORMAR\n");
    printf("Ingrese su opcion: ");
    scanf("%d",&buffer);
    return buffer;
}


