#include <stdio.h>
#include <stdlib.h>

void exec(){
  int n1 = 0, n2 = 1, res = 0, quant = 0;

  printf(" QUANTIDADE ");
  scanf("%d", &quant);

  if(quant == 0){
    printf(" 0 \n");
  }else if(quant == 1){
    printf(" 0 \n");
  }else{
    printf(" 0 \n");
    printf(" 1 \n");
    int aux = quant - 2;
    for(int i = 0; i < aux; i++){
      res = n1 + n2;
      n1 = n2;
      n2 = res;
      printf("%d\n", res);
    }
  }

}

int main() {
    exec();

    return 0;
}
