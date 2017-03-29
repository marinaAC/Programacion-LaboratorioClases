#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"


/*
    Crear una funci�n que permita ingresar un numero al usuario
    y lo retorne. Crear una funci�n que reciba el radio de un c�rculo
    y retorne su �rea Utilizar las funciones de los puntos 1 y 2
    para hacer un programa que calcule el �rea de un c�rculo cuyo
    radio es ingresado por el usuario.
*/
int main()
{
    char mensaje[] = "\nIngrese el radio del ciculo: ";
    char mensajeError[]="\nIngrese un valor entre 0.0 y 500.0";
    float max=500.0;
    float min=0.0;
    float numeroArea;
    numeroArea=obtenerFloat(mensaje,mensajeError,max,min);
    numeroArea=areaCir(numeroArea);
    printf("El area del circulo es de %.3f",numeroArea);
    return 0;
}
