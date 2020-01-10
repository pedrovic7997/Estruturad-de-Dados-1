#ifndef ARVORE_H
#define ARVORE_H

typedef struct arv Arv;

//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (char c, Arv* e, Arv* d);

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);

//retorna true se a árvore estiver vazia e false 
//caso contrário
int arv_vazia (Arv* a);

//indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence (Arv* a, char c);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

//retorna o pai de um dado no
Arv* arv_pai (Arv* a, char c);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado caracter na arvore 
int ocorrencias (Arv* a, char c);

//retorna o campo informacao de um dado no
char info (Arv* a);

//retorna a altura da arvore
int altura (Arv* a);

#endif /*ARVORE_H*/