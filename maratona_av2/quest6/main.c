#include <stdio.h>
#include <stdlib.h>

int tam = 0, cont = 0;
float media = 0;

float turma[10] = {8.5, 5, 10, 8, 3.5, 7, 9, 4, 2, 9};
int ind[10];

void buscMedia(){
  for(int i = 0; i < 10; i++){
    if(turma[i] >= 6){
      media += turma[i];
      cont++;
    }
  }
}

void imprimirInd(){
  for(int i = 0; i < tam; i++){
    printf("%.2f", ind[i]);
  }
}

int main() {

    buscMedia();
    buscInd();
    float mediaF = media / cont;
    for(int i = 0; i < 10; i++){
      if(turma[i] >= mediaF){
        printf("%d", i);
      }
    }
    return 0;
}
