#ifndef COMMANDS_H
#define COMMANDS_H
	
#include "file.h"
#include "string.h"
#include "concatena.h"
#include "getargs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct var_com
{
	char *x;
	char *y;
	char *z;
	char *d;
	char *n_arq;
	char *n_arq_type;
	FILE *file_id[10];
};

typedef struct var_com Vars_com;

void Run_Commands(Args *arg);

void Do_Commands(FILE *commands,Args *arg);

void free_all(Vars_com *var);

Vars_com *Make_Vars();

char *free_aux(char *string,int size);

char *S_Var(Vars_com *xyz, char *token, char *var);

#endif
