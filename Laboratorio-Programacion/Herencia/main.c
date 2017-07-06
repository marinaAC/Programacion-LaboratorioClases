#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"
#include "programador.h"
#include "administrativo.h"
#include "ArrayList.h"
#include "base.h"


#define AREA_COMPRAS    0
#define AREA_VENTAS     1

#define TYPE_PROGRAMADOR    1
#define TYPE_ADMINISTRATIVO 2





void imprimirObject(Object* o);


int main()
{   /*
    Programador p;
    p.obj.type=TYPE_PROGRAMADOR;
    sprintf(p.nombre,"juan");
    sprintf(p.lenguaje,"JAVA");

    Administrativo a;
    a.obj.type = TYPE_ADMINISTRATIVO;
    sprintf(a.nombre,"pepe");
    a.area = AREA_VENTAS;

    Object* o1;
    Object* o2;

    //castea puntero a programador, para que sea un casteo
    o1 = (Object*)&p;
    o2 = (Object*)&a;

    imprimirObject(o1);
    imprimirObject(o2);

*/

    ArrayList* listaTotal = al_newArrayList();
    if(initBase(listaTotal)!=NULL){
        int i;
        for(i=0;i<listaTotal->size-1;i++){
            lecturaArraylist(listaTotal,i);
        }
    }
    return 0;
}


void imprimirObject(Object* o)
{
    Programador* p;
    Administrativo* a;

    switch(o->type)
    {
        case TYPE_PROGRAMADOR:
            p = (Programador*) o;
            printf("PROGRAMADOR. Nombre:%s. Lenguaje:%s\r\n",p->nombre,p->lenguaje);
            break;

        case TYPE_ADMINISTRATIVO:
            a = (Administrativo*) o;
            printf("ADMINISTRATIVO. Nombre:%s. Area:%d\r\n",a->nombre,a->area);
            break;
    }

}
