#include "ordenacao.h"
#include "medicao.h"

/* ===================== TAREFA 1: ORDENAÇÃO =====================
   Ordene v em ordem CRESCENTE de matrícula.
   A cada comparação entre duas matrículas, faça comparacoes++.
   Dica: copie o Aluno inteiro (struct), não só a matrícula. */

void ordena_insercao(Aluno *v, int n) {
    /* TODO: Insertion Sort.
       Para cada i de 1 a n-1: guarde x = v[i]; ande para a esquerda
       deslocando os alunos com matrícula maior que x.matricula;
       coloque x no espaço que sobrou. */
    (void)v; (void)n;
}

void ordena_quick(Aluno *v, int n) {
    /* TODO: Quicksort.
       Use como pivô a matrícula do elemento do meio.
       Crie uma função auxiliar recursiva quick(v, ini, fim) e chame
       quick(v, 0, n - 1) aqui. */
    (void)v; (void)n;
}
