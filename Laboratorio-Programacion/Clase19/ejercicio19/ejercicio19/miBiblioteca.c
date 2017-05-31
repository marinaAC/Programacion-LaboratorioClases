
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

float promedio (int numero[], int cantidad) {
    int suma=0;
    float resultadoProm;
    int i;
    for (i=0; i<cantidad;i++) {

        suma = suma + numero[i];

    }
    resultadoProm = (float)suma / cantidad;

    return resultadoProm;
}

int max(int numero[], int cantidad)
{
    int flag=0;
    int i;
    int max;
    for (i=0; i<cantidad; i++)
    {
        if (flag == 0)
        {
            flag = 1;
            max = numero[i];
        }

        if(numero[i]>max)
        {
            max = numero[i];
        }
    }
    return max;
}


int min(int numero[], int cantidad)
{
    int min;
    int i;
    int flag=0;

    for (i=0; i<cantidad; i++)
    {
        if (flag == 0){
            flag = 1;
            min = numero[i];
        }
        if (numero[i]<min){
            min = numero[i];
        }
    }
    return min;
}

int minIndice(int numero[], int cantidad)
{
    int minIndice, min;
    int i;
    int flag=0;

    for (i=0; i<cantidad; i++)
    {
        if (flag == 0){
            flag = 1;
            min = numero[i];
            minIndice=i;
        }
        if (numero[i]<min){
            min = numero[i];
            minIndice=i;
        }
    }
    return minIndice;
}

int compactar(int numero[], int cantidad, int eliminar){
    int i;
    for(i=eliminar;i<cantidad;i++){
        numero[i]=numero[i+1];
    }
    return cantidad-1;
}

void ordernar(int numero[], int cantidadArray,int array2[]){
    int indiceMenor;
    int iterar=cantidadArray;
    int i;
    for(i=0;i<iterar;i++){
        indiceMenor=minIndice(numero,cantidadArray);
        array2[i]=numero[indiceMenor];
        cantidadArray=compactar(numero,cantidadArray,indiceMenor);
    }
}


 float promedioUno(float numerosSumados,float cantidadDeVeces){
    float resultado;
    resultado = numerosSumados/cantidadDeVeces;
    return resultado;

}

float suma(float numero1, float numero2){
    float result;
    fflush(stdin);
    result = numero1 + numero2;
    return result;
}

float resta(float numero1, float numero2){
    float result;
    fflush(stdin);
    result = numero1 - numero2;
    return result;
}

float division(float numero1, float numero2){
    float result;
    fflush(stdin);
    while(numero2<=0){
        printf("No se puede realizar una division por 0 o menor a 0. Ingrese nuevos valor para el numero b: ");
        fflush(stdin);
        scanf("%f",&numero2);
    }
    result = numero1/numero2;
    return result;
}

float multilicacion(float numero1, float numero2){
    float result;
    fflush(stdin);
    result = numero1 * numero2;
    return result;
}

float factorial(float numero){
    float result=1.0;
    for(;numero>0;numero--){
        result = result*numero;
    }
    return result;
}

int esNumerico(char num[]){
    int i=0;
    while(num[i]!='\0'){
        if(num[i]<'0'||num[i]>'9'){
            return 0;
        }
        i++;
    }
    return 1;
}

int soloLetras(char palabra[]){
    int i = 0;
    while(palabra[i]!='\0'){
        if((palabra[i]!=' ')&&(palabra[i]<'a'||palabra[i]>'z')&&(palabra[i]<'A'||palabra[i]>'Z')){
            return 0;
        }
        i++;
    }
    return 1;
}

int alfaNum(char palabra[]){
    int i=0;
    while(palabra[i]!='\0'){
        if((palabra[i]!=' ')&&(palabra[i]<'a'||palabra[i]>'z')&&(palabra[i]<'A'||palabra[i]>'Z')&&(palabra[i]<'0'||palabra[i]>'9')){
            return 0;
        }
        i++;
    }
    return 1;
}

int esTel(char tel[]){
    int i=0;
    int contadorGuiones = 0;
    while(tel[i]!='\0'){
        if((tel[i]!=' ')&&(tel[i]!='-')&&(tel[i]<'0'||tel[i]>'9')){
            return 0;
        }
        if(tel[i]=='-'){
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones==1){
        return 1;
    }
    return 0;
}


int getInt(char mensaje[]){
    int buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&buffer);
    return buffer;
}

float getFloat(char mensaje[]){
    float buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%f",&buffer);
    return buffer;
}

char getChar(char mensaje[]){
    char buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%c",&buffer);
    return buffer;
}

void getString(char mensaje[], char input[]){
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",input);
}

int getStringSoloLetras(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(soloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringSoloNum(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void inicializarListaInt(EUsuario lista[],int cantidadPersonas,int valor){
    int i;
    for(i=0;i<cantidadPersonas;i++){
        lista[i].isEmpty=valor;
    }
}

void inicializarArrayInt(int arrayDos[][3],int primerElemento,int segundoElemento,int valor){
    int i,j;
    for(i=0;i<primerElemento;i++){
        for(j=0;j<segundoElemento;j++){
            arrayDos[i][j]=valor;
        }
    }
}


int obtenerEspacioLibre(EUsuario lista[], int cantidadPersonas, int valor){
    int i;
    for(i=0;i<cantidadPersonas;i++){
        if(lista[i].isEmpty==valor){
            return i;
        }
    }
    return -1;
}
/*
int buscarPorDni(EUsuario lista[], int dni, int cantidadPersonas){
    int i;
    for(i=0;i<cantidadPersonas;i++){
        if(lista[i].dni==dni){
            return i;
        }
    }
    return -1;
}
*/
void graficar(int graf[][3],int cantidadElementos){
    int i,j;
    for(i=cantidadElementos;i>=0;i--){
        for(j=0;j<3;j++){
            if(graf[i][j]!=1 && graf[i][j]!=0){
                continue;
            }
            if(graf[i][j]==1){
                printf("\t*");
            }else{
                printf("\t");
            }
        }
        printf("\n");
   }
}

void ordenarMayor(int graf[][3],int cantidadElementos){
    int x, y, m;
    int aux;

        for(y=0;y<=2;y++){
            for(x=0;x<cantidadElementos;x++){
                    for(m=x+1;m<cantidadElementos;m++){
                        if(graf[x][y]<graf[m][y]){
                            aux = graf[m][y];
                            graf[m][y] = graf[x][y];
                            graf[x][y] = aux;
                    }
                }
            }
        }
}

int menu()
{
    //El menu, tiene una validacion, ya que si lo declaro como un entero y por pantalla le ingresan un flotante, el programa se rompe.
    //Habilito que por pantalla pueda tomar un flotante, lo parseo a entero y luego, esa validacion tendra otra que le dira que el valor ingresado es incorrecto.
    float opcion=0.0;
    printf("\nSistema de ingreso: \n");
    printf("1- ALTA DE USUARIO\n");
    printf("2- MODIFICAR DATOS DEL USUARIO\n");
    printf("3- BAJA DEL USUARIO\n");
    printf("4- PUBLICAR PRODUCTO\n");
    printf("5- MODIFICAR PUBLICACION\n");
    printf("6- CANCELAR PUBLICACION\n");
    printf("7- COMPRAR PRODUCTO\n");
    printf("8- LISTAR PUBLICACIONES DE USUARIO\n");
    printf("9- LISTAR PUBLICACIONES\n");
    printf("10- LISTAR USUARIOS\n");
    printf("11- Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%f", &opcion);
    int opcionfinal=(int)opcion;
    return opcionfinal;
}

void validacionIngreso(int opcion){
    while(opcion>6||opcion<0){
            printf("Valor incorrecto!.\nSolo puede elegir las opciones entre 1 y 5.\nPor favor, vuelva a ingresar una opcion: \n");
            opcion=menu();
        }
}



int initUsuario(EUsuario* pUsuario, int length)
{   int retorna = -1;
    int i;
    if(pUsuario != NULL && length >0){

        for(i=0;i<length;i++){
            pUsuario[i].isEmpty=1;
        }
        retorna = 0;
    }
    return retorna;
}

int initPub(EPublicacion* pPublicacion, int length)
{   int retorna = -1;
    int i;
    if(pPublicacion != NULL && length >0){

        for(i=0;i<length;i++){
            pPublicacion[i].isEmpty=1;
        }
        retorna = 0;
    }
    return retorna;
}


int addUsuario(EUsuario* pUsuario, int length, int id, char name[],char pass[])
{   int retorna = -1;
    int i;
    if(pUsuario != NULL && length >0){
        for(i=0;i<length;i++){
            if(pUsuario[i].isEmpty==1){
                pUsuario[i].id=id;
                strcpy(pUsuario[i].nombre,name);
                strcpy(pUsuario[i].passwords,pass);
                pUsuario[i].calificacion=0;
                pUsuario[i].idPublicacion[0]=-1;
                pUsuario[i].cantidadPublicaciones=0;
                pUsuario[i].isEmpty=0;
                retorna = 0;
                break;
            }
        }
    }
    return retorna;
}


int addPublicacion(EPublicacion* pPublicacion, int length, int id, char name[],int precio, int stock, int idUsuario)
{   int retorna = -1;
    int i;
    if(pPublicacion != NULL && length >0){
        for(i=0;i<length;i++){

                pPublicacion[i].id=id;
                strcpy(pPublicacion[i].nombreProducto,name);
                pPublicacion[i].precio= precio;
                pPublicacion[i].stock=stock;
                pPublicacion[i].idUsuario = idUsuario;
                pPublicacion[i].cantidadVendida = 0;
                retorna = 0;
                break;

        }
    }
    return retorna;
}



EUsuario* findUsuarioById(EUsuario* pUsuario, int length,int id)
{   EUsuario* retorna = NULL;
    int i;
    if(pUsuario != NULL && length > 0){
        for(i=0;i<length;i++){
            if(pUsuario[i].id==id){
                return &pUsuario[i];
            }
        }
    }
    return retorna;
}

EPublicacion* findPublicacionById(EPublicacion* pPublicacion, int length,int id)
{   EPublicacion* retorna = NULL;
    int i;
    if(pPublicacion != NULL && length > 0){
        for(i=0;i<length;i++){
            if(pPublicacion[i].id==id){
                return &pPublicacion[i];
            }
        }
    }
    return retorna;
}


EUsuario* findPrimerLugar(EUsuario* pUsuario, int length)
{   EUsuario* retorna = NULL;
    int i;
    if(pUsuario != NULL && length > 0){
        for(i=0;i<length;i++){
            if(pUsuario[i].isEmpty==1){
                return &pUsuario[i];
            }
        }
    }
    return retorna;
}



int removeEmployee(EUsuario* pUsuario, int length, int id)
{   int retorna = -1;
    EUsuario* auxUss;
    if(auxUss != NULL && length >0){

        auxUss = findUsuarioById(auxUss,length,id);
        (*auxUss).isEmpty = 1;
        retorna = 0;
    }
    return retorna;
}

int removePublicacion(EPublicacion* pUsuario, int length, int id)
{   int retorna = -1;
    EPublicacion* auxPub;
    if(auxPub != NULL && length >0){

        auxPub = findPublicacionById(auxPub,length,id);
        (*auxPub).isEmpty = 1;
        retorna = 0;
    }
    return retorna;
}

int loadPerson(S_Persona* pPersona){
    getString("Ingrese el nombre: ", pPersona->nombre);

    pPersona->edad = getInt("Ingrese la edad: ");
    if(pPersona->edad<=0 || pPersona->edad>100){
        return 0; //error
    }
    if(getStringSoloNum("Ingrese el DNI: ",pPersona->id)==0){
        return 0;
    }
    return 1;
}

void printPerson(S_Persona* pPersona){
    printf("Nombre: %s, Edad: %d, DNI: %s",pPersona->nombre,pPersona->edad,pPersona->id);
}



/**
 * \brief Permite al usuario ingresar un texto y lo devuelve en un nuevo espacio de memoria
 * \param char* msg. Mensaje a ser impreso.
 * \return puntero a cadena de caracteres con texto ingresado. Se debe liberar con free().
*/
char* getDynamicString(char* msg){
    printf(msg);
    char* pData = (char*) malloc(sizeof(char)*1024);
    scanf("%1023s", pData); // cantidad maxima 1023 (dejamos 1 byte para tener el cuenta el caracter terminador)
    int len = strlen(pData); //para saber cuantas letras hay dentro de la cadena de caracteres que usamos con malloc
    pData = (char*)realloc(pData,sizeof(char)*(len+1)); // hacemos un realloc de len para poder achicar el espacio de la memoria
    return pData;
}

int loadDataFile(char* fileName,S_Data* array, int arrayLen){
    FILE *fp;
    char lineStr[128]; //variable donde almaccena la linea leida
    //abrimos el archivo para lectura
    fp = fopen(fileName, "r");
    if(fp == NULL){
        perror("Error opening file");
        return -1;
    }

    //leemos las lineas
    int index = 0;
    while(fgets(lineStr,128,fp)!=NULL){ //leemos una linea, 128 caracteres como un maximo
        int indexDivider =strcspn(lineStr,"="); //devuelve la posicion del signo "="
        int keyLen = indexDivider+1; // calculo el tamaño del texto de la clave, se suma 1 ya que tiene que terminar en 0
        int valueLen = strlen(lineStr)- indexDivider-1;//calculo la palabra clave y la palabra del valor

        char* key = (char*)malloc(keyLen);
        char* value = (char*)malloc(valueLen);

        strncpy(key,lineStr,keyLen-1);
        key[keyLen-1]=0x00;

        strncpy(value,&lineStr[keyLen],valueLen-1);
        value[valueLen-1]=0x00;

        //guardamos los punteros creados con malloc en la struct
        array[index].key = key;
        array[index].value = value;
        index++;
        if(index>=arrayLen){
            break;
        }
    }

    fclose(fp);
    return index;
}


/**
 *\brief Pide al usuario los datos y los guarda en la struct
 *\param struct S_person* p puntero a struct donde se almacenan los datos ingresados
 *\return void
**/

void loadData(S_Pers* p){
    getStringSoloLetras("Ingrese el nombre: ",p->name);
    getStringSoloLetras("Ingrese el apellido: ",p->surname);
    p->age=getInt("Ingrese la edad");
}

/**
 *\brief Guarda una struct al final de un archivo binario bin.dat
 *\param struct S_Pers* p puntero a struct a ser escrita
 *\return 0:error, 1: ok
**/
int savePerson(S_Pers* p){
    FILE* fp;
    fp=fopen("bin.dat","ab+"); //append binario, lo crea sino existe
    if(fp==NULL){
        printf("Error abriendo el archivo");
        return 0;
    }
    fwrite(p,sizeof(S_Pers),1,fp);//escribo una strut al final
    fclose(fp);
    return 1;
}

S_Pers* readPerson(char* surname){
     FILE* fp;
     fp= fopen("bin.dat","rb"); //lectura binaria
     if(fp==NULL){
        printf("Error abriendo el archivo");
        return  NULL;
     }
     S_Pers* pRet = malloc(sizeof(S_Pers));
     int flagFound = 0;
     while(fread(pRet,sizeof(S_Pers),1,fp)!=0){
        if(strcmp(surname,pRet->surname)==0){
            flagFound = 1;
            break;
        }
     }
     fclose(fp);
     if(flagFound){
        return pRet;
     }
     free(pRet);
     return NULL;
}

