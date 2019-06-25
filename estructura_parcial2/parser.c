#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error;
    char buffer[4][128];
    int cant;
    Employee* nuevoEmpleado;
    error = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //Leida fantasma
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(cant==4)
        {
            while(!feof(pFile))
            {
                cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                if(cant!=4)
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    error = 1;
                    break;
                }
                nuevoEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(nuevoEmpleado == NULL)
                {
                    error = 1;
                    break;
                }
                if(ll_add(pArrayListEmployee,nuevoEmpleado))
                {
                    error = 1;
                    break;
                }
            }
        }
    }

    free(nuevoEmpleado);

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
