#include <stddef.h>
#include "arvoreb.h"
#include "medicao.h"

/* ===================== TAREFA 4: ÁRVORE-B =====================
   Mesmo algoritmo do laboratório (CLRS), agora com o grau mínimo t
   guardado em a->t. Cada nó tem até 2t-1 chaves e 2t filhos.
   Junto de cada chave, guarde também pos (a posição do aluno no vetor).
   Para criar nós, use arvb_novo_no(a, folha), que já está pronta. */

int arvb_busca(const ArvoreB *a, int chave) {
    /* TODO: a partir de a->raiz, faça comparacoes++ a cada NÓ visitado;
       ache a primeira posição i com chave <= x->chave[i];
       se for igual, devolva x->pos[i]; se o nó for folha, devolva -1;
       senão, desça para x->filho[i]. */
    (void)a; (void)chave;
    return -1;
}

static void divide_filho(ArvoreB *a, NoB *x, int i) {
    /* TODO: y = x->filho[i] está cheio (2t-1 chaves).
       1. z = arvb_novo_no(a, y->folha).
       2. Copie as t-1 maiores chaves (e pos) de y para z;
          se y não for folha, copie também os t últimos filhos.
       3. y->n = t-1 e z->n = t-1.
       4. Em x, abra espaço: filhos a partir de i+1 e chaves a partir de i.
       5. x->filho[i+1] = z; suba y->chave[t-1] (e y->pos[t-1]) para a
          posição i de x; x->n++. */
    (void)a; (void)x; (void)i;
}

static void insere_nao_cheio(ArvoreB *a, NoB *x, int k, int v) {
    /* TODO:
       - Folha: desloque para a direita as chaves maiores que k e coloque
         k (e v) na posição livre; x->n++.
       - Interno: ache o filho i onde k deve descer; se ele estiver cheio,
         divida-o (divide_filho) e decida entre i e i+1; desça. */
    (void)a; (void)x; (void)k; (void)v;
    (void)divide_filho;
}

void arvb_insere(ArvoreB *a, int chave, int pos) {
    /* TODO:
       - Se a chave já existir (arvb_busca diferente de -1), não insira.
       - Árvore vazia: crie a raiz folha com essa única chave.
       - Raiz cheia: crie uma nova raiz s (não folha), s->filho[0] = raiz
         antiga, a->raiz = s, divida o filho 0.
       - Por fim, chame insere_nao_cheio(a, a->raiz, chave, pos). */
    (void)a; (void)chave; (void)pos;
    (void)insere_nao_cheio;
}

int arvb_altura(const ArvoreB *a) {
    /* TODO: conte os níveis descendo sempre por filho[0] até uma folha.
       Árvore vazia: 0. */
    (void)a;
    return 0;
}

/* ===================== DESAFIO (BÔNUS) =====================
   Conte quantas chaves estão no intervalo [ini, fim] SEM visitar a árvore
   inteira: só desça nas subárvores que podem ter chaves do intervalo.
   O programa usa isso para contar os ingressantes de 2024. */
int arvb_conta_faixa(const ArvoreB *a, int ini, int fim) {
    (void)a; (void)ini; (void)fim;
    return -1;
}
