#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Productos.h"



S_Productos* newProducto(){
    S_Productos* aux = (S_Productos*)malloc(sizeof(S_Productos));
    return aux;
}

void setIdProcut(S_Productos* this, int id){
    this->id = id;
}

void setNameProduct(S_Productos* this, char* name){
    strncpy(this->name,name,sizeof(this->name));
}

void setVersionProduct(S_Productos* this, char* number){
    strncpy(this->version,number,sizeof(this->version));
}

void setCategory(S_Productos* this, int number){
    this->category = number;
}

