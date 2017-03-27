#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    float numPrincipal;
    float sumaTotalNumeros;
    float max;
    float min;
    float prom;
    int flag=0;
    int i;
    char men[]="Ingrese el numero";
    for(i=0;i<5;i++){
        numPrincipal=obtenerNumero(men);
        sumaTotalNumeros=numPrincipal+sumaTotalNumeros;
        if(flag==0){
            max=numPrincipal;
            min=numPrincipal;
            flag=1;
        }
        if(numPrincipal>max){
            max=numPrincipal;
        }
        if(numPrincipal<min){
            min=numPrincipal;
        }

    }
    prom=sumaTotalNumeros/5.0;
    printf("\nEl promedio de los numeros ingresados es %f", prom);
    printf("\nEl numero maximo es %f, el numero minimo es %f",max,min);
    printf("\nsumaaaaaaaaaaaaaaaaaaaa %f",sumaTotalNumeros);
    return 0;
}
