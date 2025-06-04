#ifndef _GATO_H
#define _GATO_H

#include "utils.h"

typedef struct gato Gato;

Gato* inicGato(char* nome, enum Personalidade personalidade);

void liberaGato(Gato* g);

void atribuiNivelAgressividadeGato(Gato* g, enum Personalidade p);

enum Personalidade getPersonalidadeGato(Gato* g);

void imprimeGato(void* g);

#endif