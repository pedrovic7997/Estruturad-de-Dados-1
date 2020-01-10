###### MAKEFILE #####

CC=gcc

all: Compacta Descompacta

Compacta: compactador.o arvore.o lista.o bitmap.o caracter.o
	$(CC) -o $@ $^

Descompacta: descompactador.o arvore.o lista.o bitmap.o caracter.o
	$(CC) -o $@ $^

compactador.o: compactador.c
	$(CC) -o $@ -c $<

arvore.o: arvore.c
	$(CC) -o $@ -c $<

descompactador.o: descompactador.c
	$(CC) -o $@ -c $<

lista.o: lista.c
	$(CC) -o $@ -c $<

bitmap.o: bitmap.c
	$(CC) -o $@ -c $<

caracter.o: caracter.c
	$(CC) -o $@ -c $<

clean: 
	rm -rf *.o

mrproper: clean
	rm -rf Compacta Descompacta


