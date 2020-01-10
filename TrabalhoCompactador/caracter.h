#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct character tCharacter;

// TODO: VERIFICAR SE PRECISA MESMO DESSE TAD

char getCharacter(tCharacter*); //Retorna o caractere
int getWeight(tCharacter*); //Retorna a frequencia

//Inicializa character
tCharacter* initializeCharacter(char, int);

//Compara a frequencia entre dois character
int compareCharacterWeight(tCharacter*, tCharacter*);

//Libera character
tCharacter* freeCharacter(tCharacter*);

#endif /* CHARACTER_H */
