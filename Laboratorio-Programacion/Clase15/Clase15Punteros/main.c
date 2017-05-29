#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************************************************
  *  1) Escribir 4 funciones que reciban un array de n�meros int y su tama�o, e impriman los n�meros por pantalla.
  *
  *  * 1era funcion: Recibe el array como vector y accede a los datos utilizando notaci�n vectorial ([])
  *
  *  * 2da funcion: Recibe el array como vector y accede a los datos utilizando aritmetica de punteros
  *
  *  * 3era funcion: Recibe el array como puntero y accede a los datos utilizando notaci�n vectorial ([])
  *
  *  * 4da funcion: Recibe el array como puntero y accede a los datos utilizando aritmetica de punteros
******************************************************************************************************************/

void printArray1(int arrayP[], int length){
    int i;
    for(i=0;i<length;i++){
        printf("%d",arrayP[i]);
    }
    printf("\r\n");
}
/**
    Accedemos a la impresion con aritmetica de punteros

*/
void printArray2(int arrayP[], int length){
    int i;
    for(i=0;i<length;i++){
        printf("%d",*(arrayP+i);
    }
    printf("\r\n");
}
int main()
{

    return 0;
}


