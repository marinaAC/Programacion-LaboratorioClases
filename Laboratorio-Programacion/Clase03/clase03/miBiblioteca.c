#include <stdio.h>
#include <stdlib.h>

/*EJERCICIO CLASE03 */

int obtenerInt(char mensaje[],char mensajeError[],int maximo, int minimo){
    //pasar maximos y minimos para saber el limite del valor de lo que se pide
    int buffer;
    printf("%s",mensaje);
    scanf("%d",&buffer);

     while(buffer<minimo || buffer>maximo){
        printf("%s",mensajeError);
        scanf("%d",&buffer);
    }
    return buffer;
 }

 float obtenerFloat(char mensaje[],char mensajeError[],float maximo, float minimo){
    float buffer;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&buffer);

     while(buffer<minimo || buffer>maximo){
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%f",&buffer);
    }
    return buffer;
 }

 char obtenerChar(char mensaje[],char mensajeError[],char maximo, char minimo){
    char buffer;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&buffer);

     while(buffer<minimo || buffer>maximo){
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%c",&buffer);
    }
    return buffer;
 }

 float promedio(float numerosSumados,float cantidadDeVeces){
    float resultado;
    resultado = numerosSumados/cantidadDeVeces;
    return resultado;

}

float suma(float numero1, float numero2){
    float result;
    fflush(stdin);
    result = numero1 + numero2;
    return result;
}

float areaCir(float radio){
    float resultado;
    resultado=3.14*(radio*radio);
    return resultado;
}
