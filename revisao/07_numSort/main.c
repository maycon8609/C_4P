#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exec() {
    srand(time(NULL));
    int vet[10], modifi[10];
    int cont = 0;
    modifi[0] = vet[0];

    //Adicionar valores aleatorios
    for(int i = 0; i < 10; i++){
      vet[i] = rand()%10;
    }

    //Imprimir valores normais
    printf(" VETOR ORIGINAL \n");
    for(int i = 0; i < 10; i++){
      printf(" %d", vet[i]);
    }
    printf("\n");
    printf("\n");

    //Valores manipulados
    printf(" VETOR MANIPULADO \n");

    //
    for(int i = 0; i < 10; i++){
      for(int j = 0; j <= i; j++){
        cont += vet[j];
      }
      modifi[i] = cont;
      cont = 0;
    }

    for(int i = 0; i < 10; i++){
      printf(" %d", modifi[i]);
    }
    printf("\n");

}


int main() {
    exec();
    return 0;
}
