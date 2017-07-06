#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"
#include "programador.h"
#include "administrativo.h"
#include "ArrayList.h"

int parseoArchivo(FILE* fp, ArrayList* listaTotal){
    char lineas[50];
    int* auxId;
    int* auxType;
    char auxName[20];
    char auxData[20];
    int returnAux = 0;
    while(fgets(lineas,sizeof(lineas)-1,fp)!= NULL){
        sscanf(lineas,"%d,%d,%[^,],%[^\n]",auxId,auxType,auxName,auxData);
        if(*auxType==1){
            Programador* p = new_programador();
            p_setNom(p,auxName);
            p_setLenguaje(p,auxData);
            al_add(listaTotal,p);
        }else if(*auxType==2){
            Administrativo* a = new_admin();
            int auxD;
            ad_setNom(a,auxName);
            auxD = atoi(auxData);
            ad_setArea(a,auxD);
            al_add(listaTotal,a);
        }else{
            returnAux = -1;
        }

    }
    return returnAux;
}

int initBase(ArrayList* listaTotal){
    int returnAux = -1;
    FILE* fp = fopen("data.txt","r");
    if(fp != NULL){
        parseoArchivo(fp,listaTotal);
        returnAux = 0;
    }
    fclose(fp);

    return returnAux;
}


int lecturaArraylist(ArrayList* listaTotal, int i){
    Object* typeObject =(Object*)al_get(listaTotal,i);
    Programador* p;
    Administrativo* a;
     switch(typeObject->type)
        {
            case 1:
                p = (Programador*) typeObject;
                printf("PROGRAMADOR. Nombre:%s. Lenguaje:%s\r\n",p->nombre,p->lenguaje);
                break;

            case 2:
                a = (Administrativo*) typeObject;
                printf("ADMINISTRATIVO. Nombre:%s. Area:%d\r\n",a->nombre,a->area);
                break;
        }
        return 0;
}
