#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPar(int n){
  if(n % 2 == 0){
    return true;
  }else{
    return false;
  }
}

void exec(){
  int vet[100];
  int num;

  int m = 0, f = 0;

  printf(" NUMERO DE CARTOES DISTRIBUIDOS ");
  scanf("%d", &num);
  vet[num];
  printf(" NUMERO DOS CARTOES \n");

  for(int i = 0; i < num; i++){
    scanf("%d", &vet[i]);

    if(isPar(vet[i])){
      m++;
    }else{
      f++;
    }
  }

  if(m == f){
    printf(" S ");
  }else{
    printf(" N ");
  }

}


int main() {
    exec();

    return 0;
}
