#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#define MAX 100
int main()
{
    int edad[MAX];
    int contador=0;
    char continuar='s';
    int suma=0;
    float promedio;
    do{
        printf("Ingrese la edad de la persona\n");
        fflush(stdin);
        scanf("%d",&edad[contador]);
        suma= suma+edad[contador];
        printf("\nsuma: %d\n",suma);
        printf("\ncontador antes de incrementar: %d\n",contador);
        contador++;
        printf("contador despues de incrementar %d\n",contador);
        printf("Si desea continuar, ingrese s: \n");
        fflush(stdin);
        scanf("%c",&continuar);
    }while(continuar=='s');
    promedio=prom(suma,contador);
    printf("El promedio de las edades es %.2f", promedio);
    return 0;
}
