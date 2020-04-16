/** \brief Funci�n que permite ingresar un double y retornarlo.
 *
 * \param mensaje[] char Mensaje para mostrar al usuario al ingresar un nro.
 * \return double N�mero ingresado por el usuario.
 *
 */
double getDouble(char mensaje[]);


/** \brief Funci�n que permite ingresar y validar un n�mero entero.
 *
 * \param mensaje[] char Mensaje para mostrar al usuario al ingresar el n�mero
 * \param mensajeError[] char Mensaje que indica que el n�mero ingresado no es v�lido.
 * \param desde int N�mero que indica el inicio del rango de n�meros v�lidos.
 * \param hasta int N�mero que indica el final del rango de n�meros v�lidos
 * \return int N�mero validado que retorna la funci�n.
 *
 */
int getInt(char mensaje[],char mensajeError[],int desde,int hasta);



/** \brief Funci�n que suma dos n�meros y retorna el resultado.
 *
 * \param nro1 double Primer n�mero a sumar.
 * \param nro2 double Segundo n�mero a sumar.
 * \return double Resultado de la suma.
 *
 */
double sumar(double nro1,double nro2);


/** \brief Funci�n que realiza una resta y retorna el resultado
 *
 * \param nro1 double N�mero al que se le va a restar el segundo.
 * \param nro2 double N�mero que se le va a restar al primero.
 * \return double Resultado de la resta.
 *
 */
double restar(double nro1,double nro2);


/** \brief Funci�n que multiplica dos n�meros y retorna el resultado.
 *
 * \param nro1 double Primer n�mero a multiplicar.
 * \param nro2 double Segundo n�mero a multiplicar.
 * \return double Resultado de multiplicaci�n.
 *
 */
double multiplicar(double nro1,double nro2);


/** \brief Funci�n que realiza la divisi�n de dos n�meros si el segundo par�metro es distinto de cero.
 *
 * \param nro1 double Dividendo de la operaci�n.
 * \param nro2 double Divisor de la operaci�n.
 * \return double Resultado de la operaci�n.
 *
 */
double dividir(double nro1,double nro2);


/** \brief Funci�n que muestra un men� de opciones.
 *
 * \param nro1 double N�mero a mostrar entre las opciones para guiar al usuario.
 * \param nro2 double N�mero a mostrar entre las opciones para guiar al usuario.
 * \return void La funci�n no retorna valor.
 *
 */
void mostarMenuDeOperaciones(double nro1,double nro2);


/** \brief Funci�n que inserta una pausa y limpia la pantalla.
 *
 * \return void No retorna valor.
 *
 */
void limpiarPantalla();


/** \brief Funci�n que calcula el factorial(previa verificaci�n) de un n�mero siempre que este sea entero.
 *
 * \param nro double N�mero para calcular el factorial.
 * \return double Si el par�metro es entero retorna su factorial, caso contrario retorna -1
 *
 */
double calcularFactorial(double nro);


/** \brief Funci�n que verifica si el par�metro recibido es entero.
 *
 * \param nro double Par�metro a validar.
 * \return int Retorna 1 si el par�metro es entero,caso contrario retorna 0.
 *
 */
int verificarNroEntero(double nro);



/** \brief Funci�n que muestra el resultado de una division(divisor distinto de 0) o un mensaje de error.
 *
 * \param resultado double Resultado de una divis�n.
 * \param divisor double Divisor a evaluar.
 * \return void No retorna valor.
 *
 */
void mostrarResultadoDivision(double resultado,double divisor);

