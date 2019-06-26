#ifndef dominio_H_INCLUDED
#define dominio_H_INCLUDED
 typedef struct
 {
     int id;
     char dominio[7];
     int anio;
     char tipo;
 }eDominio;

eDominio* dominio_newParametros(char* idStr,char* dominioStr,char* anioStr,char tipo);
int asignarTipo(eDominio* this);

int dominio_setId(eDominio* this,int id);
int dominio_getId(eDominio* this,int* id);

int dominio_setDominio(eDominio* this,char* dominio);
int dominio_getDominio(eDominio* this,char* dominio);

int dominio_setAnio(eDominio* this,int anio);
int dominio_getAnio(eDominio* this,int* anio);

int dominio_setTipo(eDominio* this,char tipo);
int dominio_getTipo(eDominio* this,char* tipo);

void printDominios(eDominio* p);
#endif // dominio_H_INCLUDED
