#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/

int main()
{
    Employee* aux;
    ArrayList* lista;
    lista = al_newArrayList();
    //len
    FILE* fp;
    fp = fopen("data.csv","r");
    if(fp == NULL){
        printf("No se pudo cargar el archivo!!!");
        return -1;
    }
    parserEmployee(fp,lista);
    printf("Se cargo con exito");
    fclose(fp);

    int len = al_len(lista);
    printf("%d",len);

    int i;
    for(i=0;i<len;i++){
        Employee* obtenido = al_get(lista,i);
        Employee* obtenido2 = al_get(lista,i+1);
        al_sort(lista,compararPersonas(obtendio->name,obtenido2->name),1);
        printf("id: %d - nombre: %s\n",obtenido->id, obtenido->name);
    }

    printf("%d",len);
    return 0;
}


int compararPersonas(void* auxA, void* auxB){
    if(strcmp(((Employee*)auxA)->name,((Employee*)auxB)->name)>0){
        return 1;
    }
    if(strcmp(((Employee*)auxA)->name,((Employee*)auxB)->name)<0){
        return -1;
    }
    return 0;
}
