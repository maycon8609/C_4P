#include <stdio.h>
#include <stdlib.h>


int raizQ(int n){
  int sub = 1;
  int cont = 0;
  while(n >= sub){
    n -= sub;
    sub += 2;
    cont++;
  }
  if(n == 0){
    return 1;
  }
  return 0;
}

void exec(){
  int n, cont = 0;

  do{
  printf(" Digite um numero maior que 0 || 0 - sair \n");
  scanf("%d", &n);

  if(raizQ(n) == 1 && n > 0){
    cont++;
  }

  }while(n > 0);

  printf(" EXISTE %d NUMEROS PERFEITOS", cont);
}

int main() {
    exec();
    return 0;
}
