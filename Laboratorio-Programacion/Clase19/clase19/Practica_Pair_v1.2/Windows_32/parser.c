#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* fp , ArrayList* pArrayListEmployee)
{   Employee* emp;
     while(!feof(fp)){
        emp = (Employee*)malloc(sizeof(Employee));
        char auxId[100];
        char auxIsEmpty[50];
        fscanf(fp,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,emp->name,emp->lastName,auxIsEmpty);
        emp->id=atoi(auxId);
        emp->isEmpty = atoi(auxIsEmpty);
        al_add(pArrayListEmployee,(void*)emp);
    }
    return 0;
}
