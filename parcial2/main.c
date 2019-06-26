#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "inputs.h"
#include "Controller.h"
#include "dominio.h"

int main()
{
    char *option;
    char path[30];
    int retorno = 1;
    //path = (char*) malloc (sizeof(char)*15);
    option = (char*) malloc (sizeof(char)*5);
    LinkedList* listaDominios = ll_newLinkedList();
    if(listaDominios == NULL)
    {
        printf("No se ha podido crear la lista de empleados. Reinicie el programa.\n\n");
        system("pause");
    }

    do
    {
        printf("\nMenu");
        printf("\n1. Cargar los datos de los dominios desde el archivo data.csv (modo texto).");
        printf("\n3. Asignar tipos a los elementos de la lista");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
        printf("\n10. Salir\n");
        fflush(stdin);
        scanf("%s",option);

        switch(atoi(option))
        {
        case 1:
            //path = (char*) malloc (sizeof(char)*15);
            if(getString(path,"\nIngrese la direccion del archivo: ","\nHubo un error\n",15) == 0)
            {
                printf("\npath leido  %s",path);
                //strcpy(path,"datos.csv");
                retorno = controller_loadFromText(path,listaDominios);

                printf("\nlen de dominio %d",ll_len(listaDominios));
                /*for(int i = 0; i<ll_len(listaDominios); i++)
                {
                    printDominios(ll_get(listaDominios,i));
                }*/
                //retorno = 0;
            }

            break;
        case 2:
            //map(path,asignarTipo(listaDominios));
            break;
        case 3:
            //retorno = controller_addEmployee(listaEmpleados);
            break;
        case 4:
            /*if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_editEmployee(listaEmpleados);*/
            break;
        case 5:
            /*if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_removeEmployee(listaEmpleados);*/
            break;
        case 6:
            /*if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_ListEmployee(listaEmpleados);*/
            break;
        case 7:
            /*if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_sortEmployee(listaEmpleados);*/
            break;
        case 8:
            //controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            //controller_saveAsBinary("data.bin",listaEmpleados);

            break;
        case 10:
            //ll_deleteLinkedList(listaEmpleados);
            break;
        default:
            printf("\nOpcion invalida");
            system("cls");
            break;
        }
    }
    while((atoi(option)) != 10);
    //free(path);

    return 0;
}
