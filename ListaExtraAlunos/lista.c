#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct aluno
{
    char *nome;
    int matricula;
};

typedef struct celula TCelula;

struct celula
{
    TAluno *item;
    TCelula *prox;
};


struct lista
{
    TCelula *inicio;
    TCelula *fim;
};

TLista* InicializaLista(){

    TLista *lista;

    lista = (TLista*)malloc(sizeof(TLista));
    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

TAluno* InicializaAluno(char* nome, int matricula){

    TAluno *aluno;

    aluno = (TAluno*)malloc(sizeof(TAluno));
    aluno->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    aluno->nome = nome;
    aluno->matricula = matricula;

    return aluno;
}

void Insere (TLista* lista, TAluno* aluno){

    TCelula *celula;
    
    celula = (TCelula*)malloc(sizeof(TCelula));
    celula->item = aluno;
    celula->prox = NULL;
    if(lista->inicio == NULL){
        lista->fim = lista->inicio = celula;
    }
    else{
        celula->prox = lista->inicio;
        lista->inicio = celula;
    }
}

TAluno* Retira (TLista* lista, int mat){

    TCelula *p, *ant;

    for(p=lista->inicio; p!=NULL && p->item->matricula != mat; p=p->prox){
        ant = p;
    }
    if(p == NULL){
        if(lista->inicio == NULL){
            printf("Lista vazia\n");
        }
        else{
            printf("Nao achou\n");
        }
        return NULL;
    }
    else if(p == lista->inicio){
        lista->inicio = p->prox;
        p->prox = NULL;
    }
    else if(p == lista->fim){
        lista->fim = ant;
        ant->prox = NULL;
    }
    else{
        ant->prox = p->prox;
        p->prox = NULL;
    }
    return p->item;
}

void RetiraRepetidos (TLista* lista){

    TCelula *p1, *p2, *ant;

    for(p1=lista->inicio; p1!=lista->fim; p1=p1->prox){
        for(p2=p1->prox; p2!=NULL; p2=ant->prox){
            if(p1->item->matricula == p2->item->matricula){
                if(p2 == lista->fim){
                    lista->fim = ant;
                }
                ant->prox = p2->prox;
                p2->prox = NULL;
                free(p2);
            }
            ant = p2;
        }
    }

}

TLista* Merge (TLista* turma1, TLista* turma2){

    TLista *mix;
    TCelula *p1, *p2, *pc, *pn;
    int chave = 0;

    mix = InicializaLista();
    p1 = turma1->inicio;
    p2 = turma2->inicio;
    pc = (TCelula*)malloc(sizeof(TCelula));
    pc->prox = NULL;
    mix->inicio = pc;

    while(p1 != NULL || p2 != NULL)
    {
        if(p1 != NULL && chave == 0){
            pc->item = p1->item;
            p1 = p1->prox;
            if(p2 != NULL){
                chave = !chave;
            }
        }
        else if(p2 != NULL && chave == 1){
            pc->item = p2->item;
            p2 = p2->prox;
            if(p1 != NULL){
                chave = !chave;
            }
        }
        if(p1 != NULL || p2 != NULL){
            pn = (TCelula*)malloc(sizeof(TCelula));
            pn->prox = NULL;
            pc->prox = pn;
            pc = pn;
        }
    }

    mix->fim = pc;

    return mix;
}

void LiberaAluno (TAluno* aluno){

    free(aluno->nome);
    free(aluno);
    
}

void Imprime (TLista* lista){

    TCelula *p;
    if(lista->inicio != NULL){
        for(p=lista->inicio; p!=NULL; p=p->prox){
            printf("NOME: %s, MATRICULA: %d\n", p->item->nome, p->item->matricula);
        }
    }
}

void Libera (TLista* lista){

    TCelula *p;

    for(p=lista->inicio; p!=NULL; p=lista->inicio){
        lista->inicio = p->prox;
        LiberaAluno(p->item);
        free(p);
    }
    free(lista);

}