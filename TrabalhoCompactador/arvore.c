#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"
#include "caracter.h"

struct tree
{
    tTree *lt; //left tree
    tTree *rt; //right tree
    tCharacter *inf;
};

tTree *createTree(tTree *lt, tTree *rt, tCharacter *inf)
{
    tTree *tree = (tTree *)malloc(sizeof(tTree));
    tree->rt = rt;
    tree->lt = lt;
    tree->inf = inf;
    return tree;
}

tTree *createEmpty()
{
    return NULL;
}

int emptyTree(tTree *tree)
{
    return !tree;
}

int isLeaf(tTree *tree)
{
    return emptyTree(tree->lt) && emptyTree(tree->rt);
}

void writeTree(tTree *tree, FILE *arch)
{
    if (isLeaf(tree))
    {
        fprintf(arch, "1 (%c)", getCharacter(tree->inf));
        return;
    }
    fprintf(arch, "0 ");
    writeTree(tree->lt, arch);
    writeTree(tree->rt, arch);
}

int getNodeWeight(tTree *tree)
{
    return getWeight(tree->inf);
}

char getNodeChar(tTree *tree)
{
    return getCharacter(tree->inf);
}

tTree *assembleTree(FILE *arch)
{
    int aux;
    static int cont = 0;
    cont++;
    tTree *tree = (tTree *)malloc(sizeof(tTree));
    fscanf(arch, "%d", &aux);
    if (aux)
    {
        char letter;
        fscanf(arch, " (%c)", &letter);
        tree->inf = initializeCharacter(letter, 0);
        tree->lt = tree->rt = NULL;
        return tree;
    }
    tree->lt = assembleTree(arch);
    tree->rt = assembleTree(arch);
    return tree;
}

int compareTreeNodeWeight(tTree *t1, tTree *t2)
{

    int result;

    result = compareCharacterWeight(t1->inf, t2->inf);

    return result;
}

void createTreeCode(tTree *tree, char *code, char *newCode[256], void func(int, char **, char *))
{
    if (emptyTree(tree))
        return;
    if (isLeaf(tree))
    {
        func(getCharacter(tree->inf), newCode, code);
        return;
    }
    char *leftCode = (char *)malloc(sizeof(char) * (strlen(code) + 2));
    strcpy(leftCode, code);
    strcat(leftCode, "0");
    createTreeCode(tree->lt, leftCode, newCode, func);
    char *rightCode = (char *)malloc(sizeof(char) * (strlen(code) + 2));
    strcpy(rightCode, code);
    strcat(rightCode, "1");
    createTreeCode(tree->rt, rightCode, newCode, func);
    free(rightCode);
    free(leftCode);
}

tTree *freeTree(tTree *tree)
{
    if (emptyTree(tree))
        return NULL;
    freeTree(tree->lt);
    freeTree(tree->rt);
    freeCharacter(tree->inf);
    free(tree);
    return NULL;
}

tTree *freeTreeDescompact(tTree *tree)
{
    if (emptyTree(tree))
        return NULL;
    freeTree(tree->lt);
    freeTree(tree->rt);
    if (isLeaf(tree))
        freeCharacter(tree->inf);
    free(tree);
    return NULL;
}

int descompactaArvore(FILE *file, FILE *output, tTree *tree, int pos, unsigned char *c)
{
    static int countCharacters = 0;
    if (isLeaf(tree))
    {
        countCharacters++;
        fprintf(output, "%c", getCharacter(tree->inf));
        return pos;
    }
    if (pos == 8)
    {
        fscanf(file, "%c", c);
        pos = 0;
    }
    unsigned char aux = 1;
    aux = aux << 7 - pos;
    unsigned char path = *c & aux;
    pos++;
    if (path == 0)
    {
        return descompactaArvore(file, output, tree->lt, pos, c);
    }
    return descompactaArvore(file, output, tree->rt, pos, c);
}
