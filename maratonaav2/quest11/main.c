quest 2

#include <stdio.h>
#include <stdlib.h>

int vet[9] = {5, 8, 6, 2, 3, 4, 1, 1, 7};

void imprimir(){
  int ind = 0;
  for(int i = 0; i < 9; i++){
    printf("%d ", ind);
    ind = vet[ind];
  }
}

int main() {
    imprimir();
    return 0;
}


quest 3

#include <stdio.h>
#include <stdlib.h>

int main() {
    int  r[5], s[10], x[5], i, j, cont = 0;
    for(i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d",&r[i]);
    }
    for(i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &s[i]);
    }
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 10; j++) {
            if(r[i] == s[j]) {
                x[cont] = s[j];
                cont++;
                break;
            }
        }
    }
    for(i = 0; i < cont; i++) {
        printf("%d  ", x[i]);
    }
    return 0;
}

quest 4

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


quest 5

#include<stdio.h>

int main() {
    int i, j, x=0, y=0;
    int vet1[10];

    for(i=0; i<10; i++) {
        scanf("%d", &x);
        vet1[i] = x;
    }

    for(i=0; i<10; i++) {
        if(vet1[i]>0) {
            printf("%d ", vet1[i]);
        }
    }
    return 0;
}


quest 6

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


quest 7

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x[10], y[10], r[20], i, cont = 0;
    for(i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &x[i]);
    }
    for(i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &y[i]);
    }
    for(i = 0; i < 10; i++) {
        r[cont]= x[i];
        cont+=2;
    }
    cont=1;
    for(i = 0; i < 10; i++) {
        r[cont]= y[i];
        cont+=2;
    }
    for(i = 0; i < 20; i++) {
        printf("%d  ", r[i]);
    }
    return 0;
}


quest 8

 #include<stdio.h>

int main() {
    int i, j, x=0, y=0, soma=0;
    int vet1[10];

    for(i=0; i<10; i++) {
        scanf("%d", &x);
        if(x<=0) {
            break;
        } else(vet1[i] = x);
        y++;
    }

    for(i=0; i<y; i++) {
        if(vet1[i] > 5) {
            soma = soma + vet1[i];
        }
        //printf("%d ", vet1[i]);
    }

    printf("%d ", soma);


    return 0;
}


quest 10

#include <stdio.h>
#include <stdlib.h>

int main() {


    int main() {
        int i, j, x=0, y=0;
        int b[9], c[10];

        for(i=0; i<9; i++) {
            printf("digite os elementos do vetor ");
            scanf("%d", &x);
            b[i] = x;
        }

        printf("digite o valor: ");
        scanf("%d", &y);

        c[0] = y;
        for(i=0; i<10; i++) {
            c[i+1] = b[i];
        }

        for(i=0; i<10; i++) {
            printf("%d ", c[i]);
        }

        return 0;
    }

    return 0;
}

quest 11

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int vet10[10] = {7, 4, 4, 5, 7, 2, 1, 3, 4, 6};
int vet5[10];
int cont = 0;

void rept(){
  int verif = 0;
  for(int i = 0; i < 10; i++){
    verif = 0;
    for(int j = 0; j < 10; j++){
      if(vet10[i] == vet10[j]){
        verif++;
      }
    }
    if(verif == 1){
      vet5[cont] = vet10[i];
      cont++;
    }
  }
}

void imprimir(int vet[], int tam){
  for(int i = 0; i < tam; i++){
    printf("  %d", vet[i]);
  }
}

int main() {
    rept();
    printf(" vet 10 \n");
    imprimir(vet10, 10);
    printf("\n");
    printf(" vet 5 \n");
    imprimir(vet5, 5);
    return 0;
}


