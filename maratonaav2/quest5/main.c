#include<stdio.h>

int main() {
    int i, j, x=0, y=0;
    int vet1[10];

    for(i=0; i<10; i++) {
        scanf("%d", &x);
        vet1[i] = x;
    }

    for(i=0; i<10; i++) {
        if(vet1[i]>0) {
            printf("%d ", vet1[i]);
        }
    }
    return 0;
}

