#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "base.h"
#include "Productos.h"

int main()
{
    ArrayList* listaProd = al_newArrayList();
    S_Productos* prod;
    int rta;
    rta = parseoData(listaProd);
    printf("%d",rta);
    listaProd=filter(listaProd,4);
    int i;
    for(i=0;i<listaProd->size-1;i++){
        prod=al_get(listaProd,i);
        printf("%d ,%s, %s, %d\n", prod->id,prod->name,prod->version,prod->category);
    }
    return 0;
}
