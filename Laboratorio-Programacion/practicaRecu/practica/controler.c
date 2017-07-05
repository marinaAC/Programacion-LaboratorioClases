#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controler.h"
#include "ArrayList.h"
#include "destinatario.h"


static ArrayList* listaDestinatarios;
static ArrayList* listaNegra;



int initController(ArrayList* listaDestinatariosAux,ArrayList* listaNegraAux){
    int returnAux = -1;
    if(listaDestinatariosAux != NULL || listaNegraAux != NULL){
        returnAux = 0;
        listaNegra = listaNegraAux;
        listaDestinatarios = listaDestinatariosAux;
        printf("en teoria cargo todo");
    }
    return returnAux;
}

int cargarListaController(void){
    int returnAux = -1;
    cargarBase(listaDestinatarios);
    cargarListaNegra(listaNegra);
    returnAux = 0;
    return returnAux;
}
