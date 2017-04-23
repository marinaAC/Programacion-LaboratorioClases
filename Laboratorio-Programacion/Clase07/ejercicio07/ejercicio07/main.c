#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#define MAXCLIENTES 100

int main()
{
    char nombreCliente[MAXCLIENTES][50];
    char apellidoCliente[MAXCLIENTES][50];
    int legajosClientes[MAXCLIENTES];

    char auxNom[50];
    char auxApe[50];
    char auxLegString[50];
    int auxLeg;

    int indiceLibre;
    int indiceResultBusqueda;
    int opcion = 0;

    int i;
    int j;

    inicializarArrayInt(legajosClientes,MAXCLIENTES,-1);
    while(opcion!=6){

        printf("Elija la opcion con la que desea trabajar");
        opcion = getInt("\n\n1 - ALTA\n2 - BAJA\n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR");

        switch(opcion){
        case 1:

            indiceLibre = buscarPrimero(legajosClientes,MAXCLIENTES,-1);
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

            if(buscarPrimero(legajosClientes,MAXCLIENTES,auxLeg)!=1){
                printf("\nEL LEGAJO INGRESADO YA EXISTE\n");
                break;
            }

            strcpy(nombreCliente[indiceLibre],auxNom);
            strcpy(apellidoCliente[indiceLibre],auxApe);
            legajosClientes[indiceLibre]=auxLeg;
            break;
        case 2:
            printf("\nBAJA\n");
            if(!getStringSoloNum("\nIngrese el legajo a buscar: ", auxLegString)){
                printf("\nEl legajo debe ser numerico");
                break;
            }
            indiceResultBusqueda = buscarPrimero(legajosClientes,MAXCLIENTES,atoi(auxLegString));
            if(indiceResultBusqueda==-1){
                printf("\nNO SE ENCUENTRA EL LEGAJO");
                break;
            }
            //baja logica: quedaran el nombre y el apellido del cliente, pero cuando realicemos la busqueda el legajo y ese espacio se pueden utilizar
            legajosClientes[indiceResultBusqueda]=-1;
            break;
        case 3:
            printf("\nMODIFICACION\n");
            if(!getStringSoloNum("\nIngrese el legajo a modificar: ", auxLegString)){
                printf("\nEl legajo debe ser numerico");
                break;
            }
            indiceResultBusqueda = buscarPrimero(legajosClientes,MAXCLIENTES,atoi(auxLegString));
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
            strcpy(nombreCliente[indiceResultBusqueda],auxNom);
            strcpy(apellidoCliente[indiceResultBusqueda],auxApe);
            break;
        case 4:
            printf("\nLISTAR\n");
            for(i=0;i<MAXCLIENTES;i++){
                if(legajosClientes[i]!=-1){
                    printf("\n %s, %s, %d", apellidoCliente[i], nombreCliente[i], legajosClientes[i]);
                }
            }
            break;
        case 5:
            printf("\nORDENAR\n");
            //el continue no rompe la interaccion, salta a la siguiente
            for(i=0; i<MAXCLIENTES;i++){
                    if(legajosClientes[i]==-1){
                        continue;
                    }
                for(j =i+1;j<MAXCLIENTES;j++){
                    if(legajosClientes[j]==-1){
                        continue;
                    }
                    if(strcmp(apellidoCliente[i],apellidoCliente[j])){
                        strcpy(auxApe,apellidoCliente[i]);
                        strcpy(apellidoCliente[i],apellidoCliente[j]);
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


            break;
        case 6:
            break;
        default:
            break;
        }

    }



    return 0;
}
