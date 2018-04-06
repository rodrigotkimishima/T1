#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getargs.h"

/*
Função Para Ver Se As Strings São Iguais

*token = String
*param = String De Verificação
*/
int S_Match(char *token,char *param);

char *S_Cat(Args *arg,char *token, char *param);

char *Fix_Barra_N(char *token);

char *Left_Pull(char *token,unsigned int j);

char *Fix_Dir(char *dir);

void Dir_Cat( char **s, const char *c );

void free_c(char *string);

#endif
