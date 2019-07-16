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
    int (*pFunc)();
    //path = (char*) malloc (sizeof(char)*15);
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
        printf("\n2. Asignar tipos a los elementos de la lista");
        printf("\n3. Filter");
        printf("\n4. Guardar archivo segun tipo (auto y moto)");
        printf("\n5. Salir\n");
        fflush(stdin);
        scanf("%s",option);

        switch(atoi(option))
        {
        case 1:
            //path = (char*) malloc (sizeof(char)*15);
            if(getString(path,"\nIngrese la direccion del archivo: ","\nHubo un error\n",15) == 0)
            {
                //printf("\npath leido  %s",path);
                //strcpy(path,"datos.csv");
                retorno = controller_loadFromText(path,listaDominios);

                printf("\nlen de dominio %d",ll_len(listaDominios));
                for(int i = 0; i<ll_len(listaDominios); i++)
                {
                    printDominios(ll_get(listaDominios,i));
                }
                system("pause");
                //retorno = 0;
            }

            break;
        case 2:
            if(retorno == 0)
            {
                pFunc = asignarTipo;
                map(listaDominios,pFunc);

                for(int i = 0; i<ll_len(listaDominios); i++)
                {
                    printDominios(ll_get(listaDominios,i));
                }
                system("pause");
                retorno = 2;
            }
            break;
        case 3:
            if(retorno == 2)
            {
                pFunc = esUnAuto;
                listaAutos = filter(listaDominios,pFunc);
                pFunc = esUnaMoto;
                listaMotos = filter(listaDominios,pFunc);

                for(int i = 0; i<ll_len(listaAutos); i++)
                {
                    printDominios(ll_get(listaAutos,i));
                }
                for(int i = 0; i<ll_len(listaMotos); i++)
                {
                    printDominios(ll_get(listaMotos,i));
                }
                system("pause");
                retorno = 3;
            }
            break;
        case 4:
            if(retorno == 3)
            {
                controller_saveAsText("auto.csv",listaAutos);
                controller_saveAsText("moto.csv",listaMotos);
            }
            break;
        default:
            printf("\nOpcion invalida");
            system("cls");
            break;
        }
    }
    while((atoi(option)) != 5);
    //free(path);

    return 0;
}
