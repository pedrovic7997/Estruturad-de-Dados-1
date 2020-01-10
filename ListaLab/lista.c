#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct tipoitem{
    char *nome;
    char *endereco;
    int matricula;
};

typedef struct celula TCelula;

struct celula{
    TCelula *prox;
    TipoItem *item;
};

struct tipolista{
    TCelula *ini;
    TCelula *fim;
};

TipoLista* InicializaLista(){
    
    TipoLista *lista;

    lista = (TipoLista*)malloc(sizeof(TipoLista));
    lista->ini = NULL;
    lista->fim = NULL;

    return lista;
}

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){

    TipoItem *aluno = (TipoItem*)malloc(sizeof(TipoItem));

    aluno->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    strcpy(aluno->nome, nome);

    aluno->matricula = matricula;

    aluno->endereco = (char*)malloc((strlen(endereco)+1)*sizeof(char));
    strcpy(aluno->endereco, endereco);

    return aluno;
}

void Insere (TipoItem* aluno, TipoLista* lista){

    TCelula* celula;

    celula = (TCelula*)malloc(sizeof(TCelula));
    celula->item = aluno;
    celula->prox = lista->ini;
    lista->ini = celula;

    if(lista->fim == NULL){
        lista->fim = celula;
    }
}

void Imprime (TipoLista *lista){

    TCelula *p;

    p = lista->ini;
    while(p != NULL){
        printf("Nome: %s, Matricula: %d e Endereco: %s\n",
                 p->item->nome, p->item->matricula, p->item->endereco);
        p = p->prox;
    }// OU for(p=lista->ini; p!=NULL; p=p->prox)
}

TipoItem* Retira (TipoLista* lista, int mat){

    TCelula *p, *a;
    TipoItem *retirado;

    /*if(lista->ini != NULL){
        p = a = lista->ini;
        if(a->prox != NULL && a->item->matricula != mat){
            p = p->prox;
        }
    }*/
    p = lista->ini;
    while(p != NULL && p->item->matricula != mat){
        a = p;
        p = p->prox;
    }
    if(p != NULL && p->item->matricula == mat){
        //bypass
        a->prox = p->prox;
        if(p == lista->fim){
            lista->fim = a;
        }
        if(p == lista->ini){
            lista->ini = p->prox;
        }
        retirado = p->item;
        free(p);
        return retirado;
    }
    else{
        retirado = NULL;
        return retirado;
    }
    
}

TipoLista* Libera (TipoLista* lista){

    TCelula *p, *a;

    p=lista->ini;
    while(p!=lista->fim){
        //bypass
        a = p;
        p=p->prox;
        //free aluno
        free(a->item->nome);
        free(a->item->endereco);
        free(a->item);
        free(a);
    }
    
    lista->fim = NULL;

    free(p->item->nome);
    free(p->item->endereco);
    free(p->item);
    free(p);

    return NULL;
}