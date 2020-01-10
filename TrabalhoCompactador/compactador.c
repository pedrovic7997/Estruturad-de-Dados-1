#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitmap.h"
#include "arvore.h"
#include "lista.h"

#define TAMBM 240

//Limpa o vetor de contador
void clearCounter(int* counter) {
    int i;
    for (i = 0; i < 256; i++) {
        counter[i] = 0;
    }
}

//Limpa o vetor de novo codigo
void clearNewCode(char *newCode[256]) {
    int i;
    for (i = 0; i < 256; i++) {
        newCode[i] = NULL;
    }
}

//Le a quantidade de repetições de cada caracter do arquivo dado de entrada
int readCounter(int* counter, FILE* file) {
    unsigned char c;
    int qtdCharacters = 0;
    while (!feof(file)) {
        fscanf(file, "%c", &c);
        counter[c]++;
        qtdCharacters++;
    }
    return qtdCharacters - 1;
}

//Adiciona o novo codigo ao vetor de codigos 
void createNewCode(int letter, char *newCode[256], char *code) {
    newCode[letter] = (char*) malloc(strlen(code) + 1);
    strcpy(newCode[letter], code);
}

//Cria um novo nome para o arquivo de saida a partir do nome do arquivo de entrada
char* createOutputName(char *name) {
    char* output = (char*) malloc(strlen(name) + 5);
    int x;
    for (x = strlen(name); name[x] != '.' && x > 0; x--);
    strcpy(output, name);
    if (x == 0) x = strlen(name) - 1;
    strcpy(output + x, ".comp");
    return output;
}

//Escreve o bitmap no arquivo que esta sendo compactado
void printBitmap(bitmap bm, FILE* file) {
    int i;
    for (i = 0; i < TAMBM / 8; i++) {
        fprintf(file, "%c", bitmapGetContents(bm)[i]);
    }

}

//Le novamente o arquivo de entrada e escreve ele compactado
void compactar(FILE* file, char *newCode[256], FILE* output) {
    bitmap bm = bitmapInit(TAMBM);
    int x = 0;
    int charQty = 0;
    while (!feof(file)) {
        char c;
        fscanf(file, "%c", &c);
        for (int y = 0; y < strlen(newCode[c]); y++) {
            if (x == TAMBM) {
                printBitmap(bm, output);
                x = 0;
                free(bm.contents);
                bm = bitmapInit(TAMBM);
            }
            charQty++;
            bitmapAppendLeastSignificantBit(&bm, newCode[c][y] - '0');
            x++;
        }
    }
    printBitmap(bm, output);
    free(bm.contents);
}

//Libera o vetor de codigos
void freeNewCode(char *newCode[256]) {
    int i;
    for (i = 0; i < 256; i++) {
        if(newCode[i]!=NULL)
            free(newCode[i]);
    }
}

//Pega a extenxão de um arquivo
char* getExt(char* name) {
    int x;
    for (x = strlen(name); name[x] != '.' && x > 0; x--);
    if (x == 0)return NULL;
    char* ext = (char*) malloc(sizeof (char)*(strlen(name) - x) + 1);
    strcpy(ext, name + x);
    return ext;
}

int main(int argc, char** argv) {
    int counter[256];
    FILE* file;
    file = fopen(argv[1], "r");
    clearCounter(counter);
    int qtdCharacter = readCounter(counter, file);
    char *newCode[256];
    clearNewCode(newCode);
    tList* list = NULL;
    int i;
    for (i = 0; i < 256; i++) {
        if (counter[i]) {
            tCharacter* c = initializeCharacter((char) i, counter[i]);
            tTree* tree = createTree(createEmpty(), createEmpty(), c);
            list = includeList(list, tree);
        }
    }
    sortList(list);
    list = renewList(list);
    char *c=(char*)malloc(1);
    *c=0;
    createTreeCode(getTree(list), c, newCode, createNewCode);
    free(c);
    rewind(file);
    char *nameOutput;
    nameOutput = createOutputName(argv[1]);
    FILE* output = fopen(nameOutput, "w");
    char *ext;
    ext = getExt(argv[1]);
    fprintf(output, "%s ", ext);
    printListTree(list, output);
    fprintf(output, "%d ", qtdCharacter);
    compactar(file, newCode, output);
    fclose(file);
    fclose(output);
    freeList(list);
    freeNewCode(newCode);
    free(nameOutput);
    free(ext);
    return (EXIT_SUCCESS);
}

