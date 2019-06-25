#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>

Employee* employee_new()
{
    Employee* emp = (Employee*) malloc (sizeof(Employee));
    if(emp != NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre,"") ;
        emp->sueldo = 0;
        emp->horasTrabajadas = 0;
    }

    return emp;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int error = 1;
    Employee* emp = (Employee*) malloc (sizeof(Employee));
    if(emp != NULL)
    {
        if(employee_setId(emp,atoi(idStr))==0)
        {
            if(employee_setNombre(emp,nombreStr)==0)
            {
                if(employee_setHorasTrabajadas(emp,atoi(horasTrabajadasStr))==0)
                {
                    if(employee_setSueldo(emp,atoi(sueldoStr))==0)
                    {
                        error = 0;

                    }
                }
            }
        }
        if (error)
        {
            free(emp);
            emp = NULL;
        }
    }
    return emp;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this != NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        error = 0;
    }

    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int error = 1;
    if (this != NULL || nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }
    return error;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 1;

    if(this != NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        error = 0;
    }
    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;
    if (this != NULL || sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;

}

int employee_setId(Employee* this,int id)
{
    int error = 1;

    if(this != NULL && id>0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}
int employee_getId(Employee* this,int* id)
{
    int error = 1;
    if (this != NULL || id!=NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = 1;

    if(this != NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }
    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int error = 1;
    if (this != NULL || horasTrabajdas!=NULL)
    {
        *horasTrabajdas = this->horasTrabajadas;
        error = 0;
    }
    return error;

}

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->sueldo > ((Employee*)pEmployeeB)->sueldo)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->sueldo < ((Employee*)pEmployeeB)->sueldo)
    {
        return -1;
    }
    return 0;

}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%d\r\n",p->nombre,p->sueldo);
}
