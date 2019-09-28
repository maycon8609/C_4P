#include <stdio.h>
#include <stdlib.h>

void exec(){
  float media, soman = 0, somap = 0, nota = 1, peso = 0;

  printf(" DIGITE AS NOTA SEQUIDAS DO PESO \n");

  while(nota != 0){
  scanf("%f", &nota);
    if(nota == 0){
      break;
    }else{
      scanf("%f", &peso);
      soman += (peso * nota);
      somap += peso;
    }
  }
  printf("%f", soman);
  printf("%f", somap);
  media = soman / somap;
  printf(" MEDIA = %0.2f", media);
}

int main() {
    exec();

    return 0;
}
