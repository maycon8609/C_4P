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
    printf(" Raiz exata  ");
  }else {
    printf(" Raiz aproximada  ");
  }
  return cont;
}


int main() {
    printf("%d",raizQ(25));

    return 0;
}
