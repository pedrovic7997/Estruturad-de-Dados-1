#include <stdio.h>
#include <stdlib.h>
#include "caracter.h"

struct character
{
    char letter;
    int weight;
};

char getCharacter(tCharacter* c) {return c->letter;}
int getWeight(tCharacter* c) {return c->weight;}

//Inicializa Character
tCharacter* initializeCharacter(char letter, int weight){

    tCharacter* new = (tCharacter*)malloc(sizeof(tCharacter));

    new->letter = letter;
    new->weight = weight;

    return new;

}

//Compara a frequencia entre dois character
int compareCharacterWeight(tCharacter* c1, tCharacter* c2){

    if(c1->weight == c2->weight) return 0;
    else if(c1->weight < c2->weight) return -1;
    else return 1;

}

//Libera character
tCharacter* freeCharacter(tCharacter* character){

    free(character);

    return NULL;

}