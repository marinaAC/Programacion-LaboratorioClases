#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[20];
    char email[20];
}Destinatario;


Destinatario* newDestinatario();

char* getName(Destinatario* this);

char* getEmail(Destinatario* this);

char* setName(Destinatario* this, char* name);

void printDestinatario(Destinatario* this);

