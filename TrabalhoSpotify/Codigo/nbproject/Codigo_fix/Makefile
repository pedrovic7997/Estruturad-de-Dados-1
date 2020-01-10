# all
all: PlayED

PlayED: amigos.o musica.o playlist.o usuario.o usuarios.o main.o
	gcc *.o -o PlayED
amigos.o: amigos.c
	gcc amigos.c -c
musica.o: musica.c
	gcc musica.c -c
playlist.o: playlist.c
	gcc playlist.c -c
usuario.o: usuario.c
	gcc usuario.c -c
usuarios.o: usuarios.c
	gcc usuarios.c -c
main.o: main.c
	gcc main.c -c
clean:
	rm -rf *.o
rmproper: clean
	rm -rf PlayED
	
run: PlayED
	./PlayED
rmSaida: 
	rmdir Saida -r
