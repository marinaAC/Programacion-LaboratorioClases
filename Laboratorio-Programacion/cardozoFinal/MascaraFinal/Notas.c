#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notas.h"


Nota* nota_newNota(void){
    Nota* n = (Nota*)malloc(sizeof(Nota));
    return n;
}


void nota_delete(Nota* this){
    free(this);
}

//SETTERS
int nota_setNombre(Nota* this, char* name){
    int returnAux = -1;

    if(this != NULL){
        strcpy(this->nombre,name);
        returnAux = 0;
    }

    return returnAux;
}

int nota_setFrecuencia(Nota* this, int* freq){
    int returnAux = -1;
    //int auxFreq;
    if(this != NULL){
       //auxFreq = atoi(freq);
       if(freq>0){
            this->freq=freq;
            returnAux = 0 ;
        }
        returnAux = 1;
    }
    return returnAux;
}

int nota_setDuration(Nota* this, char* duration){
    int returnAux = -1;
    int auxDur;
    if(this != NULL){
        auxDur = atoi(duration);
        if(auxDur>0){
            this->duration=auxDur;
            returnAux =0 ;
        }
        returnAux = 1;
    }
    return returnAux;
}

int nota_setVolumen(Nota* this, char* volumen){
    int returnAux = -1;
    int auxVol;
    if(this != NULL){
        auxVol = atoi(volumen);
        if(auxVol>0){
            this->volumen=auxVol;
            returnAux =0 ;
        }
        returnAux = 1;
    }
    return returnAux;
}


//GETTERS

char* nota_getNombre(Nota* this){
    return this->nombre;
}

int* nota_getFrecuencia(Nota* this){
    return this->freq;
}

int* nota_getDuration(Nota* this){
    return this->duration;
}

int* nota_getVolumen(Nota* this){
    return this->volumen;
}

//PRINT

void nota_print(Nota* this){
    printf("--------------------------------\n");
    printf("Nota: %s | Frecuencia: %d | Duration: %d | Volumen: %d\n",this->nombre,this->freq,this->duration,this->volumen);
    printf("--------------------------------\n");
}
