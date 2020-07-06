#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Company.h"
#include "parser.h"

int parser_CompanyFromText(FILE* pFile, LinkedList* pArrayListCompany)
{

    Company* pAuxEmpresa;
    char id[10];
    char nombre[128];
    char anio[10];
    char empleados[10];
    int retorno=-1;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,anio,empleados);
    if(pFile != NULL){
        while(!feof(pFile)){
            if(feof(pFile)){
                break;
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,anio,empleados);
            pAuxEmpresa = company_newParametros(id,nombre,anio,empleados);
            if(pAuxEmpresa != NULL){
                ll_add(pArrayListCompany,pAuxEmpresa);
            }
        }
        fclose(pFile);
        retorno=0;
    }

    return retorno;
}

int parser_CompanyFromBinary(FILE* pFile, LinkedList* pArrayListCompany)
{
    Company* pEmpresa=NULL;
    int retorno=-1;

    if(pFile != NULL){

        do{
            pEmpresa=company_new();
            if(pEmpresa != NULL){
                if(fread(pEmpresa,sizeof(Company),1,pFile)==1){
                    ll_add(pArrayListCompany,pEmpresa);
                }

            }
        }while(feof(pFile)==0);
        retorno = 0;
        fclose(pFile);

    }
    return retorno;
}
