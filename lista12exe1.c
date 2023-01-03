#include <stdio.h>
#include <stdlib.h>


int mdc_recursiva(int a, int b) {
    printf("\n%d e %d", a, b);
    if (a % b == 0) return b;
    return mdc_recursiva (b, a % b);

}

int main() {
    int a=32, b=18;
    printf("\nResultado=%d",mdc_recursiva(a, b));
    printf("\n\na funcão verifica se o resto da divisao de a e b eh igual a 0 se sim retorna b pq ele eh o mdc\n");
    printf("\nse nao ele retorna fazendo o mdc so que b vira o a, e o resto da divisao de a e b vira b\n");
    printf("\ne fica nisso ate resto da divisao de a e b se torna igual a 0, no pior cenario ira rodar direto ate retorna 1\n");
}
