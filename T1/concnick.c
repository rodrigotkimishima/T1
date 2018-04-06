#include "concatena.h"

int main(int argc,char *argv[])
{
	char *x;
	int i;
	x = alloc_inicial();
	for(i = 1; i < argc; i++)
	{
		x = concatena(x,argv[i]);
		printf("Variavel De X = %s\n",x);
	}
	return 0;
}

char *limpa(char *x) {
  free(x);
  return alloc_inicial();
}

char *alloc_inicial() {
  char *str;
  str = malloc(sizeof(char));
  *str = 0;
  return str;
}

char *concatena(char *inicio, char *fim) {
  inicio = (char *) realloc(inicio, sizeof(char) * (strlen(inicio) + strlen(fim) + 1));
  strcat(inicio, fim);
  return inicio;
}