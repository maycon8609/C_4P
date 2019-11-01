#include <stdio.h>
#include <stdlib.h>

typedef struct produtos{
  char codProd[3];
  char nome[40];
  float precoCompra;
  float precoVenda;
  float lucro;
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
    while(
    (fscanf(fprod, "%s", vetProd[tprod].codProd)) != EOF &&
    (fscanf(fprod, "%s", vetProd[tprod].nome)) != EOF &&
    (fscanf(fprod, "%f0.2", vetProd[tprod].precoCompra)) != EOF &&
    (fscanf(fprod, "%f0.2", vetProd[tprod].precoVenda)) != EOF &&
    (fscanf(fprod, "%f0.2", vetProd[tprod].lucro)) != EOF  ){
      tprod++;
    }
    printf(" produtos.txt ABERTO com exito \n");
  }else {
    printf(" erro ao ABRIR o aquivo produtos.txt \n");
  }
}

void salvarAquivos(){
  // Arquivo de produtos
  if(fprod = fopen("produtos.txt", "w")){
    for(int i = 0; i < tprod; i++){
      fprintf(fprod, "%s\n", vetProd[i].codProd);
      fprintf(fprod, "%s\n", vetProd[i].nome);
      fprintf(fprod, "%f\n", vetProd[i].precoCompra);
      fprintf(fprod, "%f\n", vetProd[i].precoVenda);
      fprintf(fprod, "%f\n", vetProd[i].lucro);
    }
    fclose(fprod);
    printf(" produtos.txt salvo com sucesso ");
  }else{
    printf(" erro ao SALVAR produtos.txt ");
  }
}


// FUNCOES REFERENTE A PRODUTOS

void lucro(int x){
  vetProd[x].lucro = vetProd[x].precoVenda - vetProd[x].precoCompra;
}

void cadastrar(){
  printf(" CODIGO DO PRODUTO ");
  scanf("%s", &vetProd[tprod].codProd);

  printf(" NOME DO PRODUTO ");
  scanf("%s", &vetProd[tprod].nome);

  printf(" PRECO DE COMPRA ");
  scanf("%f", &vetProd[tprod].precoCompra);

  printf(" PRECO DE VENDA ");
  scanf("%f", vetProd[tprod].precoVenda);

  lucro(tprod);

  tprod++;
}

void buscar(){}

void editar(){}

void excluir(){}

void listar(){}

void produto(){
  int op = 0;

  do{
    printf(" 1- CADASTRAR | 2- BUSCAR | 3- EDITAR | 4- EXCLUIR | 5- LISTAR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      cadastrar();
    }else if(op == 2){

    }else if(op == 3){

    }else if(op == 4){

    }else if(op == 5){

    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
}

// CHAMAR TODAS AS FUNCOES/ MENU PRINCIPAL
void exec()

int main() {
    exec();

    return 0;
}
