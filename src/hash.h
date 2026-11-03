#ifndef HASH_H
#define HASH_H

/* Tabela hash com tratamento de colisão por encadeamento. */
typedef struct NoHash {
    int chave;              /* matrícula */
    int pos;                /* posição do aluno no vetor do cadastro */
    struct NoHash *prox;
} NoHash;

typedef struct {
    int m;                  /* tamanho da tabela (número de listas) */
    int n;                  /* quantidade de chaves inseridas */
    NoHash **lista;         /* vetor de m ponteiros para o início de cada lista */
} Hash;

Hash *hash_cria(int m);                          /* tabela vazia com m listas */
int   hash_funcao(const Hash *h, int chave);     /* h(k) = k % m */
void  hash_insere(Hash *h, int chave, int pos);  /* insere no INÍCIO da lista */
int   hash_busca(const Hash *h, int chave);      /* pos do aluno ou -1; +1 em comparacoes por nó visitado */
int   hash_maior_lista(const Hash *h);           /* tamanho da maior lista */
void  hash_libera(Hash *h);

#endif
