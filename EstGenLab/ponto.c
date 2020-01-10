#include <stdio.h>
#include "lponto.h"

int main() {

    float x, y;
    int retorno;
    tPonto* p, *cg;
    tListgen* l = NULL;
    tPonto* pTeste;

    scanf("%f%f", &x, &y); // caso teste: 9 9 3 3 0 0 7.0 3.1 -1 -1
    while(x >= 0 && y >= 0){
        p = cria_ponto(x, y);
        l = insere_lista_ponto(l, p);
        scanf("%f%f", &x, &y);
    }
    imprime_lista(l);
    printf("\n");
    pTeste = cria_ponto(12.0, 38.1);
    retorno = pertence(l, pTeste);
    if(!retorno){
        imprime_ponto(pTeste, NULL);
        printf("nao pertence\n");
        libera_ponto(pTeste);
    } else{
        l = retira_lista_ponto(l, pTeste);
        imprime_lista(l);
    }
    pTeste = cria_ponto(7.0, 3.1);
    retorno = pertence(l, pTeste);
    if(!retorno){
        imprime_ponto(pTeste, NULL);
        printf("nao pertence\n");
    } else{
        l = retira_lista_ponto(l, pTeste);
        imprime_lista(l);
        libera_ponto(pTeste);
    }
    printf("\n");
    cg = centro_geometrico_lista(l);
    libera_ponto(cg);
    imprime_ponto(cg, NULL);
    libera_lista_ponto(l);

    return 0;

}