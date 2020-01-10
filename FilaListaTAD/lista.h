#ifndef LISTA_H
#define LISTA_H
#include "pessoa.h"

#define MAX_TAM 10

typedef struct lista Lista;

Lista* criaLista();

void imprimiLista(Lista* lista);

void insereLista(Lista* lista, Pessoa* pessoa);

Pessoa* retiraLista(Lista* lista);

int qtdPessoas(Lista* lista);

void destroiLista(Lista* lista);

#endif /*LISTA_H*/