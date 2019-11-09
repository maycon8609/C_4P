#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct generic{
  char code[50];
  char nome[50];
  char tipo[50];
  int qtd;
  float valor1;
  float valor2;
}generic;

// vetores
generic vetProd[500];
int tProd = 0;

generic vetFunc[50];
int tFunc = 0;

generic vetVend[500];
int tVend = 0;

// ponteiros
FILE *fProd;
FILE *fFunc;
FILE *fVend;

// abrir & salvar arquivos.txt
void openFile(char arquivo[], generic vetor[], int *tam, FILE *pont){
  if(pont = fopen(arquivo, "r")){
    while((fscanf(pont, "%s %s %s %d %f %f",
            &vetor[*tam].nome,
            &vetor[*tam].code,
            &vetor[*tam].tipo,
            &vetor[*tam].qtd,
            &vetor[*tam].valor1,
            &vetor[*tam].valor2)) != EOF){
      (*tam)++;
    }
  }
}

void saveFile(char arquivo[], generic vetor[], int tam, FILE *pont){
  if(pont = fopen(arquivo, "w")){
    for(int i = 0; i < tam; i++){
      fprintf(pont, "%s\n", vetor[i].nome);
      fprintf(pont, "%s\n", vetor[i].code);
      fprintf(pont, "%s\n", vetor[i].tipo);
      fprintf(pont, "%d\n", vetor[i].qtd);
      fprintf(pont, "%.2f\n", vetor[i].valor1);
      fprintf(pont, "%.2f\n", vetor[i].valor2);
    }
  }
}

// funcoes exclusivas de produtos
float lucroProd(int pos){
  return vetProd[pos].valor2 - vetProd[pos].valor1;
}


// funcoes exclusivas de funcionarios
float returnSalario(int ind){
  return (vetFunc[ind].qtd * vetFunc[ind].valor1) + vetFunc[ind].valor2;
}

// funcoes gerais produtos, funcionarios & vendas
bool exist(char code[], generic vetor[], int tam){
  for(int i = 0; i < tam; i++){
    if(strcmp(code, vetor[i].code) == 0){
      return true;
      break;
    }
  }
  return false;
}

void list(generic vetor[], int tam){
  for(int i = 0; i < tam; i++){
    printf("%s\n",vetor[i].nome);
    printf("%s\n",vetor[i].code);
    printf("%s\n",vetor[i].tipo);
    printf("%d\n",vetor[i].qtd);
    printf("%.2f\n",vetor[i].valor1);
    printf("%.2f\n",vetor[i].valor2);
  }
}

void cadastrar(generic vetor[], int *tam){
    printf("\33[H\33[2J");
    char nome[50], code[20];

    if(vetor == vetProd){
      printf(" Cadastrar Novo Produto\n");
    } else {
      printf(" Cadastrar Novo Funcionario\n");
    }
    printf("   Nome ------------- ");
    scanf("%s", &nome);
    printf("   Code ------------- ");
    scanf("%s", &code);
    if(!exist(code, vetProd, tProd)){
      sprintf(vetor[*tam].nome, "%s", nome);
      sprintf(vetor[*tam].code, "%s", code);

        if(vetor == vetProd)
            printf("   Tipo Produto ----- ");
          else
            printf("   Cargo ------------ ");
        scanf("%s", &vetor[*tam].tipo);

        if(vetor == vetProd)
          printf("   Quantidade ------- ");
        else
          printf("   Horas Mensais ---- ");
        scanf("%d", &vetor[*tam].qtd);

        if(vetor == vetProd)
          printf("   Preco de Compra  - ");
        else
          printf("   Valor Hora ------- ");
        scanf("%f", &vetor[*tam].valor1);

        if(vetor == vetProd)
          printf("   Preco de Venda --- ");
        else
          printf("   Valor fixo ------- ");
        scanf("%f", &vetor[*tam].valor2);

      (*tam)++;
    } else {
      printf("%s ja cadastrado\n", nome);
    }
}

void buscar(generic vetor[], int tam){
    printf("\33[H\33[2J");
    int verific = 0;
    char code[50];

      if(vetor == vetProd)
        printf(" Buscar Produto\\Code  ");
      else
        printf(" Buscar Funcionario\\Code  ");

      scanf("%s", &code);

    for(int i = 0; i < tam; i++){
      if(strcmp(code, vetor[i].code) == 0){
        verific = 1;
          printf("  Nome --------- %s\n", vetor[i].nome);
          printf("  Code --------- %s\n", vetor[i].code);
        if(vetor == vetProd){
        printf("  Tipo Produto - %s\n", vetor[i].tipo);
        printf("  Preco Venda -- %.2f\n", vetor[i].valor2);
        }else{
          printf("  Cargo -------- %s\n", vetor[i].tipo);
          printf("  Salario ------ %.2f\n", returnSalario(i));
        }
      }
    }

    if(verific == 0)
      printf("  %s nao encontrado\n", code);
}


void editar(generic vetor[], int tam){
  printf("\33[H\33[2J");
  char code[30];
  int verif = 0;

      if(vetor == vetProd)
        printf(" Editar Produto \n");
      else
        printf(" Editar Funcionario \n");
      printf(" Digitar Code  ");
      scanf("%s", &code);

    for(int i = 0; i < tam; i++){
      if(strcmp(code, vetor[i].code) == 0){
        printf(" Informe Novos Dados \n");
        verif = 1;
        printf("  Nome ------------- ");
        scanf("%s", &vetor[i].nome);
        printf("  Code ------------- ");
        scanf("%s", &vetor[i].code);

          if(vetor == vetProd)
            printf("  Tipo Produto ----- ");
          else
            printf("  Cargo ------------ ");
          scanf("%s", &vetor[i].tipo);

          if(vetor == vetProd)
            printf("  Quantidade ------- ");
          else
            printf("  Horas Mensais ---- ");
          scanf("%d", &vetor[i].qtd);

          if(vetor == vetProd)
            printf("  Preco de Compra  - ");
          else
            printf("  Valor Hora ------- ");
          scanf("%f", &vetor[i].valor1);

          if(vetor == vetProd)
            printf("  Preco de Venda --- ");
          else
            printf("  Valor fixo ------- ");
          scanf("%f", &vetor[i].valor2);
      }
    }

    if(verif == 0)
      printf(" %s nao encontrado ", code);
}

void exec(){
  openFile("produtos.txt", vetProd, &tProd, fProd);
  openFile("funcionarios.txt", vetFunc, &tFunc, fFunc);
  list(vetProd, tProd);
  list(vetFunc, tFunc);
  //cadastrar(vetProd, &tProd);
  //buscar(vetProd, tProd);
  editar(vetFunc, tFunc);
  buscar(vetFunc, tFunc);
  saveFile("produtos.txt", vetProd, tProd, fProd);
  saveFile("funcionarios.txt", vetFunc, tFunc, fFunc);
}

int main() {
    exec();
    return 0;
}
