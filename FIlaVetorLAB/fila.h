#ifndef FILA_H_
#define FILA_H_

/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - endereco (string)
  */
typedef struct pessoa Pessoa;

/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco);

Pessoa* liberaPessoa(Pessoa* p);


/*Tipo que define a fila (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Usar como base o TAD Pilha (pilha.h) - não usar outra estrutura de dados
  */
typedef struct fila Fila;

/*Cria uma fila vazia, usando pilha
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia*/
Fila* cria_fila(void);

/*Insere uma pessoa na fila de Pessoas (lembre-se, fila e' FIFO). Imprime mensagem de erro caso a fila esteja cheia.
* inputs: pessoa a ser inserida na fila (do tipo pessoa) e a fila
* output: nenhum 
* pre-condicao: pessoa e fila não são nulos
* pos-condicao: fila contém a pessoa inserida na ultima posição*/
void insere (Pessoa* pessoa, Fila* f);

/*Retira uma pessoa da fila (usando FIFO). Imprime mensagem de erro caso a fila esteja vazia.
* inputs: a fila
* output: a Pessoa (do tipo Pessoa) retirada da Fila (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila não é nula
* pos-condicao: fila não contém a pessoa que estava na primeira posicao */
Pessoa* retira (Fila* f);


/*Imprime os dados de todos as pessoas da fila (do inicio ao fim da fila!). Imprime mensagem de fila vazia, caso a fila esteja vazia.
* inputs: a fila de pessoas
* output: nenhum
* pre-condicao: fila não é nula
* pos-condicao: dados dos pessoas impressos na saida padrao
*/
void imprime_fila (Fila* f);

/*Imprime os dados de uma pessoa
* inputs: Uma estrutura pessoa
* output: nenhum
* pre-condicao: Pessoa P não nula
* pos-condicao: Os dados da pessoa permanecem inalterados
*/
void imprimepessoa(Pessoa* p);

/*Retorna a idade de uma pessoa
* inputs: Uma estrutura pessoa
* output: nenhum
* pre-condicao: Pessoa P não nula
* pos-condicao: Os dados da pessoa permanecem inalterados
*/
int retorna_idade (Pessoa* p);


/*Verifica se a fila esta ou nao vazia
* inputs: a fila de pessoas
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila não é nula
* pos-condicao: nenhuma
*/
int Vazia_fila (Fila* f);


/*Separa a fila f de tal forma que as pessoas com idade maior que 60 sejam movidas para a fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores".
* inputs: a fila de pessoas, as filas f_maiores e f_menores (inicialmente vazias)
* output: nao tem
* pre-condicao: fila f não é nula
* pos-condicao: fila f vazia, pessoas com idade maior ou igual a 60 na fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores" */
void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores);


/*Libera toda a memória utilizada pelas estruturas de dados.
* inputs: a fila de pessoas
* output: NULL
* pre-condicao: fila f não é nula
* pos-condicao: Memória liberada */
Fila* destroi_fila (Fila* f);


#endif /* FILA_H_ */