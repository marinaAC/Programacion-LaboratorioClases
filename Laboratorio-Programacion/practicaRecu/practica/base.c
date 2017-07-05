#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinatario.h"
#include "ArrayList.h"



int cargarBase(ArrayList* listaDestinatarios){
    int returnAux = 0;
    char auxName[300];
    char auxEmail[400];
    char auxLinea[500];
    FILE* fp = fopen("destinatarios.csv", "r");
    if(fp != NULL){
        while(fgets(auxLinea,sizeof(auxLinea)-1,fp) != NULL){
            Destinatario* destinatario = newDestinatario();
                if(destinatario != NULL){
                    sscanf(auxLinea,"%[^,],%[^\n]",auxName,auxEmail);
                    strncpy(destinatario->name, auxName,sizeof(destinatario->name));
                    strncpy(destinatario->email, auxEmail,sizeof(destinatario->email));
                    al_add(listaDestinatarios,destinatario);
                }
                else{
                    returnAux = -1;
                }
        }
    }else{
        returnAux = -1;
    }

    fclose(fp);
    return returnAux;

}

int cargarListaNegra(ArrayList* listaNegra){
    int returnAux = 0;
    char auxName[300];
    char auxEmail[400];
    char auxLinea[500];
    FILE* fp = fopen("black_list.csv","r");
    if(fp != NULL){
        while(fgets(auxLinea,sizeof(auxLinea)-1,fp) != NULL){
            Destinatario* destinatario = newDestinatario();
            if(destinatario != NULL){
                sscanf(auxLinea,"%[^,],%[^\n]",auxName,auxEmail);
                strncpy(destinatario->name, auxName,sizeof(destinatario->name));
                strncpy(destinatario->email, auxEmail,sizeof(destinatario->email));
                al_add(listaNegra,destinatario);
            }else{
                returnAux = -1;
            }
        }
    }else{
        returnAux = -1;
    }
    return returnAux;
}
