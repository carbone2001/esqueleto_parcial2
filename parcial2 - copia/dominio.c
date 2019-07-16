#include "dominio.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "LinkedList.h"

eDominio* dominio_newParametros(char* idStr,char* dominioStr,char* anioStr,char tipo)
{
    eDominio * newDom = (eDominio*) malloc (sizeof(eDominio));
    int error = 1;
    if(dominio_setId(newDom,atoi(idStr))==0)
    {
        if(dominio_setDominio(newDom,dominioStr)==0)
        {
            if(dominio_setAnio(newDom,atoi(anioStr))==0)
            {
                if(dominio_setTipo(newDom,tipo)==0)
                {
                    error = 0;
                }
            }
        }
    }
    if(error)
    {
        newDom = NULL;
    }
    return newDom;
}


void printDominios(eDominio* p)
{
    printf("\nID: %d, Dominio: %s, Anio: %d, tipo: %c",p->id,p->dominio,p->anio,p->tipo);
}

int asignarTipo(eDominio* this)
{
    int error = 1;
    if(this != NULL)
    {
        if(isdigit( this->dominio[0] ))
        {
            this->tipo = 'M';
            error = 0;
        }
        else
        {
            this->tipo = 'A';
            error = 0;
        }
    }
    return error;
}

int esUnAuto(eDominio* this)
{
    int r = 0;
    if(this->tipo == 'A')
    {
        r = 1;
    }
    return r;
}

int esUnaMoto(eDominio* this)
{
    int r = 0;
    if(this->tipo == 'M')
    {
        r = 1;
    }
    return r;
}








int dominio_setDominio(eDominio* this,char* dominio)
{
    int error = 1;
    if(this != NULL)
    {
        strcpy(this->dominio,dominio);
        error = 0;
    }
    return error;
}

int dominio_getDominio(eDominio* this,char* dominio)
{
    int error = 1;
    if(this != NULL)
    {
        strcpy(dominio,this->dominio);
        error = 0;
    }

    return error;
}



int dominio_setTipo(eDominio* this,char tipo)
{
    int error = 1;
    if(this != NULL)
    {
        this->tipo = tipo;
        error = 0;
    }
    return error;
}
int dominio_getTipo(eDominio* this,char* tipo)
{
    int error = 1;
    if(this != NULL)
    {
        *tipo = this->tipo;
        error = 0;
    }

    return error;

}

int dominio_setId(eDominio* this,int id)
{
    int error = 1;
    if(this != NULL)
    {
        this->id = id;
        error = 0;
    }
    return error;
}
int dominio_getId(eDominio* this,int* id)
{
    int error = 1;
    if(this != NULL)
    {
        *id = this->id;
        error = 0;
    }

    return error;
}

int dominio_setAnio(eDominio* this,int anio)
{
    int error = 1;
    if(this != NULL)
    {
        this->anio = anio;
        error = 0;
    }
    return error;
}
int dominio_getAnio(eDominio* this,int* anio)
{
    int error = 1;
    if(this != NULL)
    {
        *anio = this->anio;
        error = 0;
    }

    return error;
}
