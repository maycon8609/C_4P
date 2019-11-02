#include <stdio.h>
#include <stdlib.h>

typedef struct produtos{
  char nome[40];
  float precoVenda;
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
    while((fscanf(fprod, "%s %f %s",
            &vetProd[tprod].nome,
            &vetProd[tprod].precoVenda,
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
      fprintf(fprod, "%s\n", vetProd[i].nome);
      fprintf(fprod, "%.2f\n", vetProd[i].precoVenda);
      fprintf(fprod, "%s\n", vetProd[i].codProd);
    }
    fclose(fprod);
    printf(" produtos.txt salvo com sucesso ");
  }else{
    printf(" erro ao SALVAR produtos.txt ");
  }
}


// FUNCOES REFERENTE A PRODUTOS

void cadastrar(){
  printf(" NOME DO PRODUTO ");
  scanf("%s", &vetProd[tprod].nome);

  printf(" PRECO DE VENDA ");
  scanf("%f", &vetProd[tprod].precoVenda);

  printf(" CODIGO DO PRODUTO ");
  scanf("%s", &vetProd[tprod].codProd);



  tprod++;
}

void buscar(){
  char nome[30];
  int verif = 0;

  printf(" BUSCAR PRODUTO  ");
  scanf("%s", &nome);

  for(int i = 0; i < tprod; i++){
    if(strcmp(nome, vetProd[i].nome) == 0){
      printf(" NOME   %s\n", vetProd[i].nome);
      printf(" VALOR  %.2f\n", vetProd[i].precoVenda);
      printf(" CODIGO %s\n", vetProd[i].codProd);
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
      printf(" PRECO DE VENDA ");
      scanf("%f", &vetProd[i].precoVenda);
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

/*
void excluir(){
  char nome[30];
  int verif = 0;

  printf(" PRODUTO A SER EXCLUIDO ");
  scanf("%s", &nome);

  for(int i = 0; i < tprod; i++){
    if(strcmp(nome, vetProd[i].nome) == 0){
      strcpy(vetProd[i].nome, vetProd[tprod - 1].nome);
      strcpy(vetProd[i].precoVenda, vetProd[tprod - 1].precoVenda);
      strcpy(vetProd[i].codProd, vetProd[tprod - 1].codProd);
      tprod--;
      verif = 0;
      break;
    }
  }

  if(verif == 0){
    printf(" PRODUTO NAO ENCONTRADO ");
  }else{
    printf(" PRODUTO EXCLUIDO COM SUCESSO ");
  }
}
*/

void listar(){
  int cont = 1;
  for(int i = 0; i < tprod; i++){
    printf(" PRODUTO %d\n", cont);
    printf("   Nome   %s\n", vetProd[i].nome);
    printf("   Preco  %.2f\n", vetProd[i].precoVenda);
    printf("   Codigo %s\n", vetProd[i].codProd);
    printf("");
    cont++;
  }
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
      //excluir();
    }else if(op == 5){
      listar();
    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
}

// CHAMAR TODAS AS FUNCOES/ MENU PRINCIPAL
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
