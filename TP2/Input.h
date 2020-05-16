/** \brief Funcion que permite ingresar un no entero.
 *
 * \param [] char Mensaje a mostrar para ingresar un nro.
 * \param [] char Mensaje de error a mostrar en case de ingresar un dato invalido.
 * \param int Valor de rango inicial de valores validos.
 * \param int Valor de fin de rango de valores validos.
 * \return int Retorna el nro validado ingresado por el usuario.
 *
 */
int getInt(char [],char [],int,int);


/** \brief Fnucion que permite el ingreso de una cadena de caracteres.
 *
 * \param [] char Mensaje a mostrar para el ingreso de caracteres.
 * \param [] char Mensaje de error a mostrar en caso de ingresar datos invalidos.
 * \param [] char Cadena en la que se almacenara la cadena de caracteres ingresada.
 * \return void No retorna valor.
 *
 */
void getName(char [],char [],char []);


/** \brief Funcione que valida cada uno de los caracteres de la cadena.
 *
 * \param [] char Cadena que se valida.
 * \return int Retorna 1 en case de que todos los caracteres sean letras o -1 en case de que tenga caracteres invalidos.
 *
 */
int validarNombre(char []);


/** \brief Funcion que retorna un nro flotante.
 *
 * \param [] char Mensaje a mostrar para ingresar un nro.
 * \param [] char Mensaje a mostrar en case de error en el ingreso de datos.
 * \param int Valor minimo valido.
 * \return float Nro flotante ingresado.
 *
 */
float getFloat(char [],char [],int);


/** \brief Funcion que permite el ingreso de un caracter.
 *
 * \param [] char Mensaje a mostrar para el ingreso de datos.
 * \return char Caracter ingresado.
 *
 */
char getChar(char []);


/** \brief Funcion que muestra un menu de opciones.
 *
 * \param [] char Opciones a mostrar unidas en una sola cadena separadas por un salto de linea.
 * \return void No retorna valor.
 *
 */
void showMenu(char []);

/** \brief Funcion que limpia la consola para una mayor legibilidad.
 *
 * \param void No recibe parametros.
 * \return void No retorna valor.
 *
 */
void cleanScreen(void);
