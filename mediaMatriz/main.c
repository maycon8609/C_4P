#include<stdio.h>
#include<stdlib.h>

void somar(float alunos[][4]){
  int soma = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 1; j < 4; j++){
      soma += &alunos[i][j];
    }
    alunos[i][4] = (soma / 3);
    soma = 0;
  }
}

void addNotas(float alunos[][4]) {
  for(int i = 0; i < 3; i++) {
    printf(" CODE ALUNO %d: ", i+1);
    scanf("%f", &alunos[i][0]);
    for(int j = 1; j < 4; j++) {
      printf(" NOTA %d ", j);
      scanf("%f", &alunos[i][j]);
    }
  }
  somar(alunos);
}

void imprimir(float alunos[][4]){
  for(int i = 0; i < 3; i++){
    printf(" CODE %f %d \n", &alunos[i][0]);
    printf(" NOTA 1 %f %d \n", &alunos[i][1]);
    printf(" NOTA 2 %f %d \n", &alunos[i][2]);
    printf(" NOTA 3 %f %d \n", &alunos[i][3]);
    printf(" MEDIA %f %d \n", &alunos[i][4]);
  }
}

int main(void) {
  float alunos [3][4];

  addNotas(alunos);
  imprimir(alunos);

}
