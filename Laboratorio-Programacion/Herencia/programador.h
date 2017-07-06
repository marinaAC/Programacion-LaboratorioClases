

struct S_Programador
{
    Object obj;
    char nombre[20];
    char lenguaje[16]; // "C", "JAVA", "PYTHON"
};
typedef struct S_Programador Programador;

Programador* new_programador();

char* p_getNom(Programador* this);

char* p_getArea(Programador* this);

int p_setNom(Programador* this, char* nombre);

int p_setLenguaje(Programador* this, char* lenguaje);
