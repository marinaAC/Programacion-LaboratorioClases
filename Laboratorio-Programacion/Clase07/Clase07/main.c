#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#define MAXINPUT 100

int main()
{
    char input[MAXINPUT];
    /* La funcion strlen, pertene a la biblioteca string.h y nos permite contar cuantos caracteres hay
    int length;
    length = strlen(input);
    */
    char continuar;
    do{
        printf("Ingrese el texto: ");
        fflush(stdin);
        scanf("%s", input);


        if(esNumerico(input)){
            printf("\nEl valor ingresado es un numero");
        }
        if(soloLetras(input)){
            printf("\nEl valor ingresado esta formado solo por letras");
        }
        if(alfaNum(input)){
            printf("\nEl valor ingresado es alfa numerico");
        }
        if(esTel(input)){
            printf("\nEl valor ingresado es un numero de telefono valido");
        }

        printf("\nPara continuar oprima s: ");
        fflush(stdin);
        scanf("%c",&continuar);
    }while(continuar=='s'||continuar=='S');

    return 0;
}
