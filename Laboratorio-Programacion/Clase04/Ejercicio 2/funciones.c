#include <stdio.h>
#include <stdlib.h>

float promedio (int edad[], int cantidad) {

    int suma=0;
    float resultadoProm;
    int i;

    for (i=0; i<cantidad;i++) {

        suma = suma + edad[i];

    }

    resultadoProm = (float)suma / cantidad;

    return resultadoProm;

}

int menu()
{
    int opcion=0;

    printf("\n1. Mostrar promedio");
    printf("\n2. Mostrar edad maxima");
    printf("\n3. Mostrar edad minima");
    printf("\n4. Salir");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    system("continue");

    return opcion;
}

int max(int edad[], int cantidad)
{
    int flag=0;
    int i;
    int max;

    for (i=0; i<cantidad; i++)
    {
        if (flag == 0)
        {
            flag = 1;
            max = edad[i];
        }

        if(edad[i]>max)
        {
            max = edad[i];
        }
    }

    return max;
}

int min(int edad[], int cantidad)
{
    int min;
    int i;
    int flag=0;

    for (i=0; i<cantidad; i++)
    {
        if (flag == 0)
        {
            flag = 1;
            min = edad[i];
        }
        if (edad[i]<min)
        {
            min = edad[i];
        }
    }

    return min;
}
