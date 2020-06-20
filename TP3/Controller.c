#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"

#define NOMBRE_LEN 128

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"r");

    if(pArchivoTexto == NULL)
    {
        retorno=-1;
    }else if(ll_isEmpty(pArrayListEmployee) == 0){
        retorno=1;
    }else{
        parser_EmployeeFromText(pArchivoTexto,pArrayListEmployee);
        retorno=0;
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"rb");
    int retorno;
    if(pArchivoTexto == NULL)
    {
        retorno=-1;
    }else if(ll_isEmpty(pArrayListEmployee) == 0){
        retorno=1;
    }else{
        parser_EmployeeFromBinary(pArchivoTexto,pArrayListEmployee);
        retorno=0;
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[NOMBRE_LEN];
    int horasTrabajo;
    int sueldo;
    int nuevoId;
    Employee* pEmpleado;
    int retorno;
    char respuesta;

    if(pArrayListEmployee == NULL){
        retorno=-1;
    }else if(ll_isEmpty(pArrayListEmployee)!= 0){
        retorno=1;
    }else if(loadNewWEmployee(&nuevoId,nombre,&horasTrabajo,&sueldo,pArrayListEmployee) == 0){
        pEmpleado = employee_newParametrosNumerico(nuevoId,nombre,horasTrabajo,sueldo);
        if(pEmpleado != NULL)
        {
            employee_printEmpleado(pEmpleado);
            if(utn_GetRespuesta(&respuesta,"Desea dar de alta este empleado?(s/n)","Incorrecto.\n",2)== 0 && (respuesta == 's' || respuesta=='S')){
                ll_add(pArrayListEmployee,pEmpleado);
                retorno=0;
            }

        }
    }else{
        retorno=-1;
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idElegido;
    int indiceId;
    Employee* pEmpleado;
    char respuesta;
    int opcion;
    char nombre[NOMBRE_LEN];
    int horas;
    int sueldo;
    char nombreNuevo[NOMBRE_LEN];
    int horasNuevo;
    int sueldoNuevo;
    int retorno=-1;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_GetNumero(&idElegido,"Ingrese ID del empleado a modificar:","Valor incorrecto.\n",1,2000,2)==0)
        {
            indiceId = employee_searchIdEmployee(&idElegido,pArrayListEmployee);
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,indiceId);
            employee_printEmpleado(pEmpleado);

            if(utn_GetRespuesta(&respuesta,"Desea modificar este empleado?(s/n)","Incorrecto.\n",2)== 0 && (respuesta == 's' || respuesta=='S'))
            {
                employee_getNombre(pEmpleado,nombre);
                employee_getHorasTrabajadas(pEmpleado,&horas);
                employee_getSueldo(pEmpleado,&sueldo);
                do
                {
                    if(utn_GetNumero(&opcion,"1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nElija una opcion:","Opcion ncorrecta.\n",1,4,2)==0)
                    {
                        switch(opcion)
                        {
                        case 1:
                            if(utn_GetNombre(nombreNuevo,NOMBRE_LEN,"Ingrese nuevo nombre:","Valor incorrecto.\n",2) == 0)
                            {
                                employee_setNombre(pEmpleado,nombreNuevo);
                            }
                            break;
                        case 2:
                            if(utn_GetNumero(&horasNuevo,"Ingrese horas trabajadas:","Valor incorrecto.\n",1,2000,2) == 0)
                            {
                                employee_setHorasTrabajadas(pEmpleado,horasNuevo);
                            }
                            break;
                        case 3:
                            if(utn_GetNumero(&sueldoNuevo,"Ingrese nuevo sueldo:","Valor incorrecto.\n",1,200000,2) == 0)
                            {
                                employee_setSueldo(pEmpleado,sueldoNuevo);
                            }
                            break;
                        }
                    }
                }
                while(opcion != 4);

                employee_printEmpleado(pEmpleado);
                if(utn_GetRespuesta(&respuesta,"Confirma la modificacion?(s/n)","Respuesta incorrecta",2)== 0 && (respuesta == 's' || respuesta== 'S'))
                {
                    ll_set(pArrayListEmployee,indiceId,pEmpleado);
                    retorno=0;
                }
                else
                {
                    employee_setNombre(pEmpleado,nombre);
                    employee_setHorasTrabajadas(pEmpleado,horas);
                    employee_setSueldo(pEmpleado,sueldo);
                    retorno=1;
                }
            }else{
                retorno = 1;
            }
        }

    }
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idElegido;
    int indiceId;
    Employee* pEmpleado;
    char respuesta;
    int retorno=-1;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_GetNumero(&idElegido,"Ingrese ID del empleado a borrar:","Valor incorrecto.\n",1,2000,2)==0)
        {
            indiceId = employee_searchIdEmployee(&idElegido,pArrayListEmployee);
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,indiceId);
            employee_printEmpleado(pEmpleado);

            if(utn_GetRespuesta(&respuesta,"Desea eliminar este empleado?(s/n)","Incorrecto.\n",2)== 0 && (respuesta=='s' || respuesta == 'S'))
            {
                ll_remove(pArrayListEmployee,indiceId);
                employee_delete(pEmpleado);
                retorno=0;
            }
            else
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int longitud;
    int i;
    int retorno=-1;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        longitud = ll_len(pArrayListEmployee);
        for(i=0; i < longitud; i++)
        {
            if(i % 100 == 0)
            {
                system("pause");
            }
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_printEmpleado(pEmpleado);
        }
        printf("Cantidad de empleados:%d\n",longitud);
        retorno=0;
    }

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    int orden;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0){
        if(utn_GetNumero(&opcion,
                         "Elija un criterio:\n"
                         "1.Id\n"
                         "2.Nombre\n"
                         "3.Horas trabajadas\n"
                         "4.Sueldo\nOpcion:","Incorrecto.\n",1,4,2)==0 &&
                            utn_GetNumero(&orden,"Elija orden:\n0.Descendente\n1.Ascendente\n2.Salir\nOpcion:","Incorrecto.\n",0,2,2)==0 && orden != 2){

            switch(opcion){
                case 1:
                    ll_sort(pArrayListEmployee,employee_CompareById,orden);
                    break;
                case 2:
                    ll_sort(pArrayListEmployee,employee_CompareByName,orden);
                    break;
                case 3:
                    ll_sort(pArrayListEmployee,employee_CompareByHours,orden);
                    break;
                case 4:
                    ll_sort(pArrayListEmployee,employee_CompareBySalary,orden);
                    break;
                default:
                    retorno=1;
                    break;
            }
            retorno=0;
        }

    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int longitud;
    int i;
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajo;
    int sueldo;
    int retorno=-1;
    FILE* pFile;
    Employee* pEmpleado;

    longitud = ll_len(pArrayListEmployee);
    pFile= fopen(path,"w");

    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajo,sueldo\n");
        for(i=0; i< longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&id);
            employee_getNombre(pEmpleado,nombre);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajo);
            employee_getSueldo(pEmpleado,&sueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajo,sueldo);
        }
        retorno=0;
    }

    fclose(pFile);

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int longitud;
    FILE* pFile;
    int i;
    Employee* pEmpleado;
    int retorno=-1;

    longitud = ll_len(pArrayListEmployee);
    pFile= fopen(path,"wb");

    if(pFile != NULL)
    {
        for(i=0; i < longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pFile);
        }
        retorno=0;
    }

    fclose(pFile);

    return retorno;
}

