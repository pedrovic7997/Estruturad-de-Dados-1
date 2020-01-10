//
// Created by 2019100132 on 11/11/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "lponto.h"

struct ponto{

    float x, y;

};

struct centroGeo{

    tPonto pontoSoma;
    int numPontos;

};

// callbacks para lista generica

int imprime_ponto(void* item, void* dado){

    tPonto* p = (tPonto*)item;

    printf("(%f, %f) ", p->x, p->y);

    return 0;

}
int igualdade_ponto(void* item, void* dado){

    tPonto* p1 = (tPonto*)item;
    tPonto* p2 = (tPonto*)dado;

    if(p1->x == p2->x && p1->y == p2->y){
        return 1;
    }
    return 0;

}
int centroGeometrico(void* item, void* dado){

    tPonto* p = (tPonto*)item;
    tCg* cg = (tCg*)dado;

    cg->pontoSoma.x += p->x;
    cg->pontoSoma.y += p->y;
    cg->numPontos++;

    return 0;

}
void libera_ponto(void* item){

    tPonto* p = (tPonto*)item;

    free(p);

}

// Funcoes gerais para o TAD intermediario

tPonto* cria_ponto(float x, float y){

    tPonto* p = (tPonto*)malloc(sizeof(tPonto));

    p->x = x;
    p->y = y;

    return p;

}

tListgen* insere_lista_ponto(tListgen* l, tPonto* p){

    l = (tListgen*)insere_lista(l, p);

    return l;

}

tPonto* centro_geometrico_lista(tListgen* l){

    tCg cg;
    tPonto* p = (tPonto*)malloc(sizeof(tPonto));

    cg.pontoSoma.x = 0;
    cg.pontoSoma.y = 0;
    cg.numPontos = 0;

    percorre(l, centroGeometrico, &cg);
    cg.pontoSoma.x /= cg.numPontos;
    cg.pontoSoma.y /= cg.numPontos;
    p->x = cg.pontoSoma.x;
    p->y = cg.pontoSoma.y;

    return p;

}

int pertence(tListgen* l, tPonto* p){

    int retorno;

    retorno = percorre(l, igualdade_ponto, p);

    return retorno;

}

void imprime_lista(tListgen* l){

    percorre(l, imprime_ponto, NULL);

}

void libera_lista_ponto(tListgen* l){

    libera_lista(l, libera_ponto);

}

tListgen* retira_lista_ponto(tListgen* l, tPonto* p){

    l = (tListgen*)retira_lista(l, libera_ponto, igualdade_ponto, p);

    return l;

}