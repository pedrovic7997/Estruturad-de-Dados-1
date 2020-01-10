#ifndef AMIGOS_H
#define AMIGOS_H
#include "usuario.h"

/*
*
*
*/
typedef struct amigos tAmigos;

/*
*
*
*/
tAmigos* inicializaAmigos();

/*
*
*
*/
void imprimeAmigos(tAmigos*);

/*Adiciona o usario 1 na lista de amigos do usuario 2 e o usuario 2 na lista do usuario 1
*input: Lista de usarios e os usuarios
*
*/
void criaAmizade(tAmigos* listaUser1,tAmigos* listaUser2,tUsuario* user1,tUsuario* user2);

/*
*
*
*/
void contaMusicasAmigos(FILE*, tUsuario*, tAmigos*);

/*
*
*
*/
void zeraSimilaridade(tAmigos*);

/*
*
*
*/
void contabilizaSimilaridade(char*, tAmigos*);

/*
*
*
*/
void mergeAmigos(tUsuario*, tAmigos*);

/*
*
*
*/
int contaAmigos(tAmigos*);

/*
*
*
*/
int getSimilaridade(tUsuario* ,tUsuario*,tAmigos*);

/*
*
*
*/
tAmigos* liberaAmigos(tAmigos*);

#endif /* AMIGOS_H */
