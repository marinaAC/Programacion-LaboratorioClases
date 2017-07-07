#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Productos.h"
#include "ArrayList.h"
#include "base.h"

int parseoData(ArrayList* listaProd){
    int returnAux = -1;
    FILE* fp = fopen("MOCK_DATA.csv","r");
    char auxId[20];
    char auxName[20];
    char auxVersion[20];
    char auxCategory[20];
    char auxLinea[100];
    if(fp != NULL){
        while(fgets(auxLinea,sizeof(auxLinea),fp)!= NULL){
            S_Productos* prod = newProducto();
            int parsId, parsCategory;
            if(prod!=NULL){
                sscanf(auxLinea,"%[^,],%[^,],%[^,],%[^\n]",auxId,auxName,auxVersion,auxCategory);
                parsId = atoi(auxId);
                parsCategory = atoi(auxCategory);
                setIdProcut(prod, parsId);
                setNameProduct(prod,auxName);
                setVersionProduct(prod,auxVersion);
                setCategory(prod,parsCategory);
             //   printf("Producto\n");
              //  printf("%d ,%s, %s, %d", prod->id,prod->name,prod->version,prod->category);
                al_add(listaProd,prod);
                returnAux = 0;
            }
        }
    }
    fclose(fp);
    return returnAux;
}


ArrayList* filter(ArrayList* pLista, int cat){

    ArrayList* listFilter = al_newArrayList();
    if(pLista != NULL && cat > 0){
        int i;
        S_Productos* prod;
        for(i=0;i<pLista->size-1; i++){
            prod=al_get(pLista,i);
            if(prod->category==cat){
                al_add(listFilter,prod);
            }
        }
        pLista = al_clone(listFilter);
    }
    return pLista;
}
