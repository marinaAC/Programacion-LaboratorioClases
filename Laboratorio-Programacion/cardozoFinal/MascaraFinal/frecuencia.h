
struct S_FrecuenciaPars{
    char nombre[50];
    int valor;
};
typedef struct S_FrecuenciaPars FrecArchivo;

FrecArchivo* frec_newFrecuenciaArch(void);

void frec_delete(FrecArchivo* this);

//SETTERS
int frec_setNombre(FrecArchivo* this, char* name);

int frec_setValor(FrecArchivo* this, char* valor);



//GETTERS

char* frec_getNombre(FrecArchivo* this);

int* frec_getValor(FrecArchivo* this);

