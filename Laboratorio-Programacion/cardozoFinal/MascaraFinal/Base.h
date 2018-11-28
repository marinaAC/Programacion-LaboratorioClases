

/** \brief Descarga la informaci�n del archivos text.txt a memoria.
 * \param ArrayList* lista - Puntero a la lista donde se indexar� la informaci�n.
 * \return void.
 */
void base_parse(ArrayList* listaNotas, ArrayList* listaFrecuencias);

void parseoFrec(ArrayList* listaFrecuencias);
void compareNotaConFrecuencia(Nota* nota,ArrayList* listaFrecuencias);
void ecualizarSonido(ArrayList* listaNotasCompletas);

