#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

//Cria o nome do arquivo de saida a partir do nome dado pela entrada
char* createOutputName(char *name,char* ext) {
    char* output = (char*) malloc(strlen(name) + 5);
    int x;
    for (x = strlen(name); name[x] != '.' && x > 0; x--);
    strcpy(output, name);
    if (x == 0) x = strlen(name) - 1;
    strcpy(output + x, ext);
    return output;
}

//Recebe dos arquivos por parametro e chama a função para descompactar o arquivo até 
//escrever todos os caracteres
void descompactar(FILE* file, FILE* output) {
    tTree* tree = assembleTree(file);
    int qtyCharacter;
    fscanf(file, "%d ", &qtyCharacter);
    int i, pos = 8;
    unsigned char *code = (char*) malloc(1);
    for (i = 0; i < qtyCharacter; i++) {
        pos = descompactaArvore(file, output, tree, pos, code);
    }
    free(code);
    freeTreeDescompact(tree);
}

int main(int argc, char** argv) {
    FILE *file, *output;
	file = fopen(argv[1], "r");
    char ext[7];
    fscanf(file,"%s",ext);
    if(strcmp(ext,"(null)")==0)
        ext[0]=0;
    char *outputName=createOutputName(argv[1],ext);
    output=fopen(outputName,"w");
    descompactar(file, output);
    fclose(file);
    fclose(output);
    free(outputName);
    return (EXIT_SUCCESS);
}

