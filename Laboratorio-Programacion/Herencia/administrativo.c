#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"
#include "administrativo.h"

Administrativo* new_admin(){

    Administrativo* aux = (Administrativo*)malloc(sizeof(Administrativo));

    return aux;
}


char* ad_getNom(Administrativo* this){
   return this->nombre;
}

int* ad_getArea(Administrativo* this){
    return this->area;
}

int ad_setNom(Administrativo* this, char* nombre){
    strncpy(this->nombre,nombre,sizeof(this->nombre));
    return 0;
}

int ad_setArea(Administrativo* this, int area){
    this->area = area;
    return 0;
}
