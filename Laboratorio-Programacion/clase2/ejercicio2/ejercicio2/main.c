#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int main(){
    int maximo = 50;
    int minimo = 18;
    int edadPedida;
    char mensaje[] = "\nIngrese la edad del usuario: ";
    char mensajeError[] = "Error, no se encuentra dentro de la edad permitida. Ingrese de nuevo:";
    edadPedida = obtenerInt(mensaje,mensajeError,maximo,minimo);
    printf("La edad ingresada es de %d",edadPedida);

    float max = 5.0;
    float min = 2.0;
    float valorIngresado;
    char mensajeF[] = "\nIngrese el primer valor: ";
    char mensajeErrorF[] = "Error, no se encuentra dentro del rango permitido. Ingrese de nuevo: ";
    valorIngresado = obtenerFloat(mensajeF,mensajeErrorF,max,min);
    printf("El valor ingresado es  %f",valorIngresado);

    char mx = 'O';
    char mn = 'C';
    char caracterIngresado;
    char menC[] = "\nIngrese la primera letra: ";
    char menEC[] = "Error, no se encuentra dentro del rango permitido. Ingrese de nuevo: ";
    caracterIngresado = obtenerChar(menC,menEC,mx,mn);
    printf("El valor ingresado es  %c",caracterIngresado);

    return 0;
}
