#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD 20

int main()
{
    int edad[CANTIDAD];
    int cont=0;
    char seguir='s';
    float resultado;


    do {

        printf("\nIngrese edad: ");
        fflush(stdin);
        scanf("%d", &edad[cont]);

        printf("\nAntes del incremento: %d", cont);

        cont++;

        printf("\nDespues del incremento: %d", cont);

        printf("\nDesea seguir? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir=='s');

    switch(menu())
    {
    case 1:

        resultado = promedio(edad, cont);
        printf("\nEl promedio de las edades es: %.2f", resultado);

        break;
    case 2:

        printf("\nEdad maxima: %d", max(edad, cont));

        break;
    case 3:

        printf("\nEdad minima: %d", min(edad, cont));

        break;
    case 4:
        seguir=='n';
        break;
    }



    return 0;
}

