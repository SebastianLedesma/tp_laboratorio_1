#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"

#define TEMPLOYEES 1000
#define LIBRE 0

int main()
{
    Employee listEmployees[TEMPLOYEES];
    int opcion;
    int respuesta;
    int idBuscado;
    int idEmpleado;
    int respuestaListIsEmpty;

    idEmpleado = 0;
    initEmployees(listEmployees,TEMPLOYEES);

    do
    {
        showMenu("1.ALTA DE EMPLEADO\n"
                 "2.MODIFICAR EMPLEADO\n"
                 "3.BAJA DE EMPLEADO\n"
                 "4.INFORMAR\n"
                 "5.SALIR\n");
        opcion = getInt("Elija un opcion:","Opcion incorrecta.\n",1,5);

        switch(opcion)
        {
        case 1:
            respuesta = createEmployee(listEmployees,TEMPLOYEES,idEmpleado);
            if(respuesta == 1 )
            {
                printf("Alta de empleado exitosa.\n");
                idEmpleado++;
            }
            else if(respuesta == 0)
            {
                printf("Alta de empleado cancelada.\n");
            }
            else
            {
                printf("Alta de empleado cancelada.\n");
            }
            cleanScreen();
            break;
        case 2:
            respuestaListIsEmpty = checkListEmployeesIsEmpty(listEmployees,TEMPLOYEES);
            if(respuestaListIsEmpty != LIBRE)
            {
                printEmployees(listEmployees,TEMPLOYEES);
                idBuscado = getInt("Ingrese ID de empleado a modificar:","Nro invalido.\n",1,1000);
                respuesta = modifyAEmployee(listEmployees,TEMPLOYEES,idBuscado);
                if(respuesta == 1)
                {
                    printf("Modificacion del empleado exitosa.\n");
                }
                else if(respuesta == 0)
                {
                    printf("Modificacion del empleado cancelada.\n");
                }
                else
                {
                    printf("No se pudo realizar la modificacion.\n");
                }
            }
            else
            {
                printf("Debe tener al menos un empleado para operar.\n");
            }
            cleanScreen();
            break;
        case 3:
            respuestaListIsEmpty=checkListEmployeesIsEmpty(listEmployees,TEMPLOYEES);
            if(respuestaListIsEmpty != LIBRE)
            {
                printEmployees(listEmployees,TEMPLOYEES);
                idBuscado = getInt("Ingrese ID de empleado a eliminar:","Nro invalido.\n",1,1000);
                respuesta = removeEmployee(listEmployees,TEMPLOYEES,idBuscado);
                if(respuesta == 1)
                {
                    printf("Baja de empleado exitosa.\n");
                }
                else if(respuesta == 0)
                {
                    printf("Baja de empleado cancelada.\n");
                }
                else
                {
                    printf("No se pudo dar de baja el empleado.\n");
                }
            }
            else
            {
                printf("Debe tener al menos un empleado para operar.\n");
            }

            cleanScreen();
            break;
        case 4:
            respuestaListIsEmpty = checkListEmployeesIsEmpty(listEmployees,TEMPLOYEES);
            if(respuestaListIsEmpty != LIBRE)
            {
                showMenu("1.LISTADO DE EMPLEADOS ORDENADOS POR APELLIDO Y SECTOR\n"
                         "2.TOTAL Y PROMEDIO DE SALARIOS Y CUANTOS SUPERAN EL PROMEDIO\n"
                         "3.CANCELAR\n");
                opcion = getInt("Elija una opcion:","Opcion incorrecta.\n",1,3);

                if(opcion == 1)
                {
                    showMenu("1.ORDEN ASCENDENTE.\n"
                             "2.ORDEN DESCENDENTE\n"
                             "3.CANCELAR\n");
                    opcion = getInt("Elija una opcion:","Opcion invalida.\n",1,3);
                    if(opcion == 1 || opcion == 2)
                    {
                        sortEmployees(listEmployees,TEMPLOYEES,opcion);
                    }
                    else
                    {
                        printf("Cancelaste el informe.\n");
                    }

                }
                else if(opcion == 2)
                {
                    showInformationEmployees(listEmployees,TEMPLOYEES);
                }
                else
                {
                    printf("Cancelaste el informe.\n");
                }
            }
            else
            {
                printf("Debe tener al menos un empleado para operar.\n");
            }
            cleanScreen();

            break;
        case 5:
            break;
        }


    }
    while(opcion != 5);

    return 0;
}
