#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "dominio.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_dominioFromText(FILE* pFile , LinkedList* pArrayListDominio)
{
    int error = 1;
    eDominio* newElement;
    char buffer[3][20];
    int cant;
    if(pArrayListDominio != NULL)
    {
        //Leida fantasma
        cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);
        while(!feof(pFile))
        {
            error = 1;
            cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);

            if(cant == 3)
            {
                newElement = dominio_newParametros(buffer[0],buffer[1],buffer[2],' ');
                if(newElement != NULL)
                {
                    error = ll_add(pArrayListDominio,newElement);
                }
            }
            if(error)
            {
                if(!feof(pFile))
                {
                    error = 1;
                    break;
                }
                else
                {
                    error = 0;
                }

            }

        }
    }
    return error;
}

