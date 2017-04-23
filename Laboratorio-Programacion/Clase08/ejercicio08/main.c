#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#define MAXPERSONAS 50


typedef struct{
    char nombre[50];
    char apellido[50];
    int legajo;
}Persona;



void inicializarArrayPersonas(Persona persona[],int cantidadElementos,int valor);
int buscarPrimeraPersona(Persona persona[], int cantidadElementos, int valor);

int main()
{
    Persona persona[MAXPERSONAS];
    Persona auxCliente;

    char auxNom[50];
    char auxApe[50];
    char auxLegString[50];
    int auxLeg;

    int indiceLibre;
    int indiceResultBusqueda;
    int opcion = 0;

    int i;
    int j;

    inicializarArrayPersonas(persona,MAXPERSONAS,-1);
    while(opcion!=6){

        printf("Elija la opcion con la que desea trabajar");
        opcion = getInt("\n\n1 - ALTA\n2 - BAJA\n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR");

        switch(opcion){
        case 1:

            indiceLibre = buscarPrimeraPersona(persona,MAXPERSONAS,-1);
            if(indiceLibre==-1){
                printf("\nNo hay mas lejajos disponibles\n");
                break;
            }
            printf("\nALTA\n");
            if(!getStringSoloLetras("\nIngrese el nombre del cliente: ", auxNom)){
                printf("El nombre debe estar solo compuesto por letras");
                break;
            }
            if(!getStringSoloLetras("\nIngrese el apellido del cliente: ", auxNom)){
                printf("El nombre debe estar solo compuesto por letras");
                break;
            }
            if(!getStringSoloNum("\nIngrese el legajo del cliente: ",auxLegString)){
                printf("El nombre debe estar solo compuesto por numeros");
                break;
            }
            //convierte el string en int
            auxLeg = atoi(auxLegString);

            if(buscarPrimeraPersona(persona,MAXPERSONAS,auxLeg)!=1){
                printf("\nEL LEGAJO INGRESADO YA EXISTE\n");
                break;
            }

            strcpy(persona[indiceLibre].nombre,auxNom);
            strcpy(persona[indiceLibre].apellido,auxApe);
            persona[indiceLibre].legajo=auxLeg;
            break;
        case 2:
            printf("\nBAJA\n");
            if(!getStringSoloNum("\nIngrese el legajo a buscar: ", auxLegString)){
                printf("\nEl legajo debe ser numerico");
                break;
            }
            indiceResultBusqueda = buscarPrimeraPersona(persona,MAXPERSONAS,atoi(auxLegString));
            indiceResultBusqueda = buscarPrimeraPersona(persona,MAXPERSONAS,atoi(auxLegString));
            if(indiceResultBusqueda==-1){
                printf("\nNO SE ENCUENTRA EL LEGAJO");
                break;
            }
            //baja logica: quedaran el nombre y el apellido del cliente, pero cuando realicemos la busqueda el legajo y ese espacio se pueden utilizar
            persona[indiceResultBusqueda].legajo=-1;
            break;
        case 3:
            printf("\nMODIFICACION\n");
            if(!getStringSoloNum("\nIngrese el legajo a modificar: ", auxLegString)){
                printf("\nEl legajo debe ser numerico");
                break;
            }
            indiceResultBusqueda = buscarPrimeraPersona(persona,MAXPERSONAS,atoi(auxLegString));
            if(indiceResultBusqueda==-1){
                printf("\nNO SE ENCUENTRA EL LEGAJO");
                break;
            }

            if(!getStringSoloLetras("Ingrese el nombre a modificar: ", auxNom)){
                printf("El nombre debe estar compuesto por letras");
                break;
            }

            if(!getStringSoloLetras("Ingrese el apellido a modificar: ", auxApe)){
                printf("El apellido debe estar compuesto por letras");
                break;
            }
            strcpy(persona[indiceResultBusqueda].nombre,auxNom);
            strcpy(persona[indiceResultBusqueda].apellido,auxApe);
            break;
        case 4:
            printf("\nLISTAR\n");
            for(i=0;i<MAXPERSONAS;i++){
                if(persona[i].legajo!=-1){
                    printf("\n %s, %s, %d", persona[i].apellido,persona[i].nombre,persona[i].legajo);
                }
            }
            break;
        case 5:/*
            printf("\nORDENAR\n");
            //el continue no rompe la interaccion, salta a la siguiente
            for(i=0; i<MAXPERSONAS;i++){
                    if(persona[i].legajo==-1){
                        continue;
                    }
                for(j =i+1;j<MAXPERSONAS;j++){
                    if(persona[j].legajo==-1){
                        continue;
                    }
                    if(strcmp(persona[i].apellido,persona[j].apellido)){
                        strcpy(auxApe,persona[i].apellido);
                        strcpy(persona[i].apellido,persona.[j].apellido);
                        strcpy(apellidoCliente[j],auxApe);


                        strcpy(auxNom,nombreCliente[i]);
                        strcpy(nombreCliente[i],nombreCliente[j]);
                        strcpy(nombreCliente[j],auxNom);

                        auxLeg = legajosClientes[i];
                        legajosClientes[i] = legajosClientes[j];
                        legajosClientes[j] = auxLeg;
                    }
                }
            }
*/

            break;
        case 6:
            break;
        default:
            break;
        }

    }

    return 0;
}


void inicializarArrayPersonas(Persona persona[],int cantidadElementos,int valor){
    int i;
    for(i=0;i<cantidadElementos;i++){
        persona[i].legajo=valor;
    }
}

int buscarPrimeraPersona(Persona persona[], int cantidadElementos, int valor){
    int i;
    for(i=0;i<cantidadElementos;i++){
        if(persona[i].legajo==valor){
            return i;
        }
    }
    return -1;
}
