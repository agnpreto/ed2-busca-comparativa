#include <time.h>
#include "medicao.h"

long long comparacoes = 0;

double agora(void) { return (double)clock() / CLOCKS_PER_SEC; }

static int eh_primo(int x) {
    if (x < 2) return 0;
    for (int d = 2; (long long)d * d <= x; d++)
        if (x % d == 0) return 0;
    return 1;
}

int primo_ge(int n) {
    while (!eh_primo(n)) n++;
    return n;
}
