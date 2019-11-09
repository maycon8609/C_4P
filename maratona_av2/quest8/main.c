#include<stdio.h>

int main() {
    int i, j, x=0, y=0, soma=0;
    int vet1[10];

    for(i=0; i<10; i++) {
        scanf("%d", &x);
        if(x<=0) {
            break;
        } else(vet1[i] = x);
        y++;
    }

    for(i=0; i<y; i++) {
        if(vet1[i] > 5) {
            soma = soma + vet1[i];
        }
        //printf("%d ", vet1[i]);
    }

    printf("%d ", soma);


    return 0;
}
