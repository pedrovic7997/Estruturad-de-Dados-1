#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "musica.h"
#include "playlist.h"

typedef struct celulaMusica tCelulaMusica;

typedef struct celulaPlaylist tCelulaPlaylist;

struct celulaMusica {
    tCelulaMusica* prox;
    tMusica *musica;
};

struct playlist {
    tCelulaMusica* ini;
    tCelulaMusica* fim;
    int numMusicas;
    char* nome;
};

struct celulaPlaylist {
    tCelulaPlaylist* prox;
    tPlaylist* playlist;
};

struct playlists {
    tCelulaPlaylist* ini;
    tCelulaPlaylist* fim;
    int qtdPlaylists;
};

void inserePlaylist(tPlaylists* playlists, tPlaylist* playlist) {
    tCelulaPlaylist* nova=(tCelulaPlaylist*)malloc(sizeof(tCelulaPlaylist));
    nova->prox=NULL;
    nova->playlist=playlist;
    playlists->qtdPlaylists++;
    if (!(playlists->ini)) {
        playlists->ini = playlists->fim = nova;
        
        return;
    }
    playlists->fim->prox = nova;
    playlists->fim = nova;
}

tPlaylists* inicializaPlaylist(FILE* arq) {
    tPlaylists *playlists = (tPlaylists*) malloc(sizeof (tPlaylists));
    playlists->ini = playlists->fim = NULL;
    char nomePlaylist[100];
    int qtdPlaylists;
    FILE* arqPlaylist;
    fscanf(arq, "%d%*c", &qtdPlaylists);
    tPlaylist* playlist;
    char path[] = "Entrada/Entrada/";
    char pathPlaylist[100];
    playlists->qtdPlaylists=0;
    for (int x = 0; x < qtdPlaylists; x++) {
        fscanf(arq, "%[^;\n]%*c", nomePlaylist);
        strcpy(pathPlaylist, path);
        strcat(pathPlaylist, nomePlaylist);
        arqPlaylist = fopen(pathPlaylist, "r");
        playlist = criaPlaylist(nomePlaylist);
        inserePlaylist(playlists, playlist);
        preenchePlaylist(playlist, arqPlaylist);
        fclose(arqPlaylist);
    }
    return playlists;
}

int getQtdPlaylists(tPlaylists* playlists){
    return playlists->qtdPlaylists;
}

tPlaylist* criaPlaylist(char* nome) {
    tPlaylist* playlist = (tPlaylist*) malloc(sizeof (tPlaylist));
    playlist->nome = strdup(nome);
    playlist->fim = playlist->ini = NULL;
    playlist->numMusicas = 0;
    return playlist;
}

void preenchePlaylist(tPlaylist* playlist, FILE* arq) {
    tMusica* musica;
    while (!feof(arq)) {
        musica = lerMusica(arq);
        //if (!verificaMusica(playlist, musica)) {
        adicionaMusica(playlist, musica);
        playlist->numMusicas++;
        //}
    }
}

int verificaMusica(tPlaylist* playlist, tMusica* musica) {
    for (tCelulaMusica* i = playlist->ini; i != NULL; i = i->prox) {
        if (comparaNomeMusica(i->musica, musica))
            return 1;
    }
    return 0;
}

int verificaArtista(tPlaylist* playlist, char* nome) {
    for (tCelulaMusica* i = playlist->ini; i != NULL; i = i->prox) {
        if (comparaArtistaMusica(i->musica, nome))
            return 1;
    }
    return 0;
}

int comparaPlaylist(tPlaylist* list1, tPlaylist* list2) {
    int i = 0;
    tCelulaMusica* p1, *p2;

    for (p1 = list1->ini; p1 != NULL; p1 = p1->prox) {
        for (p2 = list2->ini; p2 != NULL; p2 = p2->prox) {
            if (comparaNomeMusica(p1->musica, p2->musica)) {
                i++;
            }
        }
    }
    return i;
}

int comparaPlaylists(tPlaylists* list1, tPlaylists* list2) {
    int i = 0;
    tCelulaPlaylist* p1, *p2;
    for (p1 = list1->ini; p1 != NULL; p1 = p1->prox) {
        for (p2 = list2->ini; p2 != NULL; p2 = p2->prox) {
            if(strcmp(p2->playlist->nome,p1->playlist->nome)==0)
                i += comparaPlaylist(p1->playlist, p2->playlist);
        }
    }

    return i;

}

tPlaylist* liberaPlaylist(tPlaylist* playlist) {
    tCelulaMusica *prox;
    for(tCelulaMusica* i=playlist->ini;i!=NULL;i=prox){
        prox=i->prox;
        liberaMusica(i->musica);
        free(i);
    }
    free(playlist->nome);
    free(playlist);
    return NULL;
}

tPlaylist* liberaPlaylistNoMusic(tPlaylist* playlist) {
    tCelulaMusica *prox;
    for(tCelulaMusica* i=playlist->ini;i!=NULL;i=prox){
        prox=i->prox;
        free(i);
    }
    free(playlist->nome);
    free(playlist);
    return NULL;
}

tPlaylists* liberaPlaylists(tPlaylists* playlists) {
    tCelulaPlaylist *prox;
    for(tCelulaPlaylist* i=playlists->ini;i!=NULL;i=prox){
        prox=i->prox;
        liberaPlaylist(i->playlist);
        free(i);
    }
    free(playlists);
    return NULL;
}

tPlaylists* liberaPlaylistsNoMusic(tPlaylists* playlists) {
    tCelulaPlaylist *prox;
    for(tCelulaPlaylist* i=playlists->ini;i!=NULL;i=prox){
        prox=i->prox;
        liberaPlaylistNoMusic(i->playlist);
        free(i);
    }
    free(playlists);
    return NULL;
}

void adicionaMusica(tPlaylist* playlist, tMusica* musica) {
    tCelulaMusica *nova = (tCelulaMusica*) malloc(sizeof (tCelulaMusica));
    nova->musica = musica;
    nova->prox = NULL;
    playlist->numMusicas++;
    if (!(playlist->ini)) {
        playlist->ini = playlist->fim = nova;
        return;
    }
    playlist->fim->prox = nova;
    playlist->fim = nova;
}

void retiraMusica(tPlaylist* playlist, tMusica* musica) {
    if (!(playlist->ini))
        return;
    tCelulaMusica* aux = playlist->ini, *ant = NULL;
    while (aux != NULL) {
        if (comparaNomeMusica(aux->musica, musica)) {
            if (aux == playlist->ini)
                playlist->ini = aux->prox;
            else {
                if (aux == playlist->fim) {
                    playlist->fim = ant;
                    ant->prox = NULL;
                } else ant->prox = aux->prox;
            }
            if (!(playlist->ini))
                playlist->fim = NULL;
            if (ant) {
                free(aux);
                aux = ant->prox;
            } else {
                ant = aux;
                aux = aux->prox;
                free(ant);
                ant = NULL;
            }

        } else {
            ant = aux;
            aux = aux->prox;
        }
    }
}

char* getNomePLaylist(tPlaylist* playlists) {
    return playlists->nome;
}

void escrevePLaylists(tPlaylist* playlists, FILE* arq) {
    for (tCelulaMusica *i = playlists->ini; i != NULL; i = i->prox) {
        escreveMusica(i->musica, arq);
    }
}

void imprimePlaylists(FILE* arq,tPlaylists* playlists) {

    tCelulaPlaylist* p;

    for (p = playlists->ini; p != NULL; p = p->prox) {
        fprintf(arq,";%s", p->playlist->nome);
    }

}

void imprimePlaylist(char* path,tPlaylists* playlists) {

    tCelulaMusica* cel;
    tCelulaPlaylist* p;
    char playlist[100];
    FILE* arq;
    for (p = playlists->ini; p != NULL; p = p->prox) {
        strcpy(playlist,path);
        strcat(playlist,p->playlist->nome);
        strcat(playlist,".txt");
        arq=fopen(playlist,"w");
        for (cel = p->playlist->ini; cel != NULL; cel = cel->prox) {
            imprimeMusica(arq,cel->musica);
            fprintf(arq,"\n");
        }
        fclose(arq);
    }

}

tPlaylist* comparaNomePaylists(tPlaylists* playlists, char* artista) {
    for (tCelulaPlaylist *i = playlists->ini; i != NULL; i = i->prox) {
        if (strcmp(i->playlist->nome, artista) == 0) {
            return i->playlist;
        }
    }
    return NULL;
}

tPlaylists* criaPlaylistRefat(tPlaylists* playlists) {
    tPlaylists *refat = (tPlaylists*) malloc(sizeof (tPlaylists));
    refat->ini = refat->fim = NULL;
    tPlaylist *nova;
    tCelulaMusica *x;
    refat->qtdPlaylists=0;
    for (tCelulaPlaylist *i = playlists->ini; i != NULL; i = i->prox) {
        x = i->playlist->ini;
        while (x != NULL) {
            nova = comparaNomePaylists(refat, getNomeArtista(x->musica));
            if (!nova) {
                nova = criaPlaylist(getNomeArtista(x->musica));
               // if (!verificaMusica(nova, x->musica)) {
                    adicionaMusica(nova, x->musica);
                //}
                x = x->prox;
                //criaPlaylistArtista(i, nova);
                inserePlaylist(refat, nova);
            } else {
                //if (!verificaMusica(nova, x->musica)) {
                    adicionaMusica(nova, x->musica);
                //}
                x = x->prox;
                //criaPlaylistArtista(i, nova);
            }
        }
    }
    return refat;
}

void criaPlaylistArtista(tPlaylist* playlists, tPlaylist* playlistArtista) {
    tCelulaMusica* i = playlists->ini, *aux = NULL;
    while (i != NULL) {
        if (comparaArtistaMusica(i->musica, playlistArtista->nome)) {
            if (!verificaMusica(playlistArtista, i->musica)) {
                adicionaMusica(playlistArtista, i->musica);
                aux = i;
                i = i->prox;
                //retiraMusica(playlists, aux->musica);
            } else i = i->prox;
        } else i = i->prox;
    }
}

tPlaylist* mergePlaylist(tPlaylist *i, tPlaylist* x) {
    tCelulaMusica *aux1, *aux2, *merge;
    merge = i->ini;
    aux1 = i->ini->prox;
    aux2 = x->ini;
    while (aux1 || aux2) {
        if (aux2) {
            if (!verificaMusica(i, aux2->musica)) {
                merge->prox = aux2;
                merge = merge->prox;
            }
            aux2 = aux2->prox;
        }
        if (aux1) {
            merge->prox = aux1;
            merge = merge->prox;
            aux1 = aux1->prox;
        }
    }
    merge->prox = NULL;
    return i;
}

void mergePlaylists(tPlaylists* userList, tPlaylists* friendList) {
    tCelulaPlaylist *ant = NULL,*aux;
    static int aaux=0;

    for (tCelulaPlaylist *i = userList->ini; i != NULL; i = i->prox) {
        for (tCelulaPlaylist *x = friendList->ini; x != NULL; x = x->prox) {
            if (strcmp(i->playlist->nome, x->playlist->nome) == 0) {
                if(ant){
                    ant->prox->playlist = mergePlaylist(i->playlist, x->playlist);
                }
                else friendList->ini->playlist=mergePlaylist(i->playlist, x->playlist);
            }
            ant = x;
        }
        ant=NULL;
    }

}