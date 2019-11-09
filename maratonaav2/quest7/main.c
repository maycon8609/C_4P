#include <stdio.h>
#include <stdlib.h>

int main() {
    int x[10], y[10], r[20], i, cont = 0;
    for(i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &x[i]);
    }
    for(i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &y[i]);
    }
    for(i = 0; i < 10; i++) {
        r[cont]= x[i];
        cont+=2;
    }
    cont=1;
    for(i = 0; i < 10; i++) {
        r[cont]= y[i];
        cont+=2;
    }
    for(i = 0; i < 20; i++) {
        printf("%d  ", r[i]);
    }
    return 0;
}
