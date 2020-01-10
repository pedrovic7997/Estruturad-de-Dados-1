#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arv
{
    char item;
    Arv* sae;
    Arv* sad;
};

Arv* arv_criavazia (void){

    return NULL;

}

Arv* arv_cria (char c, Arv* e, Arv* d){

    Arv* a = (Arv*)malloc(sizeof(Arv));

    a->item = c;
    a->sad = d;
    a->sae = e;

    return a;

}

Arv* arv_libera (Arv* a){

    if(a == NULL){
        return a;
    }
    
    arv_libera(a->sad);
    arv_imprime(a->sae);

    free(a);

    return a;

}

int arv_vazia (Arv* a){

    if(a == NULL){
        return 1;
    }
    return 0;

}

int arv_pertence (Arv* a, char c){

    if(!arv_vazia(a)){
        if(a->item == c){
            return 1;
        }
        return arv_pertence(a->sae, c) || arv_pertence(a->sad, c);
    }

    return 0;

}

void arv_imprime (Arv* a){

    if(!arv_vazia(a)){
        printf("< %c", a->item);
        arv_imprime(a->sae);
        printf(">");
        arv_imprime(a->sad);
        printf(">");
        return;
    }
    printf("<>");
    return;

}

Arv* arv_pai (Arv* a, char c){

    if(!arv_vazia(a)){
        if(info(a->sae) == c || info(a->sad) == c){
            return a;
        }
        return arv_pai(a->sae, c) || arv_pai(a->sad, c);
    }
    return NULL;

}

int folhas (Arv* a){

    int i;

    if(!arv_vazia(a)){
        i+=folhas(a->sae) + folhas(a->sad);
    }
    return 1;

}

int ocorrencias (Arv* a, char c){

    int i;

    if(!arv_vazia(a)){
        if(a->item == c){
            return 1 + ocorrencias(a->sae, c) + ocorrencias(a->sad, c);
        }
        return ocorrencias(a->sae, c) + ocorrencias(a->sad, c);
    }
    return 0;

}

char info (Arv* a){

    return a->item;

}

