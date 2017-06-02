#include <stdio.h>
#include <stdlib.h>

/**
   *Crear una struct con dos campos de cadena de caracteres, uno llamado 'key' y otro llamado 'value'.

        struct S_Data
        {
            char* key;
            char* value;
        };

    *Hacer una función que reciba el nombre de un archivo y un array de estas estructuras.
     La función leerá un archivo de texto con el siguiente formato:

        clave=valor
        clave=valor

    *La función deberá leer cada línea del archivo y separar por
     el caracter '=' la clave y el valor, y deberá cargarlo en una struct del array, generando de forma dinámica las variables para almacenar ambas palabras, y luego guardando los punteros en la struct. Prototipo de la función:

    *int loadDataFile(char* fileName,struct S_Data* array, int arrayLen)

    *La función devolverá la cantidad de items que se cargaron en el array,
     y nunca se superará el tamaño del array

*/
typedef struct
{
    char id[4096];
    char name[4096];
    char lastName[4096];
    char isEmpty[4096];

}SPersona;

int main()
{
    /**
        id,first_name,last_name,is_empty
        1,Eric,Knight,false
    */
    FILE* pData;
    //char* buffer = (char*)malloc((sizeof(char)*4096)); //necesito un auxiliar
    SPersona* buffer = (SPersona*)malloc((sizeof(SPersona)*4096));
    char* pChar;
    SPersona* pAuxliar;
   // char id[4096];
   // char name[4096];
   // char lastName[4096];
   // char isEmpty[4096];
    int cantidadLeidos;
    //int qty = 60;

    pData = fopen("data.csv","r");
    if(pData!=NULL){
        printf("Se puede abrir el archivo\n");
    }else{
        printf("No se pudo abrir el archivo\n");
    }

    /**
        Con esto se si llego al final del archivo
    */
    while(!feof(pData)){
        /*cantidadLeidos=fread(buffer+(qty-60),sizeof(char),60,pData);

         pChar=realloc(buffer,sizeof(char)*(qty+60));
         if(pChar == NULL){
            break;
         }
         buffer=pChar;
         qty=qty+60;
         /*
            if(cantidadLeidos != 60){
                seguir
            }
            */
        cantidadLeidos = fread(buffer,sizeof(SPersona),4096,pData);
        pAuxliar = realloc(buffer,sizeof(SPersona)*4096);
        fscanf(pData,"%[^,],%[^,],%[^,],%[^\n]",(SPersona).id,*SPersona.name,*SPersona.lastName,*SPersona.isEmpty);
            //la consola de windows tiene un buffer muy chico, no es que la condicion esta mal
        //fscanf(pData,"%s",buffer);
        //fscanf(pData,"%[^,],%[^,],%[^,],%[^\n]",id,name,lastName,isEmpty);
        //printf("%s--%s--%s--%s\n",id,name,lastName,isEmpty);
    }
    //buffer[qty] = '\0';
    //printf("%s",buffer);


    return 0;
}
