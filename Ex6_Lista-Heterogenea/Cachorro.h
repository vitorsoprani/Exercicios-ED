#ifndef _CACHORRO_H
#define _CACHORRO_H
#include "utils.h"
typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char* nome, enum Personalidade personalidade);

void liberaCachorro(Cachorro* c);

void atribuiNivelAgressividadeCachorro(Cachorro* c, enum Personalidade p);

enum Personalidade getPersonalidadeCachorro(Cachorro* c);

void imprimeCachorro(void* c);

int comparaCachorro(void* cachorro, void* nome);

char* getNomeCachorro(Cachorro* c);

#endif