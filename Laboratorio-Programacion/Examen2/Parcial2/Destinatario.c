#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"


typedef struct{
    char nombre[20];
    char email[20];
}EDestinatario;


EDestinatario* newDestinatario(void){
    EDestinatario* nuevoDestinatario;
    nuevoDestinatario = (EDestinatario*)malloc(sizeof(EDestinatario));
    if(nuevoDestinatario==NULL){
        free(nuevoDestinatario);
    }
    return nuevoDestinatario;
}


