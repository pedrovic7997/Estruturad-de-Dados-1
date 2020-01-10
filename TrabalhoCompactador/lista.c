#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct list
{
    tTree* item;
    tList* next;
};

tList* initializeList(tTree* tree){

    tList* list = (tList*)malloc(sizeof(tList));

    list->item = tree;
    list->next = NULL;

    return list;

}

tTree* getTree(tList* list){

    return list->item;

}

tList* sortList(tList* list){

    tList* p, *limit;
    tTree *aux;
    int swapped;

    if(!list)
        return list;
    
    limit = NULL;
    swapped = 1;
    while(swapped){
        p = list;
        swapped = 0;
        while (p->next != limit){
            if(compareTreeNodeWeight(p->item, p->next->item) > 0){
                aux = p->next->item;
                p->next->item = p->item;
                p->item = aux;
                swapped = 1;
            }
            p = p->next;
        }
        limit = p;
    }
    
    return list;

}

tList* includeList(tList* list, tTree* new){

    tList* p = initializeList(new);

    p->next = list;
    list = p;

    return p;

}

tList* renewList(tList* list){

    tTree* tNew;
    tCharacter* cNew;
    tList* aux1, *aux2;

    while(list->next){
        cNew = initializeCharacter(0, 
                getNodeWeight(list->item) + getNodeWeight(list->next->item));
        tNew = createTree(list->item, list->next->item, cNew);
        // Auxiliares para liberar a estrutura sem perder o conteudo
        aux1 = list;
        aux2 = list->next;
        list = list->next->next;
        freeStructureList(aux1);
        freeStructureList(aux2);
        list = includeList(list, tNew);
        list = sortList(list);
    }
    return list;

}

tList* freeStructureList(tList* list){

    free(list);

    return NULL;

}

tList* freeList(tList* list){
    freeTree(list->item);
    free(list);

    return NULL;

}

void printListLeafes(tList* list){

    tList* p;

    for(p=list; p!=NULL; p=p->next){
        printf("%c - %d\n", getNodeChar(p->item), getNodeWeight(p->item));
    }

}

void printListTree(tList* list, FILE* file){

    writeTree(list->item, file);
    fprintf(file,"\n");

}