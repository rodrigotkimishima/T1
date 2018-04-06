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
	char *newfile;

	newfile = malloc((strlen(dir)+strlen(n_arq)+strlen(n_arq_type)+2)*sizeof(char));
	strcat(newfile,dir);
	strcat(newfile,n_arq);
	strcat(newfile,".");
	strcat(newfile,n_arq_type);
	printf("%s\n",newfile);
	return newfile;
}
