#include "getargs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Args *Make_Arg()
{
	Args *args;
	args = malloc(sizeof(Args));
	return args;
}

void Free_Arg(Args *args)
{
	free(args);
}

int Get_Args(Args *args, int argc, char *argv[])
{
	args->f = Search_String(argc, argv, "-f");
	args->o = Search_String(argc, argv, "-o");
	if(args->f == NULL)
	{
		return 1;
	}
	else
	{
		Get_Par(args,argc,argv);
		return 0;
	}
}	

void Get_Par(Args *args, int argc, char *argv[])
{
	int i,j = 0;
	for(i=1;i < argc;i++)
	{
		args->par[j] = Search_Par(argv, &i, &j);
	}
}

char *Search_String(int argc, char *argv[], char *arg)
{
	int i;
	for(i = 1; i < argc; i++)
	{
		if( strcmp(arg, argv[i] ) == 0)
		{
			return argv[i+1];
		}
	}
	return NULL;
}

char *Search_Par(char *argv[], int *i, int *j)
{
	if(strcmp("-f", argv[*i]) == 0||strcmp("-o", argv[*i]) == 0)
	{
		*i = *i + 1;
		return NULL;
	}
	else
	{
		*j = *j + 1;
		printf("%s\n",argv[*i]);
		return argv[*i];
	}
}