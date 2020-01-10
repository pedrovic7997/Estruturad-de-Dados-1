#ifndef ABB_H
#define ABB_H

typedef struct arvore tArvore;

tArvore* criaVazia();

tArvore* cria(int a, tArvore* sae, tArvore* sad);

int vazia(tArvore* arv);

void imprime(tArvore* arv);

tArvore* retira(tArvore* arv, int item);

tArvore* busca(tArvore* arv, int item);

int retornaItemNo(tArvore* arv);

tArvore* insere(tArvore* arv, int item);

tArvore* buscaMaior(tArvore* arv);

tArvore* libera(tArvore* arv);

#endif /* ABB_H */