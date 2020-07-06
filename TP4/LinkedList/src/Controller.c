#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"

#define NOMBRE_LEN 128

int controller_loadFromText(char* path, LinkedList* pArrayListCompany)
{
    int retorno=-1;
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"r");

    if(pArchivoTexto == NULL)
    {
        retorno=-1;
    }else if(ll_isEmpty(pArrayListCompany) == 0){
        retorno=1;
    }else{
        parser_CompanyFromText(pArchivoTexto,pArrayListCompany);
        retorno=0;
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListCompany)
{
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"rb");
    int retorno;
    if(pArchivoTexto == NULL)
    {
        retorno=-1;
    }else if(ll_isEmpty(pArrayListCompany) == 0){
        retorno=1;
    }else{
        parser_CompanyFromBinary(pArchivoTexto,pArrayListCompany);
        retorno=0;
    }
    return retorno;
}


int controller_addCompany(LinkedList* pArrayListCompany)
{
    char nombre[NOMBRE_LEN];
    int anio;
    int empleados;
    int nuevoId;
    Company* pEmpresa;
    int retorno=-1;
    char respuesta;

    if(pArrayListCompany != NULL){
        if(ll_isEmpty(pArrayListCompany) == 0){
            if(loadNewCompany(&nuevoId,nombre,&anio,&empleados,pArrayListCompany) == 0){
                pEmpresa = company_newParametrosNumerico(nuevoId,nombre,anio,empleados);
                if(pEmpresa != NULL){
                    company_printEmpresa(pEmpresa);
                    if(utn_GetRespuesta(&respuesta,"Desea dar de alta esta empresa?(s/n)","Incorrecto.\n",2)== 0 && (respuesta == 's' || respuesta=='S')){
                        ll_push(pArrayListCompany,ll_len(pArrayListCompany),pEmpresa);
                        retorno=0;
                    }

                }
            }
        }else{
            retorno = 1;
        }
    }

    return retorno;
}


int controller_editCompany(LinkedList* pArrayListCompany)
{
    int idElegido;
    int indiceId;
    Company* pEmpresa;
    char respuesta;
    int opcion;
    char nombre[NOMBRE_LEN];
    int anio;
    int empleados;
    char nombreNuevo[NOMBRE_LEN];
    int anioNuevo;
    int empleadosNuevo;
    int retorno=-1;

    if(pArrayListCompany != NULL && ll_isEmpty(pArrayListCompany) == 0)
    {
        controller_ListCompany(pArrayListCompany);
        if(utn_GetNumero(&idElegido,"Ingrese ID de la empresa a modificar:","Valor incorrecto.\n",1,2000,2)==0)
        {
            indiceId = company_searchIdCompany(&idElegido,pArrayListCompany);

            if(indiceId != -1){
                pEmpresa =(Company*) ll_get(pArrayListCompany,indiceId);
                company_printEmpresa(pEmpresa);

                if(utn_GetRespuesta(&respuesta,"Desea modificar esta empresa?(s/n)","Incorrecto.\n",2)== 0 && (respuesta == 's' || respuesta=='S'))
                {
                    company_getNombre(pEmpresa,nombre);
                    company_getAnio(pEmpresa,&anio);
                    company_getEmpleados(pEmpresa,&empleados);
                    do
                    {
                        if(utn_GetNumero(&opcion,"1.Nombre\n2.Anio de fundacion\n3.Cant de empleados\n4.Salir\nElija una opcion:","Opcion ncorrecta.\n",1,4,2)==0)
                        {
                            switch(opcion)
                            {
                            case 1:
                                if(utn_GetNombre(nombreNuevo,NOMBRE_LEN,"Ingrese nuevo nombre:","Valor incorrecto.\n",2) == 0)
                                {
                                    company_setNombre(pEmpresa,nombreNuevo);
                                }
                                break;
                            case 2:
                                if(utn_GetNumero(&anioNuevo,"Ingrese nuevo anio:","Valor incorrecto.\n",1,2021,2) == 0)
                                {
                                    company_setAnio(pEmpresa,anioNuevo);
                                }
                                break;
                            case 3:
                                if(utn_GetNumero(&empleadosNuevo,"Ingrese nuevo cant de empleados:","Valor incorrecto.\n",1,200000,2) == 0)
                                {
                                    company_setEmpleados(pEmpresa,empleadosNuevo);
                                }
                                break;
                            }
                        }
                    }
                    while(opcion != 4);

                    company_printEmpresa(pEmpresa);
                    if(utn_GetRespuesta(&respuesta,"Confirma la modificacion?(s/n)","Respuesta incorrecta",2)== 0 && (respuesta == 's' || respuesta== 'S'))
                    {
                        ll_set(pArrayListCompany,indiceId,pEmpresa);
                        retorno=0;
                    }
                    else
                    {
                        company_setNombre(pEmpresa,nombre);
                        company_setAnio(pEmpresa,anio);
                        company_setEmpleados(pEmpresa,empleados);
                        retorno=1;
                    }
                }else{
                    retorno = 1;
                }
            }
        }

    }
    return retorno;
}

int controller_removeCompany(LinkedList* pArrayListCompany)
{
    int idElegido;
    int indiceId;
    Company* pEmpresa;
    char respuesta;
    int retorno=-1;

    if(pArrayListCompany != NULL && ll_isEmpty(pArrayListCompany) == 0)
    {
        controller_ListCompany(pArrayListCompany);
        if(utn_GetNumero(&idElegido,"Ingrese ID de la empresa a borrar:","Valor incorrecto.\n",1,2000,2)==0)
        {
            indiceId = company_searchIdCompany(&idElegido,pArrayListCompany);

            if(indiceId != -1){
               pEmpresa =(Company*) ll_get(pArrayListCompany,indiceId);
                company_printEmpresa(pEmpresa);

                if(utn_GetRespuesta(&respuesta,"Desea eliminar esta empresa?(s/n)","Incorrecto.\n",2)== 0 && (respuesta=='s' || respuesta == 'S'))
                {
                    ll_pop(pArrayListCompany,indiceId);
                    company_delete(pEmpresa);
                    retorno=0;
                }
                else
                {
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}


int controller_ListCompany(LinkedList* pArrayListCompany)
{
    Company* pEmpresa;
    int longitud;
    int i;
    int retorno=-1;

    if(pArrayListCompany != NULL && ll_isEmpty(pArrayListCompany) == 0)
    {
        printf("ID     NOMBRE     FUNDADA   EMPLEADOS\n");
        longitud = ll_len(pArrayListCompany);
        for(i=0; i < longitud; i++)
        {
            if(i % 100 == 0)
            {
                system("pause");
            }
            pEmpresa =(Company*) ll_get(pArrayListCompany,i);
            company_printEmpresa(pEmpresa);
        }
        printf("Cantidad de empresas:%d\n",longitud);
        retorno=0;
    }

    return retorno;
}


int controller_sortCompany(LinkedList* pArrayListCompany)
{
    int retorno=-1;
    int opcion;
    int orden;

    if(pArrayListCompany != NULL && ll_isEmpty(pArrayListCompany) == 0){
        if(utn_GetNumero(&opcion,
                         "Elija un criterio:\n"
                         "1.Id\n"
                         "2.Nombre\n"
                         "3.Anio de funcacion\n"
                         "4.Cant de empleados\nOpcion:","Incorrecto.\n",1,4,2)==0 &&
                            utn_GetNumero(&orden,"Elija orden:\n0.Descendente\n1.Ascendente\n2.Salir\nOpcion:","Incorrecto.\n",0,2,2)==0 && orden != 2){

            switch(opcion){
                case 1:
                    ll_sort(pArrayListCompany,company_CompareById,orden);
                    break;
                case 2:
                    ll_sort(pArrayListCompany,company_CompareByName,orden);
                    break;
                case 3:
                    ll_sort(pArrayListCompany,company_CompareByYear,orden);
                    break;
                case 4:
                    ll_sort(pArrayListCompany,company_CompareByNumberEmployees,orden);
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


int controller_saveAsText(char* path, LinkedList* pArrayListCompany)
{
    int longitud;
    int i;
    int id;
    char nombre[NOMBRE_LEN];
    int anio;
    int empleados;
    int retorno=-1;
    FILE* pFile;
    Company* pEmpresa;

    longitud = ll_len(pArrayListCompany);
    pFile= fopen(path,"w");

    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,anio,empleados\n");
        for(i=0; i< longitud; i++)
        {
            pEmpresa =(Company*) ll_get(pArrayListCompany,i);
            company_getId(pEmpresa,&id);
            company_getNombre(pEmpresa,nombre);
            company_getAnio(pEmpresa,&anio);
            company_getEmpleados(pEmpresa,&empleados);
            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,anio,empleados);
        }
        retorno=0;
    }

    fclose(pFile);

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListCompany)
{
    int longitud;
    FILE* pFile;
    int i;
    Company* pEmpresa;
    int retorno=-1;

    longitud = ll_len(pArrayListCompany);
    pFile= fopen(path,"wb");

    if(pFile != NULL)
    {
        for(i=0; i < longitud; i++)
        {
            pEmpresa =(Company*) ll_get(pArrayListCompany,i);
            fwrite(pEmpresa,sizeof(Company),1,pFile);
        }
        retorno=0;
    }

    fclose(pFile);

    return retorno;
}


int controller_saveAll(char* path,char* pathBinary ,LinkedList* pArrayListCompany, LinkedList* pCopyArrayList,int editado){
    int retorno=-1;

    if(path != NULL && pathBinary != NULL && pArrayListCompany != NULL && pCopyArrayList != NULL){
        retorno = 0;

       if(ll_containsAll(pCopyArrayList,pArrayListCompany) != 1 || (ll_len(pArrayListCompany) != ll_len(pCopyArrayList)) || editado == 1){
        controller_saveAsText(path,pCopyArrayList);
        controller_saveAsBinary(pathBinary,pCopyArrayList);
        retorno=1;
        }
    }

    ll_clear(pArrayListCompany);
    ll_deleteLinkedList(pArrayListCompany);
    ll_clear(pCopyArrayList);
    ll_deleteLinkedList(pCopyArrayList);

    return retorno;
}
