#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#define REGULAR 0
#define URGENTE 1


struct{
    int dni;
    int turno;
    int tipoTramite;
    int estado;
}typedef tramite;

int main()
{
    char continuar = 's';
    tramite tramiteDelDia[100];
    int contadorUrgente = 0;
    int contadorGenerico = 0;
    int contadorRegular = 0;
    int atendidosUrg=0;
    int opcion;
    int i;
    int indiceMenor;
    int primerUrgente=0;

    do{

        opcion = menu();
        switch(opcion){
        case 1:
            tramiteDelDia[contadorGenerico].dni=obtenerDni();
            tramiteDelDia[contadorGenerico].turno=contadorUrgente+1;
            tramiteDelDia[contadorGenerico].tipoTramite= URGENTE;
            tramiteDelDia[contadorGenerico].estado=0;
            contadorUrgente++;
            break;
        case 2:
            tramiteDelDia[contadorGenerico].dni=obtenerDni();
            tramiteDelDia[contadorGenerico].turno=contadorRegular+1;
            tramiteDelDia[contadorGenerico].tipoTramite= REGULAR;
            tramiteDelDia[contadorGenerico].estado=0;
            contadorRegular++;
            break;
        case 3:
            for(i=0;i<contadorGenerico;i++){


                if(tramiteDelDia[i].tipoTramite==1 && tramiteDelDia[i].estado==0 && tramiteDelDia[i].turno==contadorUrgente){
                    tramiteDelDia[i].estado=1;
                    indiceMenor=i;
                    printf("Dni: %d, estado %d; tipo: %d\n", tramiteDelDia[i].dni, tramiteDelDia[i].estado, tramiteDelDia[i].tipoTramite);
                    break;
                }
            }
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }


        contadorGenerico++;
        printf("\n\nDesea continuar: Ingrese s para si, ingrese n para finalizar: ");
        scanf("%s",&continuar);

    }while(continuar=='s'|| continuar == 'S');


    return 0;
}
