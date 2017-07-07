#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Productos.h"

void impresionLista(ArrayList* listaProd){
    int i;
    S_Productos* prod;
    for(i=0;i<listaProd->size-1;i++){
        prod=al_get(listaProd,i);
        printf("%d ,%s, %s, %d\n", prod->id,prod->name,prod->version,prod->category);
    }

}

int menu (){


}

