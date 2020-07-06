#include "../inc/LinkedList.h"
#include "Company.h"
#include "parser.h"

/** \brief Funcion principal que permite extraer los datos de un archivo de texto y guardarlos en memoria.
 *
 * \param path char* Cadena de carateres que representa la ruta o nombre del archivo.
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros donde se guardaran los datos.
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListCompany);


/** \brief Funcion principal que permite extraer los datos de un archivo binario y guardarlos en memoria.
 *
 * \param path char* Cadena de carateres que representa la ruta o nombre del archivo.
 * \param pArrayListCompany LinkedList* LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros donde se guardaran los datos.
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListCompany);



/** \brief Funcion principal que permite crear una empresa y agregarla a una lista.
 *
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de la lista de punteros donde se guardara la nueva empresa.
 * \return int Retorna 0 si pudo hacer el alta,1 si se cancela o -1 si hubo un error.
 *
 */
int controller_addCompany(LinkedList* pArrayListCompany);


/** \brief Funcion que permite editar una empresa de la lista.
 *
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de la lista de punteros que apuntan a las empresas.
 * \return int Retorna 0 si pudo hacer la edicion,1 si se cancela o -1 su hubo un error.
 *
 */
int controller_editCompany(LinkedList* pArrayListCompany);


/** \brief Funcion principal que elimina una empresa de la lista.
 *
 * \param pArrayListCompany LinkedList* Puntero que contiene la lista de punteros que apuntan a las empresas.
 * \return int Retorna 0 si pudo hacer la baja,1 si se cancela o -1 su hubo un error.
 *
 */
int controller_removeCompany(LinkedList* pArrayListCompany);


/** \brief Funcion que muestra todos las empresas disponibles.
 *
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros que apuntan a las empresas.
 * \return int Retorna 0 si pudo mostrar los empleados o -1 si hubo un error.
 *
 */
int controller_ListCompany(LinkedList* pArrayListCompany);


/** \brief Funcion principal que permite ordenar la lista de punteros que apuntan a las empresas.
 *
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de la lista con los punteros de las empresas.
 * \return int Retorna 0 si pudo hacer el ordenamiento,1 si se cancelo o -1 si hubo un error.
 *
 */
int controller_sortCompany(LinkedList* pArrayListCompany);



/** \brief Funcion que permite guardar la lista de las empresas almacenada en memoria y escribirla en un archivo de texto.
 *
 * \param path char* Cadena de caracteres que representa la ruta o nombre del archivo donde se escribiran los datos.
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de memoria de la lista de las empresas a guardar.
 * \return int Retorna 0 si pudo hacer el guardado o -1 si hubo un error.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListCompany);


/** \brief Funcion que permite guardar la lista de empresas almacenada en memoria y escribirla en un archivo para despues leerla en forma binaria.
 *
 * \param path char* Cadena de caracteres que representa la ruta o nombre del archivo donde se escribiran los datos.
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de memoria de la lista de empresas a guardar.
 * \return int Retorna 0 si pudo hacer el guardado o -1 si hubo un error.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListCompany);


/** \brief Funcion que guarda los datos en los archivos antes de cerrar la aplicacion
 *
 * \param pathText char* Archivo de texto para guardar los datos en modo texto.
 * \param pathBinary char* Archivo para guardar los datos en modo binario.
 * \param pArrayListCompany LinkedList* Puntero a la lista original copiada al inicio del programa.
 * \param pCopyArrayList LinkedList* Copia de la lista original copiada al inicio del programa.Esta contiene las modificaciones.
 * \param editado int Flag a evaluar para saber si se modifico la lista
 * \return int Retorna -1 si hubo un error,0 si no hubo cambios en la lista o 1 si se guardaron los datos.
 *
 */
int controller_saveAll(char* pathText,char* pathBinary, LinkedList* pArrayListCompany, LinkedList* pCopyArrayList,int editado);
