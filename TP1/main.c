#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    double numeroA;
    double numeroB;
    double suma;
    double resta;
    double producto;
    double division;
    double factorialA;
    double factorialB;
    int opcion;

    numeroA=0;
    numeroB=0;

    do
    {
        mostarMenuDeOperaciones(numeroA,numeroB);
        opcion=getInt("Elija una opcion:","\nOpcion incorrecta.\n",1,5);

        switch(opcion)
        {
        case 1:
            numeroA=getDouble("\nIngrese valor para A:");
            limpiarPantalla();
            break;
        case 2:
            numeroB=getDouble("\nIngrese valor para B:");
            limpiarPantalla();
            break;
        case 3:
            suma=sumar(numeroA,numeroB);
            resta=restar(numeroA,numeroB);
            producto=multiplicar(numeroA,numeroB);
            division=dividir(numeroA,numeroB);
            factorialA = calcularFactorial(numeroA);
            factorialB = calcularFactorial(numeroB);
            limpiarPantalla();
            break;
        case 4:
            printf("\nEl resultado de A+B es:%lf",suma);
            printf("\nEl resultado de A-B es:%lf",resta);
            mostrarResultadoDivision(division,numeroB);
            printf("\nEl resultado de A*B es:%lf",producto);

            if(factorialA != -1 && factorialB != -1)
            {
                printf("\nEl factorial de A es %lf y el factorial de B es %lf\n",factorialA,factorialB);
            }
            else
            {
                printf("\nNo se puede calcular factorial.Verifique los operandos.\n");
            }

            limpiarPantalla();
            break;
        case 5:
            break;
        }

    }
    while(opcion != 5);

    return 0;
}
