#include <stdio.h>
#include <stdlib.h>

float soma(float x, float y){
  return x + y;
}

float subtracao(float x, float y){
  return x - y;
}

float multiplicacao(float x, float y){
  return x * y;
}

float divisao(float x, float y){
  return x / y;
}

int main() {
    float x, y;

    printf(" ENTER COM X E Y \n");
    scanf("%f", &x);
    scanf("%f", &y);

    printf(" soma de %0.1f + %0.1f = %0.1f \n", x, y, soma(x, y));
    printf(" subtração de %0.1f - %0.1f = %0.1f \n", x, y, subtracao(x, y));
    printf(" multiplicação de %0.1f * %0.1f = %0.1f \n", x, y, multiplicacao(x, y));
    printf(" divisao de %0.1f / %0.1f = %0.1f \n", x, y, divisao(x, y)
    );

    return 0;
}
