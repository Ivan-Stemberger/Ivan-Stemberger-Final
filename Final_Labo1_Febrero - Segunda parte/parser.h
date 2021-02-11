#include "LinkedList.h"

#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED

int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EntregaFromText(FILE* pFile , LinkedList* pArrayListEnvio);

#endif // parser_H_INCLUDED
