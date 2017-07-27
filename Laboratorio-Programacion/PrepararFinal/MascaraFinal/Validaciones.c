#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"



int esNumerico(char* num){
	int returnAux = 1;
    int i=0;
    while(num[i]!='\0'){
        if(num[i]<'0'||num[i]>'9'){
            return 0;
        }
        i++;
    }
    return returnAux;
}

int soloLetras(char* palabra){
	int returnAux = 1;
    int i = 0;
    while(palabra[i]!='\0'){
        if((palabra[i]!=' ')&&(palabra[i]<'a'||palabra[i]>'z')&&(palabra[i]<'A'||palabra[i]>'Z')){
            return 0;
        }
        i++;
    }
    return returnAux;
}

int alfaNum(char* palabra){
    int i=0;
    while(palabra[i]!='\0'){
        if((palabra[i]!=' ')&&(palabra[i]<'a'||palabra[i]>'z')&&(palabra[i]<'A'||palabra[i]>'Z')&&(palabra[i]<'0'||palabra[i]>'9')){
            return 0;
        }
        i++;
    }
    return 1;
}

int esTel(char* tel){
    int i=0;
    int contadorGuiones = 0;
    while(tel[i]!='\0'){
        if((tel[i]!=' ')&&(tel[i]!='-')&&(tel[i]<'0'||tel[i]>'9')){
            return 0;
        }
        if(tel[i]=='-'){
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones==1){
        return 1;
    }
    return 0;
}


int esMail(char* email){
	int returnAux = 0;
	int i=0;
    int contadorArroba = 0;
    while(email[i]!='\0'){
        if((email[i]!=' ')&&(email[i]!='@')&&(email[i]<'0'||email[i]>'9')&&(email[i]<'a'||email[i]>'z')&&(email[i]<'A'||email[i]>'Z')){
            returnAux = 0;
        }
        if(email[i]=='@'){
            contadorArroba++;
        }
        i++;
    }
    if(contadorArroba==1){
        returnAux = 1;
    }
    return returnAux;

}

int getInt(char* mensaje){
    int buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&buffer);
    return buffer;
}

float getFloat(char* mensaje){
    float buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%f",&buffer);
    return buffer;
}

char getChar(char* mensaje){
    char buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%c",&buffer);
    return buffer;
}





