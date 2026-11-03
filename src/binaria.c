#include "binaria.h"
#include "medicao.h"

/* ===================== TAREFA 2: BUSCA BINÁRIA =====================
   v está ordenado por matrícula. Devolva a posição de mat ou -1.
   Faça comparacoes++ UMA vez por elemento do meio examinado. */

int busca_binaria(const Aluno *v, int n, int mat) {
    /* TODO:
       ini = 0, fim = n - 1;
       enquanto ini <= fim:
         meio = ini + (fim - ini) / 2;  comparacoes++;
         se v[meio].matricula == mat: achou;
         se for menor: procure à direita; senão, à esquerda. */
    (void)v; (void)n; (void)mat;
    return -1;
}
