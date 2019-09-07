#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main() {
    int x = 5, y = 2;

    int som = soma(x, y);
    int sub = subtracao(x, y);
    int mult = multipicacao(x, y);
    int div = divisao(x, y);

    printf("soma de %d + %d = %d \n", x, y, som);
    printf("subtracao de %d - %d = %d \n", x, y, sub);
    printf("multiplicacao de %d * %d = %d \n", x, y, mult);
    // 5 / 2 = 2 por se tratar de numeros inteiros
    printf("divisao de %d / %d = %d \n", x, y, div);

    return 0;
}
