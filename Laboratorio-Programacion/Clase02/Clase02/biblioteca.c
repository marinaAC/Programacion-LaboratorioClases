#include <stdio.h>
#include <stdlib.h>

float obtenerNumero(char mensaje[]){
    float buffer;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&buffer);
    return buffer;
}

float promedio(float numerosSumados,float cantidadDeVeces){
    float numTotal;
    float cantidad;
    float resultado;
    resultado = numTotal/cantidad;
    return resultado;

}

float suma(float numero1, float numero2){
    float num1;
    float num2;
    float result;
    fflush(stdin);
    result = num1 + num2;
    return result;
}
