#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char *option;
    int retorno = 1;
    option = (char*) malloc (sizeof(char)*5);
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("No se ha podido crear la lista de empleados. Reinicie el programa.\n\n");
        system("pause");
    }

    do
    {
        printf("\nMenu");
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
        printf("\n3. Alta de empleado");
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
            retorno = controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            retorno = controller_loadFromBinary("data.bin",listaEmpleados);
            break;
        case 3:
            retorno = controller_addEmployee(listaEmpleados);
            break;
        case 4:
            if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            if(retorno)
            {
                system("cls");
                printf("\nPrimero debe cargar algun empleado\n");
                break;
            }
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.bin",listaEmpleados);

            break;
        case 10:
            ll_deleteLinkedList(listaEmpleados);
            break;
        default:
            printf("\nOpcion invalida");
            system("cls");
            break;
        }
    }
    while((atoi(option)) != 10);
    return 0;
}

