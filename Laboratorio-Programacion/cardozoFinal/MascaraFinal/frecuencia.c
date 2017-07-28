#include <stdio.h>
#include <stdlib.h>
#include "frecuencia.h"

FrecArchivo* frec_newFrecuenciaArch(void){
    FrecArchivo* f = (FrecArchivo*)malloc(sizeof(FrecArchivo));
    return f;
}


void frec_delete(FrecArchivo* this){
    free(this);
}

//SETTERS
int frec_setNombre(FrecArchivo* this, char* name){
    int returnAux = -1;

    if(this != NULL){
        strncpy(this->nombre,name,sizeof(this->nombre));
        returnAux = 0;
    }

    return returnAux;
}

int frec_setValor(FrecArchivo* this, char* valor){
    int returnAux = -1;
    int auxValor;
    if(this != NULL){
        auxValor = atoi(valor);
        if(auxValor>0){
            this->valor=auxValor;
            returnAux =0 ;
        }
        returnAux = 1;
    }
    return returnAux;
}



//GETTERS

char* frec_getNombre(FrecArchivo* this){
    return this->nombre;
}

int* frec_getValor(FrecArchivo* this){
    return this->valor;
}
