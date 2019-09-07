#include "func.h"
#define row 3
#define coll 4

float add(float matriz[row][coll]) {
  for(int i = 0; i < row; i++) {
    printf(" CODE ALUNO: ");
    scanf("%f", &matriz[i][0]);
     for(int j = 1; j < coll; j++) {
       printf("nota do aluno %d", j);
       scanf("%f", &matriz[i][j]);
     }
  }
}

float media(float matriz[][coll]) {

}

void imprimir(float matriz[][coll]) {

}
