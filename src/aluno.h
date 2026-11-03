#ifndef ALUNO_H
#define ALUNO_H

/* Registro do cadastro. A chave de busca é a matrícula. */
typedef struct {
    int matricula;
    char nome[24];
    float media;
} Aluno;

/* Gerador de números aleatórios próprio, para que todos os computadores
   (Windows, Linux, Mac) gerem exatamente os mesmos dados. */
void semear(unsigned int semente);
unsigned int aleatorio(void);

/* Preenche v com n alunos (n <= 1.000.000) de matrículas sorteadas, sem
   repetição, no formato ano + 5 dígitos (ex.: 202304817). O vetor fica
   fora de ordem. */
void gera_cadastro(Aluno *v, int n, unsigned int semente);

/* Preenche q com nq matrículas a procurar: metade existe no cadastro e
   metade não existe no cadastro. Chame depois de gera_cadastro. */
void gera_consultas(const Aluno *v, int n, int *q, int nq, unsigned int semente);

#endif
