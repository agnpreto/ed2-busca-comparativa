#include <stdio.h>
#include <string.h>
#include "aluno.h"

static unsigned int estado = 1;

void semear(unsigned int semente) { estado = semente ? semente : 1; }

/* xorshift32 */
unsigned int aleatorio(void) {
    estado ^= estado << 13;
    estado ^= estado >> 17;
    estado ^= estado << 5;
    return estado;
}

/* Matrícula = ano de ingresso (2015 a 2026) + 5 dígitos. Ex.: 202304817 */
#define ANOS 12
#define FAIXA (ANOS * 100000)
static unsigned char usada[FAIXA];

static int sorteia_matricula(void) {
    int r = (int)(aleatorio() % FAIXA);
    return (2015 + r / 100000) * 100000 + r % 100000;
}

static int indice(int mat) { return (mat / 100000 - 2015) * 100000 + mat % 100000; }

void gera_cadastro(Aluno *v, int n, unsigned int semente) {
    semear(semente);
    memset(usada, 0, sizeof usada);
    for (int i = 0; i < n; i++) {
        int mat;
        do mat = sorteia_matricula(); while (usada[indice(mat)]);
        usada[indice(mat)] = 1;
        v[i].matricula = mat;
        snprintf(v[i].nome, sizeof v[i].nome, "Aluno %06d", i);
        v[i].media = (aleatorio() % 1001) / 100.0f;
    }
}

void gera_consultas(const Aluno *v, int n, int *q, int nq, unsigned int semente) {
    semear(semente);
    for (int k = 0; k < nq; k++) {
        if (k % 2 == 0) {
            q[k] = v[aleatorio() % (unsigned int)n].matricula;     /* existe */
        } else {
            int mat;
            do mat = sorteia_matricula(); while (usada[indice(mat)]);
            q[k] = mat;                                           /* não existe */
        }
    }
}
