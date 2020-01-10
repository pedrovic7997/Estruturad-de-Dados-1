#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct pessoa{
    char* nome;
    char* endereco;
    int idade;
};

Pessoa* inicializaPessoa(char* nome, int idade, char* enderco){

    Pessoa* nova;

    nova = (Pessoa*)malloc(sizeof(Pessoa));
    /* nova = (char*)malloc((strlen(nome)+1)*sizeof(char));
    nova = (char*)malloc((strlen(enderco)+1)*sizeof(char)); */
    nova->nome = strdup(nome);
    nova->endereco = strdup(enderco);
    nova->idade = idade;

    return nova;
}

void apresentaPessoa(Pessoa* pessoa){

    printf("NOME: %s, IDADE: %d, ENDERECO: %s", 
            pessoa->nome, pessoa->idade, pessoa->endereco);
    
}

int retornaIdade(Pessoa* pessoa){

    return pessoa->idade;
}

Pessoa* liberaPessoa(Pessoa* pessoa){

    free(pessoa->nome);
    free(pessoa->endereco);
    free(pessoa);

    return pessoa;
}