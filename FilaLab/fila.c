#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

#define MAX_TAM 10

struct fila{
    Pilha *p;
    Pilha *aux;
};

Fila* cria_fila(void){

    Fila* nova;

    nova = (Fila*)malloc(sizeof(Fila));
    nova->p = cria_pilha();
    nova->aux = cria_pilha();

    return nova;
}

void insere (Pessoa* pessoa, Fila* f){

    if(tamanho_pilha(f->p) == MAX_TAM){
        printf("\nPILHA CHEIZ\n");
    }
    else{
        push(pessoa, f->p);
    }
}

Pessoa* retira (Fila* f){

    Pessoa* retirado;
    
    if(vazia_pilha(f->p)){
        printf("\nPILHA VAZIA\n");
        return NULL;
    }
    else{
        while(!vazia_pilha(f->p)){
            push(pop(f->p), f->aux);
        }
        retirado = pop(f->aux);
        while(!vazia_pilha(f->aux)){
            push((pop(f->aux)),f->p);
        }
    }

    return retirado;
}

void imprime_fila (Fila* f){

    while(!vazia_pilha(f->p)){
        push(pop(f->p), f->aux);
    }
    imprime_pilha(f->aux);
    while(!vazia_pilha(f->aux)){
        push(pop(f->aux), f->p);
    }
    
}

int Vazia_fila (Fila* f){

    if(vazia_pilha(f->p)){
        return 1;
    }
    else{
        return 0;
    }
    
}

void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){

    Pessoa* nova;
    
    while(!Vazia_fila(f)){
        nova = pop(f->p);
        if(retorna_idade(nova) >= 60){
            push(nova, f_maiores->p);
        }
        else{
            push(nova, f_menores->p);
        }
    }

}

Fila* destroi_fila (Fila* f){

    f->p = destroi_pilha(f->p);
    if(!f->p){
        printf("\nNAO LIBEROU P\n");
    }
    f->aux = destroi_pilha(f->aux);
    if(!f->aux){
        printf("\nNAO LIBEROU AUX\n");
    }
    free(f);
    if(!f){
        printf("\nNAO LIBEROU F\n");
    }

    return f;
}