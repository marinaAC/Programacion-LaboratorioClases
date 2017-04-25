#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAXPERSONAS 20


int main()
{
    EPersona lista[MAXPERSONAS];
    EPersona auxPersona;

    char auxNombre[50];
    char auxEdadStr[30];
    char auxDniStr[20];
    int auxEdad;
    int auxEstado;
    int auxDni;
    int minEdad;
    int maximaEdad;
    int segundaEdadMinima;
    int segundaEdadMaxima;
    int contadorEdadMinima = 0;
    int contadorEdadMaxima = 0;
    int contadorIntermedio = 0;

    int indicePrimero;
    int indicePrimerBusqueda;
    int i,j;

    char seguir='s';
    int opcion=0;

    inicializarListaInt(lista,MAXPERSONAS,-1);
    while(seguir=='s')
    {
        printf("\nSistema de ingreso: \n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\nAGREGAR PERSONA\n");
                indicePrimero = obtenerEspacioLibre(lista,MAXPERSONAS,-1);
                if(indicePrimero == -1){
                    printf("\nNO QUEDAN MAS LUGARES PARA GUARDAR EN LA LISTA\n");
                    break;
                }

                if(!getStringSoloLetras("\nIngrese el nombre de la persona: ",auxNombre)){
                    printf("\nEl nombre solo debe estar compuesto por letras\n");
                    break;
                }
                if(!getStringSoloNum("\nIngrese el dni de la persona: ", auxDniStr)){
                    printf("\nEl dni solo puede estar compuesto por numeros\n");
                    break;
                }
                if(!getStringSoloNum("\nIngrese la edad de la persona: ", auxEdadStr)){
                    printf("\nLa edad solo puede estar compuesto por numeros\n");
                    break;
                }
                auxDni = atoi(auxDniStr);
                auxEdad = atoi(auxEdadStr);
                strcpy(lista[indicePrimero].nombre,auxNombre);
                lista[indicePrimero].edad=auxEdad;
                lista[indicePrimero].dni=auxDni;
                lista[indicePrimero].estado=1;
                break;
            case 2:
                printf("\nBORRAR\n");
                if(!getStringSoloNum("Ingrese el dni que desea buscar: ",auxDniStr)){
                    printf("\nSolo se permiten ingresar numeros\n");
                    break;
                }
                auxDni=atoi(auxDniStr);
                indicePrimerBusqueda = buscarPorDni(lista,MAXPERSONAS,auxDni);
                if(indicePrimerBusqueda==-1){
                    printf("\nLA PERSONA NO SE ENCUENTRA\n");
                    break;
                }
                lista[indicePrimerBusqueda].estado=-1;
                break;
            case 3:
                printf("\nLISTA\n");
                for(i=0;i<MAXPERSONAS;i++){
                    if(lista[i].estado==-1){
                        continue;
                    }
                    for(j=i+1;j<MAXPERSONAS;j++){
                        if(lista[j].estado==-1){
                            continue;
                        }
                        if(strcmp(lista[i].nombre,lista[j].nombre)>0){
                            auxPersona = lista[j];
                            lista[j]= lista[i];
                            lista[i]=auxPersona;
                        }

                    }
                    for(i=0;i<MAXPERSONAS;i++){
                            if(lista[i].estado!=-1){
                                    printf("\nNombre: %s, Edad: %d, dni; %d",lista[i].nombre,lista[i].edad,lista[i].dni);
                            }
                    }
                }
                break;
            case 4:

                for(i=0;i<MAXPERSONAS;i++){
                    if(lista[i].estado!=-1){
                        continue;
                    }
                    minEdad=minimaEdad(lista,MAXPERSONAS);
                    maximaEdad=maxEdad(lista,MAXPERSONAS);
                    if(lista[i].edad==minEdad){
                        contadorEdadMinima++;
                    }
                    if(lista[i].edad==maximaEdad){
                        contadorEdadMaxima++;
                    }
                    if(lista[i].edad!=maximaEdad||lista[i].edad!=minEdad){
                        contadorIntermedio++;
                    }
                }

                    printf("\t contador MAXIMA %d",contadorEdadMaxima);
                    printf("\t contador min %d",contadorEdadMinima);
                    printf("\t contador intrer %d",contadorIntermedio);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
