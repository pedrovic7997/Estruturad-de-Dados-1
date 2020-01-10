//
// Created by 2019100132 on 11/11/19.
//

#ifndef LPONTO_H
#define LPONTO_H

#include "listagen.h"

typedef struct ponto tPonto;
typedef struct centroGeo tCg;

// callbacks para lista generica

int imprime_ponto(void*, void*);
int igualdade_ponto(void*, void*);
int centroGeometrico(void*, void*);
void libera_ponto(void*);

// Funcoes gerais para o TAD intermediario

tPonto* cria_ponto(float, float);

tListgen* insere_lista_ponto(tListgen*, tPonto*);

tPonto* centro_geometrico_lista(tListgen*);

int pertence(tListgen*, tPonto*);

void imprime_lista(tListgen*);

void libera_lista_ponto(tListgen*);

void libera_CG(tCg*);

tListgen* retira_lista_ponto(tListgen*, tPonto*);

#endif // LPONTO_H
