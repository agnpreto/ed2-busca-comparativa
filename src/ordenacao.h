#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "aluno.h"

/* Ordenam v em ordem crescente de matrícula.
   Some 1 em comparacoes a cada comparação entre duas matrículas. */
void ordena_insercao(Aluno *v, int n);
void ordena_quick(Aluno *v, int n);

#endif
