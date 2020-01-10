#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amigos.h"
#include "usuario.h"
#include "usuarios.h"
#include "playlist.h"
#include "musica.h"

typedef struct celAmigos tCelAmigos;

struct celAmigos
{
    tUsuario* amigo;
    int flagSimilar;
    tCelAmigos* prox;
};

tCelAmigos* inicializaCelAmigo(tUsuario* user){

    tCelAmigos* nova = (tCelAmigos*)malloc(sizeof(tCelAmigos));

    nova->amigo = user;
    nova->prox = NULL;
    nova->flagSimilar=0;

    return nova;

}

tCelAmigos* liberaCelAmigos(tCelAmigos* celula){

    free(celula);

    return celula;

}

struct amigos
{
    tCelAmigos* inicio;
    tCelAmigos* fim;
};

tAmigos* inicializaAmigos(){

    tAmigos* amigos = (tAmigos*)malloc(sizeof(tAmigos));

    amigos->inicio = NULL;
    amigos->fim = NULL;

    return amigos;

}

void imprimeAmigos(tAmigos* friends){

    tCelAmigos* p;
    char* nome;

    for(p=friends->inicio; p!=NULL; p=p->prox){
        nome = retornaNome(p->amigo);
        printf("%s -> ", nome);
    }

}

void criaAmizade(tAmigos* listaUser1,tAmigos* listaUser2,tUsuario* user1,tUsuario* user2){

    tCelAmigos* cel;

    cel = inicializaCelAmigo(user2);
    if(listaUser1->inicio == NULL){
        listaUser1->inicio = cel;
        listaUser1->fim = cel;
    }
    else{
        listaUser1->fim->prox = cel;
        listaUser1->fim = cel;
    }

    cel = inicializaCelAmigo(user1);
    if(listaUser2->inicio == NULL){
        listaUser2->inicio = cel;
        listaUser2->fim = cel;
    }
    else{
        listaUser2->fim->prox = cel;
        listaUser2->fim = cel;
    }

}

void contaMusicasAmigos(FILE* arq, tUsuario* user, tAmigos* userFriends){

    tCelAmigos* friend;
    int i;

    for(friend=userFriends->inicio; friend!=NULL; friend=friend->prox){
        
        if(friend->flagSimilar == 0)
        {
            friend->flagSimilar = 1;
            contabilizaSimilaridadeUsuario(user, friend->amigo);
            i = comparaPlaylistsUsuario(user, friend->amigo);
            fprintf(arq, "%s;%s;%d\n", retornaNome(user), retornaNome(friend->amigo), i);
        }

    }
}

void zeraSimilaridade(tAmigos* amigos){
    for(tCelAmigos* i=amigos->inicio;i!=NULL;i=i->prox){
        i->flagSimilar=0;
    }
}

int getSimilaridade(tUsuario* user,tUsuario* friend,tAmigos* userFriendList){
    tCelAmigos* i;
    for(i=userFriendList->inicio;i!=NULL;i=i->prox){
        if(!comparaNome(friend,retornaNome(i->amigo))){
            return i->flagSimilar;
        }
    }
}

void contabilizaSimilaridade(char* userName, tAmigos* friendFriends){

    tCelAmigos* p;

    for(p=friendFriends->inicio; p!=NULL; p=p->prox){
        if(strcmp(retornaNome(p->amigo), userName) == 0){
            break;
        }
    }
    p->flagSimilar = 1;

}

void mergeAmigos(tUsuario* user, tAmigos* friends){

    tCelAmigos* p;

    for(p=friends->inicio; p!=NULL; p=p->prox){
        mergePlaylistsUsuario(user, p->amigo);
    }

}

int contaAmigos(tAmigos* friends){
    
    tCelAmigos* p;
    int i = 0;

    for(p=friends->inicio; p!=NULL; p=p->prox){
        i++;
    }

    return i;
}

tAmigos* liberaAmigos(tAmigos* friends){

    tCelAmigos* p, *pprox;
    
    for(p=friends->inicio; p!=NULL; p=pprox){
        pprox = p->prox;
        liberaCelAmigos(p);
    }

}