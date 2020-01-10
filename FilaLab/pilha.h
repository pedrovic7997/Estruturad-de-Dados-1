#ifndef PILHA_H_
#define PILHA_H_

/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - endereco (string)
  */
typedef struct pessoa Pessoa;


/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Pessoas
*/
typedef struct pilha Pilha;


/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P está definida e vazia
*/
Pilha* cria_pilha();

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da função, a pilha tem E como o elemento
do topo
*/
void push(Pessoa* pessoa, Pilha* pilha);


/*Retira uma Pessoa do topo da Pilha (se pilha não vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha não é nula e não é vazia
* pos-condicao: pilha não contém o elemento retirado do topo
*/
Pessoa* pop(Pilha* pilha);


/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha não é nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* pilha);

/*Verifica se a pilha estah vazia
* inputs: a Pilha
* output: 1 (se vazia), 0 (caso contrario)
* pre-condicao: Pilha não é nula
* pos-condicao: Pilha permanece inalterada
*/
int vazia_pilha (Pilha* pilha);


/*Retorna o numero de elementos da pilha
* inputs: a Pilha
* output: o numero de elementos da pilha
* pre-condicao: Pilha não é nula
* pos-condicao: Pilha permanece inalterada
*/
int tamanho_pilha (Pilha* pilha);


/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco);


/*Imprime as pessoas da pilha
* inputs: a pilha
* output: nenhum
* pre-condicao: pilha P não vazia
* pos-condicao: Pilha permanece inalterada
*/
void imprime_pilha (Pilha* pilha);


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

#endif /* PILHA_H_ */