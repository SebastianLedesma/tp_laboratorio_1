typedef struct{
    int id;
    char name[25];
    char lastName[25];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief Funcion que inicializa el estado de los empleados para la carga posterior de datos
 *
 * \param [] Employee Array de empleados a inicializar.
 * \param int Longitud del array de empleados.
 * \return int Respuesta de la funcion, 0 si no pudo inicializar o 1 si lo pudo hacer.
 *
 */
int initEmployees(Employee [], int);


/** \brief Funcion que imprime un array de Employees mostrando los datos en forma de tabla.
 *
 * \param [] Employee Array de Employees a mostrar.
 * \param int Longitud del array.
 * \return int Respuesta de la funcion, 0 si no pudo inicializar o 1 si lo pudo hacer.
 *
 */
int printEmployees(Employee [], int);


/** \brief Funcion que busca un id especifico.
 *
 * \param [] Employee Array de Employee donde se buscara el ID.
 * \param len int Longitud del array de tipo Employee.
 * \param id int Nro de ID a buscar entre los emplyoyees dados de alta en el array.
 * \return int Retorna el indice donde hay  coincidencia o -1 en caso de que no halla podido hacer la busqueda.
 *
 */
int findEmployeeById(Employee [], int len,int id);


/** \brief Funcion que busca en un array un lugar libre para cargar in Employee.
 *
 * \param [] Employee Array en el que se buscará la posicion libre.
 * \param int Longitud del array de Employee.
 * \return int Retorna el indice donde de la posicion libre o -1 en caso de no haber podido realizar la funcion.
 *
 */
int findFreeIndexEmployee(Employee [],int);


/** \brief Funcion que agrega un Employee a un array.
 *
 * \param [] Employee Array de employees al que se agrega uno nuevo.
 * \param len int Longitud del array.
 * \param id int ID que se le asigna al nuevo Employee en case de que sean correctos los parametros.
 * \param name[] char Nombre que tendra el nuevo employee.
 * \param lastName[] char Apellido que tendra el nuevo employee.
 * \param salary float Salario que tendra el nuevo employee.
 * \param sector int Sector en el que trabaja el nuevo employee.
 * \return int Indica si se agrego un employee al array.1 si se agrego,0 si se cancelo el alta o -1 en case de que no halla lugar.
 *
 */
int addEmployee(Employee [],int len,int id,char name[],char lastName[],float salary,int sector);


/** \brief Funcion que permite el ingreso de datos para crear un employee.Invoca a la funcion addEmployee.
 *
 * \param [] Employee Array de employees al que se agregara un nuevo employee.
 * \param int Longitud del array de employees.
 * \param int Id para sasignarle al nuevo empleado.
 * \return int Retorna 1 si el alta fue exitosa o -1 si no se pudo dar de alta.
 *
 */
int createEmployee(Employee [],int,int);


/** \brief Funcion que imprime un employee.
 *
 * \param Employee Employee a imprimir por consola.
 * \return void No retorna valor.
 *
 */
void printAEmployee(Employee);


/** \brief Funcion que elimnina de forma logica un employee.
 *
 * \param [] Employee Array a recorrer para buscar el employee a eliminar.
 * \param int Longitud del array de employees.
 * \param int ID del employee a eliminar.
 * \return int Retorna 1 si se confirma la eliminacion,0 si cancela la eliminacion o -1 si no pudo realizar la baja.
 *
 */
int removeEmployee(Employee [], int, int);

/** \brief Funcion que ordena una lista segun criterio a eleccion.
 *
 * \param [] Employee Array a ordenar.
 * \param int Longitud del array de Employee.
 * \param int Opcion que determina orden del array(1 ascendente,2 descendente).
 * \return int Retorna 0 si pudo realizar el ordenamiento.
 *
 */
int sortEmployees(Employee [], int,int);

/** \brief Funcion que acumula los salarios de los empleados dados de alta.
 *
 * \param [] Employee Array de Employee a recorrer.
 * \param int Longitud del array de Employee.
 * \return float Total de salarios.
 *
 */
float countSalaryEmployees(Employee [],int);


/** \brief Funcion que cuenta la cantidad de empleados dados de alta.
 *
 * \param [] Employee Employee Array de Employee a recorrer.
 * \param int Longitud del array de Employee.
 * \return int Cantidad de empleados contados.
 *
 */
int countEmployeeList(Employee [],int);


/** \brief Funcion que calcula el salario promedio de un array de Employee.
 *
 * \param float Suma total de salarios de los empleados que figuran dados de alta.
 * \param int Cantidad de empleados dados de alta en el array.
 * \return float Promedio de salarios.
 *
 */
float calculateAverageSalary(float,int);


/** \brief Funcion que cuenta la cantidad de empleados que tiene salario superior al promedio.
 *
 * \param [] Employee Array de Employee a recorrer.
 * \param int Longitud del array.
 * \param float Salario promedio a comparar con el de los empleados.
 * \return int Cantidad de empleados con salario superior al promedio.
 *
 */
int countEmployeesHigherSalaryAverage(Employee [],int,float);

/** \brief Funcion que muestra total de salarios,promedio de los mismos y cuantos empleados superan ese promedio.
 *
 * \param [] Employee Array de Employee que reciben otras funciones para poder operar.
 * \param int Longitud del array de Employee.
 * \return int Retorna 1 si pudo mostrar el informe con los datos obtenidos.
 *
 */
int showInformationEmployees(Employee [],int);

/** \brief Funcion que permite modificar datos de un empleado recibido por parametro.
 *
 * \param Employee Employee a modificar.
 * \return Employee Empleado modificado.
 *
 */
Employee modifyAttributeEmployee(Employee);

/** \brief Funcion que busca por id un empleado y si existe permite modificarlo.
 *
 * \param [] Employee Array de Employee a recorrer.
 * \param int Longitud del array de Employee.
 * \param int Id del empleado a modificar.
 * \return int Retorna 1 si pudo hacer la modificacion.
 *
 */
int modifyAEmployee(Employee [],int,int);

/** \brief Funcion que permite chequear si el array de Employee tiene al menos un empleado dado de alta.(necesaria para los puntos 2,3,4).
 *
 * \param [] Employee Array a recorrer.
 * \param int Longitud del array.
 * \return int Retorna 1 si encontro al menos un empleado dado de alta o 0 si no hay empleados dados de alta.
 *
 */
int checkListEmployeesIsEmpty(Employee [],int);
