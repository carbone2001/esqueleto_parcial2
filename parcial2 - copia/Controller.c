#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "dominio.h"
#include "parser.h"
#include "inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path, LinkedList* pArrayListDominios)
{
    int error = 1;
    FILE* arch;
    if(path != NULL && pArrayListDominios != NULL)
    {
        arch = fopen(path,"r");
        if(arch != NULL)
        {
            error = parser_dominioFromText(arch,pArrayListDominios);
        }
        else
        {
            printf("\n No pudo abrirse el archivo");
        }
    }
    fclose(arch);
    return error;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path, LinkedList* pArrayListDominio)
{
    int error = 1;
    eDominio* dom;
    FILE * pFile;
    pFile = fopen(path,"w");
    if(pArrayListDominio != NULL && pFile != NULL)
    {
        fprintf(pFile,"ID,dominio,anio,tipo\n");
        for(int i=0;i<ll_len(pArrayListDominio);i++)
        {
            dom = ll_get(pArrayListDominio,i);
            if(dom != NULL)
            {
                if(fprintf(pFile,"%d,%s,%d,%c\n",dom->id,dom->dominio,dom->anio,dom->tipo))
                {
                    error = 0;
                }
            }
        }
    }
    fclose(pFile);
    return error;
}




