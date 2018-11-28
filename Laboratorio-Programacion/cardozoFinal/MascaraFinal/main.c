#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Notas.h"
#include "frecuencia.h"
#include "Base.h"
#include "Interface.h"

int main()
{
    ArrayList* listaMelodias = al_newArrayList();
    ArrayList* listaFrecuenciaNotas = al_newArrayList();

    printf("1\n");
    getchar();

    parseoFrec(listaFrecuenciaNotas);

    printf("2\n");
    getchar();
    base_parse(listaMelodias,listaFrecuenciaNotas);

    printf("3\n");
    getchar();
    ArrayList* listaClonada = al_clone(listaMelodias);
    ecualizarSonido(listaClonada);
    int i;
    for(i=0;i<listaClonada->size-1;i++){
        Nota* nota = al_get(listaClonada,i);
        nota_print(nota);
    }

    return 0;
}
