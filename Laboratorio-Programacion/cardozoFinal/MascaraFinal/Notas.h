

struct S_Nota{
    char nombre[50];
    int freq;
    int duration;
    int volumen;
};
typedef struct S_Nota Nota;

//INICIALIZACION
/** \brief Reserva memoria para un nuevo objeto e inicializa campos.
 * \param void.
 * \return Nota* - Puntero al nuevo objeto.
 */
Nota* nota_newNota(void);

//ELIMINACION
/** \brief Libera la memoria utilizada por el objeto.
 * \param Nota* this - Puntero al objeto.
 * \return void.
 */
void nota_delete(Nota* this);

//SETTERS
/** \brief Valida y almacena la información en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return int - (-1) if error, (0) if ok.
 */
int nota_setNombre(Nota* this, char* name);

/** \brief Valida y almacena la información en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return int - (-1) if error, (0) if ok.
 */
int nota_setFrecuencia(Nota* this, int* freq);

/** \brief Valida y almacena la información en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return int - (-1) if error, (0) if ok.
 */
int nota_setDuration(Nota* this, char* duration);

/** \brief Valida y almacena la información en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return int - (-1) if error, (0) if ok.
 */
int nota_setVolumen(Nota* this, char* volumen);

//GETTERS
/** \brief Devuelve el dato almacenado en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return char* - dato almacenado en el campo.
 */
char* nota_getNombre(Nota* this);

/** \brief Devuelve el dato almacenado en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return char* - dato almacenado en el campo.
 */
int* nota_getFrecuencia(Nota* this);

/** \brief Devuelve el dato almacenado en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return char* - dato almacenado en el campo.
 */
int* nota_getDuration(Nota* this);

/** \brief Devuelve el dato almacenado en el campo.
 * \param Nota* this - Puntero al objeto.
 * \return char* - dato almacenado en el campo.
 */
int* nota_getVolumen(Nota* this);

//IMPRESION
/** \brief Imprime por pantalla la información almacenada en los campos.
 * \param Nota* this - Puntero al objeto.
 * \return void.
 */
void nota_print(Nota* this);
