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
    int retorno = 1; ///El retorno sirve para que se respete cierto orden al ejecutar tareas que dependen de otras
    int (*pFunc)();
    option = (char*) malloc (sizeof(char)*5);
    LinkedList* listaDominios = ll_newLinkedList();
    LinkedList* listaAutos = ll_newLinkedList();
    LinkedList* listaMotos = ll_newLinkedList();
    if(listaDominios == NULL)
    {
        printf("No se ha podido crear la lista de empleados. Reinicie el programa.\n\n");
        system("pause");
    }

    do
    {
        printf("\nMenu");
        printf("\n1. Cargar los datos de los dominios desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los dominios desde el arhivco binario");
        printf("\n3. Asignar tipos a los elementos de la lista");
        printf("\n4. Filter");
        printf("\n5. Guardar archivo segun tipo (auto y moto)");
        printf("\n6. Guardar archivos (binarios) segun tipo (auto y moto)");
        printf("\n7. Ordenar");
        printf("\n8. Salir\n");
        fflush(stdin);
        scanf("%s",option);

        switch(atoi(option))
        {
        case 1:
            if(getString(path,"\nIngrese la direccion del archivo: ","\nHubo un error\n",15) == 0)
            {
                retorno = controller_loadFromText(path,listaDominios);

                printf("\nlen de dominio %d",ll_len(listaDominios));
                for(int i = 0; i<ll_len(listaDominios); i++)
                {
                    printElementos(ll_get(listaDominios,i));
                }
                system("pause");
            }

            break;
        case 2:
            if(getString(path,"\nIngrese la direccion del archivo: ","\nHubo un error\n",15) == 0)
            {
                retorno = controller_loadFromBinary(path,listaDominios);

                printf("\nlen de dominio %d",ll_len(listaDominios));
                for(int i = 0; i<ll_len(listaDominios); i++)
                {
                    printElementos(ll_get(listaDominios,i));
                }
                system("pause");
            }

            break;
        case 3:
            if(retorno == 0)
            {
                pFunc = asignarTipo;
                map(listaDominios,pFunc);

                for(int i = 0; i<ll_len(listaDominios); i++)
                {
                    printElementos(ll_get(listaDominios,i));
                }
                system("pause");
                retorno = 2;
            }
            break;
        case 4:
            if(retorno == 2)
            {
                pFunc = esUnAuto;
                listaAutos = filter(listaDominios,pFunc);
                pFunc = esUnaMoto;
                listaMotos = filter(listaDominios,pFunc);

                for(int i = 0; i<ll_len(listaAutos); i++)
                {
                    printElementos(ll_get(listaAutos,i));
                }
                for(int i = 0; i<ll_len(listaMotos); i++)
                {
                    printElementos(ll_get(listaMotos,i));
                }
                system("pause");
                retorno = 3;
            }
            break;
        case 5:
            if(retorno == 3)
            {
                if(controller_saveAsText("auto.csv",listaAutos)==0)
                {
                    if(controller_saveAsText("moto.csv",listaMotos)==0)
                    {
                        printf("\nLos archivos han sido guardados con exito");
                        system("pause");
                    }
                }

            }
            break;
        case 6:
            if(retorno == 3)
            {
                if(controller_saveAsBinary("auto.bin",listaAutos)==0)
                {
                    if(controller_saveAsBinary("moto.bin",listaMotos)==0)
                    {
                        printf("\nLos archivos han sido guardados con exito");
                        system("pause");
                    }
                }

            }
            break;
        case 7:
            if(retorno == 3)
            {
                pFunc = idcmp;
                ll_sort(listaAutos,pFunc,0);
                for(int i = 0; i<ll_len(listaAutos); i++)
                {
                    printElemento(ll_get(listaAutos,i));
                }

            }
            break;
        default:
            printf("\nOpcion invalida");
            system("cls");
            break;
        }
    }
    while((atoi(option)) != 8);

    return 0;
}
