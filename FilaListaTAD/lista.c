#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct celula Celula;

struct celula{
    Celula* prox;
    Pessoa* item;
};

struct lista{
    Celula* inicio;
    Celula* fim;
    int qtd;
};

Lista* criaLista(){

    Lista* nova;

    nova = (Lista*)malloc(sizeof(Lista));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qtd = 0;

    return nova;
}

void imprimiLista(Lista* lista){

    Celula* p;

    for(p=lista->inicio; p!=NULL; p=p->prox){
        apresentaPessoa(p->item);
        printf("\n");
    }

}

void insereLista(Lista* lista, Pessoa* pessoa){

    Celula* p;

    if(lista->qtd == MAX_TAM){
        printf("LISTA CHEIA\n");
    }
    else if(lista->qtd == 0){
        p = (Celula*)malloc(sizeof(Celula));
        p->item = pessoa;
        p->prox = NULL;
        lista->inicio = p;
        lista->fim = lista->inicio;
        lista->qtd++;
    }
    else{
        p = (Celula*)malloc(sizeof(Celula));
        p->item = pessoa;
        p->prox = NULL;
        lista->fim->prox = p;
        lista->fim = p;
        lista->qtd++;
    }

}

Pessoa* retiraLista(Lista* lista){

    Pessoa* retirado;

    if(lista->inicio == NULL){
        printf("LISTA VAZIA\n");

        return NULL;
    }
    else{
        retirado = lista->inicio->item;
        lista->inicio = lista->inicio->prox;
        lista->qtd--;

        return retirado;
    }
}

int qtdPessoas(Lista* lista){

    return lista->qtd;
}

void destroiLista(Lista* lista){

    Celula* p, *pprox;

    for(p=lista->inicio; p!=NULL; p=pprox){
        pprox = p->prox;
        liberaPessoa(p->item);
        free(p);
    }
}