#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int numDivisores(int n){
  int cont = 0;
  for(int i = 1; i <= n; i++){
    if(n % i == 0){
      printf(" divisor %d \n", i);
      cont++;
    }
  }
  return cont;
}

bool isInt(int n){
  int aux = n;
  if(aux == n){
    return true;
  }else{
    return false;
  }
}

void exec(){
  int valor;
  bool aux = true;

  do{
    printf(" DIGITE UM NUMERO MAIOR QUE ZERO ");
    scanf("%d", &valor);

    if(isInt(valor) && valor > 0){
      if(valor < 10){
        printf(" fatorial de %d = %d \n", valor, fatorial(valor));
      }else{
        printf(" numero %d possui %d divisores \n", valor, numDivisores(valor));
      }
    }else{
      aux = false;
    }

  }while(aux == true);
}

int main() {
  exec();
}
