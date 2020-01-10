#ifndef USUARIOS_H
#define USUARIOS_H

#include "usuario.h"

/*
*
*
*/
typedef struct usuarios tUsuarios;

/*
*
*
*/
tUsuarios* inicializaUsuarios(FILE*);

/*
*
*
*/
void imprimeUsuarios(tUsuarios*);

void imprimeAmigosUsuarios(tUsuarios*);

void imprimePlaylistsUsuarios(tUsuarios*);

void imprimePlaylistsRefatUsuarios(char* path,FILE*,tUsuarios*);

/*
*
*
*/
void insereUsuario(tUsuarios*, tUsuario*);

/*
*
*
*/
tUsuario* buscaUsuario(char*, tUsuarios*);

/*
*
*
*/
void lerAmizade(FILE*, tUsuarios*);

/*
*
*
*/
void similaridades(FILE*, tUsuarios*);

/*
*
*
*/
void preenchePlaylistUsuarios(FILE*, tUsuarios*);

/*
*
*
*/
void criaPLaylistsRefatUsers(tUsuarios*);


/*
*
*
*/
void geraMerge(tUsuarios*);

/*
*
*
*/
void zeraSimilaridades(tUsuarios* usuarios);

/*
*
*
*/
tUsuarios* liberaUsuarios(tUsuarios*);

#endif /* USUARIOS_H */
