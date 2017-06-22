#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "miBiblioteca.h"

int main()
{
    EDireccionesEmail* listBlack;
    EDireccionesEmail* destinatario;

    ArrayList* listaB;
    ArrayList* listaDest;
    listaB = al_newArrayList();
    listaDest = al_newArrayList();

    printf("Prueba si carga archivos\n");
    agregarListaNegra(listaDest);
    destinatario = al_get(listaDest,0);
    printf("%s",destinatario->email);


    return 0;
}
