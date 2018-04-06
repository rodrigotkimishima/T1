#include "file.h"
#include "commands.h"
#include "concatena.h"
#include "string.h"
#include <string.h>

FILE *Open_Commands(char *path)
{
	FILE *commands;
	commands = fopen(path,"r");
	if(commands != NULL)
	{
		return commands;
	}
	else
	{
		printf("Erro Ao Tentar Abrir o Arquivo |%s|.\n",path);
		return NULL;
	}
}

FILE *Create_File(char *n_arq,char *n_arq_type,char *dir,char *type_ofopen)
{
	FILE *arq;
	char *string;
	if(n_arq == NULL || n_arq_type == NULL)
	{
		printf("Erro Ao Tentar Abrir Diretorio Ou Arquivo.\n");
		return NULL;
	}
	if(dir == NULL)
	{
		dir = Alloc_SI();
	}

	string = Concatena_Path(dir, n_arq, n_arq_type);

	arq = fopen(string, type_ofopen);
	if(arq == NULL)
	{
		printf("Falha Ao Tentar Abrir Ou Criar Arquivo %s\n",string);
		return arq;
	}
	else
	{
		printf("Arquivo Aberto Para |%s|\n",type_ofopen);
		return arq;
	}
}

void close_file(FILE *arq)
{
	fclose(arq);
}