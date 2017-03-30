#include <stdio.h>
#include <stdlib.h>
float prom(int suma, int cantidad){
    float buffer;
    buffer=((float)suma/cantidad);
    return buffer;
}

/* Otra forma de crear o sintetizar el promedio
float promedio(int edad[], int cantidad){
    float returnProm;
    int i, suma =0;
    for(i=0;i<cantidad;i++){
        suma=suma+edad[i];
    }
    returnProm=suma/cantidad;
    return returnProm;
}
*/
