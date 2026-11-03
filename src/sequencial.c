#include "sequencial.h"
#include "medicao.h"

/* Já pronta: serve de modelo de como contar comparações. */
int busca_sequencial(const Aluno *v, int n, int mat) {
    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (v[i].matricula == mat) return i;
    }
    return -1;
}
