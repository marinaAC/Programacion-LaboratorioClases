#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

/**
    1) Realizar una funci�n para cargar los datos de una persona en una struct, para ello se debe definir una estructura con los campos nombre, edad, dni.

    A) La funci�n tendr� el siguiente prototipo:

    int loadPerson(struct S_Person* pPerson);

    B) La funci�n deber� devolver un 1 si los datos ingresados son correctos, y un 0 si no lo son.

    C) Hacer otra funci�n que reciba un puntero a la estructura e imprima por pantalla los datos, el prototipo es:

    void printPerson(struct S_Person* pPerson);

    D) Escribir un programa para probar las funciones.
**/

int main()
{
    S_Persona pers;
    if(loadPerson(&pers)){
        printf("Datos correctos\r\n");
        printPerson(&pers);
    }else{
        printf("Datos incorrectos");
    }
    return 0;
}
