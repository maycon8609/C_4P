#include <stdio.h>
#include <stdlib.h>

int exec() {
    int num1 = 0, num2 = 0, mdc = 1, divisor = 2;

    printf(" INSIRA DOIS NUMEROS INTEIROS \n");
    scanf("%d%d", &num1, &num2);

    while(num1 > 1 || num2 > 1) {
        if(num1 % divisor == 0 || num2 % divisor == 0) {
            if(num1 % divisor == 0) {
                num1 /= divisor;
            }
            if(num2 % divisor == 0) {
                num2 /= divisor;
            }
            mdc *= divisor;
        } else {
            divisor++;
        }
    }

    printf(" MDC = %d\n", mdc);
}


int main() {
    exec();

    return 0;
}
