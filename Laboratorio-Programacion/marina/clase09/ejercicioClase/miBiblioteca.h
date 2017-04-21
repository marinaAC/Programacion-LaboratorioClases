struct S_Director{
    char nombre[50];
    char fechNac[50];
    char paisOrigen[50];
    int id;
    int flagLibre;
};
typedef struct S_Director Director;
//Otra forma de utilizar y definirlo, asi cada vez que lo queres llamar no se tiene que utilizar struct S_Director


struct S_Pelicula{
    char titulo[50];
    int year;
    char nacionalidad[50];
    int idPelicula;
    int idDirector;
    int flagLibPelicula;
    //indice del director
    //Se puede poner Director director, pero serian 150bytes
};
typedef struct S_Pelicula Pelicula;

void cargarDIrector(Director directores[],int index, int id);
void cargarPelicula(Pelicula peliculas[],int index, int id, Director directores[]);
int buscarLugarVacioListaDirec(Director directores[], int largo);
int buscarLugarVacioListaPeliculas(Pelicula peliculas[], int largo);
int buscarDirPorIndice(Director directores[],int largo, int idDirectores);
void listarPeliculas(Pelicula peliculas[],Director directores[], int largo);
int menu();
