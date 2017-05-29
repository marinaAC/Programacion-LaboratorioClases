#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
/**********************************************************************************************************
*
*   1) Construir una función llamada "getDynamicString" que permita al usuario ingresar un texto
*   y devuelva un puntero a un espacio de memoria donde esta almacenado el texto ingresado.
*   Se requiere el uso de memoria dinámica.
*
***********************************************************************************************************/


int main()
{
    char* pName = getDynamicString("Ingresa tu nombre: ");
    printf("Tu nombre es: %s", pName);
    free(pName);
    return 0;
}
