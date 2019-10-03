#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// tam = tamanho inicial do vetor
int tam;
int vet[100];

// verificar se "a" ja existe no vetor
bool verificar(int a){
  for(int i = 0; i < tam; i++){
    if(a == vet[i]){
      return true;
    }
  }
  return false;
}

// ordenar numeros (Bubble Sort)
void ordenar(){
  int aux;
  for(int i = 0; i < tam; i ++){
    for(int j = i; j < tam; j++){
      if(vet[i] > vet[j]){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
    }
  }
}

// imprimir
void imprimir(){
  for(int i = 0; i < tam; i++){
    if(vet[i] > 0){
      printf(" POS %d = %d \n", i, vet[i]);
    }
  }
}


int input(){
  int num;

  // TAMANHO DO VETOR
  printf(" DIGITE O TAMANHO DO VETOR \n");
  scanf("%d", &tam);

  // ENTRADA DE DADOS DO VETOR
  printf(" DIGITE OS NUMEROS \n");
  for(int i = 0; i < tam; i++){
      scanf("%d", &num);
      if(!verificar(num) && num > 0){
        vet[i] = num;
      }
  }
}

void exec(){
  input();
  printf(" SEM ORDENAÇÃO \n");
  imprimir();
  ordenar();
  printf(" COM ORDENAÇÃO \n");
  imprimir();
}

int main() {
    exec();
    return 0;
}
