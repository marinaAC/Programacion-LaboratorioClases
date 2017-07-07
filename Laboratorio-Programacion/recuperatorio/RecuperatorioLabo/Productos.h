#ifndef S_PRODUCTO
typedef struct{
    int id;
    char name[20];
    char version[20];
    int category;
}S_Productos;
#define S_PRODUCTO
#endif

/**
*\brief Reserva un espacio de memoria, con malloc, para crear un nuevo producto del tipo S_Productos
*\param void
*\return retorna un puntero donde se encuentra disponible el espacio para el guardado
**/
S_Productos* newProducto();

/**
*\brief Setea, guarda el valor pasado por parametro para guardarlo en la direccion pasada, donde se encuentra alojada la estructura
*\param Recibe un puntero de tipo S_Productos
*\param id tipo entero, el numero que se desea guardar en el id para ese elemento
*\return no retorna nada
**/
void setIdProcut(S_Productos* this, int id);

/**
*\brief Setea, guarda el valor pasado por parametro para guardarlo en la direccion pasada, donde se encuentra alojada la estructura
*\param Recibe un puntero de tipo S_Productos
*\param Recibe el nombre que se desea guardar, de tipo char
*\return no retorna nada
**/
void setNameProduct(S_Productos* this, char* name);

/**
*\brief Setea, guarda el valor pasado por parametro para guardarlo en la direccion pasada, donde se encuentra alojada la estructura
*\param Recibe un puntero de tipo S_Productos
*\param Recibe el valor de la version, de tipo char
*\return no retorna nada
**/
void setVersionProduct(S_Productos* this, char* number);

/**
*\brief Setea, guarda el valor pasado por parametro para guardarlo en la direccion pasada, donde se encuentra alojada la estructura
*\param Recibe un puntero de tipo S_Productos
*\param recibe el numero de la categoria, tipo int
*\return no retorna nada
**/
void setCategory(S_Productos* this, int number);
