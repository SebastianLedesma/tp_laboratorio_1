#include <stdlib.h>
#include "Employee.h"
#include <string.h>

#define NOMBRE_LEN 128

Employee* employee_new()
{
    Employee* pEmpleado=(Employee*) malloc(sizeof(Employee));
    return pEmpleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado= NULL;
    pEmpleado= employee_new();


    if(pEmpleado != NULL &&
                            employee_setIdText(pEmpleado,idStr) ==0  &&
                            employee_setNombre(pEmpleado,nombreStr) == 0 &&
                            employee_setHorasTrabajadasText(pEmpleado,horasTrabajadasStr)==0 &&
                            employee_setSueldoText(pEmpleado,sueldoStr)==0){
         return pEmpleado;
    }else{
        return NULL;
    }

}


Employee* employee_newParametrosNumerico(int id,char* nombreStr,int horasTrabajadas,int sueldo)
{
    Employee* pEmpleado= NULL;
    pEmpleado= employee_new();


    if(pEmpleado != NULL &&
                            employee_setId(pEmpleado,id) ==0  &&
                            employee_setNombre(pEmpleado,nombreStr) == 0 &&
                            employee_setHorasTrabajadas(pEmpleado,horasTrabajadas)==0 &&
                            employee_setSueldo(pEmpleado,sueldo)==0){
         return pEmpleado;
    }else{
        return NULL;
    }

}


void employee_delete(Employee* pEmpleado){
    if(pEmpleado != NULL){
        free(pEmpleado);
    }
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
	if(this != NULL && nombre != NULL){
		if(esNombre(nombre,NOMBRE_LEN)==1){
			strncpy(this->nombre,nombre,NOMBRE_LEN);
			retorno=0;
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

	if(this!= NULL && sueldo >= 0){
		this->sueldo=sueldo;
		retorno = 0;
	}
	return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;

	if(this!= NULL && sueldo != NULL){
		*sueldo =this->sueldo;
		retorno = 0;
	}
	return retorno;
}


int employee_setSueldoText(Employee* this,char* sueldo){
    int retorno=-1;
	if(this!= NULL && sueldo != NULL){
		if(esNumerica(sueldo,10)==1){
			this->sueldo=atoi(sueldo);
			retorno = 0;
		}
	}
	return retorno;

}


int employee_getSueldoText(Employee* this){
    int retorno=-1;
    char sueldo[10];

	if(this!= NULL){
		retorno = 0;
		sprintf(sueldo,"%d",this->sueldo);
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;

	if(this!= NULL && id >= 0){
		this->id=id;
		retorno = 0;
	}
	return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno=-1;

	if(this!= NULL && id != NULL){
		*id=this->id;
		retorno = 0;
	}
	return retorno;
}


int employee_getIdText(Employee* this){
	int retorno=-1;
	char id[10];

	if(this!= NULL){
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}


int employee_setIdText(Employee* this,char* id){
	int retorno=-1;

	if(this!= NULL && id != NULL){
		if(esNumerica(id,10)==1){
			this->id=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}




int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
	if(this!= NULL && horasTrabajadas >= 0){
		this->horasTrabajadas=horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajo)
{
    int retorno=-1;
	if(this!= NULL && horasTrabajo != NULL){
		*horasTrabajo = this->horasTrabajadas;
		retorno =0;
	}
	return retorno;
}


int employee_setHorasTrabajadasText(Employee* this,char* horasTrabajadas){
    int retorno=-1;

	if(this!= NULL && horasTrabajadas != NULL){
		if(esNumerica(horasTrabajadas,10)==1){
			this->horasTrabajadas=atof(horasTrabajadas);
			retorno = 0;
		}
	}
	return retorno;
}



int employee_getHorasTrabajadasText(Employee* this){
    int retorno=-1;
    char horasTrabajadas[10];

	if(this!= NULL){
		retorno = 0;
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
	}
	return retorno;
}




int employee_CompareByName(Employee* pEmpleado1, Employee* pEmpleado2)
{
    int retorno;
    char nombre1[NOMBRE_LEN];
    char nombre2[NOMBRE_LEN];
    if(pEmpleado1 != NULL && pEmpleado2 != NULL){
        employee_getNombre(pEmpleado1,nombre1);
        employee_getNombre(pEmpleado2,nombre2);
        retorno = strcmp(nombre1,nombre2);
    }

    return retorno;
}

int employee_CompareById(Employee* pEmpleado1, Employee* pEmpleado2)
{
    int retorno;
    int idPrimero;
    int idSegundo;

    if(pEmpleado1 != NULL && pEmpleado2 != NULL){
        employee_getId(pEmpleado1,&idPrimero);
        employee_getId(pEmpleado2,&idSegundo);
        if(idPrimero > idSegundo){
            retorno=1;
        }else if(idPrimero < idSegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}

int employee_CompareBySalary(Employee* pEmpleado1, Employee* pEmpleado2)
{
    int retorno;
    int salaryPrimero;
    int salarySegundo;

    if(pEmpleado1 != NULL && pEmpleado2 != NULL){
        employee_getSueldo(pEmpleado1,&salaryPrimero);
        employee_getSueldo(pEmpleado2,&salarySegundo);
        if(salaryPrimero > salarySegundo){
            retorno=1;
        }else if(salaryPrimero < salarySegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}


int employee_CompareByHours(Employee* pEmpleado1, Employee* pEmpleado2)
{
    int retorno;
    int horasPrimero;
    int horasSegundo;

    if(pEmpleado1 != NULL && pEmpleado2 != NULL){
        employee_getHorasTrabajadas(pEmpleado1,&horasPrimero);
        employee_getHorasTrabajadas(pEmpleado2,&horasSegundo);
        if(horasPrimero > horasSegundo){
            retorno=1;
        }else if(horasPrimero < horasSegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}


int employee_printEmpleado(Employee* pEmpleado){
    int retorno=-1;
    int id;
    char nombre[128];
    int horasTrabajo;
    int sueldo;

    if(pEmpleado != NULL && employee_getId(pEmpleado,&id)==0 && employee_getNombre(pEmpleado,nombre)==0 && employee_getHorasTrabajadas(pEmpleado,&horasTrabajo)==0 && employee_getSueldo(pEmpleado,&sueldo)==0){
        retorno=0;
        printf("%d    %s   %d    %d\n",id,nombre,horasTrabajo,sueldo);
    }
    return retorno;
}

int loadNewWEmployee(int* nuevoId,char* nombre,int* horasTrabajo,int* sueldo,LinkedList* pArrayListEmployee){
    int retorno=-1;

    if(pArrayListEmployee != NULL &&
                utn_GetNombre(nombre,NOMBRE_LEN,"Ingrese un nombre:","Nombre invalido.\n",2) == 0 &&
                utn_GetNumero(horasTrabajo,"Ingrese las horas trabajadas:","Valor incorrecto.\n",1,1000,2) == 0 &&
                utn_GetNumero(sueldo,"Ingrese el sueldo:","Valor incorrecto.\n",1,200000,2) == 0 &&
                employee_searchMaxIdEmployee(pArrayListEmployee,nuevoId) == 0){
        (*nuevoId)++;
        retorno =0;
    }

    return retorno;
}


int employee_searchIdEmployee(int* id,LinkedList* pArrayListEmployee){
    int retorno=-1;
    Employee* pEmpleado;
    int longitud;
    int idAux;
    int i;

    if(id != NULL && pArrayListEmployee != NULL){
        longitud = ll_len(pArrayListEmployee);

        for(i=0; i < longitud;i++){
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&idAux);
            if(pEmpleado != NULL && idAux == *id){
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int employee_searchMaxIdEmployee(LinkedList* pArrayListEmployee,int* maxId){
    int retorno=-1;
    int longitud;
    int i;
    int id;
    Employee* pEmpleado;


    if(pArrayListEmployee != NULL && maxId != NULL){
        longitud = ll_len(pArrayListEmployee);

        for(i=0; i< longitud;i++){
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&id);
            if(id > *maxId || i == 0){
                *maxId = id;
            }
        }

        retorno = 0;
    }

    return retorno;
}

