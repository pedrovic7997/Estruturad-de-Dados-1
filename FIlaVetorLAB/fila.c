#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

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

void imprimepessoa(Pessoa* p){

    printf("NOME: %s, ENDERECO: %s, IDADE: %d", p->nome, p->endereco, p->idade);
    
}

int retorna_idade (Pessoa* p){

    return p->idade;
    
}

Pessoa* liberaPessoa(Pessoa* p){

    free(p->nome);
    free(p->endereco);
    free(p);

    return p;
}

struct fila{
    Pessoa* pessoas[MAX_TAM];
    int inicio;
    int numPessoas;
};

Fila* cria_fila(void){

    Fila* nova;

    nova = (Fila*)malloc(sizeof(Fila));
    nova->inicio = 0;
    nova->numPessoas = 0;

    return nova;
}

void insere (Pessoa* pessoa, Fila* f){

    if(f->numPessoas == MAX_TAM){
        printf("\nPILHA CHEIA\n");
    }
    else{
        f->pessoas[(f->inicio + f->numPessoas) % MAX_TAM] = pessoa;
        f->numPessoas++;
    }
}

Pessoa* retira (Fila* f){

    Pessoa* retirado;
    
    if(f->numPessoas == 0){
        printf("\nPILHA VAZIA\n");
        return NULL;
    }
    else{
        retirado = f->pessoas[f->inicio];
        f->inicio = (f->inicio + 1) % MAX_TAM;
        f->numPessoas--;
    }

    return retirado;
}

void imprime_fila (Fila* f){

    for(int i=0; i<f->numPessoas; i++){
        imprimepessoa(f->pessoas[(i + f->inicio) % MAX_TAM]);
        printf("\n");
    }
    
}

int Vazia_fila (Fila* f){

    if(f->numPessoas == 0){
        return 1;
    }
    else{
        return 0;
    }
    
}

void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){

    Pessoa* nova;
    
    while(!Vazia_fila(f)){
        nova = retira(f);
        if(retorna_idade(nova) >= 60){
            insere(nova, f_maiores);
        }
        else{
            insere(nova, f_menores);
        }
    }

}

Fila* destroi_fila (Fila* f){

    for(int i=0; i<f->numPessoas; i++){
        liberaPessoa(f->pessoas[(f->inicio + i) % MAX_TAM]);
        if(!f->pessoas[(f->inicio + i) % MAX_TAM]){
            printf("\nNAO LIBEROU PESSOA %d\n", i);
        }
    }
    
    free(f);
    if(!f){
        printf("\nNAO LIBEROU FILA\n");
    }

    return f;
}