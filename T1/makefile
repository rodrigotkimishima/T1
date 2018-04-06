cc = gcc -Wall -Wextra -pedantic -ansi -g
o = getargs.o commands.o string.o file.o concatena.o
t1: $(o)
	$(cc) main.c $(o) -o t1

getargs.o: getargs.c getargs.h
	$(cc) -c getargs.c

commands.o: commands.c commands.h
	$(cc) -c commands.c

string.o: string.c string.h
	$(cc) -c string.c

file.o: file.c file.h
	$(cc) -c file.c

concatena.o: concatena.c concatena.h
	$(cc) -c concatena.c
	
clean:
	rm -rf *.o
	rm -rf *.gch
