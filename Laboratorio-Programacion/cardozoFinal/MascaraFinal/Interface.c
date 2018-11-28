#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"
#include "Validaciones.h"
/**
 * \brief Muestra un mensaje de Alerta
 * \param text char* - texto a mostrar.
 * \return void
 */
void interface_msjAlerta(char* text){
    printf("\nAlerta!\n");
    printf("%s\n",text);
    printf("----------\n");
}

/**
 * \brief Imprime un título.
 * \param text char* - texto a mostrar.
 * \return void
 */
void interface_printTitulo(char* text){
    printf("%s\n",text);
    printf("---------\n");
}

/**
 * \brief Imprime texto de operacion interrumpida/Erronea.
 * \param void
 * \return void
 */
void interface_msjError(void){
    printf("\nOperacion finalizada inesperadamente.\n");
}


/**
 * \brief Hace una pregunta y pide por respuesta 'S' para si o 'N' para no. Valida respuesta.
 * \param message char* - pregunta a mostrar por pantalla.
 * \return retorno int - Devuelve (1) para sí. Devuelve (0) para no.
 */
int interface_msjConfirm(char* message){
    char answer;
    int returnAux = 0;
    printf("%s (S/N): ",message);
    //fflush();
    scanf("%c",&answer);/*
    if(answer != 'S' &&  answer != 's' &&  answer != 'N' &&  answer != 'n'){
            printf("ERROR. Debe ingresar 'S' para si o 'N' para no.");
    }else if(answer == 'S' || answer == 's'){
            returnAux = 1;
            break;
        }
        else{
            break;
        }
    }*/
    return returnAux;
}


/**
	Interaccion y validacion del mensaje con el usuario
	GET
*/
void getString(char* mensaje, char* input){
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",input);
}

int getStringSoloLetras(char* mensaje, char* input){
    char aux[256];
    getString(mensaje,aux);
    if(soloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringSoloNum(char* mensaje, char* input){
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
