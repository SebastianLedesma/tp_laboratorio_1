#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include "utn.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Funcion que busca un espacio de memoria libre para alamcenar un Employee.
 *
 * \return Employee* Retorna la direccion de memoria asignada para guardar el employee o NULL si no encontro.
 *
 */
Employee* employee_new();


/** \brief Funcion constructor que crea un empleado mediante la validacion de los valores recibidos por parametro.
 *
 * \param idStr char* Puntero hacia una cadena de caracteres que represnta el id del empleado.
 * \param nombreStr char* Puntero hacia una cadena de caracteres que representa el nombre del usuario.
 * \param horasTrabajadasStr char* Puntero hacia una cadena de caracteres que representa las horas trabajadas.
 * \param sueldoStr char* Puntero hacia una cadena de caracteres que representa el sueldo.
 * \return Employee* Puntero hacia la direccion de memoria donde esta almacenado el nuevo empleado.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Funcion que permite liberar un espacio de memoria asignado anteriormente pero vacio al momento de la invocacion.
 *
 * \param Employee* Puntero que contiene la direccio de memoria a liberar mediante la funcion free();
 * \return void No retorna valor.
 *
 */
void employee_delete(Employee*);

//*************************************
/** \brief Funcion que funciona como getter del atributo id como texto.
 *
 * \param this Employee* Puntero hacia donde esta almacenado el empleado para obtener el id.
 * \return int Retorna -1 en caso de error(punteros null) o 0 si pudo hacer la operacion.
 *
 */
int employee_getIdText(Employee* this);


/** \brief Funcion que actua como setter del atributo id como texto.Se usa en el constructor para validar y asignar.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \param id char* Puntero que contiene la direccion de memoria donde esta el valor a asignar del id.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_setIdText(Employee* this,char* id);

/** \brief Funcion que actua como setter del atributo id como numero.Se usa en el constructor para validar y asignar.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta el espacio para el empleado.
 * \param id int Variable que contiene el id para asignarle al empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Funcion que actua como getter del atributo id como numero.Retorna el id del empleado.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta el empleado.
 * \param id int* Puntero que contiene la direccion de memoria para guardar el id del empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la asignacion.
 *
 */
int employee_getId(Employee* this,int* id);
//*************************************

//*************************************
/** \brief Funcion que actua como setter del atributo nombre.Se usa en el constructor para asignar y validar la cadena.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta el espacio para almacenar el empleado.
 * \param nombre char* Cadena de caracteres que representa el nombre a asignar al empleado.
 * \return int Retorna -1 si hubo error o 0  si pudo hacer la operacion.
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Funcion que actua como getter del atributo nombre.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \param nombre char* Cadena de caracteres donde se retornara el nombre del empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_getNombre(Employee* this,char* nombre);
//*************************************

/** \brief Funcion que actua como setter del atributo horas trabajadas en formato numero.Valida que sea numero
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \param horasTrabajadas int Variable que contiene el valor de horas trabajadas para asignarle al empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Funcion que actua como getter del atributo horas trabajadas en formato numero.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \param horasTrabajo int* Puntero que contiene la direccion de memoria donde se guardara el valor de las horas.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajo);


/** \brief Funcion que actua como setter del atributo horas trabajadas en formato texto.Se usa en el constructor.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria del empleado donde se guardara el nombre.
 * \param horasTrabajadas char* Cadena de caracteres que representa las horas trabajadas a asignar al empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_setHorasTrabajadasText(Employee* this,char* horasTrabajadas);


/** \brief Funcion que actua como getter del atributo horas trabajadas en formtato texto.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_getHorasTrabajadasText(Employee* this);
//*************************************

/** \brief Funcion que actua como setter del atributo sueldo.Se usa en el contructor para asignar y validar.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria del empleado donde se guardara el sueldo.
 * \param sueldo char* Cadena de caracteres que repreesnta el sueldo del empleado.Se hace la conversion y se asigna el valor.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_setSueldoText(Employee* this,char* sueldo);

/** \brief Funcion que actua como getter del atributo sueldo en formato texto.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \return int Retorna -1 si hubo un error o 0 si pudo hacer la operacion.
 *
 */
int employee_getSueldoText(Employee* this);

/** \brief Funcion que actua como setter del atributo sueldo en formato numero.Se usa en el constructor para validar y asignar.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \param sueldo int Valor del sueldo a asignar al empleado.
 * \return int Retorna -1 si hubo un error o 0 si pudo hacer la operacion.
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Funcionque acuta como getter del atributo sueldo en formato numero.
 *
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \param sueldo int* Puntero que contiene la direccion de memoria que retornara el sueldo del empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

//*************************************
int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);

/** \brief Funcion que imprime un empleado
 *
 * \param pEmpleado Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado.
 * \return int Retorna -1 si hubo error o 0 si pudo hacer la operacion.
 *
 */
int employee_printEmpleado(Employee* pEmpleado);


/** \brief Funcion que permite la carga de datos para el alta de un empleado.
 *
 * \param nuevoId int* Puntero que contiene la direccion del maximo id encontrado para poder actualizarlo.
 * \param nombre char* Puntero que contiene la direccion de memoria para asignar el nombre.
 * \param horasTrabajo int* Puntero que contiene la direccion de memoria para asignar las horas.
 * \param sueldo int* Puntero que contiene la direccion de memoria para asignar el sueldo.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros para ser usada dentro de la funcion.
 * \return int Retorna 0 si los datos ingresados son validos o -1 si no los son o si hubo un error.
 *
 */
int loadNewWEmployee(int* nuevoId,char* nombre,int* horasTrabajo,int* sueldo,LinkedList* pArrayListEmployee);


/** \brief Funcion que realiza la busqueda de un empleado por id y retorna el indice correspondiente.
 *
 * \param id int* Puntero que contiene la direccion del valor del id a buscar.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros de los empleados.
 * \return int Retorna el indice que coincide con el id o -1 si hubo error o no hubo coincidencia.
 *
 */
int employee_searchIdEmployee(int* id,LinkedList* pArrayListEmployee);


/** \brief Funcion que busca el maximo id en una lista.
 *
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de la lista de punteros de los empleados.
 * \param maxId int* Puntero donde se guardara la el valor max encontrado.
 * \return int Retorna 0 si pudo hacer la busqueda o -1 si huboun error.
 *
 */
int employee_searchMaxIdEmployee(LinkedList* pArrayListEmployee,int* maxId);



/** \brief Funcion constructor que permite almacenar en memoria un nuevo empleado(dado de alta por el usuario).
 *
 * \param id int Representa al id a asignar al nuevo empleado.
 * \param nombreStr char* Represnta el nombre del nuev empleado.
 * \param horasTrabajadas int Representa las horas trabajadas del empleado.
 * \param sueldo int Representa el sueldo del trabajador.
 * \return Employee* Puntero que contiene la direccion donde se almacenó el nuevo empleado o NUll si hubo error.
 *
 */
Employee* employee_newParametrosNumerico(int id,char* nombreStr,int horasTrabajadas,int sueldo);


/** \brief Funcion que hace la comparacion del atributo sueldo de 2 empleados y retorna el valor.
 *
 * \param pEmpleado1 Employee* Puntero del primer dato Empleado a evaluar.
 * \param pEmpleado2 Employee* Puntero del segundo dato Empleado a evaluar.
 * \return int Valor de la comparacion realizada entre los 2 empleados.
 *
 */
int employee_CompareBySalary(Employee* pEmpleado1, Employee* pEmpleado2);


/** \brief Funcion que hace la comparacion del atributo horasTrabajas de 2 empleados y retorna el valor.
 *
 * \param pEmpleado1 Employee* Puntero del primer dato Empleado a evaluar.
 * \param pEmpleado2 Employee* Puntero del segundo dato Empleado a evaluar.
 * \return int Valor de la comparacion realizada entre los 2 empleados.
 *
 */
int employee_CompareByHours(Employee* pEmpleado1, Employee* pEmpleado2);

#endif // employee_H_INCLUDED
