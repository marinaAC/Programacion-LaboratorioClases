
struct S_Person{
    char name[30];
	char lastName[30];
    int age;
};
typedef struct S_Person Person;

//INICIALIZACION
/** \brief Reserva memoria para un nuevo objeto e inicializa campos.
 * \param void.
 * \return Person* - Puntero al nuevo objeto.
 */
Person* person_newPerson(void);

//ELIMINACION
/** \brief Libera la memoria utilizada por el objeto.
 * \param Person* this - Puntero al objeto.
 * \return void.
 */
void person_delete(Person* this);

//SETTERS
/** \brief Valida y almacena la información en el campo.
 * \param Person* this - Puntero al objeto.
 * \return int - (-1) if error, (0) if ok.
 */
int person_setName(Person* this, char* name);

/** \brief Valida y almacena la información en el campo.
 * \param Person* this - Puntero al objeto.
 * \return int - (-1) if error, (0) if ok.
 */
int person_setAge(Person* this, char* age);

//GETTERS
/** \brief Devuelve el dato almacenado en el campo.
 * \param Person* this - Puntero al objeto.
 * \return char* - dato almacenado en el campo.
 */
char* person_getName(Person* this);

/** \brief Devuelve el dato almacenado en el campo.
 * \param Person* this - Puntero al objeto.
 * \return char* - dato almacenado en el campo.
 */
char* person_getAge(Person* this);

//IMPRESION
/** \brief Imprime por pantalla la información almacenada en los campos.
 * \param Person* this - Puntero al objeto.
 * \return void.
 */
void person_print(Person* this);
