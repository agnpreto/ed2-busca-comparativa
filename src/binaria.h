#ifndef BINARIA_H
#define BINARIA_H
#include "aluno.h"

/* v precisa estar ordenado por matrícula.
   Devolve a posição do aluno com a matrícula mat, ou -1.
   Some 1 em comparacoes a cada elemento do meio examinado. */
int busca_binaria(const Aluno *v, int n, int mat);

#endif
