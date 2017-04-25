#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


void inicializarListaInt(EPersona lista[],int cantidadPersonas,int valor);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidadPersonas, int valor);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int cantidadPersonas);

#endif // FUNCIONES_H_INCLUDED


//Funciones para obtener promedio de un array, max y min, y el indice del minimo
float promedio (int numero[], int cantidad);
int max(int numero[], int cantidad);
int min(int numero[], int cantidad);
int minIndice(int numero[], int cantidad);
//Funcion para compactar y ordenar un array de enteros
int compactar(int numero[], int cantidad, int eliminar);
void ordernar(int numero[], int cantidadArray,int array2[]);

//Funcion para obtener un promedio y suma
 float promedioUno(float numerosSumados,float cantidadDeVeces);
 float suma(float numero1, float numero2);
 float resta(float numero1, float numero2);
 float division(float numero1, float numero2);
 float multilicacion(float numero1, float numero2);
 float factorial(float numero);
 void validacionIngreso(int opcion);




 //////////Nuevos tipos de validaciones


 int esNumerico(char num[]);
 int soloLetras(char palabra[]);
 int alfaNum(char palabra[]);
 int esTel(char tel[]);

 char getChar(char mensaje[]);
 float getFloat(char mensaje[]);
 int getInt(char mensaje[]);

 void getString(char mensaje[], char input[]);
 int getStringSoloLetras(char mensaje[], char input[]);
 int getStringSoloNum(char mensaje[], char input[]);

int maxEdad(EPersona lista[], int cantidadPersonas);
int minimaEdad(EPersona lista[], int cantidadPersonas);
