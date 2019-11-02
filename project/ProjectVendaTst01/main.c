#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct produtos{
  char nome[100];
  float precoCompra;
  float precoVenda;
  float lucro;
  char tipo[50];
  char codProd[50];
}produtos;

typedef struct funcionario{
  char nome[100];
  char codFunc[50];
}funcionario;

/* VETORES */
produtos vetProd[1000];
int tprod = 0;

funcionario vetFunc[100];
int tfunc = 0;

/* PONTEIROS */
FILE *fprod;
FILE *ffunc;

/* FUNCOES GLOBAIS */

void abrirArquivos(){
  /* Arquivo de produtos */
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
  }

  /* Arquivo de FUNCIONARIOS */
  if(ffunc = fopen("funcionarios.txt", "r")){
    while((fscanf(ffunc, "%s %s",
            &vetFunc[tfunc].nome,
            &vetFunc[tfunc].codFunc)) != EOF){
      tfunc++;
    }
  }
}

void salvarArquivos(){
  /* Arquivo de produtos */
  if(fprod = fopen("produtos.txt", "w")){
    for(int i = 0; i < tprod; i++){
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

  /* Arquivo de funcionarios */
  if(ffunc = fopen("funcionarios.txt", "w")){
    for(int i = 0; i < tfunc; i++){
      fprintf(ffunc, "%s\n", vetFunc[i].nome);
      fprintf(ffunc, "%s\n", vetFunc[i].codFunc);
    }
    fclose(ffunc);
    printf(" funcionarios.txt salvo com sucesso \n");
  }else{
    printf(" erro ao SALVAR funcionarios.txt \n");
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
  printf("\33[H\33[2J");

  bool varif = false;
  char nome[40];


  printf(" CADASTRAR NOVO PRODUTO ");
  printf(" NOME DO PRODUTO ");
  scanf("%s", &nome);

  if(!existeProd(nome)){
    sprintf(vetProd[tprod].nome, "%s", nome);

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
  }else {
    printf(" PRODUTO JA CADASTRADO \n");
  }
}

void buscar(){
  printf("\33[H\33[2J");

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
  printf("\33[H\33[2J");

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
  printf("\33[H\33[2J");

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
  printf("\e[H\e[2J");

  int cont = 1;
  for(int i = 0; i < tprod; i++){
    printf(" PRODUTO %d\n", cont);
    printf("   NOME -------  %s\n", vetProd[i].nome);
    printf("   VALOR COMPRA  %.2f\n", vetProd[i].precoCompra);
    printf("   VALOR VENDA - %.2f\n", vetProd[i].precoVenda);
    printf("   LUCRO ------- %.2f\n", vetProd[i].lucro);
    printf("   TIPO PRODUTO  %s\n", vetProd[i].tipo);
    printf("   CODIGO ------ %s\n", vetProd[i].codProd);
    printf("\n");
    cont++;
  }
}

void listTipo(){
  printf("\33[H\33[2J");

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
      printf("\n");
      cont++;
    }
  }
}


void listar(){
  printf("\33[H\33[2J");

  int op = 0;

  do{
    printf(" 1- GERAL | 2- LISTAR/TIPO | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      listarGeral();
    }else if(op == 2){
      listTipo();
    }else if(op != 0){
      printf(" OPCAO INVALIDA ");
    }

  }while(op != 0);
  printf("\33[H\33[2J");
}

void produto(){
  /* Limpar a tela do terminal */
  //printf("\e[H\e[2J");
  printf("\33[H\33[2J");
  /* Limpar a tela do terminal */

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
  printf("\33[H\33[2J");
}
/* FIM FUNCOES PRODUTO */

/* FUNCOES REFERENTES A FUNCIONARIOS */

bool existeFunc(char funcionario[]){
  int verif = 0;
  for(int i = 0; i < tfunc; i++){
    if(strcmp(funcionario, vetFunc[i].codFunc) == 0){
      return true;
      verif = 1;
      break;
    }
  }

  if(verif == 0){
    return false;
  }
}

void cadastrarFunc(){
  printf("\33[H\33[2J");

  bool varif = false;
  char codigo[40];

  printf(" CADASTRAR NOVO FUNCIONARIO \n");

  printf(" NOME DO FUNCIONARIO ");
  scanf("%s", &vetFunc[tfunc].nome);

  printf(" CODIGO DO FUNCIONARIO ");
  scanf("%s", &codigo);
  if(!existeFunc(codigo)){
    sprintf(vetFunc[tfunc].codFunc, "%s", codigo);

    tfunc++;
  }else {
    printf(" FUNCIONARIO JA CADASTRADO \n");
  }
}

void buscarFunc(){
  printf("\33[H\33[2J");

  char nome[30];
  int verif = 0;

  printf(" BUSCAR FUNCIONARIO  ");
  scanf("%s", &nome);

  for(int i = 0; i < tfunc; i++){
    if(strcmp(nome, vetFunc[i].nome) == 0){
      printf(" NOME -- %s\n", vetFunc[i].nome);
      printf(" CODIGO  %s\n", vetFunc[i].codFunc);
      verif = 1;
      break;
    }
  }
  if(verif == 0){
     printf(" Funcionario nao encontrado ");
  }
}

void editarFunc(){
  printf("\33[H\33[2J");

  char nome[30];
  int verif = 0;

  printf(" NOME DO FUNCIONARIO A SER EDITADO ");
  scanf("%s", &nome);

  for(int i = 0; i < tfunc; i++){
    if(strcmp(nome, vetFunc[i].nome) == 0){

      printf(" INFORME NOVOS DADOS \n");

      printf(" NOME ");
      scanf("%s", &vetFunc[i].nome);

      printf(" CODIGO DO FUNCIONARIO ");
      scanf("%s", &vetFunc[i].codFunc);

      verif = 1;
      break;
    }
  }

  if(verif == 0){
    printf(" Funcionario nao encontrado \n");
  }
}


void excluirFunc(){
  printf("\33[H\33[2J");

  char nome[30];
  int verif = 0;

  printf(" FUNCIONARIO A SER EXCLUIDO ");
  scanf("%s", &nome);

  for(int i = 0; i < tprod; i++){
    if(strcmp(nome, vetFunc[i].nome) == 0){
      strcpy(vetFunc[i].nome, vetFunc[tfunc - 1].nome);
      strcpy(vetFunc[i].codFunc, vetFunc[tfunc - 1].codFunc);
      tfunc--;
      verif = 1;
      break;
    }
  }

  if(verif == 0){
    printf(" FUNCIONARIO NAO ENCONTRADO \n");
  }else{
    printf(" FUNCIONARIO EXCLUIDO COM SUCESSO \n");
  }
}


void listarFunc(){
  printf("\e[H\e[2J");

  int cont = 1;
  for(int i = 0; i < tfunc; i++){
    printf(" FUNCIONARIO %d\n", cont);
    printf("   NOME -------  %s\n", vetFunc[i].nome);
    printf("   CODIGO ------ %s\n", vetFunc[i].codFunc);
    printf("\n");
    cont++;
  }

  if(tfunc == 0){
    printf(" NAO A FUNCIONARIOS REGISTRADOS \n");
  }
}

void funcionarios(){
  printf("\33[H\33[2J");

  int op = 0;

  do{
    printf(" 1- CADASTRAR | 2- BUSCAR | 3- EDITAR | 4- EXCLUIR | 5- LISTAR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      cadastrarFunc();
    }else if(op == 2){
      buscarFunc();
    }else if(op == 3){
      editarFunc();
    }else if(op == 4){
      excluirFunc();
    }else if(op == 5){
      listarFunc();
    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
  printf("\33[H\33[2J");
}

/* FIM FUNCOES FUNCIONARIO */

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
      funcionarios();
    }else if(op != 0){
      printf(" OPCAO INVALIDA ");
    }
  }while(op != 0);
  printf("\33[H\33[2J");

  salvarArquivos();
}

bool exi(char nome[]){
  return nome;
}

int main() {
    exec();

    return 0;
}
