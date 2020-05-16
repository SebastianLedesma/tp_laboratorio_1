#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Input.h"
#define LIBRE 1
#define OCUPADO 0

int initEmployees(Employee listEmployees[], int len)
{
    int i;
    int retorno;

    retorno = -1;
    if(len > 0)
    {
        for(i=0 ; i < len; i++)
        {
            listEmployees[i].isEmpty = LIBRE;
        }
        retorno = 0;
    }

    return retorno;
}


int printEmployees(Employee listEmployees[], int length)
{
    int i;
    int retorno;

    retorno = -1;
    if(length > 0)
    {
        retorno = 0;

        printf("ID  NAME\t LAST NAME\tSALARY\tSECTOR\n");
        for(i=0; i < length; i++)
        {
            if(listEmployees[i].isEmpty != LIBRE)
            {
                printAEmployee(listEmployees[i]);
            }
        }
    }

    return retorno;
}

int findEmployeeById(Employee listEmployee[], int len,int id)
{
    int retorno;
    int i;

    retorno = -1;

    if(len > 0 && id > 0)
    {
        for(i=0; i < len; i++)
        {
            if(listEmployee[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}


int findFreeIndexEmployee(Employee listEmployee[],int lenghtEmployee)
{
    int i;
    int retorno;

    retorno = -1;

    if(lenghtEmployee > 0)
    {
        for(i=0; i<lenghtEmployee; i++)
        {
            if(listEmployee[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}


int addEmployee(Employee listEmployees[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    Employee auxEmployee;
    char respuesta;
    int retorno;
    int indice;

    indice = findFreeIndexEmployee(listEmployees,len);

    if(len > 0 && salary > 0 && sector > 0 && id >= 0 && strcmp(name,"-") != 0 && strcmp(lastName,"-") != 0)
    {
        auxEmployee.id = id;
        strcpy(auxEmployee.name,name);
        strcpy(auxEmployee.lastName,lastName);
        auxEmployee.salary=salary;
        auxEmployee.sector=sector;
        auxEmployee.isEmpty = OCUPADO;

        printAEmployee(auxEmployee);
        respuesta = getChar("Desea dar de alta esta persona?(s/n)");

        if(respuesta == 's')
        {
            listEmployees[indice] = auxEmployee;
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }

    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


int createEmployee(Employee listEmployee[],int lengthEmployee,int idEmployee)
{

    char name[25];
    char lastName[25];
    float salary;
    int sector;
    int retorno;
    int altaEmployee;
    int indice;

    retorno = -1;

    indice = findFreeIndexEmployee(listEmployee,lengthEmployee);

    if(indice != -1)
    {
        getName("Ingrese un nombre:","Cadena invalida.\n",name);
        getName("Ingrese un apellido:","Cadena invalida.\n",lastName);
        salary = getFloat("Ingrese el salario:","Nro invalido.\n",0);
        sector = getInt("Ingrese nro de sector(entre 0 y 20):","Opcion invalida.\n",1,20);
        idEmployee++;


        altaEmployee = addEmployee(listEmployee,lengthEmployee,idEmployee,name,lastName,salary,sector);

        if(altaEmployee == 1)
        {
            retorno = 1;
        }

    }

    return retorno;
}


void printAEmployee(Employee employee)
{
    printf("%d %8s %10s %12.2f %8d\n",employee.id,
                                    employee.name,
                                    employee.lastName,
                                    employee.salary,
                                    employee.sector);
}


int removeEmployee(Employee listEmployee[], int len, int id)
{
    int indice;
    int retorno;
    char respuesta;

    retorno = -1;
    indice = findEmployeeById(listEmployee,len,id);

    if(indice != -1)
    {
        printAEmployee(listEmployee[indice]);
        respuesta = getChar("Desea eliminar este empleado?(s/n)");

        if(respuesta == 's')
        {
            listEmployee[indice].isEmpty = LIBRE;
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}


int sortEmployees(Employee listEmployee[], int len, int order)
{
    int i;
    int j;
    Employee auxEmployee;

    if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName)>0 && listEmployee[j].isEmpty != LIBRE)
                {
                    auxEmployee = listEmployee[i];
                    listEmployee[i] = listEmployee[j];
                    listEmployee[j] = auxEmployee;
                }
                else if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName) == 0  && listEmployee[i].sector > listEmployee[j].sector && listEmployee[j].isEmpty != LIBRE)
                {
                    auxEmployee = listEmployee[i];
                    listEmployee[i] = listEmployee[j];
                    listEmployee[j] = auxEmployee;
                }
            }
        }
    }
    else
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName) < 0 && listEmployee[j].isEmpty != LIBRE)
                {
                    auxEmployee = listEmployee[i];
                    listEmployee[i] = listEmployee[j];
                    listEmployee[j] = auxEmployee;
                }
                else if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName)== 0 && listEmployee[i].sector < listEmployee[j].sector && listEmployee[j].isEmpty != LIBRE)
                {
                    auxEmployee = listEmployee[i];
                    listEmployee[i] = listEmployee[j];
                    listEmployee[j] = auxEmployee;
                }
            }
        }
    }

    printEmployees(listEmployee,len);

    return 0;
}


float countSalaryEmployees(Employee listEmployee[],int len)
{
    int i;
    float acumuladorSalario;

    acumuladorSalario=0;

    if(len > 0 )
    {
        for(i=0; i < len ; i++)
        {
            if(listEmployee[i].isEmpty != LIBRE)
            {
                acumuladorSalario+= listEmployee[i].salary;
            }
        }
    }


    return acumuladorSalario;
}


int countEmployeeList(Employee listEmployee[],int len)
{
    int i;
    int contador;

    contador = 0;

    if(len > 0)
    {
        for(i=0; i< len; i++)
        {
            if(listEmployee[i].isEmpty != LIBRE)
            {
                contador++;
            }
        }
    }

    return contador;
}


float calculateAverageSalary(float salarioAcumulado,int contadorEmpleados)
{
    float retorno;

    retorno = 0;
    if(salarioAcumulado > 0 && contadorEmpleados > 0)
    {
        retorno = salarioAcumulado / contadorEmpleados;
    }

    return retorno;
}


int countEmployeesHigherSalaryAverage(Employee listEmployee[],int len,float salarioPromedio)
{
    int i;
    int contadorEmpleados;

    contadorEmpleados=0;

    if(len > 0 && salarioPromedio > 0)
    {
        for(i=0; i< len ; i++)
        {
            if(listEmployee[i].salary > salarioPromedio && listEmployee[i].isEmpty != LIBRE)
            {
                contadorEmpleados++;
            }
        }
    }

    return contadorEmpleados;
}


int showInformationEmployees(Employee listEmployee[],int len)
{
    int contadorEmpleados;
    int cantidadEmpleadosSalarioMayor;
    float acumuladorSalario;
    float salarioPromedio;
    int retorno;

    retorno = 0;

    if(len > 0)
    {
        acumuladorSalario = countSalaryEmployees(listEmployee,len);
        contadorEmpleados = countEmployeeList(listEmployee,len);
        salarioPromedio = calculateAverageSalary(acumuladorSalario,contadorEmpleados);
        cantidadEmpleadosSalarioMayor = countEmployeesHigherSalaryAverage(listEmployee,len,salarioPromedio);

        retorno = 1;

        printf("Total de salario:%.2f\n",acumuladorSalario);
        printf("Promedio de salarios:%.2f\n",salarioPromedio);
        printf("Empleados con salario mayor al promedio:%d\n",cantidadEmpleadosSalarioMayor);
    }

    return retorno;
}


Employee modifyAttributeEmployee(Employee paramEmployee){
    char nombre[25];
    char apellido[25];
    float salario;
    int sector;
    int opcion;
    char respuesta;
    Employee auxEmployee;

    auxEmployee = paramEmployee;

    do{
        showMenu("1.MODIFICAR NOMBRE\n"
                 "2.MODIFICAR APELLIDO\n"
                 "3.MODIFICAR SALARIO\n"
                 "4.MODIFICAR SECTOR\n"
                 "5.SALIR\n");
        opcion = getInt("Elija una opcion:","Opcion incorrecta.\n",1,5);

        switch(opcion){
        case 1:
            getName("Ingrese nuevo nombre:","Cadena incorrecta.\n",nombre);
            strcpy(auxEmployee.name,nombre);
            break;
        case 2:
            getName("Ingrese nuevo apellido:","Cadena incorrecta.\n",apellido);
            strcpy(auxEmployee.lastName,apellido);
            break;
        case 3:
            salario = getFloat("Ingrese nuevo salario:","Nro invalido",1);
            auxEmployee.salary=salario;
            break;
        case 4:
            sector = getInt("Ingrese nuevo sector:","Sector incorrecto.\n",1,5);
            auxEmployee.sector = sector;
            break;
        case 5:
            break;
        }

        respuesta = getChar("Desea continuar modificando?(s/n)");

    }while(respuesta == 's');

    return auxEmployee;
}


int modifyAEmployee(Employee listEmployee[],int len,int id){
    int indice;
    int retorno;
    char respuesta;
    Employee auxEmployee;

    retorno = -1;
    indice = findEmployeeById(listEmployee,len,id);

    if(indice != -1){
        printAEmployee(listEmployee[indice]);
        auxEmployee = modifyAttributeEmployee(listEmployee[indice]);

        printAEmployee(auxEmployee);

        respuesta = getChar("Confirma los cambios del empleado?(s/n)");

        if(respuesta == 's'){
            listEmployee[indice]=auxEmployee;
            retorno = 1;
        }else{
            retorno = 0;
        }
    }

    return retorno;

}

int checkListEmployeesIsEmpty(Employee listEmployee[],int len){
    int i;
    int retorno;

    retorno = 0;
    for(i=0; i < len;i++){
        if(listEmployee[i].isEmpty == OCUPADO){
            retorno = 1;
            break;
        }
    }

    return retorno;
}
