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
    int error;
    char buffer[3][50];
    int cant;
    char* tipo = ' ';
    eDominio* dom;
    error = 0;
    if(pFile != NULL && pArrayListDominio != NULL)
    {
        printf("\nok2\n");
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
                if(ll_add(pArrayListDominio,dom))
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
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee *emp;
    int error = 1;
    int cant;
    if(pFile != NULL && pArrayListEmployee != NULL)
    while(!feof(pFile))
    {
        emp = (Employee*) malloc (sizeof(Employee));
        if(emp == NULL)
        {
            break;
        }
        cant = fread(emp,sizeof(Employee),1,pFile);
        if(cant != 1)
        {
            if(feof(pFile))
            {
                error = 0;
                break;
            }
            break;
        }

        if(ll_add(pArrayListEmployee,emp))
        {
            break;
        }
    }
    return error;
}
*/
