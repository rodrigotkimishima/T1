#include "string.h"
#include "concatena.h"

int S_Match(char *token, char *var)
{
	if(strcmp(token, var) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char *S_Cat(Args *arg, char *token, char *var)
{
	char *string;

	string = Alloc_SI();
	token = Fix_Barra_N(token);

	if(S_Match(token, "@1"))
	{
		string = Concatena(var,arg->par[0]);
	}
	else if(S_Match(token, "@2"))
	{
		string = Concatena(var,arg->par[1]);
	}
	else if(S_Match(token, "@3"))
	{
		string = Concatena(var,arg->par[2]);
	}
	else
	{
		string = Concatena(var, token);
	}

	return string;
}

char *Fix_Barra_N(char *token)
{
	unsigned int i;

	for(i = 0; i < strlen(token); i++)
	{
		if(token[i] == '\r' || token[i] == '\n')
		{
			token[i] = 0;
		}
	}

	return token;
}

char *Left_Pull(char *token,unsigned int j)
{
	unsigned int i;
	for(i = j; i < strlen(token)-1; i++)
	{
		token[i] = token[i+1];
	}
	return token;
}

char *Fix_Dir(char *token)
{
	char *newdir;
	char *aux;
	if(token == NULL)
	{
		return NULL;
	}
	newdir = Alloc_SI();
	token = Fix_Barra_N(token);

	if(token[0] == '.' && token[1] != '/')
	{
		token = Left_Pull(token, 0);
		aux = newdir;
		newdir = Alloc_SI();
		free_c(aux);
		aux = newdir;
		newdir = Concatena(newdir, "./");
		free_c(aux);
		aux = newdir;
		newdir = Concatena(newdir, token);
		free_c(aux);
	}
	else
	{
		aux = newdir;
		newdir = Concatena(newdir, token);
	}

	printf("------%c--------\n",newdir[strlen(newdir)-1]);

	if(newdir[strlen(newdir)-1] != '/')
	{
		aux = newdir;
		newdir = Concatena(newdir, "/");
		free_c(aux);
	}
	
	return newdir;
}

int S_Size(char *string)
{
	unsigned int i;
	i = strlen(string);
	return i;
}

void free_c(char *string)
{
	if(string != NULL)
	{
		free(string);
		string = NULL;
	}
}
