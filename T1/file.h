#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "getargs.h"
#include "concatena.h"

/*
Função Para Abrir o Arquivo De Entrada

*path = Arquivo De Entrada a Ser Aberto
*/
FILE *Open_Commands(char *path);

FILE *Create_File(char *n_arq,char *n_arq_type,char *dir,char *type_ofopen);

void close_file(FILE *arq);

#endif
