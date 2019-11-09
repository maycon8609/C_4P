#include <stdio.h>
#include <stdlib.h>

int main() {
    int  r[5], s[10], x[5], i, j, cont = 0;
    for(i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d",&r[i]);
    }
    for(i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &s[i]);
    }
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 10; j++) {
            if(r[i] == s[j]) {
                x[cont] = s[j];
                cont++;
                break;
            }
        }
    }
    for(i = 0; i < cont; i++) {
        printf("%d  ", x[i]);
    }
    return 0;
}
