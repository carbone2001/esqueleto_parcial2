#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "inputs.h"
#include "Controller.h"
#include "dominio.h"

int main()
{
    int opcion;
    int (*pFunc) ();
    LinkedList * listaDominios;
    LinkedList * autos;
    LinkedList * motos;

    char path[20];
    do
    {
        printf("\n1. Leer archivo \n2. Funcion map \n3. Funcion filter \n4. Guardar archivos auto.csv y moto.csv");
        getInt(&opcion,"\nIngrese opcion: ","\nOpcion incorrecta. Saliendo...\n",0);
        switch(opcion)
        {
        case 1:
            if(getString(path,"\nIngrese nombre del archivo: ","\nError al cargar nombre",20)==0)
            {
                listaDominios = ll_newLinkedList();
                if(controller_loadFromText(path,listaDominios))
                {
                    printf("\nError al cargar datos del archivo\n");
                    listaDominios = NULL;
                }
                else
                {
                    printf("\nLos archivos han sido cargados con exito!!");
                    for(int i=0; i<ll_len(listaDominios); i++)
                    {
                        printDominios(ll_get(listaDominios,i));
                    }
                }
            }
            break;
        case 2:
            if(listaDominios != NULL)
            {
                pFunc = asignarTipo;
                map(listaDominios, pFunc);
                printf("\n La funcion map ha sido ejecutada");
                for(int i=0; i<ll_len(listaDominios); i++)
                {
                    printDominios(ll_get(listaDominios,i));
                }
            }
            else
            {
                printf("\n No se ha podido ejecutar la funcion map");
            }
            break;
        case 3:
            if(listaDominios != NULL)
            {
                pFunc = esUnAuto;
                autos = filter(listaDominios,pFunc);
                pFunc = esUnaMoto;
                motos = filter(listaDominios,pFunc);
                if(motos == NULL || autos == NULL)
                {
                    printf("\n Error al ejecutar la funcion filter");
                }
                else
                {
                    printf("\n La funcion filter ha funcionado exitosamente");
                    for(int i=0; i<ll_len(autos); i++)
                    {
                        printDominios(ll_get(autos,i));
                    }
                    for(int i=0; i<ll_len(motos); i++)
                    {
                        printDominios(ll_get(motos,i));
                    }
                }
            }
            break;
        case 4:
            if(listaDominios != NULL)
            {
                if(controller_saveAsText("auto.csv",autos) || controller_saveAsText("moto.csv",motos))
                {
                    printf("\nHa ocurrido un error al guardar los archivos");
                }
                else
                {
                    printf("\n Los archivos han sido guardados exitosamente");
                }
            }
            break;

        }
    }
    while(opcion);
    return 0;
}
