#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "usuarios.h"

int main(int argc, char** argv) {

    tUsuarios *usuarios;
    char file1[] = "Entrada/Entrada/amizade.txt";
    char file2[] = "Entrada/Entrada/playlists.txt";
    char file3[] = "Saida/similaridades.txt";
    char file4[] = "Saida/played-refatorada.txt";

    mkdir("Saida", 0755);

    FILE *arqAmizade;
    arqAmizade = fopen(file1, "r");
    FILE *arqPlaylist;
    arqPlaylist = fopen(file2, "r");
    FILE *arqSimilaridades;
    arqSimilaridades=fopen(file3, "w");
    FILE *arqPlayEDRefat;
    arqPlayEDRefat=fopen(file4, "w");
    
    char path[]="Saida/";

    if(!arqPlaylist||!arqAmizade){
        printf("Falha ao abrir o arquivo");
        exit(1);
    }
    
    usuarios=inicializaUsuarios(arqAmizade);
    //imprimeUsuarios(usuarios);
    //printf("\n");
    lerAmizade(arqAmizade,usuarios);
    //imprimeAmigosUsuarios(usuarios);
    preenchePlaylistUsuarios(arqPlaylist,usuarios);
    //imprimePlaylistsUsuarios(usuarios);
    criaPLaylistsRefatUsers(usuarios);
    zeraSimilaridades(usuarios);
    similaridades(arqSimilaridades,usuarios);
    zeraSimilaridades(usuarios);
    imprimePlaylistsRefatUsuarios(path,arqPlayEDRefat,usuarios);
    strcat(path,"merge/");
    mkdir(path, 0755);
    geraMerge(usuarios);
    imprimePlaylistsRefatUsuarios(path,NULL,usuarios);
    liberaUsuarios(usuarios);

    fclose(arqAmizade);
    fclose(arqPlaylist);
    fclose(arqPlayEDRefat);
    fclose(arqSimilaridades);

    return 0;
}


    