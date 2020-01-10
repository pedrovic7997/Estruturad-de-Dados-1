#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int nlinhas;
    int ncolunas;
    int** mat;
};

Matriz* inicializaMatriz(int nlinhas, int ncolunas){
    
    Matriz* matrix;
    int i, j;

    matrix = (Matriz*)malloc(sizeof(Matriz));
    matrix->nlinhas = nlinhas;
    matrix->ncolunas = ncolunas;
    matrix->mat = (int**)malloc(nlinhas*sizeof(int*));
    for(i=0; i<nlinhas; i++){
        matrix->mat[i] = (int*)malloc(ncolunas*sizeof(int));
    }

    return matrix;
}

void modificaElemento(Matriz* mat, int linha, int coluna, int elem){

    mat->mat[linha][coluna] = elem;

}

void imprimeMatriz(Matriz* mat){

    int i, j;

    for(i=0; i<mat->nlinhas; i++){
        for(j=0; j<mat->ncolunas; j++){
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }

}

int recuperaElemento(Matriz* mat, int linha, int coluna){

    return mat->mat[linha][coluna];

}

int recuperaNColunas (Matriz* mat){

    return mat->ncolunas;

}

int recuperaNLinhas(Matriz* mat){
    
    return mat->nlinhas;

}

Matriz* transposta (Matriz* mat){

    int i, j;
    Matriz* trans;

    trans = inicializaMatriz(mat->ncolunas, mat->nlinhas);

    for(i=0; i<trans->nlinhas; i++){
        for(j=0; j<trans->ncolunas; j++){
            trans->mat[i][j] = mat->mat[j][i];
        }
    }

    return trans;
}

Matriz* multiplicacao(Matriz* mat1, Matriz* mat2){

    Matriz* produto;
    int i, j, op;

    produto = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);

    for(i=0; i<produto->nlinhas; i++){
        for(j=0; j<produto->ncolunas; j++){
            produto->mat[i][j] = 0;
        }
    }

    for(i=0; i<produto->nlinhas; i++){
        for(j=0; j<produto->ncolunas; j++){
            for(op=0; op<mat1->ncolunas; op++){
                produto->mat[i][j] += mat1->mat[i][op]*mat2->mat[op][j];
            }
        }
    }

    return produto;
}

void destroiMatriz(Matriz* mat){
    
    int i, j;

    for(i=0; i<mat->nlinhas; i++){
        free(mat->mat[i]);
    }

    free(mat->mat);
    free(mat);
}