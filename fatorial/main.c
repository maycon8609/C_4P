#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    int fat = 1;

    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        for(int i = 2; i <= n; i++) {
            fat *= i;
        }
        return fat;
    }
}

float soma(float n) {
  float total = 1;
  for(int i = 1; i <= n; i++){
    float fat = fatorial(i);
    printf("%0.2f\n", fat);
    total += (1 / fat);
  }
  return total;
}

int main() {
    printf("%d\n", fatorial(3));
    printf("%0.2f", soma(3));
}
