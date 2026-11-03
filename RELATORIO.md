# Relatório: Comparativo de Estruturas de Busca

Grupo: __________________________________________

Copiem os valores da coluna **Comparacoes/busca** (e dos Detalhes, quando pedido). Os tempos são opcionais, porque variam de um computador para outro.

## E1. Crescimento de N (t = 3, alfa = 1)

| N | Sequencial | Binária | Hash | Árvore-B |
| --- | --- | --- | --- | --- |
| 10.000 |  |  |  |  |
| 50.000 |  |  |  |  |
| 100.000 |  |  |  |  |
| 200.000 |  |  |  |  |

**Perguntas**

1. Na busca sequencial, quantas comparações são feitas quando a matrícula existe? E quando não existe? Usem isso para explicar por que a média fica perto de 0,75 × N.
2. Calculem log₂ N para cada N e comparem com a coluna da binária. O que acontece com as comparações quando N dobra?
3. Qual estrutura quase não muda quando N cresce? Por quê?

## E2. Ordenação

| Algoritmo | N | Comparações | Tempo (s) |
| --- | --- | --- | --- |
| Inserção | 10.000 |  |  |
| Quicksort | 10.000 |  |  |
| Quicksort | 100.000 |  |  |

**Perguntas**

4. Quantas vezes a Inserção fez mais comparações que o Quicksort com N = 10.000? Relacionem com as complexidades O(n²) e O(n log n).
5. Para usar a busca binária é preciso ordenar antes. Com N = 100.000, depois de quantas buscas o custo do Quicksort "se paga", comparado a fazer só buscas sequenciais? Mostrem a conta.

## E3. Grau da Árvore-B (N = 100.000)

| t | Máx. chaves por nó | Altura | Nós | Nós visitados por busca |
| --- | --- | --- | --- | --- |
| 2 |  |  |  |  |
| 3 |  |  |  |  |
| 10 |  |  |  |  |
| 50 |  |  |  |  |

**Perguntas**

6. Por que a altura cai quando t aumenta?
7. Com t = 50, cada nó visitado pode exigir até 99 comparações dentro do nó. Mesmo assim, por que bancos de dados usam árvores com nós grandes? Pensem em cada nó como uma leitura de disco.

## E4. Fator de carga da hash (N = 100.000)

| alfa | m (listas) | Comparações por busca | Maior lista |
| --- | --- | --- | --- |
| 0,5 |  |  |  |
| 1 |  |  |  |
| 2 |  |  |  |
| 5 |  |  |  |

**Perguntas**

8. A teoria diz que, no encadeamento, uma busca com sucesso faz em média cerca de 1 + alfa/2 comparações e uma busca sem sucesso faz cerca de alfa. Como metade das consultas existe, qual seria a média teórica para cada alfa? Comparem com o medido.
9. Por que é possível ter comparação por busca menor que 1?

## Conclusão

10. Qual estrutura vocês escolheriam em cada situação? Justifiquem.
    1. Sistema que só busca alunos pela matrícula, com o cadastro inteiro na memória.
    2. Relatório que lista os alunos em ordem de matrícula ou por faixa (ex.: todos os ingressantes de 2024).
    3. Índice de um banco de dados guardado em disco, com milhões de registros.

## Divisão do trabalho

| Integrante | O que fez |
| --- | --- |
|  |  |
|  |  |
|  |  |
