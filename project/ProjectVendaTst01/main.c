#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct produtos{
  char nome[40];
  float precoCompra;
  float precoVenda;
  float lucro;
  char tipo[20];
  char codProd[3];

}produtos;

// VETORES
produtos vetProd[100];
int tprod = 0;


// PONTEIROS
FILE *fprod;


// FUNCOES GLOBAIS

void abrirArquivos(){
  // Arquivo de produtos
  if(fprod = fopen("produtos.txt", "r")){
    while((fscanf(fprod, "%s %f %f %f %s %s",
            &vetProd[tprod].nome,
            &vetProd[tprod].precoCompra,
            &vetProd[tprod].precoVenda,
            &vetProd[tprod].lucro,
            &vetProd[tprod].tipo,
            &vetProd[tprod].codProd)) != EOF){
      tprod++;
    }
    printf(" produtos.txt ABERTO com exito \n");
  }else {
    printf(" erro ao ABRIR o aquivo produtos.txt \n");
  }
}

void salvarArquivos(){
  // Arquivo de produtos
  if(fprod = fopen("produtos.txt", "w")){
    for(int i = 0; i < tprod; i++){
      fprintf(fprod,"\n");
      fprintf(fprod, "%s\n", vetProd[i].nome);
      fprintf(fprod, "%.2f\n", vetProd[i].precoCompra);
      fprintf(fprod, "%.2f\n", vetProd[i].precoVenda);
      fprintf(fprod, "%.2f\n", vetProd[i].lucro);
      fprintf(fprod, "%s\n", vetProd[i].tipo);
      fprintf(fprod, "%s\n", vetProd[i].codProd);
    }
    fclose(fprod);
    printf(" produtos.txt salvo com sucesso \n");
  }else{
    printf(" erro ao SALVAR produtos.txt \n");
  }
}


/* FUNCOES REFERENTE A PRODUTOS */

bool existeProd(char produto[]){
  int verif = 0;
  for(int i = 0; i < tprod; i++){
    if(strcmp(produto, vetProd[i].nome) == 0){
      return true;
      verif = 1;
      break;
    }
  }

  if(verif == 0){
    return false;
  }
}

float lucro(){
  return vetProd[tprod].precoVenda - vetProd[tprod].precoCompra;
}

void cadastrar(){
  bool varif = false;
  char nome[40];

  printf(" NOME DO PRODUTO ");
  scanf("%s", &nome);

  if(!existeProd(nome)){
    vetProd[tprod].nome = nome;

    printf(" PRECO DE COMPRA ");
    scanf("%f", &vetProd[tprod].precoCompra);

    printf(" PRECO DE VENDA ");
    scanf("%f", &vetProd[tprod].precoVenda);

    vetProd[tprod].lucro = lucro();

    printf(" TIPO DO PRODUTO ");
    scanf("%s", &vetProd[tprod].tipo);

    printf(" CODIGO DO PRODUTO ");
    scanf("%s", &vetProd[tprod].codProd);

    tprod++;
  }
}

void buscar(){
  char nome[30];
  int verif = 0;

  printf(" BUSCAR PRODUTO  ");
  scanf("%s", &nome);

  for(int i = 0; i < tprod; i++){
    if(strcmp(nome, vetProd[i].nome) == 0){
      printf(" NOME -------- %s\n", vetProd[i].nome);
      printf(" VALOR COMPRA  %.2f\n", vetProd[i].precoCompra);
      printf(" VALOR VENDA - %.2f\n", vetProd[i].precoVenda);
      printf(" LUCRO ------- %.2f\n", vetProd[i].lucro);
      printf(" TIPO PRODUTO  %s\n", vetProd[tprod].tipo);
      printf(" CODIGO ------ %s\n", vetProd[i].codProd);
      verif = 1;
      break;
    }
  }
  if(verif == 0){
     printf(" produto nao encontrado ");
  }
}

void editar(){
  char nome[30];
  int verif = 0;

  printf(" PRODUTO A SER EDITADO/NOME ");
  scanf("%s", &nome);

  for(int i = 0; i < tprod; i++){
    if(strcmp(nome, vetProd[i].nome) == 0){

      printf(" INFORME NOVOS DADOS \n");

      printf(" NOME ");
      scanf("%s", &vetProd[i].nome);

      printf(" PRECO DE COMPRA ");
      scanf("%f", &vetProd[i].precoCompra);

      printf(" PRECO DE VENDA ");
      scanf("%f", &vetProd[i].precoVenda);

      vetProd[i].lucro = lucro();

      printf(" TIPO DO PRODUTO ");
      scanf("%s", &vetProd[i].tipo);

      printf(" CODIGO DO PRODUTO ");
      scanf("%s", &vetProd[i].codProd);

      verif = 1;
      break;
    }
  }

  if(verif == 0){
    printf(" Produto nao encontrado ");
  }
}


void excluir(){
  char nome[30];
  int verif = 0;

  printf(" PRODUTO A SER EXCLUIDO ");
  scanf("%s", &nome);

  for(int i = 0; i < tprod; i++){
    if(strcmp(nome, vetProd[i].nome) == 0){
      strcpy(vetProd[i].nome, vetProd[tprod - 1].nome);
      vetProd[i].precoCompra = vetProd[tprod - 1].precoCompra;
      vetProd[i].precoVenda = vetProd[tprod - 1].precoVenda;
      vetProd[i].lucro = vetProd[tprod - 1].lucro;
      strcpy(vetProd[i].tipo, vetProd[tprod - 1].tipo);
      strcpy(vetProd[i].codProd, vetProd[tprod - 1].codProd);
      tprod--;
      verif = 1;
      break;
    }
  }

  if(verif == 0){
    printf(" PRODUTO NAO ENCONTRADO \n");
  }else{
    printf(" PRODUTO EXCLUIDO COM SUCESSO \n");
  }
}


void listarGeral(){
  int cont = 1;
  for(int i = 0; i < tprod; i++){
    printf(" PRODUTO %d\n", cont);
    printf("   NOME -------  %s\n", vetProd[i].nome);
    printf("   VALOR COMPRA  %.2f\n", vetProd[i].precoCompra);
    printf("   VALOR VENDA - %.2f\n", vetProd[i].precoVenda);
    printf("   LUCRO ------- %.2f\n", vetProd[i].lucro);
    printf("   TIPO PRODUTO  %s\n", vetProd[i].tipo);
    printf("   CODIGO ------ %s\n", vetProd[i].codProd);
    printf("");
    cont++;
  }
}

void listTipo(){
  char tipo[20];
  int cont = 1;
  printf(" DIGITE O TIPO A SER LISTADO ");
  scanf("%s", &tipo);

  for(int i = 0; i < tprod; i++){
    if(strcmp(tipo, vetProd[i].tipo) == 0){
      printf(" PRODUTO %d\n", cont);
      printf("   NOME -------  %s\n", vetProd[i].nome);
      printf("   VALOR COMPRA  %.2f\n", vetProd[i].precoCompra);
      printf("   VALOR VENDA - %.2f\n", vetProd[i].precoVenda);
      printf("   LUCRO ------- %.2f\n", vetProd[i].lucro);
      printf("   TIPO PRODUTO  %s\n", vetProd[i].tipo);
      printf("   CODIGO ------ %s\n", vetProd[i].codProd);
      printf("");
      cont++;
    }
  }
}

void listar(){
  int op = 0;

  do{
    printf(" 1- GERAL | 2- LISTAR/TIPO | 3- LISTAR/LUCRO | 4- MAIOR VALOR | 5- MENOR VALOR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      listarGeral();
    }else if(op == 2){
      listTipo();
    }else if(op == 3){

    }else if(op == 4){

    }else if(op == 5){

    }else if(op != 0){
      printf(" OPCAO INVALIDA ");
    }

  }while(op != 0);
}

void produto(){
  int op = 0;

  do{
    printf(" 1- CADASTRAR | 2- BUSCAR | 3- EDITAR | 4- EXCLUIR | 5- LISTAR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      cadastrar();
    }else if(op == 2){
      buscar();
    }else if(op == 3){
      editar();
    }else if(op == 4){
      excluir();
    }else if(op == 5){
      listar();
    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
}
/* FIM FUNCOES DE PRODUTO */


/* CHAMAR TODAS AS FUNCOES/ MENU PRINCIPAL */
void exec(){
  int op = 0;
  abrirArquivos();

  do{
    printf(" 1- VENDAS | 2- PRODUTOS | 3- FUNCIONARIOS | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){

    }else if(op == 2){
      produto();
    }else if(op == 3){

    }else if(op != 0){
      printf(" OPCAO INVALIDA ");
    }
  }while(op != 0);

  salvarArquivos();
}

int main() {
    exec();

    return 0;
}
