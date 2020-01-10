#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "usuario.h"
#include "playlist.h"
#include "amigos.h"

struct usuario
{
    char* nome;
    tPlaylists* playlists;
    tPlaylists* playlistsRefat;
    tAmigos* amigos;
};

tUsuario* inicializaUsuario(char* nome){

    tUsuario* user = (tUsuario*)malloc(sizeof(tUsuario));

    user->nome = strdup(nome);
    user->playlists = NULL;
    user->playlistsRefat = NULL;
    user->amigos = inicializaAmigos();

    return user;

}

void imprimeAmigosUsuario(tUsuario* user){

    imprimeAmigos(user->amigos);

}
/*

void imprimePlaylistsUsuario(tUsuario* user){

    imprimePlaylists(user->playlists);

}
*/

void imprimePlaylistsRefatUsuario(FILE* arq,tUsuario* user){

    imprimePlaylists(arq,user->playlistsRefat);

}

/*
void imprimePlaylistUsuario(tUsuario* user){

    imprimePlaylist(user->playlists);

}
*/

void imprimePlaylistRefatUsuario(char* path,tUsuario* user){
    char pathUser[100];
    strcpy(pathUser,path);
    strcat(pathUser,user->nome);
    strcat(pathUser,"/");
    mkdir(pathUser, 0755);
    imprimePlaylist(pathUser,user->playlistsRefat);
}

int comparaNome(tUsuario* user, char* nome){

    return strcmp(user->nome, nome);

}

char* retornaNome(tUsuario* user){

    return user->nome;

}

void comecaAmizade(tUsuario* user1,tUsuario* user2){
    
    criaAmizade(user1->amigos, user2->amigos, user1, user2);

}

void contaSimilares(FILE* arq, tUsuario* user){

    contaMusicasAmigos(arq, user, user->amigos);

}

void contabilizaSimilaridadeUsuario(tUsuario* user, tUsuario* friend){

    contabilizaSimilaridade(user->nome, friend->amigos);

}

int comparaPlaylistsUsuario(tUsuario* user, tUsuario* friend){

    int i=0;
    i=comparaPlaylists(user->playlistsRefat, friend->playlistsRefat);

    return i;

}

int getQtdPlaylistsUser(tUsuario* user){
    getQtdPlaylists(user->playlistsRefat);
}

void mergeUsuario(tUsuario* user){

    mergeAmigos(user, user->amigos);

    /* qtd = contaAmigos(user->amigos);
    for(int i=0; i<qtd; i++){
        p = buscaPlaylistAmigos();
        mergePlaylist(user, p);
    }
    
     */

}

void mergePlaylistsUsuario(tUsuario* user, tUsuario* friend){
    if(!getSimilaridade(user,friend,user->amigos)){
        mergePlaylists(user->playlistsRefat, friend->playlistsRefat);
        contabilizaSimilaridade(friend->nome,user->amigos);
        contabilizaSimilaridade(user->nome,friend->amigos);
    }

}

tUsuario* liberaUsuario(tUsuario* user){

    free(user->nome);
    user->playlists = liberaPlaylistsNoMusic(user->playlists);
    user->playlistsRefat = liberaPlaylists(user->playlistsRefat);
    user->amigos = liberaAmigos(user->amigos);
    free(user);

    return user;

}

void criaPLaylistRefatUser(tUsuario* usuario){
    usuario->playlistsRefat=criaPlaylistRefat(usuario->playlists);
}

void zeraSimilaridadeUser(tUsuario* user){
    zeraSimilaridade(user->amigos);
}

void preenchePlaylistUsuario(tUsuario* usuario,FILE *arq){
    usuario->playlists=inicializaPlaylist(arq);
}