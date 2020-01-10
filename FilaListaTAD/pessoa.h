#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

Pessoa* inicializaPessoa(char* nome, int idade, char* enderco);

void apresentaPessoa(Pessoa* pessoa);

int retornaIdade(Pessoa* pessoa);

Pessoa* liberaPessoa(Pessoa* pessoa);

#endif /*PESSOA_H*/