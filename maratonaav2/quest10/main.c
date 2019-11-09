#include <stdio.h>
#include <stdlib.h>

int main() {


    int main() {
        int i, j, x=0, y=0;
        int b[9], c[10];

        for(i=0; i<9; i++) {
            printf("digite os elementos do vetor ");
            scanf("%d", &x);
            b[i] = x;
        }

        printf("digite o valor: ");
        scanf("%d", &y);

        c[0] = y;
        for(i=0; i<10; i++) {
            c[i+1] = b[i];
        }

        for(i=0; i<10; i++) {
            printf("%d ", c[i]);
        }

        return 0;
    }

    return 0;
}
