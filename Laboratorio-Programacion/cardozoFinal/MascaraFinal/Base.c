#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Notas.h"
#include "frecuencia.h"
#include "Base.h"
#include "Interface.h"


/** \brief Descarga la información del archivos text.txt a memoria.
 * \param ArrayList* lista - Puntero a la lista donde se indexará la información.
 * \return void.
 */
void base_parse(ArrayList* listaNotas, ArrayList* listaFrecuencias){
    char buffer[400]; //Guarda temporalmente las lineas obtenidas por fgets();
    char auxNombre[10];
    char auxDuracion[50];
    char auxVolumen[50];

    FILE* fp;
    fp = fopen("melodia.txt","r");



    if(fp == NULL){
        interface_msjAlerta("ERROR MELODIAS!!.\nEl programa no pudo leer un archivo.\nEl programa deberá finalizar.");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer,sizeof(buffer)-1,fp) != NULL){
        Nota* n = nota_newNota();
        if(n == NULL){
            interface_msjAlerta("ERROR CRITICO.\nEl programa no pudo reservar memoria.\nEl programa deberá finalizar.");
            exit(EXIT_FAILURE);
        }
        sscanf(buffer,"%[^;];%[^;];%[^\n]",auxNombre,auxDuracion,auxVolumen);
        nota_setNombre(n, auxNombre);
        nota_setDuration(n, auxDuracion);
        nota_setVolumen(n, auxVolumen);
        compareNotaConFrecuencia(n,listaFrecuencias);
        nota_print(n);
        al_add(listaNotas,n);
    }

    fclose(fp);
}


/** \brief Descarga la información del archivos text.txt a memoria.
 * \param ArrayList* lista - Puntero a la lista donde se indexará la información.
 * \return void.
 */
void parseoFrec(ArrayList* listaFrecuencias){
    char auxNombre[10];
    char auxVolor[10];
    char bufferAux[1000];
    FILE* freNotas = fopen("notas.txt","r");
    if(freNotas == NULL){
        interface_msjAlerta("ERROR NOTAS!!.\nEl programa no pudo leer un archivo.\nEl programa deberá finalizar.");
        exit(EXIT_FAILURE);
    }

     while(fgets(bufferAux,sizeof(bufferAux)-1,freNotas) != NULL){
        FrecArchivo* f = frec_newFrecuenciaArch();
        if(f == NULL){
            interface_msjAlerta("ERROR CRITICO.\nEl programa no pudo reservar memoria.\nEl programa deberá finalizar.");
            exit(EXIT_FAILURE);
        }
        sscanf(bufferAux,"%[^;];%[^\n]",auxNombre,auxVolor);
        frec_setNombre(f,auxNombre);
        frec_setValor(f,auxVolor);
        printf("nombre: %s valor: %d\n",f->nombre,f->valor);
        al_add(listaFrecuencias,f);
     }
     fclose(freNotas);
}

/** \brief Compra los elementos de la lista de frecuencias con la nota recibida
 * \param ArrayList* lista - Puntero a la lista donde se indexará la información.
 * \return void.
 */
void compareNotaConFrecuencia(Nota* nota,ArrayList* listaFrecuencias){

    int i;
    for(i=0;i<listaFrecuencias->size-1;i++){
        FrecArchivo* frec = al_get(listaFrecuencias,i);
        int auxFrec;
        if(strcmp(nota_getNombre(nota),frec_getNombre(frec))==0){
            auxFrec = frec_getValor(frec);
            nota_setFrecuencia(nota,auxFrec);
            break;
        }
    }

}


void ecualizarSonido(ArrayList* listaNotasCompletas){
    int i;
    int auxVolumen;
    ArrayList* auxArray = al_newArrayList();
    for(i=0;i<listaNotasCompletas->size-1;i++){
        Nota* auxNota = al_get(listaNotasCompletas,i);

            if(auxNota->volumen>100){
                al_remove(listaNotasCompletas,i);
            }
            if(auxNota->freq>250&&auxNota->freq<330&&auxNota->volumen<100){
                auxVolumen=auxNota->volumen;
                auxVolumen= auxVolumen*0.3;
                if(auxVolumen<100){
                    auxNota->volumen=auxVolumen;
                    al_add(auxArray,auxNota);
                }else{
                    al_remove(listaNotasCompletas,i);
                }
            }
            if(auxNota->freq>330&&auxNota->volumen<100){
                auxVolumen=auxNota->volumen;
                auxVolumen= auxVolumen*0.5;
                if(auxVolumen<100){
                    auxNota->volumen=auxVolumen;
                    al_add(auxArray,auxNota);
                }else{
                    al_remove(listaNotasCompletas,i);
                }
            }
    }

    listaNotasCompletas = al_clone(auxArray);

}

void nuevoArchivo(ArrayList* listaNotasCompletas){
    FILE* fp = fopen("melodia_corregida.txt","w+");
    if(fp == NULL){
        interface_msjAlerta("ERROR NUEVA MELODIA!!.\nEl programa no pudo leer un archivo.\nEl programa deberá finalizar.");
        exit(EXIT_FAILURE);
    }

}
