#ifndef LIST_H
#define LIST_H

#include "arvore.h"

typedef struct list tList;

//Inicializa a lista com o noh de arvore no conteudo.
tList* initializeList(tTree*);

//Retorna o noh que eh o conteudo desse ponteiro de lista
tTree* getTree(tList*);

//Ordena a lista pela frequencia dos char's
tList* sortList(tList*);

//Inclui um noh novo no inicio da lista
tList* includeList(tList*, tTree*);

//Renova a lista montando a arvore usando o algoritmo de Huffman
tList* renewList(tList*);

//Libera estrutura lista sem liberar a arvore no item
tList* freeStructureList(tList*);

//Libera a lista e a arvore no seu item
tList* freeList(tList*);

//Imprime folhas
void printListLeafes(tList*);

//Imprime lista com nohs
void printListTree(tList*, FILE*);

#endif /* LIST_H */