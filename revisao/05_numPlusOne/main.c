#include <stdio.h>
#include <stdlib.h>

int vet[100], i = 0;

void input(){
  int n = 0;

  printf(" DIGITE N > 0 || 0 - SAIR \n");
  do{
    scanf("%d", &n);

    if(n != 0){
      vet[i] = ++n;
      i++;
    }

  }while(n > 0);
}

void imprimir(){
  for(int j = 0; j < i; j++){
    printf("%d\n", vet[j]);
  }
}

int main() {
    input();
    imprimir();
    return 0;
}
