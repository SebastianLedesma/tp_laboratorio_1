#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


double getDouble(char mensaje[])
{
    double numero;

    printf("%s",mensaje);
    scanf("%lf",&numero);

    return numero;
}


int getInt(char mensaje[],char mensajeError[],int desde,int hasta)
{
    int opcion;

    do
    {
        printf("%s",mensaje);
        scanf("%d",&opcion);

        if(opcion < desde || opcion > hasta)
        {
            printf("%s",mensajeError);
        }
    }
    while(opcion < desde || opcion > hasta);

    return opcion;
}


double sumar(double nro1,double nro2)
{
    double suma;
    suma= nro1 + nro2;

    return suma;

}


double restar(double nro1,double nro2)
{
    double resta;
    resta = nro1 - nro2;

    return resta;
}


double multiplicar(double nro1,double nro2)
{
    double producto;

    producto=nro1*nro2;

    return producto;
}


double dividir(double nro1,double nro2)
{
    double division;

    if(nro2 != 0)
    {
        division = nro1 / nro2;
    }
    else
    {
        division=0;
    }

    return division;

}


void mostarMenuDeOperaciones(double nro1,double nro2)
{
    printf("1.Ingresar 1er operando(A=%.4lf)",nro1);
    printf("\n2.Ingresar 2do operando(B=%.4lf)",nro2);
    printf("\n3.Calcular todas las operaciones:");
    printf("\n\ta)Calcular la suma(A+B)");
    printf("\n\tb)Calcular la resta(A-B)");
    printf("\n\tc)Calcular la division(A/B)");
    printf("\n\td)Calcular la multiplicacion(A*B)");
    printf("\n\te)Calcular factorial");
    printf("\n4.Informar resultados");
    printf("\n5.Salir\n");

}


void limpiarPantalla()
{
    system("pause");
    system("cls");
}


double calcularFactorial(double nro)
{
    int i;
    int esEntero;
    double factorial;

    factorial=1;
    esEntero=verificarNroEntero(nro);

    if(esEntero == 1 && nro > 0)
    {
        for(i=nro; i > 0; i--)
        {
            factorial*=i;
        }
    }
    else if(nro == 0)
    {
        factorial=1;
    }
    else
    {
        factorial=-1;
    }

    return factorial;
}


int verificarNroEntero(double nro)
{
    double resultado;
    int parteEntera;
    int respuesta;

    parteEntera = nro;

    resultado = nro - parteEntera;

    if(resultado == 0)
    {
        respuesta=1;
    }
    else
    {
        respuesta=0;
    }

    return respuesta;
}



void mostrarResultadoDivision(double resultado,double divisor)
{
    if(divisor != 0)
    {
        printf("\nEl resultado de A/B es:%lf",resultado);
    }
    else
    {
        printf("\nNo es posible dividir por cero.");
    }
}
