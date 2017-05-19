#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[50];
    int edad;
}EPersona;
/**
    *Formas de acceder a los arrays sin necesidad de poner los corchetes
**/
void cargarPunteros(EPersona** puntero1, EPersona* puntero2);
void ordenarDeMayorAMenor(EPersona** puntero);

int main()
{
    EPersona arrayPersona[10];
    EPersona* punteroArray[10];
    EPersona* auxPuntero;
    arrayPersona[0].edad=10;
    arrayPersona[1].edad=50;
    arrayPersona[2].edad=30;
    int i;
/*
    for(i=0;i<10;i++){
        punteroArray[i]=&arrayPersona[i];
    }*/
    cargarPunteros(punteroArray,arrayPersona);
    for(i=3;i<10;i++){
        arrayPersona[i].edad = 0;
    }


    printf("Primera edad: %d\n",(*punteroArray[0]).edad);
/*
    int flag =0;
    while(flag==0){
        flag=1;
        for(i=0;i<10-1;i++){
            if(punteroArray[i]->edad == 0){
                break;
            }
            if(punteroArray[i]->edad<punteroArray[i+1]->edad){
                auxPuntero = punteroArray[i];
                punteroArray[i] = punteroArray[i+1];
                punteroArray[i+1]= auxPuntero;
                flag=0;
            }
        }
    }
*/
    ordenarDeMayorAMenor(punteroArray);
    printf("Primera edad ordenada: %d\n",(*punteroArray[0]).edad);
    printf("Primera edad ordenada: %d\n",(*punteroArray[1]).edad);
    printf("Primera edad ordenada: %d\n",(*punteroArray[2]).edad);

    return 0;
}

void cargarPunteros(EPersona** puntero1, EPersona* puntero2){
   int i;
    for(i=0;i<10;i++){
        puntero1[i]=&puntero2[i];
    }
}

void ordenarDeMayorAMenor(EPersona** puntero){
    int i;
    int flag = 0;
    EPersona* auxiliarP;
    while(flag==0){
      flag=1;
        for(i=0;i<10-1;i++){
            if(puntero[i]->edad == 0){
                break;
            }
            if(puntero[i]->edad<puntero[i+1]->edad){
                auxiliarP = puntero[i];
                puntero[i] = puntero[i+1];
                puntero[i+1]= auxiliarP;
                flag=0;
            }
        }
    }
}

