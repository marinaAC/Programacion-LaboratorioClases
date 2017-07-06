

struct S_Administrativo
{
    Object obj;
    char nombre[20];
    int area; // AREA_COMPRAS, AREA_VENTAS
};
typedef struct S_Administrativo Administrativo;


Administrativo* new_admin();

char* ad_getNom(Administrativo* this);

int* ad_getArea(Administrativo* this);

int ad_setNom(Administrativo* this, char* nombre);

int ad_setArea(Administrativo* this, int area);
