#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

int main(){

    TipoListaDpl* lista;
    char *nome = {"Pedro"};

    lista = NULL;
    TipoItem *buffer = InicializaTipoItem("Pedro", 123, "Rua do Coqueiro");
    lista = Insere(buffer, lista);
    buffer = InicializaTipoItem("Lenke", 456, "Que eu nao sei");
    lista = Insere(buffer, lista);
    buffer = InicializaTipoItem("Ryan", 789, "Alguma Rua");
    lista = Insere(buffer, lista);
    buffer = InicializaTipoItem("Rogerio", 179, "Perto da Ufes");
    lista = Insere(buffer, lista);
    buffer = InicializaTipoItem("Raphael", 248, "Burgues q mora praia");
    lista = Insere(buffer, lista);
    Imprime(lista);

    lista = Retira(lista, nome);
    printf("\n\nRETIRADO: %s\n", nome);
    Imprime(lista);

    lista = libera(lista);
    if(lista == NULL){
        printf("\n\nLISTA NULL");
    }

    return 0;
}