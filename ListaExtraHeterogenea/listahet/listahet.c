#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

#define IMOVEL 0
#define MOVEL 1

struct cliente
{
    char *nome;
    int id;
};

Cliente* cria_cliente (char* nome, int id){

    Cliente *novo;

    novo = (Cliente*)malloc(sizeof(Cliente));
    novo->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    strcpy(novo->nome, nome);
    novo->id = id;

    return novo;
}

void liberaCliente(Cliente* cliente){

    free(cliente->nome);
    free(cliente);

}

struct movel
{
    int placa;
    int ano;
    float valor;
};

struct imovel
{
    int id;
    int ano;
    float valor;
};

Movel* cria_movel (int placa, int ano, float valor){

    Movel *novo;

    novo = (Movel*)malloc(sizeof(Movel));
    novo->placa = placa;
    novo->ano = ano;
    novo->valor = valor;

    return novo;
}

Imovel* cria_imovel (int id, int ano, float valor){

    Imovel *novo;

    novo = (Imovel*)malloc(sizeof(Imovel));
    novo->id = id;
    novo->ano = ano;
    novo->valor = valor;

    return novo;
}

void liberaItem(void* item){

    free(item);

}

struct listahet
{
    Cliente *dono;
    void* item;
    ListaHet *prox;
    int tag;
};

ListaHet* cria (){

    ListaHet *lista;

    lista = (ListaHet*)malloc(sizeof(ListaHet));
    lista = NULL;

    return lista;
}

ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item){

    ListaHet *p;

    p = (ListaHet*)malloc(sizeof(ListaHet));
    p->dono = dono;
    p->tag = MOVEL;
    p->item = (Movel*)item;
    p->prox = lista;
    lista = p;

    return lista;
}

ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item){

    ListaHet *p;

    p = (ListaHet*)malloc(sizeof(ListaHet));
    p->dono = dono;
    p->tag = IMOVEL;
    p->item = (Imovel*)item;
    p->prox = lista;
    lista = p;

    return lista;
}

void imprime (ListaHet* lista){

    ListaHet *p;
    
    for(p=lista; p!=NULL; p=p->prox){
        if(p->tag == MOVEL){
            printf("NOME: %s, ID: %d, MOVEL:: PLACA: %d, ANO: %d, VALOR: %.2f\n", 
                p->dono->nome, p->dono->id, ((Movel*)p->item)->placa, 
                ((Movel*)p->item)->ano, ((Movel*)p->item)->valor);
        }
        else{
            printf("NOME: %s, ID: %d, IMOVEL:: IDENTIF: %d, ANO: %d, VALOR: %.2f\n", 
                p->dono->nome, p->dono->id, ((Imovel*)p->item)->id, 
                ((Imovel*)p->item)->ano, ((Imovel*)p->item)->valor);
        }
    }
}

ListaHet* retira_cliente (ListaHet* lista, int id_cliente){

    ListaHet *p, *ant;

    for(p=lista, ant = lista; p!=NULL; p=p->prox){
        if(p->dono->id == id_cliente){
            ant->prox = p->prox;
            liberaCliente(p->dono);
            liberaItem(p->item);
        }
        ant = p;
    }
    
    return lista;
}

float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel){

    ListaHet *p;
    float soma = 0;

    for(p=lista; p!=NULL; p=p->prox){
        if(strcmp(p->dono->nome, dono->nome) == 0){
            switch (p->tag)
            {
                case MOVEL:
                soma += ((Movel*)p->item)->valor * taxa_movel;
                break;
            
                case IMOVEL:
                soma += ((Imovel*)p->item)->valor * taxa_imovel;
                break;
            }
        }
    }

    return soma;
}