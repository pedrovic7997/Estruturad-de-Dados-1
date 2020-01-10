#include <stdio.h>
#include "abb.h"

int main(){

//    tArvore* arv = cria(6, cria(2, cria(1, criaVazia(), criaVazia()), cria(4,
//            cria(3, criaVazia(), criaVazia()), criaVazia())), cria(8, criaVazia(), criaVazia()));

    tArvore* arv = criaVazia();

//    imprime(arv);
//
//    tArvore* aux;
//    aux = busca(arv, 8);
//    printf("\n%d\n", retornaItemNo(aux));

    arv = insere(arv, 6);
    imprime(arv);

    printf("\n");

    arv = insere(arv, 2);
    imprime(arv);

    printf("\n");

    arv = insere(arv, 1);
    imprime(arv);

    printf("\n");

    arv = insere(arv, 4);
    imprime(arv);

    printf("\n");

    arv = insere(arv, 3);
    imprime(arv);

    printf("\n");

    arv = insere(arv, 8);
    imprime(arv);

    printf("\n");

    arv = retira(arv, 4);
    imprime(arv);

    libera(arv);

    return 0;
}