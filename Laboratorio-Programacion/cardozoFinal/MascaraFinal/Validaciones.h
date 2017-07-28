

/**
  * Valida que los caracteres ingresados sean solo de tipo numerico
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int esNumerico(char* num);

 /**
  * Valida que los caracteres ingresados sean solo letras
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int soloLetras(char* palabra);

 /**
  * Valida que los caracteres ingresados sean solo letras y numeros
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int alfaNum(char* palabra);

/**
  * Valida que los caracteres ingresados sean alfanumericos y permite solo un guion
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int esTel(char* tel);

/**
  * Valida que los caracteres ingresados sean alfanumericos y permite solo un arroba
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
int esMail(char* email);

/**
  * Obtiene un entero ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el entero ingresado para guardarlo en alguna variable.
 */
int getInt(char* mensaje);

 /**
  * Obtiene un numero flotante ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el valor ingresado para guardarlo en alguna variable.
 */
float getFloat(char* mensaje);

 /**
  * Obtiene un caracter ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el caracter ingresado para guardarlo en alguna variable.
 */
char getChar(char* mensaje);

