#include <stdio.h>
#include <stdlib.h>
#define a 10
#define r 5

int loto[r];
int gab[a];

void addLoto(){
  printf(" numeros da loto \n");
  int cont = 1;
  for(int i = 0; i < r; i++){
    printf("numero %d  ", cont);
    scanf("%d", &loto[i]);
    cont++;
  }
}

void addGab(){
  printf(" numeros que voce jogou \n");
  int cont = 1;
  for(int i = 0; i < a; i++){
    printf("numero %d  ", cont);
    scanf("%d", &gab[i]);
    cont++;
  }
}

int verific(){
  int acert = 0;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < a; j++){
      if(loto[i] == gab[j]){
        acert++;
      }
    }
  }
  return acert;
}

void exec(){
  addLoto();
  addGab();
  printf(" %d acertos", verific());
}

int main() {
    exec();

    return 0;
}
