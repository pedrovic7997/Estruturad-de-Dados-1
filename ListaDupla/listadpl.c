#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadpl.h"

struct tipoitem{
    char *nome, *ender;
    int matricula;
};

struct tipolistadpl{
    TipoItem *item;
    TipoListaDpl *prox;
    TipoListaDpl *ant;
};

TipoListaDpl* Insere (TipoItem* aluno, TipoListaDpl* lista){
    
    TipoListaDpl *nova;

    nova = (TipoListaDpl*)malloc(sizeof(TipoListaDpl));
    nova->prox = lista;
    nova->ant = NULL;
    nova->item = aluno;
    if(lista == NULL){
        return nova;
    }
    else{
        lista->ant = nova;
        return nova;
    }
}

TipoListaDpl* Retira (TipoListaDpl* lista, char* nome){

    TipoListaDpl *p;

    for(p=lista; p!=NULL; p=p->prox){
        if(strcmp(p->item->nome, nome) == 0){
            if(p == lista && p->prox == NULL){
                lista = NULL;
            }
            else if(p->ant == NULL){
                lista = p->prox;
                lista->ant = NULL;
            }
            else if(p->prox == NULL){
                p->ant->prox = NULL;
            }
            else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
            }
            free(p->item->nome);
            free(p->item->ender);
            free(p->item);
            free(p);
            return lista;
        }
    }
    return lista;
}

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){

    TipoItem *item;

    item = (TipoItem*)malloc(sizeof(TipoItem*));
    item->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    item->ender = (char*)malloc((strlen(endereco)+1)*sizeof(char));
    strcpy(item->nome, nome);
    strcpy(item->ender, endereco);
    item->matricula = matricula;
}

void Imprime (TipoListaDpl* lista){

    TipoListaDpl *p;

    for(p=lista; p!=NULL; p=p->prox){
        printf("%s, %s, %d\n", p->item->nome, p->item->ender, p->item->matricula);
    }
}

TipoListaDpl* libera (TipoListaDpl* lista){

    TipoListaDpl *p;

    for(p=lista; p!=NULL; p=lista){
        lista = p->prox;
        free(p->item->nome);
        free(p->item->ender);
        free(p->item);
        free(p);
    }

    return lista;
}