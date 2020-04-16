/** \brief Función que permite ingresar un double y retornarlo.
 *
 * \param mensaje[] char Mensaje para mostrar al usuario al ingresar un nro.
 * \return double Número ingresado por el usuario.
 *
 */
double getDouble(char mensaje[]);


/** \brief Función que permite ingresar y validar un número entero.
 *
 * \param mensaje[] char Mensaje para mostrar al usuario al ingresar el número
 * \param mensajeError[] char Mensaje que indica que el número ingresado no es válido.
 * \param desde int Número que indica el inicio del rango de números válidos.
 * \param hasta int Número que indica el final del rango de números válidos
 * \return int Número validado que retorna la función.
 *
 */
int getInt(char mensaje[],char mensajeError[],int desde,int hasta);



/** \brief Función que suma dos números y retorna el resultado.
 *
 * \param nro1 double Primer número a sumar.
 * \param nro2 double Segundo número a sumar.
 * \return double Resultado de la suma.
 *
 */
double sumar(double nro1,double nro2);


/** \brief Función que realiza una resta y retorna el resultado
 *
 * \param nro1 double Número al que se le va a restar el segundo.
 * \param nro2 double Número que se le va a restar al primero.
 * \return double Resultado de la resta.
 *
 */
double restar(double nro1,double nro2);


/** \brief Función que multiplica dos números y retorna el resultado.
 *
 * \param nro1 double Primer número a multiplicar.
 * \param nro2 double Segundo número a multiplicar.
 * \return double Resultado de multiplicación.
 *
 */
double multiplicar(double nro1,double nro2);


/** \brief Función que realiza la división de dos números si el segundo parámetro es distinto de cero.
 *
 * \param nro1 double Dividendo de la operación.
 * \param nro2 double Divisor de la operación.
 * \return double Resultado de la operación.
 *
 */
double dividir(double nro1,double nro2);


/** \brief Función que muestra un menú de opciones.
 *
 * \param nro1 double Número a mostrar entre las opciones para guiar al usuario.
 * \param nro2 double Número a mostrar entre las opciones para guiar al usuario.
 * \return void La función no retorna valor.
 *
 */
void mostarMenuDeOperaciones(double nro1,double nro2);


/** \brief Función que inserta una pausa y limpia la pantalla.
 *
 * \return void No retorna valor.
 *
 */
void limpiarPantalla();


/** \brief Función que calcula el factorial(previa verificación) de un número siempre que este sea entero.
 *
 * \param nro double Número para calcular el factorial.
 * \return double Si el parámetro es entero retorna su factorial, caso contrario retorna -1
 *
 */
double calcularFactorial(double nro);


/** \brief Función que verifica si el parámetro recibido es entero.
 *
 * \param nro double Parámetro a validar.
 * \return int Retorna 1 si el parámetro es entero,caso contrario retorna 0.
 *
 */
int verificarNroEntero(double nro);



/** \brief Función que muestra el resultado de una division(divisor distinto de 0) o un mensaje de error.
 *
 * \param resultado double Resultado de una divisón.
 * \param divisor double Divisor a evaluar.
 * \return void No retorna valor.
 *
 */
void mostrarResultadoDivision(double resultado,double divisor);

