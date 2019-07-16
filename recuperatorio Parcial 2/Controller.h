#include "LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_loadFromBinary(char* path , LinkedList* pArrayList);
int controller_addEmployee(LinkedList* pArrayList);
int controller_editEmployee(LinkedList* pArrayList);
int controller_removeEmployee(LinkedList* pArrayList);
int controller_ListEmployee(LinkedList* pArrayList);
int controller_sortEmployee(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);

int controller_saveAsBinary(char* path , LinkedList* pArrayList);

int controller_asignarTipos(LinkedList* this,int(*pFn)(void*elementA, void*elementB));
