#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

        if(vetor == vetProd){
          vetor[*tam].qtd = 1;
        }else{
          printf("   Horas Mensais ---- ");
          scanf("%d", &vetor[*tam].qtd);
        }
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
        printf("\n");
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
    printf("\n");
    if(verific == 0)
      printf("  %s nao encontrado\n", code);
}

void buscaRapida(generic vetor[], int tam, char code[]){
    int verific = 0;

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
        break;
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
        buscaRapida(vetor, tam, code);
        printf("\n");
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

void excluir(generic vetor[], int *tam){
  printf("\33[H\33[2J");
  char code[30];
  int verif = 0;
  printf(" Buscar Por Code Para Excluir \n");
    if(vetor == vetProd)
      printf(" Code Produto  ");
    else
      printf(" Code Funcionario  ");
    scanf("%s", &code);

  for(int i = 0; i < *tam; i++){
    if(strcmp(code, vetor[i].code) == 0){
      printf("\33[H\33[2J");
      printf(" Dados Excluidos \n");
      buscaRapida(vetor, *tam, code);
        strcpy(vetor[i].code, vetor[*tam - 1].code);
        strcpy(vetor[i].nome, vetor[*tam - 1].nome);
        strcpy(vetor[i].tipo, vetor[*tam - 1].tipo);
         vetor[i].qtd = vetor[*tam - 1].qtd;
         vetor[i].valor1 = vetor[*tam - 1].valor1;
         vetor[i].valor2 = vetor[*tam - 1].valor2;
        (*tam)--;
        verif = 1;
        printf(" %s excluido \n", code);
      printf("\n");
        break;
    }
  }

  if(verif == 0){
    printf(" %s nao cadastrado\n", code);
  }
}


void listTipo(generic vetor[], int tam){
  printf("\33[H\33[2J");

  char tipo[20];
  int cont = 1;
  printf(" DIGITE O TIPO A SER LISTADO ");
  scanf("%s", &tipo);

  for(int i = 0; i < tam; i++){
    if(strcmp(tipo, vetor[i].tipo) == 0){
      printf(" PRODUTO %d\n", cont);
      printf("   NOME -------  %s\n", vetProd[i].nome);
      printf("   TIPO PRODUTO  %s\n", vetProd[i].tipo);
      printf("   CODIGO ------ %s\n", vetProd[i].code);
      printf("   VALOR VENDA - %.2f\n", vetProd[i].valor2);
      printf("\n");
      cont++;
    }
  }

}

void list(generic vetor[], int tam){
  printf("\33[H\33[2J");
  int cont = 1;
  for(int i = 0; i < tam; i++){
    if(vetor == vetProd)
      printf(" Produto %d\n", cont);
    else
      printf(" Funcionario %d\n", cont);

    printf("  Nome ------------- %s\n",vetor[i].nome);
    printf("  Code ------------- %s\n",vetor[i].code);
      if(vetor == vetProd)
        printf("  Tipo Produto ----- ");
      else
        printf("  Cargo ------------ ");
      printf("%s\n", vetor[i].tipo);

      if(vetor == vetFunc){
        printf("  Horas Mensais ---- %d\n", vetor[i].qtd);
      }
      if(vetor == vetProd)
        printf("  Preco de Compra  - ");
      else
        printf("  Valor Hora ------- ");
      printf("%.2f\n", vetor[i].valor1);

      if(vetor == vetProd){
        printf("  Preco de Venda --- ");
        printf("%.2f\n", vetor[i].valor2);
      }else{
        printf("  Valor fixo ------- ");
        printf("%.2f\n", vetor[i].valor2);
        printf("  Salario Final ---- %.2f", returnSalario(i));
      }
      printf("\n");
      printf("\n");
      cont++;
  }

  if(vetor == vetProd){
    int op = 0;
    do{
      printf(" 1- listar por tipo | 2- listagem geral | 0- sair  ");
      scanf("%d", &op);
      if(op == 1){
        listTipo(vetProd, tProd);
      }else if(op == 2){
        list(vetProd, tProd);
      }else if(op != 0){
        printf(" opcao invalida \n");
      }
    }while(op != 0);
    printf("\33[H\33[2J");
  }
}

// menu de produto
void produtos(){
  printf("\33[H\33[2J");
  int op = 0;
  do{
    printf(" 1- CADASTRAR | 2- BUSCAR | 3- EDITAR | 4- EXCLUIR | 5- LISTAR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      cadastrar(vetProd, &tProd);
    }else if(op == 2){
      buscar(vetProd, tProd);
    }else if(op == 3){
      editar(vetProd, tProd);
    }else if(op == 4){
      excluir(vetProd, &tProd);
    }else if(op == 5){
      list(vetProd, tProd);
    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
  printf("\33[H\33[2J");
}

// menu de funcionario
void funcionarios(){
  printf("\33[H\33[2J");
  int op = 0;
  do{
    printf(" 1- CADASTRAR | 2- BUSCAR | 3- EDITAR | 4- EXCLUIR | 5- LISTAR | 0- SAIR ");
    scanf("%d", &op);

    if(op == 1){
      cadastrar(vetFunc, &tFunc);
    }else if(op == 2){
      buscar(vetFunc, tFunc);
    }else if(op == 3){
      editar(vetFunc, tFunc);
    }else if(op == 4){
      excluir(vetFunc, &tFunc);
    }else if(op == 5){
      list(vetFunc, tFunc);
    }else if(op != 0){
      printf(" OPCAO INVALIDA \n");
    }
  }while(op != 0);
  printf("\33[H\33[2J");
}


void exec(){
  int op = 0;
  openFile("produtos.txt", vetProd, &tProd, fProd);
  openFile("funcionarios.txt", vetFunc, &tFunc, fFunc);

  do{
    printf(" 1- VENDAS | 2- PRODUTOS | 3- FUNCIONARIOS | 0- SAIR ");
    scanf("%d", &op);
    if(op == 1){
      printf(" Em Producao \n");
    }else if(op == 2){
      produtos();
    }else if(op == 3){
      funcionarios();
    }else if(op != 0){
      printf(" OPCAO INVALIDA ");
    }
  }while(op != 0);

  saveFile("produtos.txt", vetProd, tProd, fProd);
  saveFile("funcionarios.txt", vetFunc, tFunc, fFunc);
}

int main() {
    exec();
    return 0;
}
