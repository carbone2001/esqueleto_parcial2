#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    FILE * file;

    file = fopen(path,"r");
    if(file!=NULL && pArrayListEmployee != NULL)
    {
        error = parser_EmployeeFromText(file,pArrayListEmployee);
    }
    system("cls");
    if(error)
    {
        printf("\nError al cargar el texto de archivo \n");
    }
    else
    {
        printf("\nLa carga se ha realizado con exito \n");
    }
    fclose(file);
    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE * pFile;
    int error;
    pFile = fopen("data.bin","rb");
    error = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    fclose(pFile);
    system("cls");
    if(error)
    {
        printf("\nError al cargar desde el archivo binario.\n");
    }
    else
    {
        printf("\nSe ha cargado desde el archivo binario con exito!!\n");
    }
    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    int error;
    error = 1;
    char* nombre;
    int* sueldo;
    int* horasTrabajadas;
    int* id;
    Employee* aux;
    Employee* nuevoEmpleado;
    nombre = (char*) malloc (sizeof(char)*128);
    horasTrabajadas = (int*) malloc (sizeof(int));
    sueldo = (int*) malloc (sizeof(int));
    id = (int*) malloc (sizeof(int));

    if((error = getString(nombre,"\nIngrese nombre del empleado: ","\nError. No debe superar los 127 caracteres: ",127)) == 0)
    {
        if((error = getInt(sueldo,"\nIngrese sueldo: ","\nEl sueldo ingresado es invalido\n",1)) == 0)
        {
            if((error = getInt(horasTrabajadas,"\nIngrese horas trabajdas: ","\nEl numero de horas ingresado es invalido\n",1)) == 0)
            {
                if((error = getInt(id,"\nIngrese ID: ","\nEl ID ingresado es invalido\n",1)) == 0)
                {
                    error = 0;
                    for(int i=0; i<ll_len(pArrayListEmployee); i++)
                    {
                        aux = ll_get(pArrayListEmployee,i);
                        if(aux == NULL)
                        {
                            error = 1;
                            break;
                        }
                        if(aux->id == *id)
                        {
                            printf("\nEl ID ingresado ya exite. Intente ingresar otro\n");
                            system("pause");
                            error = 1;
                        }
                    }

                    nuevoEmpleado = employee_new();
                    if(nuevoEmpleado != NULL && error == 0)
                    {
                        error =+ employee_setId(nuevoEmpleado,*id);
                        error =+ employee_setNombre(nuevoEmpleado,nombre);
                        error =+ employee_setSueldo(nuevoEmpleado,*sueldo);
                        error =+ employee_setHorasTrabajadas(nuevoEmpleado,*horasTrabajadas);
                        if(error==0)
                        {
                            ll_add(pArrayListEmployee,nuevoEmpleado);
                            free(id);
                            free(nombre);
                            free(sueldo);
                            free(horasTrabajadas);
                        }
                        free(nuevoEmpleado);
                    }
                }
            }
        }
    }

    system("cls");
    if(error)
    {
        printf("\nHubo un error al cargar el empleado\n");
    }
    else
    {
        printf("\nEl empleado ha sido cargado exitosamente\n");
    }

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int id;
    int error = 0;
    int empFound=-1;
    Employee* emp;
    Employee* aux;

    int newId;
    char* newNombre;
    int newHorasTrabajadas;
    int newSueldo;
    newNombre = (char*) malloc (sizeof(char));
    printf("Ingrese ID del empleado a modificar: ");
    scanf("%d",&id);
    for(int i = 0; i<ll_len(pArrayListEmployee); i++)
    {
        emp = ll_get(pArrayListEmployee,i);
        if(emp->id == id)
        {
            empFound = i;
            break;
        }
    }

    if(empFound != -1)
    {
        system("cls");
        printf("*** MODIFICAR EMPLEADO ***");
        printf("\n1) ID");
        printf("\n1) Nombre");
        printf("\n1) Horas Trabajdas");
        printf("\n1) Sueldo");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese nuevo ID: ");
            scanf("%d",&newId);
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                if(aux == NULL)
                {
                    error = 1;
                    break;
                }
                if(aux->id == newId)
                {
                    printf("\nEl ID ingresado ya exite. Intente ingresar otro\n");
                    error = 1;
                }
            }
            if(error)
            {
                break;
            }
            if((error = employee_setId(emp,newId)))
            {
                break;
            }
            error = ll_set(pArrayListEmployee,empFound,emp);
            break;
        case 2:
            printf("Ingrese nuevo Nombre: ");
            fflush(stdin);
            gets(newNombre);
            if((error = employee_setNombre(emp,newNombre)))
            {
                break;
            }
            error = ll_set(pArrayListEmployee,empFound,emp);
            break;
        case 3:
            printf("Ingrese nuevo numero de horas trabajdas: ");
            scanf("%d",&newHorasTrabajadas);
            if((error = employee_setHorasTrabajadas(emp,newHorasTrabajadas)))
            {
                break;
            }
            error = ll_set(pArrayListEmployee,empFound,emp);
            break;
        case 4:
            printf("Ingrese nuevo sueldo: ");
            scanf("%d",&newSueldo);
            if((error = employee_setSueldo(emp,newSueldo)))
            {
                break;
            }
            error = ll_set(pArrayListEmployee,empFound,emp);
            break;
        default:
            printf("\nOpcion invalida");
            break;


        }
        if(error)
        {
            printf("\nError al modificar empleado\n");
            system("pause");
        }
        else
        {
            printf("\nEl empleado se ha modifcado exitosamente\n");
            system("pause");
        }

    }
    else
    {
        printf("\nNo se ha encontrado al empleado de ID %d\n",id);
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    Employee* emp;
    int id;
    char option;
    int found = 0;
    printf("\nIngrese ID del empleado a eliminar: ");
    scanf("%d",&id);

    for(int i = 0; i<ll_len(pArrayListEmployee); i++)
    {
        emp = ll_get(pArrayListEmployee,i);
        if(emp->id == id)
        {
            found = i;
            break;
        }
    }
    if(found)
    {
        printf("\nEl ID ingresado corresponde a: ");
        printf("%s",emp->nombre);
        printf("\nDesea proseguir con la eliminacion? (s/n): ");
        fflush(stdin);
        scanf("%c",&option);
        if(option == 's')
        {
            if(ll_remove(pArrayListEmployee,found))
            {
                printf("\nNo se ha podido eliminar al empleado");
            }
            else
            {
                printf("\nLa eliminacion ha sido exitosa");
            }
        }
        else
        {
            printf("\nSe ha cancelado la eliminacion");
        }
    }
    else
    {
        printf("\nNo se ha encontrado al empleado de ID: %d",id);
    }

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;
    Employee* empleado;
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        empleado = ll_get(pArrayListEmployee,i);
        if(empleado == NULL)
        {
            error = 1;
            break;
        }
        printf("\n%d %15s %d %d \n",empleado->id,empleado->nombre,empleado->sueldo,empleado->horasTrabajadas);
    }
    if(error)
    {
        printf("\n\nError al listar los empleados\n");
    }
    system("pause");
    system("cls");


    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* empI;
    Employee* empJ;
    Employee* aux;
    aux = (Employee*) malloc (sizeof(Employee));
    if(aux != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListEmployee)-1; i++)
        {
            empI = ll_get(pArrayListEmployee,i);
            for(int j=i+1; j<ll_len(pArrayListEmployee); j++)
            {
                empJ = ll_get(pArrayListEmployee,j);
                if(strcmp(empI->nombre,empJ->nombre)>0)
                {
                    aux = empI;
                    empI = empJ;
                    empJ = aux;
                    error = ll_set(pArrayListEmployee,i,empI);
                    error = ll_set(pArrayListEmployee,j,empJ);
                }
            }
            if(i<ll_len(pArrayListEmployee)-1)
            {
                error = 0;
            }
        }
    }
    if(error)
    {
        system("cls");
        printf("\nATENCION! Hubo un error en el ordenamiento.");
    }
    else
    {
        system("cls");
        printf("\nEl ordenamiento se ha realizado con exito!");
    }
    free(aux);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{


    FILE* pFile;
    Employee* emp;
    int error = 0;

    pFile = fopen (path,"w");
    if(pFile != NULL)
    {
        fprintf(pFile,"\nid,nombre,horasTrabajdas,sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            emp = ll_get(pArrayListEmployee,i);
            if(emp==NULL)
            {
                error = 1;
                break;
            }
            fprintf(pFile,"%d,%s,%d,%d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
        }
        system("pause");
    }
    else
    {
        error = 1;
    }
    printf("error: %d",error);
    system("pause");
    fclose(pFile);
    free(emp);

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE * pFile;
    Employee* emp;
    int error = 1;
    int cant;

    emp = (Employee*) malloc (sizeof(Employee));
    if(emp != NULL)
    {
        pFile = fopen (path,"wb");
        if(pFile != NULL)
        {
            for(int i=1; i<ll_len(pArrayListEmployee); i++)
            {
                fseek(pFile,0L,SEEK_END);
                emp = ll_get(pArrayListEmployee,i);
                if(emp == NULL)
                {
                    break;
                }
                if((cant = fwrite(emp,sizeof(Employee),1,pFile))!=1)
                {
                    break;
                }
                if(i==ll_len(pArrayListEmployee)-1)
                {
                    error = 0;
                }
            }
            fclose(pFile);
        }
    }
    system("cls");
    if(error)
    {
        printf("\nError al cargar como binario\n");
    }
    else
    {
        printf("\nLa carga se ha realizado con exito!!\n");
    }
    return error;
}

