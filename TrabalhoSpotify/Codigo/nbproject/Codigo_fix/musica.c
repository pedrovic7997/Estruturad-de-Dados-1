#include <string.h>
#include <stdlib.h>
#include "musica.h"
struct musica{
    char* nomeM;
    char* artista;
};
int comparaNomeMusica(tMusica* musica1,tMusica* musica2){
    if(strcmp(musica1->nomeM,musica2->nomeM) == 0 && strcmp(musica1->artista,musica2->artista) == 0)
        return 1;
    return 0;
}

int comparaArtistaMusica(tMusica* musica,char* artista){
    if(strcmp(musica->artista,artista)==0)
        return 1;
    return 0;
}


tMusica* lerMusica(FILE* arq){
    tMusica* musica=(tMusica*)malloc(sizeof(tMusica));
    char nome[100],artista[100];
    char trash;
    fscanf(arq,"%[^-]-%c",artista,&trash);
    while(trash!=' '){
        int tam=strlen(artista);
        artista[tam]='-';
        artista[tam+1]=trash;
        artista[tam+2]=0;
        fscanf(arq,"%[^-]-%c",artista+strlen(artista),&trash);
    }

    artista[strlen(artista)-1]=0;
    fscanf(arq," %[^\n]%*c",nome);
    musica->nomeM=strdup(nome);
    musica->artista=strdup(artista);
    return musica;
}

tMusica* liberaMusica(tMusica* musica){
    free(musica->artista);
    free(musica->nomeM);
    free(musica);
}

char* getNomeMusica(tMusica* musica){
    return musica->nomeM;
}

char* getNomeArtista(tMusica* musica){
    return musica->artista;
}

void escreveMusica(tMusica* musica, FILE* arq){
    fprintf(arq,"%s - %s\n",musica->artista,musica->nomeM);
}

void imprimeMusica(FILE* arq,tMusica* music){

    fprintf(arq,"%s - %s", music->artista, music->nomeM);

}