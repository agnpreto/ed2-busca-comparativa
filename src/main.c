/*
 * Comparativo de estruturas de busca - Estrutura de Dados II
 * NÃO é preciso alterar este arquivo.
 *
 * Uso: ./comparativo [N] [t] [alfa] [m]
 *   N    número de alunos no cadastro       (padrão 100000)
 *   t    grau mínimo da Árvore-B            (padrão 3)
 *   alfa fator de carga desejado da hash    (padrão 1.0)
 *   m    (opcional) força o tamanho da tabela hash, ignorando alfa
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "medicao.h"
#include "sequencial.h"
#include "ordenacao.h"
#include "binaria.h"
#include "hash.h"
#include "arvoreb.h"

#define CONSULTAS 10000
#define SEMENTE_CADASTRO 2026u
#define SEMENTE_CONSULTAS 7u

static int ordenado(const Aluno *v, int n) {
    for (int i = 1; i < n; i++)
        if (v[i - 1].matricula > v[i].matricula) return 0;
    return 1;
}

static void linha(const char *nome, double prep, double busca, double comp, int acertos, int total) {
    char p[16];
    if (prep < 0) strcpy(p, "-"); else snprintf(p, sizeof p, "%.4f", prep);
    printf("| %-26s | %10s | %9.4f | %16.2f | %5d/%-5d %s |\n",
           nome, p, busca, comp, acertos, total, acertos == total ? "OK  " : "ERRO");
}

int main(int argc, char **argv) {
    int n = argc > 1 ? atoi(argv[1]) : 100000;
    int t = argc > 2 ? atoi(argv[2]) : 3;
    double alfa = argc > 3 ? atof(argv[3]) : 1.0;
    if (n < 10 || n > 1000000 || t < 2 || alfa <= 0) {
        printf("Uso: %s [10<=N<=1000000] [t>=2] [alfa>0] [m]\n", argv[0]);
        return 1;
    }
    int m = primo_ge((int)(n / alfa));
    if (argc > 4 && atoi(argv[4]) > 0) m = atoi(argv[4]);

    Aluno *v = malloc(sizeof(Aluno) * (size_t)n);
    int *q = malloc(sizeof(int) * CONSULTAS);
    int *ref = malloc(sizeof(int) * CONSULTAS);      /* resposta da sequencial */
    gera_cadastro(v, n, SEMENTE_CADASTRO);
    gera_consultas(v, n, q, CONSULTAS, SEMENTE_CONSULTAS);

    printf("Cadastro: N = %d alunos | %d consultas (metade existe) | t = %d | m = %d\n\n", n, CONSULTAS, t, m);
    printf("| %-26s | %10s | %9s | %16s | %-17s |\n", "Estrutura", "Preparo(s)", "Busca(s)", "Comparacoes/busca", "Resultados");
    printf("|----------------------------|------------|-----------|------------------|-------------------|\n");

    /* 1. Sequencial (referência) */
    double t0 = agora();
    comparacoes = 0;
    for (int k = 0; k < CONSULTAS; k++) ref[k] = busca_sequencial(v, n, q[k]);
    double tb = agora() - t0;
    linha("Sequencial", -1, tb, (double)comparacoes / CONSULTAS, CONSULTAS, CONSULTAS);

    /* 2. Ordenação + busca binária */
    Aluno *ord = malloc(sizeof(Aluno) * (size_t)n);
    memcpy(ord, v, sizeof(Aluno) * (size_t)n);
    comparacoes = 0;
    t0 = agora();
    ordena_quick(ord, n);
    double tq = agora() - t0;
    long long cq = comparacoes;
    int ok_ord = ordenado(ord, n);
    if (ok_ord) {
        int acertos = 0;
        comparacoes = 0;
        t0 = agora();
        for (int k = 0; k < CONSULTAS; k++) {
            int p = busca_binaria(ord, n, q[k]);
            int certo = (ref[k] < 0) ? (p < 0) : (p >= 0 && ord[p].matricula == q[k]);
            acertos += certo;
        }
        tb = agora() - t0;
        linha("Binaria (vetor ordenado)", tq, tb, (double)comparacoes / CONSULTAS, acertos, CONSULTAS);
    } else {
        printf("| %-26s | ordena_quick nao ordenou o vetor: busca binaria nao testada          |\n", "Binaria");
    }

    /* 3. Hash com encadeamento */
    Hash *h = NULL;
    t0 = agora();
    h = hash_cria(m);
    if (h != NULL) {
        for (int i = 0; i < n; i++) hash_insere(h, v[i].matricula, i);
        double tp = agora() - t0;
        int acertos = 0;
        comparacoes = 0;
        t0 = agora();
        for (int k = 0; k < CONSULTAS; k++) acertos += (hash_busca(h, q[k]) == ref[k]);
        tb = agora() - t0;
        char nome[40];
        snprintf(nome, sizeof nome, "Hash (alfa = %.2f)", (double)h->n / h->m);
        linha(nome, tp, tb, (double)comparacoes / CONSULTAS, acertos, CONSULTAS);
    } else {
        printf("| %-26s | hash_cria ainda nao implementada                                      |\n", "Hash");
    }

    /* 4. Árvore-B */
    ArvoreB *a = arvb_cria(t);
    t0 = agora();
    for (int i = 0; i < n; i++) arvb_insere(a, v[i].matricula, i);
    double tp = agora() - t0;
    int acertos = 0;
    comparacoes = 0;
    t0 = agora();
    for (int k = 0; k < CONSULTAS; k++) acertos += (arvb_busca(a, q[k]) == ref[k]);
    tb = agora() - t0;
    char nome[40];
    snprintf(nome, sizeof nome, "Arvore-B (t = %d)", t);
    linha(nome, tp, tb, (double)comparacoes / CONSULTAS, acertos, CONSULTAS);

    /* Detalhes */
    printf("\nDetalhes\n");
    printf("  Quicksort:  %lld comparacoes, %.4f s, vetor %s\n", cq, tq, ok_ord ? "ordenado" : "NAO ordenado");
    if (n <= 20000) {
        memcpy(ord, v, sizeof(Aluno) * (size_t)n);
        comparacoes = 0;
        t0 = agora();
        ordena_insercao(ord, n);
        printf("  Insercao:   %lld comparacoes, %.4f s, vetor %s\n", comparacoes, agora() - t0,
               ordenado(ord, n) ? "ordenado" : "NAO ordenado");
    } else {
        printf("  Insercao:   pulada (N > 20000 demoraria demais; rode com N = 10000)\n");
    }
    if (h != NULL)
        printf("  Hash:       m = %d listas, %d chaves, maior lista = %d\n", h->m, h->n, hash_maior_lista(h));
    printf("  Arvore-B:   altura = %d, nos = %ld, ate %d chaves por no\n", arvb_altura(a), a->nos, 2 * t - 1);

    /* Desafio: alunos que ingressaram em 2024 */
    int esperado = 0;
    for (int i = 0; i < n; i++)
        if (v[i].matricula >= 202400000 && v[i].matricula <= 202499999) esperado++;
    int obtido = arvb_conta_faixa(a, 202400000, 202499999);
    if (obtido < 0)
        printf("  Desafio:    arvb_conta_faixa ainda nao implementada\n");
    else
        printf("  Desafio:    ingressantes de 2024 = %d (esperado %d) %s\n", obtido, esperado, obtido == esperado ? "OK" : "ERRO");

    hash_libera(h);
    arvb_libera(a);
    free(ord); free(ref); free(q); free(v);
    return 0;
}
