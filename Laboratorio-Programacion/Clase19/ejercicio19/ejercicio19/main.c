#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
/**
    1) Realizar un programa que permita ingresar los datos de una persona (usar funciones de utn.h):

    char name[32];
    char surname[32];
    int  age;

    A) Crear un archivo binario llamado BIN.DAT el cual contendrá estructuras con los campos anteriores
    y guardar al final del mismo la estructura con los datos ingresados. Luego se preguntará si se desea agregar mas datos o salir.

    B) Utilizando el archivo BIN.DAT (se supone que tiene datos válidos cargados), realizar un programa
    que permita buscar un apellido que ingresa el usuario y una vez encontrado muestre los datos en pantalla.
    De no encontrar el nombre se debe informar por medio de un mensaje de error

**/
int main()
{
    S_Pers p;
    char out='s';
    while(out=='s'){
        loadData(&p);
        savePerson(&p);
        out = getChar("Ingresar una nueva persona? s/n");
    }
    char surnameToFind[64];
    getStringSoloLetras("Ingrese apellido a buscar en el archivo: ",surnameToFind);
    S_Pers* pFound = readPerson(surnameToFind);
    if(pFound!=NULL){
        printf("Se encontro: nombre:%s,apellido:%s,edad:%d \r\n", pFound->name,pFound->surname,pFound->age);
        free(pFound);
    }else{
        printf("el apellido ingresado no esta en el archivo");
    }
    return 0;
}
