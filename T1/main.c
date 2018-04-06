#include "getargs.h"
#include "commands.h"

int main(int argc,char *argv[])
{
	Args *arg;
	int erro;
	arg = Make_Arg();
	erro = Get_Args(arg, argc, argv);
	if(erro != 0)
	{
		printf("Erro Na Linha De Comando.\n");
	}
	else
	{
		Run_Commands(arg);
	}
	free(arg);
	return erro;
}
