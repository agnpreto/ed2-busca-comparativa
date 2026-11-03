#include <stdlib.h>
#include "hash.h"
#include "medicao.h"

/* ===================== TAREFA 3: TABELA HASH =====================
   Encadeamento: cada posição da tabela é uma lista ligada de NoHash. */

Hash *hash_cria(int m) {
    /* TODO: aloque um Hash, guarde m, zere n e aloque o vetor lista com
       m ponteiros NULL (use calloc). Devolva o ponteiro.
       Enquanto devolver NULL, o programa pula o teste da hash. */
    (void)m;
    return NULL;
}

int hash_funcao(const Hash *h, int chave) {
    /* TODO: método da divisão: chave % m */
    (void)h; (void)chave;
    return 0;
}

void hash_insere(Hash *h, int chave, int pos) {
    /* TODO: calcule i = hash_funcao(h, chave); crie um NoHash com chave e
       pos e insira-o no INÍCIO da lista h->lista[i]. Aumente h->n. */
    (void)h; (void)chave; (void)pos;
}

int hash_busca(const Hash *h, int chave) {
    /* TODO: percorra a lista da posição hash_funcao(h, chave).
       Faça comparacoes++ a cada nó visitado.
       Achou: devolva p->pos. Chegou ao fim: devolva -1. */
    (void)h; (void)chave;
    return -1;
}

int hash_maior_lista(const Hash *h) {
    /* TODO: devolva o tamanho da maior lista da tabela. */
    (void)h;
    return 0;
}

void hash_libera(Hash *h) {
    if (h == NULL) return;
    /* TODO: libere todos os nós de todas as listas antes das linhas abaixo. */
    free(h->lista);
    free(h);
}
