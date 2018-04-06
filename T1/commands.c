#include "commands.h"	
#include "file.h"
#include "string.h"
#include "concatena.h"
#include "getargs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Run_Commands(Args *arg)
{
	FILE *commands;
	commands = Open_Commands(arg->f);
	if(commands != NULL)
	{
		Do_Commands(commands, arg);
	}
	fclose(commands);
}

void Do_Commands(FILE *commands,Args *arg)
{

	int cont_li = 0;
	unsigned int i;
	char *token;
	char linha[10000];
	char *aux;
	Vars_com *var;

	var = Make_Vars();
	var->d = Concatena(var->d, arg->o);
	printf("%s",arg->o);

	while(fgets(linha, 10000, commands) != NULL)
	{
		token = strtok(linha, " ");
		token = Fix_Barra_N(token);

		if(S_Match(token, "+x") == 1)
		{
			token = strtok(NULL, "\"");
			aux = var->x;
			var->x = S_Cat(arg, token, aux);
			printf("Variavel X = %s\n",var->x);
		}
		else if(S_Match(token, "+y") == 1)
		{
			token = strtok(NULL, "\"");
			aux = var->y;
			var->y = S_Cat(arg, token, var->y);
			printf("Variavel Y = %s\n",var->y);
		}
		else if(S_Match(token, "+z") == 1)
		{
			token = strtok(NULL, "\"");
			aux = var->z;
			if(token[0] == '*')
			{
				if(token[1] == '*')
				{
					var->z = malloc(((strtol(arg->par[0], NULL, 0) + 1) * strlen(aux) + 1) * sizeof(char));
					for(i = 0; i < strtol(arg->par[0], 0, 0) + 1; i++)
					{
						var->z = strcat(var->z,aux);
					}
				}
				else
				{

					token = Left_Pull(token,0);
					var->z = malloc(((strtol(token, 0, 0) + 1) * strlen(aux) + 1) * sizeof(char));

					for(i = 0; i < strtol(token, 0, 0) + 1; i++)
					{
						var->z = strcat(var->z,aux);
					}
				}
			}
			else
			{
				var->z = S_Cat(arg, token, var->z);
			}

			printf("Variavel Z = %s\n", var->z);
		}
		else if(S_Match(token, "x") == 1)
		{
			var->x = Alloc_SI();
			printf("Variavel X = %s\n",var->x);
		}
		else if(S_Match(token, "y") == 1)
		{
			var->y = Alloc_SI();
			printf("Variavel Y = %s\n",var->y);
		}
		else if(S_Match(token, "z") == 1)
		{
			var->z = Alloc_SI();
			printf("Variavel Z = %s\n",var->z);
		}
		else if(S_Match(token, "d") == 1)
		{
			token = strtok(NULL,"\"");
			var->d = Clean_S(var->d);
			var->d = S_Var(var, token, var->d);
			aux = var->d;
			var->d = Fix_Dir(var->d);
			printf("Path De Saida: %s\n",var->d);
		}
		else if(S_Match(token, "a") == 1)
		{
			token = strtok(NULL,"\"");
			var->n_arq = Clean_S(var->n_arq);
			var->n_arq = S_Var(var, token, var->n_arq);
			printf("Nome Do Arquivo: %s\n",var->n_arq);
		}
		else if(S_Match(token, "e") == 1)
		{
			token = strtok(NULL, "\"");
			var->n_arq_type = Clean_S(var->n_arq_type);
			var->n_arq_type = S_Var(var, token, var->n_arq_type);
			printf("Tipo Do Arquivo: %s\n",var->n_arq_type);
		}
		else if(S_Match(token, "c"))
		{
			token = strtok(NULL, " ");
			i = strtol(token,NULL,0);
			var->file_id[i] = Create_File(var->n_arq, var->n_arq_type, var->d, "w");
		}
		else if(S_Match(token, "o"))
		{
			token = strtok(NULL, " ");
			i = strtol(token,NULL,0);
			var->file_id[i] = Create_File(var->n_arq, var->n_arq_type, var->d, "a");
		}
		else if(S_Match(token, "l"))
		{
			token = strtok(NULL, " ");
			i = strtol(token,NULL,0);
			var->file_id[i] = Create_File(var->n_arq, var->n_arq_type, var->d, "r");
		}
		else if(S_Match(token, "w"))
		{
			token = strtok(NULL, " ");
			i = strtol(token, NULL, 0);
			if(var->file_id[i] != NULL)
			{
				token = strtok(NULL, "\"");
				aux = Clean_S(aux);
				aux = S_Var(var, token, aux);
				fprintf(var->file_id[i], "%s", aux);
				printf("String |%s| Adicionado Ao Arquivo\n",aux);
			}
			else
			{
				printf("Erro: Nenhum Arquivo Aberto em ID |%d|\n",i);
			}
		}
		else if (S_Match(token, "r")) 
		{
			char gigante[1000];
			token = strtok(NULL, " ");
			i = strtol(token, NULL, 0);
			if(var->file_id[i] != NULL)
			{
				token = strtok(NULL, " ");
				token = Fix_Barra_N(token);
				if(S_Match(token, "#x"))
				{
					free_c(var->x);
					fgets(gigante, 1000, var->file_id[i]);
					printf("%s\n",gigante);
					var->x = calloc(strlen(gigante),sizeof(char));
					strcpy(var->x,gigante);
					printf("Variavel X = %s\n",var->x);
				}
				else if(S_Match(token, "#y"))
				{
					free_c(var->y);
					fgets(gigante, 1000, var->file_id[i]);
					printf("%s\n",gigante);
					var->y = calloc(strlen(gigante),sizeof(char));
					strcpy(var->y,gigante);
					printf("Variavel Y = %s\n",var->y);
				}
				else if(S_Match(token, "#z"))
				{
					free_c(var->x);
					fgets(gigante, 1000, var->file_id[i]);
					printf("%s\n",gigante);
					var->x = calloc(strlen(gigante),sizeof(char));
					strcpy(var->z,gigante);
					printf("Variavel Z = %s\n",var->z);
				}
			}
			else
			{
				printf("Erro: Nenhum Arquivo Aberto em ID |%d|\n",i);
			}
		}
		else if(S_Match(token, "f"))
		{
			token = strtok(NULL, " ");
			i = strtol(token, NULL, 0);
			if(var->file_id[i] != NULL)
			{
				close_file(var->file_id[i]);
				printf("Arquivo Do ID |%d| Fechado.\n",i);
			}
			else
			{
				printf("Nenhum Arquivo No ID |%d| Aberto.\n",i);
			}
		}

		if(aux != NULL)
		{
			free(aux);
			aux = NULL;
		}
		cont_li++;
		printf("linha |%d| Executada!!\n\n",cont_li);
	}
	free_all(var);
}

void free_all(Vars_com *var)
{
	free_c(var->x);
	free_c(var->y);
	free_c(var->z);
	free_c(var->n_arq);
	free_c(var->n_arq_type);
	free_c(var->d);
	free(var);
}

Vars_com *Make_Vars()
{
	Vars_com *var;
	var = malloc(sizeof(Vars_com));
	var->x = Alloc_SI();
	var->y = Alloc_SI();
	var->z = Alloc_SI();
	var->n_arq = Alloc_SI();
	var->n_arq_type = Alloc_SI();
	var->d = Alloc_SI();
	return var;
}

char *free_aux(char *string,int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		string[i] = 0;
	}

	return string;
}

char *S_Var(Vars_com *xyz, char *token, char *var)
{
	char *string;

	string = Alloc_SI();
	token = Fix_Barra_N(token);

	if(S_Match(token, "#x"))
	{
		string = Concatena(var,xyz->x);
	}
	else if(S_Match(token, "#y"))
	{
		string = Concatena(var,xyz->y);
	}
	else if(S_Match(token, "#z"))
	{
		string = Concatena(var,xyz->z);
	}
	else
	{
		string = Concatena(var, token);
	}

	return string;
}