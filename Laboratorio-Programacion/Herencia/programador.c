#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"
#include "programador.h"

Programador* new_programador(){
    Programador* aux = (Programador*)malloc(sizeof(Programador));
    return aux;
}

char* p_getNom(Programador* this){
    return this->nombre;
}

char* p_getLenguaje(Programador* this){
    return this->lenguaje;
}

int p_setNom(Programador* this, char* nombre){
    strncpy(this->nombre,nombre,sizeof(this->nombre));
    return 0;
}

int p_setLenguaje(Programador* this, char* lenguaje){
    strncpy(this->lenguaje,lenguaje,sizeof(this->lenguaje));
    return 0;
}
