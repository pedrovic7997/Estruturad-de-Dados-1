#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    Lista* itens;
};

Fila* cria_fila(void){
    
    Fila* nova;

    nova = (Fila*)malloc(sizeof(Fila));
    nova->itens = criaLista();

    return nova;
}

void insere (Pessoa* pessoa, Fila* f){

    insereLista(f->itens, pessoa);

}

Pessoa* retira (Fila* f){
    
    Pessoa* retirado;

    retirado = retiraLista(f->itens);

    return retirado;
}

void imprime_fila (Fila* f){

    imprimiLista(f->itens);

}

int Vazia_fila (Fila* f){

    if(qtdPessoas(f->itens) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){
    
    Pessoa* retirada;

    while(!Vazia_fila(f)){
        retirada = retira(f);
        if(retornaIdade(retirada) >= 60){
            insere(retirada, f_maiores);
        }
        else{
            insere(retirada, f_menores);
        }
    }

}

Fila* destroi_fila (Fila* f){

    destroiLista(f->itens);
    free(f);

}