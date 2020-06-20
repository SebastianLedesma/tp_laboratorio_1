#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"


int main()
{
    LinkedList* listaEmpleados=ll_newLinkedList();
    char archivoBinario[]={"data.bin"};
    char archivoTexto[]={"data.csv"};
    int opcion;
    int retorno;
    int flagGuardadoTexto=1;
    int flagGuardadoBinario=1;


    do{
        utn_GetNumero(&opcion,"Menu:\n"
                        "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
                        "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
                        "3. Alta de empleado\n"
                        "4. Modificar datos de empleado\n"
                        "5. Baja de empleado\n"
                        "6. Listar empleados\n"
                        "7. Ordenar empleados\n"
                        "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
                        "9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n"
                        "10. Salir\n"
                        "Elija una opcion:"
                        ,"Opcion invalida.\n",1,10,2);

                        switch(opcion){
                        case 1:
                            retorno = controller_loadFromText(archivoTexto,listaEmpleados);
                            if(retorno == 0){
                                printf("Datos guardados correctamente.\n");
                                flagGuardadoTexto=1;
                            }else if(retorno == 1){
                                printf("Ya trajo los datos del archivo anteriormente.\n");
                            }else{
                                printf("No se pudo traer los datos del archivo.\n");
                            }
                            break;
                        case 2:
                            retorno = controller_loadFromBinary(archivoBinario,listaEmpleados);
                            if(retorno == 0){
                                printf("Datos guardados correctamente.\n");
                                flagGuardadoBinario=1;
                            }else if(retorno == 1){
                                printf("Ya trajo los datos del archivo anteriomente.\n");
                            }else{
                                printf("No se pudo traer los datos del archivo.\n");
                            }
                            break;
                        case 3:
                            retorno = controller_addEmployee(listaEmpleados);
                            if(retorno == 0){
                                printf("Empleado guardado correctamente.\n");
                                flagGuardadoTexto=0;
                                flagGuardadoBinario=0;
                            }else if(retorno == 1){
                                printf("Debe traer los datos a memoria para operar.\n");
                            }else{
                                printf("No se pudo hacer el alta de empleado .\n");
                            }
                            break;
                        case 4:
                            retorno = controller_editEmployee(listaEmpleados);
                            if(retorno == 0){
                                printf("Empleado modificado correctamente.\n");
                                flagGuardadoTexto=0;
                                flagGuardadoBinario=0;
                            }else if(retorno == -1){
                                printf("No se puede hacer la operacion.\n");
                            }else{
                                printf("No se hizo la modificacion de empleado .\n");
                            }
                            break;
                        case 5:
                            retorno = controller_removeEmployee(listaEmpleados);
                            if(retorno == 0){
                                printf("Empleado eliminado correctamente.\n");
                                flagGuardadoTexto=0;
                                flagGuardadoBinario=0;
                            }else if(retorno == -1){
                                printf("No se puede hacer la operacion.\n");
                            }else{
                                printf("No se elimnino el empleado .\n");
                            }
                            break;
                        case 6:
                            if(controller_ListEmployee(listaEmpleados)!= 0){
                                printf("La lista esta vacia.\n");
                            }
                            break;
                        case 7:
                            retorno = controller_sortEmployee(listaEmpleados);
                            if(retorno == 0){
                                printf("Se hizo el ordenamiento.\n");
                                flagGuardadoBinario=0;
                                flagGuardadoTexto=0;
                            }else if(retorno == 1){
                                printf("No se hicieron cambios.\n");
                            }else{
                                printf("No se pudo hacer el ordenamiento.\n");
                            }
                            break;
                        case 8:
                            if(flagGuardadoTexto == 0){
                                controller_saveAsText(archivoTexto,listaEmpleados);
                                printf("Datos guardados en archivo de texto.\n");
                            }else{
                                printf("No hay cambios para guardar.\n");
                            }
                            break;
                        case 9:
                            if(flagGuardadoBinario == 0){
                                controller_saveAsBinary(archivoBinario,listaEmpleados);
                                printf("Datos guardados en archivo de binario.\n");
                            }else{
                                printf("No hay cambios para guardar.\n");
                            }
                            break;
                        case 10:
                            if(flagGuardadoBinario == 0 || flagGuardadoTexto == 0){
                                controller_saveAsText(archivoTexto,listaEmpleados);
                                controller_saveAsBinary(archivoBinario,listaEmpleados);
                            }
                            ll_clear(listaEmpleados);
                            ll_deleteLinkedList(listaEmpleados);
                            break;
                        default:
                            cleanScreen();
                            continue;
                        }
                        cleanScreen();
    }while(opcion != 10);

    return 0;
}
