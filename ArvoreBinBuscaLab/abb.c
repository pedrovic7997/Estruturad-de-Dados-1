#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct arvore{
    int item;
    tArvore* sad;
    tArvore* sae;
};

tArvore* criaVazia(){

    return NULL;

}

tArvore* cria(int a, tArvore* sae, tArvore* sad){

    tArvore* arv = (tArvore*)malloc(sizeof(tArvore));

    arv->item = a;
    arv->sad = sad;
    arv->sae = sae;

    return arv;

}

int vazia(tArvore* arv){

    if(arv == NULL){
        return 1;
    }
    return 0;

}

void imprime(tArvore* arv){

    if(!vazia(arv)){
        imprime(arv->sae);
        printf("%d ", arv->item);
        imprime(arv->sad);
    } else{
        return;
    }

}

tArvore* busca(tArvore* arv, int item){

    tArvore* aux;

    if(!vazia(arv)){
        if(arv->item == item){
            return arv;
        }
        else{
            aux = busca(arv->sae, item);
            if(aux != NULL){
                return aux;
            }

            aux = busca(arv->sad, item);
            if(aux != NULL){
                return aux;
            }

            return NULL;
        }
    }
    return NULL;

}

int retornaItemNo(tArvore* arv){

    return arv->item;

}

tArvore* insere(tArvore* arv, int item){

    if(!vazia(arv)){
        if(arv->item <= item) {
            arv->sad = insere(arv->sad, item);
            return arv;
        } else{
            arv->sae = insere(arv->sae, item);
            return arv;
        }
    } else{
        arv = cria(item, criaVazia(), criaVazia());
        return arv;
    }

}

tArvore* buscaMaior(tArvore* arv){

    //BUSCAR PELO MAIOR ITEM DESSA ARVORE, OU SEJA, O ULTIMO MAIOR ARV->DIR POSSIVEL

    tArvore* aux;

    aux = arv;
    if(!vazia(aux->sad)){
        aux = buscaMaior(aux->sad);
    }

    return aux;

}

tArvore* retira(tArvore* arv, int item){
//        libera folhas e nohs com uma filha, com duas faz a troca e retira folha pos troca

    if(!vazia(arv)){
        if(retornaItemNo(arv) == item){
            if(!vazia(arv->sae) && !vazia(arv->sad)){

                // USAR FUNCAO BUSCAMAIOR DO ARV->SAE

                tArvore* aux, *maior;
                int auxI;

                maior = buscaMaior(arv->sae);

                auxI = maior->item;
                maior->item = arv->item;
                arv->item = auxI;

                if(!vazia(maior->sae)){

                    aux = maior->sae;
                    free(maior);
                    return aux;

                } else{

                    free(maior);

                    return NULL;

                }



            } else if(!vazia(arv->sae)){

                tArvore* aux;

                aux = arv->sae;
                free(arv);

                return aux;

            } else if(!vazia(arv->sad)){

                tArvore* aux;

                aux = arv->sad;
                free(arv);

                return aux;

            } else{

                free(arv);

                return NULL;

            }
        } else if(retornaItemNo(arv) < item){

            arv->sad = retira(arv->sad, item);

        } else if(retornaItemNo(arv) > item){

            arv->sae = retira(arv->sae, item);

        }

        return arv;

    }
    return NULL;

}

tArvore* libera(tArvore* arv){

    if(!vazia(arv)){

        libera(arv->sae);
        libera(arv->sad);
        free(arv);

    }
    return NULL;

}