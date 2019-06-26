#include "dominio.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "LinkedList.h"

eDominio* dominio_newParametros(char* idStr,char* dominioStr,char* anioStr,char tipo)
{
    int error = 1;
    eDominio* dom = (eDominio*) malloc (sizeof(eDominio));
    if(dom != NULL)
    {
        if(dominio_setId(dom,atoi(idStr))==0)
        {
            if(dominio_setDominio(dom,dominioStr)==0)
            {
                if(dominio_setAnio(dom,atoi(anioStr))==0)
                {
                    if(dominio_setTipo(dom,tipo)==0)
                    {
                        error = 0;

                    }
                }
            }
        }
        if (error)
        {
            free(dom);
            dom = NULL;
        }
    }
    return dom;
}


void printDominios(eDominio* p)
{
    printf("ID:%s dominio:%d anio: %d tipo: %c\r\n",p->id,p->dominio,p->anio,p->tipo);
}

int asignarTipo(eDominio* this)
{
    int retorno = 0;

    if(isdigit(this->dominio[0]))
    {
        dominio_setTipo(this,'M');
        retorno = 1;
    }
    return retorno;
}










int dominio_setDominio(eDominio* this,char* dominio)
{
    int error = 1;
    if(this != NULL && strlen(dominio)<7)
    {
        strcpy(this->dominio,dominio);
        error = 0;
    }

    return error;
}

int dominio_getDominio(eDominio* this,char* dominio)
{
    int error = 1;
    if (this != NULL || dominio!=NULL)
    {
        strcpy(dominio,this->dominio);
        error = 0;
    }
    return error;
}



int dominio_setTipo(eDominio* this,char tipo)
{
    int error = 1;

    if(this != NULL && (tipo == 'M' || tipo == 'A' || tipo == ' '))
    {
        this->tipo = tipo;
        error = 0;
    }
    return error;
}
int dominio_getTipo(eDominio* this,char* tipo)
{
    int error = 1;
    if (this != NULL || (*tipo == 'M' || *tipo == 'A'))
    {
        *tipo = this->tipo;
        error = 0;
    }
    return error;

}

int dominio_setId(eDominio* this,int id)
{
    int error = 1;

    if(this != NULL && id>0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}
int dominio_getId(eDominio* this,int* id)
{
    int error = 1;
    if (this != NULL || id!=NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;

}

int dominio_setAnio(eDominio* this,int anio)
{
    int error = 1;

    if(this != NULL && anio>=0)
    {
        this->anio = anio;
        error = 0;
    }
    return error;
}
int dominio_getAnio(eDominio* this,int* anio)
{
    int error = 1;
    if (this != NULL || anio!=NULL)
    {
        *anio = this->anio;
        error = 0;
    }
    return error;

}
