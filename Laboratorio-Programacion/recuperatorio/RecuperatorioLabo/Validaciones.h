
 /**
  * Valida que los caracteres ingresados sean solo de tipo numerico
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int esNumerico(char num[]);

  /**
  * Valida que los caracteres ingresados sean solo letras
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int soloLetras(char palabra[]);

  /**
  * Valida que los caracteres ingresados sean solo letras y numeros
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int alfaNum(char palabra[]);

  /**
  * Valida que los caracteres ingresados sean alfanumericos y permite solo un guion
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int esTel(char tel[]);

  /**
  * Obtiene un entero ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el entero ingresado para guardarlo en alguna variable.
 */
int getInt(char mensaje[]);

  /**
  * Obtiene un numero flotante ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el valor ingresado para guardarlo en alguna variable.
 */
float getFloat(char mensaje[]);

 /**
  * Obtiene un caracter ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el caracter ingresado para guardarlo en alguna variable.
 */
char getChar(char mensaje[]);

/**
  * Funcion que se encarga de mostrar por pantalla un mensaje y guardarlo en un array de string
  * @param necesita un mensaje y el array donde se va a guardar lo escrito
  * @return no retorna nada
 */
void getString(char mensaje[], char input[]);

/**
  * Funcion que se encarga de guardar lo escrito solo si son letras
  * @param el array con el mensaje, y el lugar donde se va a guardar el dato
  * @return no devuelve nada
 */
int getStringSoloLetras(char mensaje[], char input[]);

/**
  * Funcion que se encarga de guardar lo escrito solo si son numeros
  * @param el array con el mensaje, y el lugar donde se va a guardar el dato
  * @return no devuelve nada
 */
int getStringSoloNum(char mensaje[], char input[]);



