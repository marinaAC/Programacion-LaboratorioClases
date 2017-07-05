#include <stdio.h>
#include <stdlib.h>
#include "controler.h"
#include "base.h"


int main(){
    ArrayList* listaDestinatarios = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    initController(listaDestinatarios,listaNegra);


    return 0;
}
