#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"


typedef struct{
    char nombre[20];
    char email[20];
}EDireccionesEmail;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarDestinatario(ArrayList* this);


/**
 *  Interactua con el usuario, pidiendole los datos para luego ser cargados en el archivo
 *  @param recibe un puntero tipo emovie, donde va a realizar el cargado de los archivos momentaneos
 *  @return void
 */
void cargarDestinatario(ArrayList* this);


void agregarListaNegra(ArrayList* this);


