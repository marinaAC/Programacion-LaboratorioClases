
/**
*\brief Abre un archivo, lo parsea a productos y luego lo guarda en el arrayList que recibe de parametro
*\param listaProd puntero ArrayList donde se va alojar el parseo de archivos
*\return retorna -1 si el archivo no pudo ser abierto y 0 cuando se logro el parseo y guardado en el ArrayList
**/
int parseoData(ArrayList* listaProd);

/**
*\brief devuelve un nuevo ArraList cargado con los productos pertenecientes a la categoria indicada por parametro
*\param pLista puntero al ArrayList a filtrar
*\param cat entero que indica categoria de filtrado
*\return devuelve un nuevo arralist cargado con los elementos de la categoria pasada por parametro
**/
ArrayList* filter(ArrayList* pLista, int cat);
