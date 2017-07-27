#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Interface.h"
#include "People.h"

/** \brief Descarga la informaci�n del archivos text.txt a memoria.
 * \param ArrayList* lista - Puntero a la lista donde se indexar� la informaci�n.
 * \return void.
 */
void Base_parse(ArrayList* lista){
    char buffer[400]; //Guarda temporalmente las lineas obtenidas por fgets();

    FILE* fp = fopen("nombreArchivo.txt","r");

    if(fp == NULL){
        interface_msjAlerta("ERROR CRITICO.\nEl programa no pudo leer un archivo.\nEl programa deber� finalizar.");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer,sizeof(buffer)-1,fp) != NULL){
        Person* persona = person_newPerson();
        if(persona == NULL){
            interface_msjAlerta("ERROR CRITICO.\nEl programa no pudo reservar memoria.\nEl programa deber� finalizar.");
            exit(EXIT_FAILURE);
        }

        sscanf(buffer,"%[^;];%[^;];%[^;];%[^;];%[^\n]",date,time,serviceID,gravedad,msg);

    }

    fclose(fp);
}



