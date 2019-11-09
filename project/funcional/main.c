#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct generico{
  char nome[100];
  char tipo[50];
  char code[50];
  int quant;
  float valTotal;
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

generico carrinho[100];
int tCar = 0;

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
            &vetProd[tProd].code)) != EOF){
      tProd++;
    }
  }

  // arquivo de funcionarios
  if(fFunc = fopen("funcionarios.txt", "r")){
    while((fscanf(fFunc, "%s %s",
            &vetFunc[tFunc].nome,
            &vetFunc[tFunc].code)) != EOF){
      tFunc++;
    }
  }

  // arquivo de vendas
  if(fVend = fopen("vendas.txt", "r")){
    while((fscanf(fVend, "%s %s %d %f %f",
            &vetVend[tVend].code,
            &vetVend[tVend].nome,
            &vetVend[tVend].quant,
            &vetVend[tVend].lucro,
            &vetVend[tVend].valTotal)) != EOF){
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
      fprintf(fProd, "%s\n", vetProd[i].code);
    }
    fclose(fProd);
  }else{
    printf(" erro ao salvar produtos.txt ");
  }

  // arquivo de funcionarios
  if(fFunc = fopen("funcionarios.txt", "w")){
    for(int i = 0; i < tFunc; i++){
      fprintf(fFunc, "%s\n", vetFunc[i].nome);
      fprintf(fFunc, "%s\n", vetFunc[i].code);
    }
    fclose(fFunc);
  }else{
    printf(" erro ao salvar funcionarios.txt ");
  }

  // arquivo de vendas
  if(fVend = fopen("vendas.txt", "w")){
    for(int i = 0; i < tVend; i++){
      fprintf(fVend, "%s\n", vetVend[i].code);
      fprintf(fVend, "%s\n", vetVend[i].nome);
      fprintf(fVend, "%d\n", vetVend[i].quant);
      fprintf(fVend, "%.2f\n", vetVend[i].lucro);
      fprintf(fVend, "%.2f\n", vetVend[i].valTotal);
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
  return false;
}

float lucroProd(){
  return vetProd[tProd].precoVenda - vetProd[tProd].precoCompra;
}

void cadastrar(generico vetor[], int tam){
  printf("\33[H\33[2J");

  bool verif = false;
  char nome[50];
  if(vetor == vetProd){
    printf(" Cadastrar produto \n");
  }else{
    printf(" Cadastrar funcionario \n");
  }
  printf(" Nome                ");
  scanf("%s", &nome);

  if(!exist(nome, tam, vetor)){
    sprintf(vetor[tam].nome, "%s", nome);

    if(vetor == vetProd){
      printf(" tipo do produto     ");
      scanf("%s", &vetProd[tProd].tipo);

      printf(" preco de compra     ");
      scanf("%f", &vetProd[tProd].precoCompra);

      printf(" preco de venda      ");
      scanf("%f", &vetProd[tProd].precoVenda);

      printf(" codigo produto      ");
      scanf("%s", &vetProd[tProd].code);

      vetProd[tProd].lucro = lucroProd();
      tProd++;
    }else{
      printf(" codigo funcionario  ");
      scanf("%s", &vetor[tam].code);
      tFunc++;
    }
  }else{
    printf(" %s ja cadastrado \n", nome);
  }
}

void buscar(generico vetor[], int tam){
  printf("\33[H\33[2J");
  int verif = 0;
  char nome[50];

  if(vetor == vetProd){
    printf(" Buscar produto ");
  }else{
    printf(" Buscar funcionario ");
  }
  scanf("%s", &nome);

  for(int i = 0; i < tam; i++){
    if(strcmp(nome, vetor[i].nome) == 0){
      verif = 1;
      printf(" nome --------- %s\n", vetor[i].nome);
      if(vetor == vetProd){
        printf(" valor compra - %.2f\n", vetor[i].precoCompra);
        printf(" valor venda -- %.2f\n", vetor[i].precoVenda);
        printf(" lucro -------- %.2f\n", vetor[i].lucro);
        printf(" tipo produto - %s\n", vetor[i].tipo);
        printf(" codigo ------- %s\n", vetor[i].code);
      }else{
        printf(" codigo ------- %s\n", vetor[i].code);
      }
    }
  }

  if(verif == 0){
      printf(" %s nao encontrado\n", nome);
    }

  printf("\n");
}


void editar(generico vetor[], int tam){
  printf("\33[H\33[2J");

  char nome[30];
  int verif = 0;
  if(vetor == vetProd){
    printf(" Editar produto \n");
  }else{
    printf(" Editar funcionario \n");
  }
  printf(" Buscar por nome ");
  scanf("%s", &nome);

  for(int i = 0; i < tam; i++){
    if(strcmp(nome, vetor[i].nome) == 0){

      printf(" INFORME NOVOS DADOS \n");

      printf(" NOME ");
      scanf("%s", &vetor[i].nome);

      if(vetor == vetProd){
        printf(" PRECO DE COMPRA ");
        scanf("%f", &vetProd[i].precoCompra);

        printf(" PRECO DE VENDA ");
        scanf("%f", &vetProd[i].precoVenda);

        vetProd[i].lucro = lucroProd();

        printf(" TIPO DO PRODUTO ");
        scanf("%s", &vetProd[i].tipo);

        printf(" CODIGO DO PRODUTO ");
        scanf("%s", &vetProd[i].code);
        verif = 1;
        break;
      }else{
        printf(" CODIGO DO FUNCIONARIO ");
        scanf("%s", &vetFunc[i].code);
        verif = 1;
        break;
      }
    }
  }

  if(verif == 0){
    printf(" %s nao encontrado \n", nome);
  }
}

void excluir(generico vetor[], int tam){
  printf("\33[H\33[2J");

  char nome[30];
  int verif = 0;
  if(vetor == vetProd){
    printf(" PRODUTO A SER EXCLUIDO ");
  }else{
    printf(" FUNCIONARIO A SER EXCLUIDO ");
  }
  scanf("%s", &nome);

  for(int i = 0; i < tam; i++){
    if(strcmp(nome, vetor[i].nome) == 0){
      if(vetor == vetProd){
        strcpy(vetProd[i].nome, vetProd[tProd - 1].nome);
         vetProd[i].precoCompra = vetProd[tProd - 1].precoCompra;
         vetProd[i].precoVenda = vetProd[tProd - 1].precoVenda;
         vetProd[i].lucro = vetProd[tProd - 1].lucro;
        strcpy(vetProd[i].tipo, vetProd[tProd - 1].tipo);
        strcpy(vetProd[i].code, vetProd[tProd - 1].code);
        tProd--;
        verif = 1;
        printf(" %s excluido \n", nome);
        break;
      }else{
        strcpy(vetFunc[i].nome, vetFunc[tFunc - 1].nome);
        strcpy(vetFunc[i].code, vetFunc[tFunc - 1].code);
        tFunc--;
        verif = 1;
        printf(" %s excluido \n", nome);
        break;
      }
    }
  }

  if(verif == 0){
    printf(" %s nao cadastrado \n", nome);
  }
}

void listargem(generico vetor[], int tam){
  printf("\e[H\e[2J");

  int cont = 1;
  for(int i = 0; i < tam; i++){
    if(vetor == vetProd){
      printf(" PRODUTO %d\n", cont);
      printf("   NOME -------  %s\n", vetor[i].nome);
      printf("   VALOR COMPRA  %.2f\n", vetor[i].precoCompra);
      printf("   VALOR VENDA - %.2f\n", vetor[i].precoVenda);
      printf("   LUCRO ------- %.2f\n", vetProd[i].lucro);
      printf("   TIPO PRODUTO  %s\n", vetor[i].tipo);
      printf("   CODIGO ------ %s\n", vetor[i].code);
      printf("\n");
      cont++;
    }else{
      printf(" FUNCIONARIO %d\n", cont);
      printf("   NOME -------  %s\n", vetor[i].nome);
      printf("   CODIGO ------ %s\n", vetor[i].code);
      printf("\n");
      cont++;
    }
  }

  if(vetor == vetProd){
    int op = 0;

    do{
      printf(" 1- listar por tipo | 2- listagem geral | 0- sair  ");
      scanf("%d", &op);
      if(op == 1){
        listTipo();
      }else if(op == 2){
        listargem(vetProd, tProd);
      }else if(op != 0){
        printf(" opcao invalida \n");
      }
    }while(op != 0);
    printf("\33[H\33[2J");
  }
}

void listTipo(){
  printf("\33[H\33[2J");

  char tipo[20];
  int cont = 1;
  printf(" DIGITE O TIPO A SER LISTADO ");
  scanf("%s", &tipo);

  for(int i = 0; i < tProd; i++){
    if(strcmp(tipo, vetProd[i].tipo) == 0){
      printf(" PRODUTO %d\n", cont);
      printf("   NOME -------  %s\n", vetProd[i].nome);
      printf("   VALOR COMPRA  %.2f\n", vetProd[i].precoCompra);
      printf("   VALOR VENDA - %.2f\n", vetProd[i].precoVenda);
      printf("   LUCRO ------- %.2f\n", vetProd[i].lucro);
      printf("   TIPO PRODUTO  %s\n", vetProd[i].tipo);
      printf("   CODIGO ------ %s\n", vetProd[i].code);
      printf("\n");
      cont++;
    }
  }
}

/* inicio vendas */

float lucroVend(char nome[], int qtd){
  float lucro = 0;
    for(int i = 0; i < tProd; i++){
      if(strcmp(nome, vetProd[i].nome) == 0){
        lucro = qtd * vetProd[i].lucro;
        break;
      }
    }
  return lucro;
}

float valorTot(char nome[], int qtd){
  float total = 0;
    for(int i = 0; i < tProd; i++){
      if(strcmp(nome, vetProd[i].nome) == 0){
        total = qtd * vetProd[i].precoVenda;
        break;
      }
    }
  return total;
}

void codeFunc(char funcionario[]){
  for(int i = 0; i < tFunc; i++){
    if(strcmp(funcionario, vetFunc[i].nome) == 0){
      strcpy(vetVend[tVend].code, vetFunc[i].code);
      break;
    }
  }
}

void listCar(){
  for(int i = 0; i < tCar; i++){
    printf(" produto ---- %s\n", carrinho[i].nome);
    printf(" quantidade - %d\n", carrinho[i].quant);
    printf(" valor total  %.2f\n", carrinho[i].valTotal);
    printf("\n");
  }
}

void car(char nomeProd[], int qtd){
  for(int i = 0; i < tCar; i++){
    if(strcmp(nomeProd, vetProd[i].nome) == 0){
      strcpy(carrinho[tCar].code, vetVend[tVend - 1].code);
      strcpy(carrinho[tCar].nome, nomeProd);
      carrinho[tCar].quant = qtd;
      carrinho[tCar].valTotal = valorTot(nomeProd, qtd);
      tCar++;
      break;
    }
  }
}

void verificVend(char nomeProd[]){
  for(int i = 0; i < tCar; i++){
    if(strcmp(nomeProd, carrinho[i].nome) == 0){
      carrinho[i].quant += carrinho[tCar - 1].quant;
      carrinho[i].lucro += carrinho[tCar - 1].lucro;
      carrinho[i].valTotal += carrinho[tCar - 1].valTotal;
      tCar--;
      break;
    }
  }
}

void venda(){
  char nomeFunc[20], code[20], nomeProd[50];
  int next = 0, qtd;
  float valTot;
  printf("\33[H\33[2J");

  printf(" Nova venda \n");
  printf(" nome do funcionario ");
  scanf("%s", &nomeFunc);
  if(!exist(nomeFunc, tFunc, vetFunc)){
    printf(" funcionario nao cadastrado \n");
  }else{
    do{
      codeFunc(nomeFunc);
      printf(" nome produto ");
      scanf("%s", &nomeProd);
       if(exist(nomeProd, tProd, vetProd)){
          strcpy(vetVend[tVend].nome, nomeProd);

          printf(" quantidade ");
          scanf("%d", &qtd);
          vetVend[tVend].quant = qtd;

          vetVend[tVend].lucro = lucroVend(nomeProd, qtd);

          vetVend[tVend].valTotal = valorTot(nomeProd, qtd);

          tVend++;

        }else{
          printf(" Produto nao cadastrado ");
        }

      printf("\33[H\33[2J");
        car(nomeProd, qtd);
        verificVend(nomeProd);
        listCar();

      printf(" 1- continuar | 0- sair ");
      scanf("%d", &next);
    }while(next != 0);
  }
}

/* fim vendas */

/* menu produtos */

void produto(){
  /* Limpar a tela do terminal */
  printf("\33[H\33[2J");

  int op = 0;

  do{
    printf(" 1- CADASTRAR | 2- BUSCAR | 3- EDITAR | 4- EXCLUIR | 5- LISTAR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      cadastrar(vetProd, tProd);
    }else if(op == 2){
      buscar(vetProd, tProd);
    }else if(op == 3){
      editar(vetProd, tProd);
    }else if(op == 4){
      excluir(vetProd, tProd);
    }else if(op == 5){
      listargem(vetProd, tProd);
    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
  printf("\33[H\33[2J");
}

/* menu funcionarios */

void funcionarios(){
  printf("\33[H\33[2J");

  int op = 0;

  do{
    printf(" 1- CADASTRAR | 2- BUSCAR | 3- EDITAR | 4- EXCLUIR | 5- LISTAR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      cadastrar(vetFunc, tFunc);
    }else if(op == 2){
      buscar(vetFunc, tFunc);
    }else if(op == 3){
      editar(vetFunc, tFunc);
    }else if(op == 4){
      excluir(vetFunc, tFunc);
    }else if(op == 5){
      listargem(vetFunc, tFunc);
    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
  printf("\33[H\33[2J");
}

void exec(){
  int op = 0;
  openFile();

  do{
    printf(" 1- VENDAS | 2- PRODUTOS | 3- FUNCIONARIOS | 0- SAIR ");
    scanf("%d", &op);
    if(op == 1){
      venda();
    }else if(op == 2){
      produto();
    }else if(op == 3){
      funcionarios();
    }else if(op != 0){
      printf(" OPCAO INVALIDA ");
    }
  }while(op != 0);

  saveFile();
}

int main() {
    exec();
    return 0;
}
