
/**
 * \brief Muestra un mensaje de Alerta
 * \param text char* - texto a mostrar.
 * \return void
 */
void interface_msjAlerta(char* text);

/**
 * \brief Imprime un título.
 * \param text char* - texto a mostrar.
 * \return void
 */
void interface_printTitulo(char* text);

/**
 * \brief Imprime texto de operacion interrumpida/Erronea.
 * \param void
 * \return void
 */
void interface_msjError(void);


/**
 * \brief Hace una pregunta y pide por respuesta 'S' para si o 'N' para no. Valida respuesta.
 * \param message char* - pregunta a mostrar por pantalla.
 * \return retorno int - Devuelve (1) para sí. Devuelve (0) para no.
 */
int interface_msjConfirm(char* message);


/**
 * \brief Imprime un mensaje y guarda lo escrito por teclado
 * \param char* mensaje - pregunta a mostrar por pantalla.
 * \param char* input - lugar donde guardara lo ingresado por teclado
 * \return void
 */
void getString(char* mensaje, char* input);

/**
 * \brief Imprime un mensaje y guarda lo escrito por teclado, valida que sea solo letras
 * \param char* mensaje - pregunta a mostrar por pantalla.
 * \param char* input - lugar donde guardara lo ingresado por teclado
 * \return retorna 1 si fue exitoso, 0 sino pudo ser guardado
 */
int getStringSoloLetras(char* mensaje, char* input);

/**
 * \brief Imprime un mensaje y guarda lo escrito por teclado, valida que sea solo numeros
 * \param char* mensaje - pregunta a mostrar por pantalla.
 * \param char* input - lugar donde guardara lo ingresado por teclado
 * \return retorna 1 si fue exitoso, 0 sino pudo ser guardado
 */
int getStringSoloNum(char* mensaje, char* input);
