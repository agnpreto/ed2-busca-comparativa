#include <stdlib.h>
#include "arvoreb.h"

/* Funções já prontas: criação e liberação de memória. */

ArvoreB *arvb_cria(int t) {
    ArvoreB *a = malloc(sizeof(ArvoreB));
    a->t = t;
    a->raiz = NULL;
    a->nos = 0;
    return a;
}

NoB *arvb_novo_no(ArvoreB *a, int folha) {
    NoB *x = malloc(sizeof(NoB));
    x->n = 0;
    x->folha = folha;
    x->chave = malloc(sizeof(int) * (size_t)(2 * a->t - 1));
    x->pos = malloc(sizeof(int) * (size_t)(2 * a->t - 1));
    x->filho = calloc((size_t)(2 * a->t), sizeof(NoB *));
    a->nos++;
    return x;
}

static void libera_no(NoB *x) {
    if (x == NULL) return;
    if (!x->folha)
        for (int i = 0; i <= x->n; i++) libera_no(x->filho[i]);
    free(x->chave); free(x->pos); free(x->filho); free(x);
}

void arvb_libera(ArvoreB *a) {
    if (a == NULL) return;
    libera_no(a->raiz);
    free(a);
}
