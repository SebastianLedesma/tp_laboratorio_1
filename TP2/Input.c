#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

int getInt(char mensaje[],char mensajeError[],int desde,int hasta)
{
    int retorno;
    int esValido;

    do
    {
        printf("%s",mensaje);
        if(scanf("%d",&retorno) != 1 || retorno < desde || retorno > hasta)
        {
            fflush(stdin);
            printf("%s",mensajeError);
            esValido=0;
        }
        else
        {
            esValido=1;
        }
    }
    while(esValido == 0);

    return retorno;
}


void getName(char mensaje[],char mensajeError[],char paramNombre[])
{
    char nombre[25];
    int validacion;
    char respuesta;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(nombre);

        validacion = validarNombre(nombre);

        if(validacion == -1)
        {
            printf("%s",mensajeError);
        }

        printf("Desea volver a ingresar el nombre?(s/n)");
        fflush(stdin);
        scanf("%c",&respuesta);
    }
    while(respuesta == 's');

    if(validacion == -1)
    {
        strcpy(paramNombre,"-");
    }
    else
    {
        strcpy(paramNombre,nombre);
    }

}

int validarNombre(char paramNombre[])
{
    int retorno;
    int i;

    retorno = 1;

    for(i=0; i < strlen(paramNombre); i++)
    {
        if(!((paramNombre[i] >= 65 && paramNombre[i] <= 90) || (paramNombre[i] >=97 && paramNombre[i] <= 122) || paramNombre[i] == ' '))
        {
            retorno = -1;
            break;
        }
    }

    return retorno;
}


float getFloat(char mensaje[],char mensajeError[],int desde)
{
    float retorno;
    int esValido;

    do
    {
        printf("%s",mensaje);
        if(scanf("%f",&retorno) != 1 || retorno <= desde)
        {
            fflush(stdin);
            printf("%s",mensajeError);
            esValido=0;
        }
        else
        {
            esValido=1;
        }
    }
    while(esValido == 0);

    return retorno;
}


char getChar(char mensaje[]){
    char retorno;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&retorno);

    return retorno;
}


void showMenu(char mensaje[]){
    printf("%s",mensaje);
}

void cleanScreen(void){
    system("pause");
    system("cls");
}
