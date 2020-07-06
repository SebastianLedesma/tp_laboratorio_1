/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"


int main()
{
    LinkedList* listaEmpresas=ll_newLinkedList();
    LinkedList* copiaListaEmpresas=ll_newLinkedList();
    char archivoBinario[]={"data.bin"};
    char archivoTexto[]={"data.csv"};
    int opcion;
    int retorno;
    int flagEditado=0;


    do{
        utn_GetNumero(&opcion,"Menu:\n"
                        "1. Cargar los datos de las empresas desde el archivo data.csv (modo texto)\n"
                        "2. Cargar los datos de las empresas desde el archivo data.bin (modo binario)\n"
                        "3. Alta de empresa\n"
                        "4. Modificar datos de una empresa\n"
                        "5. Baja de una empresa\n"
                        "6. Listar empresas\n"
                        "7. Ordenar empresas\n"
                        "8. Salir\n"
                        "Elija una opcion:"
                        ,"Opcion invalida.\n",1,8,2);

                        switch(opcion){
                        case 1:
                            retorno = controller_loadFromText(archivoTexto,listaEmpresas);
                            if(retorno == 0){
                                printf("Datos guardados correctamente.\n");
                                copiaListaEmpresas=ll_clone(listaEmpresas);
                                flagEditado=1;
                            }else if(retorno == 1){
                                printf("Ya trajo los datos del archivo anteriormente.\n");
                            }else{
                                printf("No se pudo traer los datos del archivo.\n");
                            }
                            break;
                        case 2:
                            retorno = controller_loadFromBinary(archivoBinario,listaEmpresas);
                            if(retorno == 0){
                                printf("Datos guardados correctamente.\n");
                                copiaListaEmpresas=ll_clone(listaEmpresas);
                                flagEditado=1;
                            }else if(retorno == 1){
                                printf("Ya trajo los datos del archivo anteriomente.\n");
                            }else{
                                printf("No se pudo traer los datos del archivo.\n");
                            }
                            break;
                        case 3:
                            retorno = controller_addCompany(copiaListaEmpresas);
                            if(retorno == 0){
                                printf("Empresa guardada correctamente.\n");
                                flagEditado=1;
                            }else if(retorno == 1){
                                printf("Debe traer los datos a memoria para operar.\n");
                            }else{
                                printf("No se pudo hacer el alta de la empresa.\n");
                            }
                            break;
                        case 4:
                            retorno = controller_editCompany(copiaListaEmpresas);
                            if(retorno == 0){
                                printf("Empresa modificada correctamente.\n");
                                flagEditado=1;
                            }else if(retorno == -1){
                                printf("No se puede hacer la operacion.\n");
                            }else{
                                printf("No se hizo la modificacion de la empresa.\n");
                            }
                            break;
                        case 5:
                            retorno = controller_removeCompany(copiaListaEmpresas);
                            if(retorno == 0){
                                printf("Empresa eliminada correctamente.\n");
                                flagEditado=1;
                            }else if(retorno == -1){
                                printf("No se puede hacer la operacion.\n");
                            }else{
                                printf("No se elimnino la empresa.\n");
                            }
                            break;
                        case 6:
                            if(controller_ListCompany(copiaListaEmpresas)!= 0){
                                printf("La lista esta vacia.\n");
                            }
                            break;
                        case 7:
                            retorno = controller_sortCompany(copiaListaEmpresas);
                            if(retorno == 0){
                                printf("Se hizo el ordenamiento.\n");
                            }else if(retorno == 1){
                                printf("No se hicieron cambios.\n");
                            }else{
                                printf("No se pudo hacer el ordenamiento.\n");
                            }
                            break;
                        case 8:
                            retorno = controller_saveAll(archivoTexto,archivoBinario,listaEmpresas,copiaListaEmpresas,flagEditado);
                            if(retorno == 1){
                                printf("Datos guardados correctamente.\n");
                            }else if(retorno == 0){
                                printf("No se realizaron cambios.\n");
                            }else{
                                printf("No se pudieron guardar los datos.\n");
                            }
                            break;
                        default:
                            cleanScreen();
                            continue;
                        }
                        cleanScreen();
    }while(opcion != 8);

    return 0;
}



/*//test LinkedList
int main(void)
{
        //startTesting(1);  // ll_newLinkedList
        //startTesting(2);  // ll_len
        //startTesting(3);  // getNode - test_getNode
        //startTesting(4);  // addNode - test_addNode
        //startTesting(5);  // ll_add
        //startTesting(6);  // ll_get
        //startTesting(7);  // ll_set
        //startTesting(8);  // ll_remove
        //startTesting(9);  // ll_clear
        //startTesting(10); // ll_deleteLinkedList
        //startTesting(11); // ll_indexOf
        //startTesting(12); // ll_isEmpty
        //startTesting(13); // ll_push
        //startTesting(14); // ll_pop
        //startTesting(15); // ll_contains
        //startTesting(16); // ll_containsAll
        //startTesting(17); // ll_subList
        //startTesting(18); // ll_clone
        //startTesting(19); // ll_sort

    return 0;
}
*/
