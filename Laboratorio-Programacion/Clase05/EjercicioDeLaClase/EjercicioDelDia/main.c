#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 5
#include "miBiblioteca.h"

int main()
{
    /*  Para compactar un array, primero declaro una con su maximo correspondiente, luego
        despues de cargarle los datos, creo la funcion compactar, en la cual le paso, el array, el maximo,
        y el valor del indice al cual deseo eliminar.
        Luego sobreescribo con indice de la siguiente posicion.
    */
    int numero[MAXIMO]= {12,10,8,20,3};
    int array2[MAXIMO]={0,0,0,0,0};
    int i;
    int cantidadArray= 5;
   /* int eliminar=2;*/
    for(i=0;i<cantidadArray;i++){
        printf("Ingrese el valor de los array: \n");
        fflush(stdin);
        scanf("%d",&numero[i]);
    }
    /*Simplemente la funcion compactar
    nuevoTamanioArray=compactar(numero,MAXIMO,eliminar);
    for(i=0;i<nuevoTamanioArray;i++){
        printf("El numero del array es: %d \n", numero[i]);
    }
    */
    /* Con la funcion ordenar, asigno en una nueva array el valor menor, compactandolo por su indice*/
    ordernar(numero,cantidadArray,array2);
    for(i=0;i<cantidadArray;i++){
        printf("Valor del array nuevo %d\n", array2[i]);
    }
    return 0;
}
