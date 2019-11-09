#include <stdio.h>
#include <stdlib.h>

int vet[9] = {5, 8, 6, 2, 3, 4, 1, 1, 7};

void imprimir(){
  int ind = 0;
  for(int i = 0; i < 9; i++){
    printf("%d ", ind);
    ind = vet[ind];
  }
}

int main() {
    imprimir();
    return 0;
}
