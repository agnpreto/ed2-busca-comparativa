#ifndef MEDICAO_H
#define MEDICAO_H

/* Contador global de comparações de chave (ou nós visitados).
   Cada estrutura soma 1 aqui a cada comparação que fizer. */
extern long long comparacoes;

/* Tempo do processador em segundos, para medir trechos de código. */
double agora(void);

/* Menor número primo maior ou igual a n (tamanho da tabela hash). */
int primo_ge(int n);

#endif
