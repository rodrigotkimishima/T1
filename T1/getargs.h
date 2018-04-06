#ifndef GET_ARGS_H
#define GET_ARGS_H

 /*
 Criando Struct Para Argumentos
 */
struct args
{
	char *f;
	char *o;
	char *par[3];
};

typedef struct args Args;

/*
Aloca Memoria Para Tamanho De Struct 'Args'
*/
Args *Make_Arg();

/*
Desaloca Memoria De Tamanho Struct 'Args'
*/
void Free_Arg(Args *args);

/*
Função Para Obter Os Argumentos De Comandos
Caso Não Encontre Os Comandos Necessarios,A Função Retorna 1,Senão Retorna 0

argc = Quantidade De Argumentos
*argv[] = Vetor De Strings Contendo Os Argumentos
*arg = Struct Onde Sera Armazenado Dados Obtidos 
*/
int Get_Args(Args *args, int argc, char *argv[]);

/*
Função Para Obter Parametros 1,2 e 3 Caso O Usuario Tenha Inserido

*argv[] = Vetor De Strings Contendo Os Argumentos
*i = Auxiliar Para Mostrar a Posição Atual No Vetor 'argv[]'
*j = Auxiliar Para Armazenar Os Parametros No Vetor 'par[]'
*/
char *Search_Par(char *argv[], int *i, int *j);

/*
Função Para Verificar Os Comandos Inseridos Pelo Usuario 

argc = Quantidade De Argumentos
*argv[] = Vetor De Strings Contendo Os Argumentos
*arg = Struct Onde Sera Armazenado Dados Obtidos
*/
char *Search_String(int argc, char *argv[], char *arg);

/*
Função Para Obter Parametros Que o Usuario Inseriu Na Linha De Comando

*arg = Struct Onde Sera Armazenado Dados Obtidos
argc = Quantidade De Argumentos
*argv[] = Vetor De Strings Contendo Os Argumentos
*/
void Get_Par(Args *args, int argc, char *argv[]);

#endif
