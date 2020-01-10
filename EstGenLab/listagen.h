//
// Created by 2019100132 on 11/11/19.
//

#ifndef LGENERICA_H
#define LGENERICA_H

typedef struct listgen tListgen;

void* insere_lista(tListgen*, void*);

int percorre(tListgen*, int (*callback)(void*, void*), void*);

void* retira_lista(tListgen*, void (*liberaItem)(void*), int (*igualdadeItem)(void*, void*), void*);

void libera_lista(tListgen*, void (*liberaItem)(void*));

#endif // LGENERICA_H
