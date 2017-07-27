#include <stdio.h>
#include <stdlib.h>
#include "People.h"
#include "Validaciones.h"



Person* person_newPerson(void){
    Person* newPersn = (Person*)malloc(sizeof(Person));
    return newPersn;
}


void person_delete(Person* this){
    free(this);
}

//SETTERS
int person_setName(Person* this, char* name){
    int returnAux = -1;

    if(this != NULL){
        strncpy(this->name,name,sizeof(this->name));
        returnAux = 0;
    }

    return returnAux;
}

int person_setAge(Person* this, char* age){
    int returnAux = -1;
    int auxAge;
    if(this != NULL){
        auxAge = atoi(age);
        if(auxAge>0){
            this->age=auxAge;
            returnAux =0 ;
        }
        returnAux = 1;
    }
    return returnAux;
}

//GETTERS

char* person_getName(Person* this){
    return this->name;
}

char* person_getAge(Person* this){
    return this->age;
}


//PRINT

void person_print(Person* this){
    printf("--------------------------------\n");
    printf("Nombre: %s | Edad: %s\n",person_getName(this),person_getAge(this));
    printf("--------------------------------\n");
}
