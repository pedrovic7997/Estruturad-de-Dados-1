#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define MAX_TAM 10

struct pessoa
{
    char* nome;
    int idade;
    char *endereco;
};

Pessoa* inicializaPessoa(char* nome, int idade, char* endereco){

    Pessoa *nova;

    nova = (Pessoa*)malloc(sizeof(Pessoa));
    nova->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    strcpy(nova->nome, nome);
    nova->endereco = (char*)malloc((strlen(endereco)+1)*sizeof(char));
    strcpy(nova->endereco, endereco);
    nova->idade = idade;

    return nova;
}

struct pilha
{
    int topo;
    Pessoa* itens[MAX_TAM];
};

Pilha* cria_pilha(){

    Pilha *pilha;

    pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = 0;

    return pilha;
}

void push(Pessoa* pessoa, Pilha* pilha){

    if(pilha->topo == MAX_TAM){
        printf("PILHA CHEIA\n");
    }
    else{
        pilha->itens[pilha->topo] = pessoa;
        pilha->topo++;
    }
}

Pessoa* pop(Pilha* pilha){

    if(pilha->topo == 0){
        printf("PILHA VAZIA");
        return NULL;
    }
    else{
        pilha->topo--;
        return pilha->itens[pilha->topo];
    }
}

void imprime_pilha (Pilha* pilha){

    for(int i=0; i<pilha->topo; i++){
        printf("NOME: %s, IDADE: %d, ENDERECO: %s\n", 
            pilha->itens[i]->nome, pilha->itens[i]->idade, pilha->itens[i]->endereco);
    }
}

Pilha* destroi_pilha(Pilha* pilha){

    for(int i=0; i<pilha->topo; i++){
        free(pilha->itens[i]->nome);
        free(pilha->itens[i]->endereco);
    }
    free(pilha);

    return pilha;
}