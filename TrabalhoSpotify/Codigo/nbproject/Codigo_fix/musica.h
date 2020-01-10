#ifndef MUSICA_H
#define MUSICA_H
#include <stdio.h>

/*
*
*
*/
typedef struct musica tMusica;

/*
*
*
*/
int comparaNomeMusica(tMusica*,tMusica*);

/*
*
*
*/
int comparaArtistaMusica(tMusica*,char*);

/*
*
*
*/
tMusica* lerMusica(FILE*);

/*
*
*
*/
tMusica* liberaMusica(tMusica*);

/*
*
*
*/
char* getNomeMusica(tMusica*);

/*
*
*
*/
char* getNomeArtista(tMusica*);

/*
*
*
*/
void escreveMusica(tMusica*, FILE*);

void imprimeMusica(FILE*,tMusica*);
#endif /* MUSICA_H */
