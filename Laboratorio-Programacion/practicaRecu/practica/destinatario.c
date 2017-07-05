#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[20];
    char email[20];
}Destinatario;


Destinatario* newDestinatario(){
    Destinatario* aux = (Destinatario*)malloc(sizeof(Destinatario));
    return aux;
}

char* getName(Destinatario* this){
    return this->name;
}

char* getEmail(Destinatario* this){
    return this->email;
}

char* setName(Destinatario* this, char* name){
    strncpy(this->name,name,sizeof(this->name));
    return this->name;
}

void printDestinatario(Destinatario* this){
    printf("\nNombre: %s", this->name);
    printf("\nMail: %s", this->email);
}
