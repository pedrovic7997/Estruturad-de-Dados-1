#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "usuario.h"
#include "playlist.h"
#include "amigos.h"

typedef struct celUsuario tCelUsuario;

struct celUsuario {
    tUsuario* usuario;
    tCelUsuario* prox;
};

tCelUsuario* inicializaCelUsuario(tUsuario* user) {

    tCelUsuario* nova = (tCelUsuario*) malloc(sizeof (tCelUsuario));

    nova->usuario = user;
    nova->prox = NULL;

    return nova;

}

tCelUsuario* liberaCelUsuario(tCelUsuario* celula) {

    liberaUsuario(celula->usuario);
    free(celula);

    return celula;

}

struct usuarios {
    tCelUsuario* inicio;
    tCelUsuario* fim;
};

void insereUsuario(tUsuarios* users, tUsuario* user) {

    tCelUsuario* cel;

    cel = inicializaCelUsuario(user);
    if (users->inicio == NULL) {
        users->inicio = cel;
        users->fim = cel;
    } else {
        users->fim->prox = cel;
        users->fim = cel;
    }

}

tUsuarios* inicializaUsuarios(FILE* arq) {

    char nome[100];
    char stop;
    tUsuario* user;
    tUsuarios* users;

    users = (tUsuarios*) malloc(sizeof (tUsuarios));
    users->inicio = NULL;
    users->fim = NULL;


    fscanf(arq, "%[^;\n]%c", nome, &stop);


    while (stop != '\n') {
        user = inicializaUsuario(nome);
        insereUsuario(users, user);
        fscanf(arq, "%[^;\n]%c", nome, &stop);
    }
    user = inicializaUsuario(nome);
    insereUsuario(users, user);
    return users;

}

void imprimeUsuarios(tUsuarios* users) {

    tCelUsuario* p;
    char* nome;
    for (p = users->inicio; p != NULL; p = p->prox) {
        nome = retornaNome(p->usuario);
        printf("%s -> ", nome);
    }

}

void imprimeAmigosUsuarios(tUsuarios* users) {

    tCelUsuario* p;
    char* nome;

    for (p = users->inicio; p != NULL; p = p->prox) {
        nome = retornaNome(p->usuario);
        printf("%s (AMIGOS): ", nome);
        imprimeAmigosUsuario(p->usuario);
        printf("\n");
    }

}

/*
void imprimePlaylistsUsuarios(tUsuarios* users){

    tCelUsuario* p;
    char* nome;

    for(p=users->inicio; p!=NULL; p=p->prox){
        nome = retornaNome(p->usuario);
        printf("%s (PLAYLISTS): ", nome);
        imprimePlaylistsUsuario(p->usuario);
        printf("\n");
    }

    for(p=users->inicio; p!=NULL; p=p->prox){
        nome = retornaNome(p->usuario);
        printf("%s (PLAYLIST):\n", nome);
        imprimePlaylistUsuario(p->usuario);
        printf("\n");
    }

}
 */

void imprimePlaylistsRefatUsuarios(char* path,FILE* arq, tUsuarios* users) {

    tCelUsuario* p;
    char* nome;
    if (arq) {
        for (p = users->inicio; p != NULL; p = p->prox) {
            nome = retornaNome(p->usuario);
            fprintf(arq, "%s;%d", nome, getQtdPlaylistsUser(p->usuario));
            imprimePlaylistsRefatUsuario(arq, p->usuario);
            fprintf(arq, "\n");
        }
    }
    for (p = users->inicio; p != NULL; p = p->prox) {
        imprimePlaylistRefatUsuario(path,p->usuario);
    }

}

void preenchePlaylistUsuarios(FILE* arq, tUsuarios* usuarios) {
    char nome[100];
    tUsuario *usuario;
    while (!feof(arq)) {
        fscanf(arq, "%[^;];", nome);
        usuario = buscaUsuario(nome, usuarios);
        preenchePlaylistUsuario(usuario, arq);
    }
}

tUsuario* buscaUsuario(char* nome, tUsuarios* users) {

    tCelUsuario* p;

    for (p = users->inicio; p != NULL; p = p->prox) {
        if (comparaNome(p->usuario, nome) == 0) {
            break;
        }
    }

    return p->usuario;

}

void lerAmizade(FILE* arq, tUsuarios* users) {

    char nome1[100], nome2[100];
    tUsuario* user1, *user2;

    while (!feof(arq)) {
        fscanf(arq, "%[^;];%s\n", nome1, nome2);
        user1 = buscaUsuario(nome1, users);
        user2 = buscaUsuario(nome2, users);
        comecaAmizade(user1, user2);
    }

}

void similaridades(FILE* arq, tUsuarios* users) {
    tCelUsuario* u;
    for (u = users->inicio; u != NULL; u = u->prox) {
        contaSimilares(arq, u->usuario);
    }

    //fclose(arq);

}

void playlists(FILE* arq, tUsuarios* users) {

    tCelUsuario* p;
    char* nome;
    tUsuario* user;

    while (!feof(arq)) {
        fscanf(arq, "%[^;]", nome);
        user = buscaUsuario(nome, users);
        //criaPlaylists(user, arq);
    }


}

void geraMerge(tUsuarios* users) {

    tCelUsuario* p;

    for (p = users->inicio; p != NULL; p = p->prox) {
        //mergeUsuario(arq, p->usuario);
        mergeUsuario(p->usuario);
    }

}

void criaPLaylistsRefatUsers(tUsuarios* usuarios) {
    for (tCelUsuario* i = usuarios->inicio; i != NULL; i = i->prox) {
        criaPLaylistRefatUser(i->usuario);
    }
}

tUsuarios* liberaUsuarios(tUsuarios* users) {

    tCelUsuario* p, *pprox;

    for (p = users->inicio; p != NULL; p = pprox) {
        pprox = p->prox;
        p = liberaCelUsuario(p);
    }
    free(users);
    return NULL;

}

void zeraSimilaridades(tUsuarios* usuarios) {
    for (tCelUsuario* i = usuarios->inicio; i != NULL; i = i->prox) {
        zeraSimilaridadeUser(i->usuario);
    }

}