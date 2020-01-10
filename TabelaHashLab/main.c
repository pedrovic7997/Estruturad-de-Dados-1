#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NTAB 127

struct palavra{
    char* palavra;
    int n;
    struct palavra* prox;
};
typedef struct palavra tPalavra;

typedef tPalavra* Hash[NTAB];

void inicializaHash(Hash tab) {

    for (int i = 0; i < NTAB; i++)
        tab[i] = NULL;

    return;
}

int hash(char* s){

    int total = 0;

    for(int i=0; s[i]!='\0'; i++)
        total += s[i];

    return (total % NTAB);
}

tPalavra* acessa(Hash tab, char* s){

    tPalavra* p;
    int h = hash(s);

    for(p = tab[h]; p!=NULL; p = p->prox){
        if(strcmp(s, p->palavra)){
            return p;
        }
    }

    p = (tPalavra*)malloc(sizeof(tPalavra));
    strcpy(p->palavra, s);
    p->n = 0;
    p->prox = tab[h];
    tab[h] = p;

    return p;
}

/* le palavra

conta palavaras da hash

cria vetor de palavra com o tamanho da funcao conta */

int compara(const void* v1, const void* v2){ //Compara callback para qsort

    tPalavra** p1 = (tPalavra**) v1;
    tPalavra** p2 = (tPalavra**) v2;

    if((*p1)->n > (*p2)->n)
        return -1;
    else if((*p1)->n < (*p2)->n)
        return 1;
    else
        return strcmp((*p1)->palavra, (*p2)->palavra);

}

void imprime(Hash tab){

    int i;
    int n;

    n = conta(tab)

    vet = criaVet(tab, n);

    qsort(vet, n , sizeof(tPalavra), compara);

    for(){
        //print
    }

}

int main() {
    printf("Hello, World!\n");
    return 0;
}