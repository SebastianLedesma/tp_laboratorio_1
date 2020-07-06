#include <stdlib.h>
#include "Company.h"
#include <string.h>

#define NOMBRE_LEN 128

Company* company_new()
{
    Company* pEmpresa=(Company*) malloc(sizeof(Company));
    return pEmpresa;
}


Company* company_newParametros(char* idStr,char* nombreStr,char* anioStr,char* empleadosStr)
{
    Company* pEmpresa= NULL;
    pEmpresa= company_new();


    if(pEmpresa != NULL &&
                            company_setIdText(pEmpresa,idStr) ==0  &&
                            company_setNombre(pEmpresa,nombreStr) == 0 &&
                            company_setAnioText(pEmpresa,anioStr)==0 &&
                            company_setEmpleadosText(pEmpresa,empleadosStr)==0){
         return pEmpresa;
    }else{
        return NULL;
    }

}


Company* company_newParametrosNumerico(int id,char* nombreStr,int anio,int empleados)
{
    Company* pEmpresa= NULL;
    pEmpresa= company_new();


    if(pEmpresa != NULL &&
                            company_setId(pEmpresa,id) ==0  &&
                            company_setNombre(pEmpresa,nombreStr) == 0 &&
                            company_setAnio(pEmpresa,anio)==0 &&
                            company_setEmpleados(pEmpresa,empleados)==0){
         return pEmpresa;
    }else{
        return NULL;
    }

}


void company_delete(Company* pEmpresa){
    if(pEmpresa != NULL){
        free(pEmpresa);
    }
}


int company_setNombre(Company* this,char* nombre)
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

int company_getNombre(Company* this,char* nombre)
{
    int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}



int company_setEmpleados(Company* this,int empleados)
{
    int retorno=-1;

	if(this!= NULL && empleados >= 0){
		this->empleados=empleados;
		retorno = 0;
	}
	return retorno;
}


int company_getEmpleados(Company* this,int* empleados)
{
    int retorno=-1;

	if(this!= NULL && empleados != NULL){
		*empleados =this->empleados;
		retorno = 0;
	}
	return retorno;
}


int company_setEmpleadosText(Company* this,char* empleados){
    int retorno=-1;
	if(this!= NULL && empleados != NULL){
		if(esNumerica(empleados,10)==1){
			this->empleados=atoi(empleados);
			retorno = 0;
		}
	}
	return retorno;

}


int company_getEmpleadosText(Company* this){
    int retorno=-1;
    char empleados[10];

	if(this!= NULL){
		retorno = 0;
		sprintf(empleados,"%d",this->empleados);
	}
	return retorno;
}

int company_setId(Company* this,int id)
{
    int retorno=-1;

	if(this!= NULL && id >= 0){
		this->id=id;
		retorno = 0;
	}
	return retorno;
}


int company_getId(Company* this,int* id)
{
    int retorno=-1;

	if(this!= NULL && id != NULL){
		*id=this->id;
		retorno = 0;
	}
	return retorno;
}


int company_getIdText(Company* this){
	int retorno=-1;
	char id[10];

	if(this!= NULL){
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}


int company_setIdText(Company* this,char* id){
	int retorno=-1;

	if(this!= NULL && id != NULL){
		if(esNumerica(id,10)==1){
			this->id=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}




int company_setAnio(Company* this,int anio)
{
    int retorno=-1;
	if(this!= NULL && anio >= 0){
		this->anio=anio;
		retorno = 0;
	}
	return retorno;
}


int company_getAnio(Company* this,int* anio)
{
    int retorno=-1;
	if(this!= NULL && anio != NULL){
		*anio = this->anio;
		retorno =0;
	}
	return retorno;
}


int company_setAnioText(Company* this,char* anio){
    int retorno=-1;

	if(this!= NULL && anio != NULL){
		if(esNumerica(anio,10)==1){
			this->anio=atof(anio);
			retorno = 0;
		}
	}
	return retorno;
}



int company_getAnioText(Company* this){
    int retorno=-1;
    char anio[10];

	if(this!= NULL){
		retorno = 0;
		sprintf(anio,"%d",this->anio);
	}
	return retorno;
}




int company_CompareByName(Company* pCompany1, Company* pCompany2)
{
    int retorno;
    char nombre1[NOMBRE_LEN];
    char nombre2[NOMBRE_LEN];
    if(pCompany1 != NULL && pCompany2 != NULL){
        company_getNombre(pCompany1,nombre1);
        company_getNombre(pCompany2,nombre2);
        retorno = strcmp(nombre1,nombre2);
    }

    return retorno;
}

int company_CompareById(Company* pEmpresa1, Company* pEmpresa2)
{
    int retorno;
    int idPrimero;
    int idSegundo;

    if(pEmpresa1 != NULL && pEmpresa2 != NULL){
        company_getId(pEmpresa1,&idPrimero);
        company_getId(pEmpresa2,&idSegundo);
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

int company_CompareByNumberEmployees(Company* pEmpresa1, Company* pEmpresa2)
{
    int retorno;
    int empleadosPrimero;
    int empleadosSegundo;

    if(pEmpresa1 != NULL && pEmpresa2 != NULL){
        company_getEmpleados(pEmpresa1,&empleadosPrimero);
        company_getEmpleados(pEmpresa2,&empleadosSegundo);
        if(empleadosPrimero > empleadosSegundo){
            retorno=1;
        }else if(empleadosPrimero < empleadosSegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}


int company_CompareByYear(Company* pEmpresa1, Company* pEmpresa2)
{
    int retorno;
    int anioPrimero;
    int anioSegundo;

    if(pEmpresa1 != NULL && pEmpresa2 != NULL){
        company_getAnio(pEmpresa1,&anioPrimero);
        company_getAnio(pEmpresa2,&anioSegundo);
        if(anioPrimero > anioSegundo){
            retorno=1;
        }else if(anioPrimero < anioSegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}


int company_printEmpresa(Company* pEmpresa){
    int retorno=-1;
    int id;
    char nombre[128];
    int anio;
    int empleados;

    if(pEmpresa != NULL && company_getId(pEmpresa,&id)==0 && company_getNombre(pEmpresa,nombre)==0 && company_getAnio(pEmpresa,&anio)==0 && company_getEmpleados(pEmpresa,&empleados)==0){
        retorno=0;
        printf("%d  %10s %8d %10d\n",id,nombre,anio,empleados);
    }
    return retorno;
}

int loadNewCompany(int* nuevoId,char* nombre,int* anio,int* empleados,LinkedList* pArrayListCompany){
    int retorno=-1;

    if(pArrayListCompany != NULL &&
                utn_GetNombre(nombre,NOMBRE_LEN,"Ingrese un nombre:","Nombre invalido.\n",2) == 0 &&
                utn_GetNumero(anio,"Ingrese el anio de fundacion:","Valor incorrecto.\n",1,2021,2) == 0 &&
                utn_GetNumero(empleados,"Ingrese la cantidad de empleados:","Valor incorrecto.\n",1,200000,2) == 0 &&
                company_searchMaxIdCompany(pArrayListCompany,nuevoId) == 0){
        (*nuevoId)++;
        retorno =0;
    }

    return retorno;
}


int company_searchIdCompany(int* id,LinkedList* pArrayListCompany){
    int retorno=-1;
    Company* pEmpresa;
    int longitud;
    int idAux;
    int i;

    if(id != NULL && pArrayListCompany != NULL){
        longitud = ll_len(pArrayListCompany);

        for(i=0; i < longitud;i++){
            pEmpresa =(Company*) ll_get(pArrayListCompany,i);
            company_getId(pEmpresa,&idAux);
            if(pEmpresa != NULL && idAux == *id){
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int company_searchMaxIdCompany(LinkedList* pArrayListCompany,int* maxId){
    int retorno=-1;
    int longitud;
    int i;
    int id;
    Company* pEmpresa;


    if(pArrayListCompany != NULL && maxId != NULL){
        longitud = ll_len(pArrayListCompany);

        for(i=0; i< longitud;i++){
            pEmpresa =(Company*) ll_get(pArrayListCompany,i);
            company_getId(pEmpresa,&id);
            if(id > *maxId || i == 0){
                *maxId = id;
            }
        }

        retorno = 0;
    }

    return retorno;
}
