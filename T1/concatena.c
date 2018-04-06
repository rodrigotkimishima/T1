#include "concatena.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char *Alloc_SI()
{
	char *string;
	string =malloc(sizeof(char));
	*string = 0;
	return string;
}

char *Concatena(char *var,char *token)
{
	char *aux;
	aux = malloc((strlen(var)+strlen(token)+1)*sizeof(char));
	strcat(aux,var);
	strcat(aux,token);
	return aux;
}

char *Clean_S(char *string)
{
	if(string != NULL)
	{
		free(string);
		string = NULL;	
	}
	return Alloc_SI();
}

char *Concatena_Path(char *dir, char *n_arq, char *n_arq_type)
{
	char *aux;
	char *newfile;

	newfile = Alloc_SI();
	aux = newfile;
	newfile = Concatena(newfile, dir);
	free_c(aux);
	aux = newfile;
	newfile = Concatena(newfile, n_arq);
	free_c(aux);
	aux = newfile;
	newfile = Concatena(newfile, ".");
	free_c(aux);
	aux = newfile;
	newfile = Concatena(newfile, n_arq_type);
	free_c(aux);
	printf("%s\n",newfile);
	return newfile;
}