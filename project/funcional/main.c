#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct generico{
  char nome[100];
  char tipo[50];
  char codProd[50];
  char codFunc[50];
  int quant;
  float valTotal;
  float lucroVend;
  float preco;
  float precoCompra;
  float precoVenda;
  float lucro;
}generico;

/* vetores */

generico vetProd[500];
int tProd = 0;

generico vetFunc[100];
int tFunc = 0;

generico vetVend[1000];
int tVend = 0;

/* ponteiros */

FILE *fProd;
FILE *fFunc;
FILE *fVend;

/* abrir e salvar arquivos */

void openFile(){
  // arquivo de produtos
  if(fProd = fopen("produtos.txt", "r")){
    while((fscanf(fProd, "%s %f %f %f %s %s",
            &vetProd[tProd].nome,
            &vetProd[tProd].precoCompra,
            &vetProd[tProd].precoVenda,
            &vetProd[tProd].lucro,
            &vetProd[tProd].tipo,
            &vetProd[tProd].codProd)) != EOF){
      tProd++;
    }
  }

  // arquivo de funcionarios
  if(fFunc = fopen("funcionarios.txt", "r")){
    while((fscanf(fFunc, "%s %s",
            &vetFunc[tFunc].nome,
            &vetFunc[tFunc].codFunc)) != EOF){
      tFunc++;
    }
  }

  // arquivo de vendas
  if(fVend = fopen("vendas.txt", "r")){
    while((fscanf(fVend, "%s %s %d %f %f",
            &vetVend[tVend].codFunc,
            &vetVend[tVend].codProd,
            &vetVend[tVend].quant,
            &vetVend[tVend].valTotal,
            &vetVend[tVend].lucroVend)) != EOF){
      tVend++;
    }
  }
}

void saveFile(){
  // arquivo de produtos
  if(fProd = fopen("produtos.txt", "w")){
    for(int i = 0; i < tProd; i++){
      fprintf(fProd, "%s\n", vetProd[i].nome);
      fprintf(fProd, "%.2f\n", vetProd[i].precoCompra);
      fprintf(fProd, "%.2f\n", vetProd[i].precoVenda);
      fprintf(fProd, "%.2f\n", vetProd[i].lucro);
      fprintf(fProd, "%s\n", vetProd[i].tipo);
      fprintf(fProd, "%s\n", vetProd[i].codProd);
    }
    fclose(fProd);
  }else{
    printf(" erro ao salvar produtos.txt ");
  }

  // arquivo de funcionarios
  if(fFunc = fopen("funcionarios.txt", "w")){
    for(int i = 0; i < tFunc; i++){
      fprintf(fFunc, "%s\n", vetFunc[i].nome);
      fprintf(fFunc, "%s\n", vetFunc[i].codFunc);
    }
    fclose(fFunc);
  }else{
    printf(" erro ao salvar funcionarios.txt ");
  }

  // arquivo de vendas
  if(fVend = fopen("vendas.txt", "w")){
    for(int i = 0; i < tVend; i++){
      fprintf(fVend, "%s\n", vetVend[i].codFunc);
      fprintf(fVend, "%s\n", vetVend[i].codProd);
      fprintf(fVend, "%d\n", vetVend[i].quant);
      fprintf(fVend, "%.2f\n", vetVend[i].valTotal);
      fprintf(fVend, "%.2f\n", vetVend[i].lucroVend);
    }
    fclose(fVend);
  }else{
    printf(" erro ao salvar vendas.txt ");
  }
}

/* funcoes produtos, funcionarios & vendas */

bool exist(char nome[], int tam, generico vetor[]){
  int verif = 0;
  for(int i = 0; i < tam; i++){
    if(strcmp(nome, vetor[i].nome) == 0){
      return true;
      verif = 1;
      break;
    }
  }

  if(verif == 0){
    printf(" %s nao encontrado \n", nome);
  }
  return false;
}

float lucroProd(){
  return vetProd[tProd].precoVenda - vetProd[tProd].precoCompra;
}

void cadastrarProd(){
  printf("\33[H\33[2J");

  bool verif = false;
  char nome[50];

  printf(" cadastrar novo produto \n");
  printf(" nome do produto  ");
  scanf("%s", &nome);

  if(!exist(nome, tProd, vetProd)){
    sprintf(vetProd[tProd].nome, "%s", nome);

    printf(" tipo do produto    ");
    scanf("%s", &vetProd[tProd].tipo);

    printf(" preco de compra    ");
    scanf("%f", &vetProd[tProd].precoCompra);

    printf(" preco de venda     ");
    scanf("%f", vetProd[tProd].precoVenda);

    printf(" codigo do produto  ");
    scanf("%s", vetProd[tProd].codProd);

    vetProd[tProd].lucro = lucroProd();
    tProd++;
  }else{
    printf(" produto ja cadastrado ");
  }
}

void buscar(char nome[], int tam, generico vetor[]){
  int verif = 0;
  for(int i = 0; i < tam; i++){
    if(strcmp(nome, vetor[i].nome) == 0){
      verif = 1;
      printf(" nome --------- %s\n", vetor[i].nome);
      if(vetor == vetProd){
        printf(" valor compra - %.2f\n", vetor[i].precoCompra);
        printf(" valor venda -- %.2f\n", vetor[i].precoVenda);
        printf(" lucro -------- %.2f\n", vetor[i].lucro);
        printf(" tipo produto - %s\n", vetor[i].tipo);
        printf(" codigo ------- %s\n", vetor[i].codProd);
      }else{
        printf(" codigo ------- %s\n", vetor[i].codFunc);
      }
    }
  }

  if(verif == 0){
      printf(" %s nao encontrado\n", nome);
    }
}

void exec(){
  openFile();
    buscar("arroz", tProd, vetProd);
    printf("\n");
    buscar("maycon", tFunc, vetFunc);
    printf("\n");
    buscar("mayco", tFunc, vetFunc);
  saveFile();
}

int main() {
    exec();
    return 0;
}
