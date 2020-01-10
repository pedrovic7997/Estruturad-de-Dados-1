#ifndef ARVORE_H
#define ARVORE_H
#include <stdlib.h>
#include <stdio.h>

#include "caracter.h"

typedef struct tree tTree;

//Aloca uma arvore na memoria
tTree* createTree(tTree* ,tTree* ,tCharacter*);

//Retorna NULL
tTree* createEmpty();

//Retorna a soma dos pesos de uma arvore
int getNodeWeight(tTree*);

//Retorna o char q esta na arvore
char getNodeChar(tTree*);

//Escreve a arvore no arquivo mandado por parametro
void writeTree(tTree*,FILE*);

//Le e monta uma arvore a partir de um arquivo
tTree* assembleTree(FILE *);

//Libera a arvore e suas sub-arvores
tTree* freeTree(tTree*);

//Libera a arvore e suas sub-arvores
tTree* freeTreeDescompact(tTree*);

//Percorre toda a arvore e coloca o novo codigo de cada letra, a cada sub-arvore a esquerda adiciona 0
//ao codigo e cada sub-arvore  a direita adiciona 1 no codigo. Usa-se uma função da main para preencher
//o vetor de codigos
void createTreeCode(tTree*, char*, char**,void func(int,char**,char*));

//Retorna qual arvore tem o maior peso
int compareTreeNodeWeight(tTree*, tTree*);

//Escreve o arquivo descompactado a partir de um arquivo compactado
int descompactaArvore(FILE*,FILE*,tTree*,int,unsigned char*);


void freeNoLeafCharacter(tTree*);

#endif /* ARVORE_H */
