#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Distintas formas de obtener un numero, cada funcion tiene su validacion y solo cambia el tipo de valor que quiero obtener
int obtenerInt(char mensaje[],char mensajeError[],int maximo, int minimo){
    int buffer;
    printf("%s",mensaje);
    scanf("%d",&buffer);

     while(buffer<minimo || buffer>maximo){
        printf("%s",mensajeError);
        scanf("%d",&buffer);
    }
    return buffer;
 }

 float obtenerFloat(char mensaje[],char mensajeError[],float maximo, float minimo){
    float buffer;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&buffer);
     while(buffer<minimo || buffer>maximo){
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%f",&buffer);
    }
    return buffer;
 }

 char obtenerChar(char mensaje[],char mensajeError[],char maximo, char minimo){
    char buffer;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&buffer);

     while(buffer<minimo || buffer>maximo){
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%c",&buffer);
    }
    return buffer;
 }


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

int menu()
{
    //El menu, tiene una validacion, ya que si lo declaro como un entero y por pantalla le ingresan un flotante, el programa se rompe.
    //Habilito que por pantalla pueda tomar un flotante, lo parseo a entero y luego, esa validacion tendra otra que le dira que el valor ingresado es incorrecto.
    float opcion=0.0;
    printf("\n1- Ingresar 1er operando (A=x)\n");
    printf("2- Ingresar 2do operando (B=y)\n");
    printf("3- Calcular la suma (A+B)\n");
    printf("4- Calcular la resta (A-B)\n");
    printf("5- Calcular la division (A/B)\n");
    printf("6- Calcular la multiplicacion (A*B)\n");
    printf("7- Calcular el factorial (A!)\n");
    printf("8- Calcular todas las operacione\n");
    printf("9- Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%f", &opcion);
    int opcionfinal=(int)opcion;
    return opcionfinal;
}

void validacionIngreso(int opcion){
    while(opcion>9||opcion<0){
            printf("Valor incorrecto!.\nSolo puede elegir las opciones entre 1 y 9.\nPor favor, vuelva a ingresar una opcion: \n");
            opcion=menu();
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



/*
    *Valida que el string recibido sea un numero
    *Param: recibe un string de parametro
    *return: de vuelve 1 si es numero, sino un 0
*/

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


/*
    *Funcion que se encarga de mostrar por pantalla un mensaje y guardarlo en un array de string
    *Param: necesita un mensaje y el array donde se va a guardar lo escrito
    *return: no retorna nada
*/
void getString(char mensaje[], char input[]){
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",input);
}

/*
    *Funcion que se encarga de guardar lo escrito solo si son letras
    *param: el array con el mensaje, y el lugar donde se va a guardar el dato
    *return: no devuelve nada
*/
int getStringSoloLetras(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(soloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/*
    *Funcion que se encarga de guardar lo escrito solo si son numeros
    *param: el array con el mensaje, y el lugar donde se va a guardar el dato
    *return: no devuelve nada
*/
int getStringSoloNum(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/*
    *Funcion necesaria para incilizar un array en un valor determinado
    *param: recibe el array a inicializar, la cantidad de lugares que tiene, y el valor a guardar
    *return: no retorna nada
*/
void inicializarArrayInt(char arrayAtrabajar[],int cantidadMaxima,int valor){
    int i;
    for(i=0;i<cantidadMaxima;i++){
        arrayAtrabajar[i]=valor;
    }
}

/*
    *Funcion: Se encarga de buscar el indice de la posicion que se encuentra con un valor determinado
    *PARAM: recibe el array en el cual vamos a buscar, la cantidad de lugares que tiene y el valor que necesitamos encontrar
    *RETURN: Devuelve el indice que tiene el valor encontrado
*/

int buscarPrimero(char arrayAtrabajar[],int cantidadMaxima,int valor){
    int i;
    for(i=0;i<cantidadMaxima;i++){
        if(arrayAtrabajar[i]==valor){
            return i;
        }
    }
    return -1;
}

