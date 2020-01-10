//
// Created by 2019100132 on 11/11/19.
//

#include <stdlib.h>
#include "listagen.h"

struct listgen{

    void* item;
    tListgen* prox;

};

void* insere_lista(tListgen* l, void* item) {

    tListgen* nova = (tListgen*)malloc(sizeof(tListgen));

    nova->item = item;
    nova->prox = l;

    return nova;
}

int percorre(tListgen* l, int (*callback)(void*, void*), void* dado) {

    tListgen* t;
    int retorno;

    for (t=l; t!=NULL; t=t->prox) {
        retorno = callback(t->item, dado);
        if(retorno != 0){
            return retorno;
        }
    }

    return 0;
}

void* retira_lista(tListgen* l, void (*liberaItem)(void*), int (*igualdadeItem)(void*, void*), void* dado) {

    tListgen* t, *aux;

    t = l;
    while (t!=NULL) { // PODIA SER 'FOR'

        if(igualdadeItem(t->item, dado) == 1){
            aux = t;
            t = t->prox;
            liberaItem(aux->item);
            if(aux == l){
                free(aux);
                return t;
            }
            free(aux);
            return l;
        }

        t = t->prox;
    }

    return l;
}

void libera_lista(tListgen* l, void (*liberaItem)(void*)) {

    tListgen* p;

    while (l){
        p = l->prox;
        liberaItem(l->item);
        free(l);
        l = p;
    }

    return;
}


