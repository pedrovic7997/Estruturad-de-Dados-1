#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <stdio.h>
#include "musica.h"

/*
*
*
*/
typedef struct playlist tPlaylist;

/*
*
*
*/
typedef struct playlists tPlaylists;

int getQtdPlaylists(tPlaylists*);

/*
*
*
*/
tPlaylists* inicializaPlaylist(FILE*);

/*
*
*
*/
int comparaPlaylists(tPlaylists*, tPlaylists*);

/*
*
*
*/
void preenchePlaylist(tPlaylist*,FILE*);

/*Verifica se uma musica ja foi adicionada na playlist
*input: A playlist e a musica a ser verificada
*output: 1 para caso tenha encontrado a musica na playlist e 0 caso contrario
*/
int verificaMusica(tPlaylist*,tMusica*);

/*
*
*
*/
int verificaArtista(tPlaylist*,char*);

/*
*
*
*/
tPlaylist* liberaPlaylist(tPlaylist*);

/*
*
*
*/
void adicionaMusica(tPlaylist* ,tMusica*);

/* /*
*
*

void retiraMusica(tPlaylist*,tMusica*); */

/*
*
*
*/
char* getNomePLaylist(tPlaylist*);

/*
*
*
*/
void escrevePLaylists(tPlaylist*,FILE*);

void imprimePlaylists(FILE* arq,tPlaylists*);

void imprimePlaylist(char*,tPlaylists*);

/*Libera as musicas e uma playlist
*
*
*/
tPlaylist* liberaMusicas(tPlaylist* playlists);

/*Cria ou adiciona musicas a playlist de mesmo que o artista da musica
*input: A playlist de origem das musicas e a playlist do artista para adicionar as musicas
*output: Void
*Pre-Condicao:Os inpults nao sao nulos e a playlistArtista possui o nome do artista
*/
void criaPlaylistArtista(tPlaylist* playlists,tPlaylist* playlistArtista);

/*
*
*
*/
tPlaylist* criaPlaylist(char* nome);

/*
*
*
*/
void mergePlaylists(tPlaylists*, tPlaylists*);

/*
*
*
*/
tPlaylists* criaPlaylistRefat(tPlaylists*);

/*
*
*
*/
tPlaylists* liberaPlaylists(tPlaylists*);

tPlaylists* liberaPlaylistsNoMusic(tPlaylists*);

#endif /* PLAYLIST_H */
