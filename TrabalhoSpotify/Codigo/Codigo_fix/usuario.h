#ifndef USUARIO_H
#define USUARIO_H
#include <stdio.h>

/*tUsuario (tipo opaco). Contem campos:
* - nome (string)
* - amigos (sentinela*)
* - playlists (sentinela*)
* - refatorada (sentinela*)
*/
typedef struct usuario tUsuario;

/*Inicializa um usuario
*
*
*/
tUsuario* inicializaUsuario(char*);

void imprimeAmigosUsuario(tUsuario*);

void imprimePlaylistsUsuario(tUsuario*);

void imprimePlaylistsUsuario(tUsuario*);

void imprimePlaylistUsuario(tUsuario*);

void imprimePlaylistRefatUsuario(char*,tUsuario*);

void imprimePlaylistsRefatUsuario(FILE*,tUsuario*);

int getQtdPlaylistsUser(tUsuario*);

/*
*
*
*/
int comparaNome(tUsuario*, char*);

/*
*
*
*/
void preenchePlaylistUsuario(tUsuario*,FILE*);

/*
*
*
*/
char* retornaNome(tUsuario*);

/*
*
*
*/
void comecaAmizade(tUsuario*,tUsuario*);

/*
*
*
*/
void criaPlaylists(tUsuario*,FILE*);

/*
*
*
*/
void contaSimilares(FILE*, tUsuario*);

/*
*
*
*/
void contabilizaSimilaridadeUsuario(tUsuario*, tUsuario*);

/*
*
*
*/
int comparaPlaylistsUsuario(tUsuario*, tUsuario*);

/*
*
*
*/
void mergeUsuario(tUsuario*);

/*
*
*
*/
void mergePlaylistsUsuario(tUsuario*, tUsuario*);

/*
*
*
*/
void criaPLaylistRefatUser(tUsuario*);

/*
*
*
*/
void zeraSimilaridadeUser(tUsuario*);

/*
*
*
*/
tUsuario* liberaUsuario(tUsuario*);

#endif /* USUARIO_H */
