#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "../inc/LinkedList.h"
#include "utn.h"
typedef struct
{
    int id;
    char nombre[128];
    int anio;
    int empleados;
}Company;

/** \brief Funcion que busca un espacio de memoria libre para alamcenar una empresa.
 *
 * \return Company* Retorna la direccion de memoria asignada para guardar la empresa o NULL si no encontro.
 *
 */
Company* company_new();


/** \brief Funcion constructor que crea una empresa mediante la validacion de los valores recibidos por parametro.
 *
 * \param idStr char* Puntero hacia una cadena de caracteres que represnta el id de la empresa.
 * \param nombreStr char* Puntero hacia una cadena de caracteres que representa el nombre de la empresa.
 * \param anioStr char* Puntero hacia una cadena de caracteres que representa el anio.
 * \param empleadosStr char* Puntero hacia una cadena de caracteres que representa la cantidad de empleados.
 * \return Company* Puntero hacia la direccion de memoria donde esta almacenado la nueva empresa.
 *
 */
Company* company_newParametros(char* idStr,char* nombreStr,char* anioStr,char* empleadosStr);

/** \brief Funcion que permite liberar un espacio de memoria asignado anteriormente pero vacio al momento de la invocacion.
 *
 * \param Company* Puntero que contiene la direccio de memoria a liberar mediante la funcion free();
 * \return void No retorna valor.
 *
 */
void company_delete(Company*);

//*************************************
/** \brief Funcion que funciona como getter del atributo id como texto.
 *
 * \param this Company* Puntero hacia donde esta almacenado la empresa para obtener el id.
 * \return int Retorna -1 en caso de error(punteros null) o 0 si pudo hacer la operacion.
 *
 */
int company_getIdText(Company* this);


/** \brief Funcion que actua como setter del atributo id como texto.Se usa en el constructor para validar y asignar.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \param id char* Puntero que contiene la direccion de memoria donde esta el valor a asignar del id.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_setIdText(Company* this,char* id);

/** \brief Funcion que actua como setter del atributo id como numero.Se usa en el constructor para validar y asignar.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta el espacio para la empresa.
 * \param id int Variable que contiene el id para asignarle a la empresa.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_setId(Company* this,int id);

/** \brief Funcion que actua como getter del atributo id como numero.Retorna el id de la empresa.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta la empresa.
 * \param id int* Puntero que contiene la direccion de memoria para guardar el id de la empresa.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la asignacion.
 *
 */
int company_getId(Company* this,int* id);
//*************************************

//*************************************
/** \brief Funcion que actua como setter del atributo nombre.Se usa en el constructor para asignar y validar la cadena.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta el espacio para almacenar la empresa.
 * \param nombre char* Cadena de caracteres que representa el nombre a asignar a la empresa.
 * \return int Retorna -1 si hubo error o 0  si pudo hacer la operacion.
 *
 */
int company_setNombre(Company* this,char* nombre);


/** \brief Funcion que actua como getter del atributo nombre.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \param nombre char* Cadena de caracteres donde se retornara el nombre de la empresa.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_getNombre(Company* this,char* nombre);
//*************************************

/** \brief Funcion que actua como setter del atributo anio en formato numero.Valida que sea numero
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \param anio int Variable que contiene el valor del anio para asignarle a la empresa.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_setAnio(Company* this,int anio);

/** \brief Funcion que actua como getter del atributo anio en formato numero.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta almacenada la empresa.
 * \param anio int* Puntero que contiene la direccion de memoria donde se guardara el valor del anio.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_getAnio(Company* this,int* anio);


/** \brief Funcion que actua como setter del atributo anio en formato texto.Se usa en el constructor.
 *
 * \param this Company* Puntero que contiene la direccion de memoria de la empresa donde se guardara el nombre.
 * \param anio char* Cadena de caracteres que representa el anio a asignar a la empresa.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_setAnioText(Company* this,char* anio);


/** \brief Funcion que actua como getter del atributo anio en formtato texto.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_getAnioText(Company* this);
//*************************************

/** \brief Funcion que actua como setter del atributo empleados.Se usa en el contructor para asignar y validar.
 *
 * \param this Company* Puntero que contiene la direccion de memoria de la empresa donde se guardara el nro de empleados.
 * \param empleados char* Cadena de caracteres que repreesnta el nro de empleados.Se hace la conversion y se asigna el valor.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_setEmpleadosText(Company* this,char* empleados);

/** \brief Funcion que actua como getter del atributo empleados en formato texto.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \return int Retorna -1 si hubo un error o 0 si pudo hacer la operacion.
 *
 */
int company_getEmpleadosText(Company* this);

/** \brief Funcion que actua como setter del atributo empleados en formato numero.Se usa en el constructor para validar y asignar.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \param sueldo int Valor del nro de empleados a asignar a la empresa.
 * \return int Retorna -1 si hubo un error o 0 si pudo hacer la operacion.
 *
 */
int company_setEmpleados(Company* this,int empleados);

/** \brief Funcionque acuta como getter del atributo empleados en formato numero.
 *
 * \param this Company* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \param anio int* Puntero que contiene la direccion de memoria que retornara el nro de empleados.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_getEmpleados(Company* this,int* empleados);

//*************************************
/** \brief Funcion que premute hacer la comparacion entre los atributos nombre de 2 empresas.
 *
 * \param e1 Company* Puntero al primer elemento de tipo Company.
 * \param e2 Company* Puntero al segundo elemento de tipo Company
 * \return int Retorna el valor de retorno de la funcion strcmp entre los nombre.
 *
 */
int company_CompareByName(Company* e1, Company* e2);



/** \brief Funcion que permite hacer la comparacion entre los atributos  id de las empresas.
 *
 * \param e1 Company* Puntero al primer elemento de tipo Company.
 * \param e2 Company* Puntero al segundo elemento de tipo Company.
 * \return int Retorna 1 si el primer id es mayor al segundo,0 si son iguales o -1 si el segundo es mayor al primero.
 *
 */
int company_CompareById(Company* e1, Company* e2);

/** \brief Funcion que imprime una empresa.
 *
 * \param pCompany Company* Puntero que contiene la direccion de memoria donde esta almacenado la empresa.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int company_printEmpresa(Company* pCompany);


/** \brief Funcion que permite la carga de datos para el alta de una empresa.
 *
 * \param nuevoId int* Puntero que contiene la direccion del maximo id encontrado para poder actualizarlo.
 * \param nombre char* Puntero que contiene la direccion de memoria para asignar el nombre.
 * \param anio int* Puntero que contiene la direccion de memoria para asignar el anio de fundacion.
 * \param empleados int* Puntero que contiene la direccion de memoria para asignar el nro de empleados.
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros para ser usada dentro de la funcion.
 * \return int Retorna 0 si los datos ingresados son validos o -1 si no los son o si hubo un error.
 *
 */
int loadNewCompany(int* nuevoId,char* nombre,int* anio,int* empleados,LinkedList* pArrayListCompany);


/** \brief Funcion que realiza la busqueda de una empresa por id y retorna el indice correspondiente.
 *
 * \param id int* Puntero que contiene la direccion del valor del id a buscar.
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros de las empresas.
 * \return int Retorna el indice que coincide con el id o -1 si hubo error o no hubo coincidencia.
 *
 */
int company_searchIdCompany(int* id,LinkedList* pArrayListCompany);


/** \brief Funcion que busca el maximo id en una lista.
 *
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de la lista de punteros de las empresas.
 * \param maxId int* Puntero donde se guardara la el valor max encontrado.
 * \return int Retorna 0 si pudo hacer la busqueda o -1 si huboun error.
 *
 */
int company_searchMaxIdCompany(LinkedList* pArrayListCompany,int* maxId);



/** \brief Funcion constructor que permite almacenar en memoria una nueva empresa(dado de alta por el usuario).
 *
 * \param id int Representa al id a asignar a la nueva empresa.
 * \param nombreStr char* Represnta el nombre de la nueva empresa.
 * \param anio int Representa el anio de fundacion de la empresa.
 * \param empleados int Representa el nro de empleados de la empresa.
 * \return Employee* Puntero que contiene la direccion donde se almacenó la nueva empresa o NUll si hubo error.
 *
 */
Company* company_newParametrosNumerico(int id,char* nombreStr,int anio,int empleados);


/** \brief Funcion que hace la comparacion del atributo nro de empleados de 2 empresas y retorna el valor.
 *
 * \param pCompany1 Company* Puntero del primer dato Company a evaluar.
 * \param pCompany2 Company* Puntero del segundo dato Company a evaluar.
 * \return int Valor de la comparacion realizada entre las 2 empresas.
 *
 */
int company_CompareByNumberEmployees(Company* pCompany1, Company* pCompany2);


/** \brief Funcion que hace la comparacion del atributo anio de 2 empresas y retorna el valor.
 *
 * \param pCompany1 Company* Puntero del primer dato Company a evaluar.
 * \param pCompany2 Company* Puntero del segundo dato Company a evaluar.
 * \return int Valor de la comparacion realizada entre los 2 empleados.
 *
 */
int company_CompareByYear(Company* pCompany1, Company* pCompany2);

#endif // employee_H_INCLUDED
