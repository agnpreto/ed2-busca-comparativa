#ifndef ARVOREB_H
#define ARVOREB_H

/* Árvore-B de grau mínimo t (CLRS): cada nó tem no máximo 2t-1 chaves
   e, exceto a raiz, no mínimo t-1 chaves. */
typedef struct NoB {
    int n;                  /* quantidade de chaves no nó */
    int folha;              /* 1 se for folha */
    int *chave;             /* 2t-1 posições */
    int *pos;               /* posição do aluno no vetor (dado junto da chave) */
    struct NoB **filho;     /* 2t posições */
} NoB;

typedef struct {
    int t;                  /* grau mínimo */
    NoB *raiz;
    long nos;               /* total de nós criados */
} ArvoreB;

ArvoreB *arvb_cria(int t);                      /* pronta */
NoB     *arvb_novo_no(ArvoreB *a, int folha);   /* pronta */
void     arvb_libera(ArvoreB *a);               /* pronta */

void arvb_insere(ArvoreB *a, int chave, int pos);  /* sem repetição */
int  arvb_busca(const ArvoreB *a, int chave);      /* pos ou -1; +1 em comparacoes por NÓ visitado */
int  arvb_altura(const ArvoreB *a);                /* níveis; árvore vazia = 0 */

/* DESAFIO (bônus): quantas chaves estão no intervalo [ini, fim].
   Devolva -1 enquanto não implementar. */
int  arvb_conta_faixa(const ArvoreB *a, int ini, int fim);

#endif
