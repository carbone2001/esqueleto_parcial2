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
int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
    int error;
    char buffer[3][50];
    int cant;
    eDominio* dom; ///Estructura a parsear
    error = 0;
    if(pFile != NULL && pArrayList != NULL)
    {
        //Leida fantasma
        cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);
        if(cant==3)
        {
            while(!feof(pFile))
            {
                cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);
                if(cant!=3)
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    error = 1;
                    break;
                }
                dom = dominio_newParametros(buffer[0],buffer[1],buffer[2],' ');
                if(dom == NULL)
                {
                    error = 1;
                    break;
                }
                if(ll_add(pArrayList,dom))
                {
                    error = 1;
                    break;
                }
            }
        }
    }

    free(dom);

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */

int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{

    eDominio *dom;
    int error = 1;
    int cant;
    if(pFile != NULL && pArrayList != NULL)
    while(!feof(pFile))
    {
        dom = (eDominio*) malloc (sizeof(eDominio));
        if(dom == NULL)
        {
            break;
        }
        cant = fread(dom,sizeof(eDominio),1,pFile);
        if(cant != 1)
        {
            if(feof(pFile))
            {
                error = 0;
                break;
            }
            break;
        }

        if(ll_add(pArrayList,dom))
        {
            break;
        }
    }
    return error;
}

