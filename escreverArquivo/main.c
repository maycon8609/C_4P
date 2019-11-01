#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    char nome[30];
    int idade;
} pessoa;

pessoa vetor[100];
int tam = 0;

FILE *arquivo;


// ABRIR ARQUIVO
void abrirAquivo() {
    if(arquivo = fopen("arquivo.txt", "r")) {
        while((fscanf(arquivo, "%s", vetor[tam].nome)) != EOF) {
            tam++;
        }
        printf(" Abertura bem secedida\n");
    } else {
        printf("erro ao ABRIR o arquivo\n");
    }
}

// INSERIR  NO ARQUIVO
void inserir() {
    printf("Digite seu nome:  ");
    scanf("%s", &vetor[tam].nome);
    tam++;
}

// IMPRIMIR VETOR
void imprimirVetor() {
    for(int i = 0; i < tam; i++) {
        printf("%s\n", vetor[i].nome);
    }
}

// BUSCAR PESSOA PELO NOME
void buscar() {
    char nome[30];
    int verif = 0;

    printf("Digite um nome para buscar:  ");
    scanf("%s", &nome);

    for(int i = 0; i < tam; i++) {
        if(strcmp(nome, vetor[i].nome) == 0) {
            printf("%s encontado na posicao %d\n", nome, i);
            verif = 1;
            break;
        }
    }
}

// ALTERAR REGISTRO
void alterar() {
    char nome[30];
    int verif = 0;

    printf(" Nome a ser alterado    ");
    scanf("%s", &nome);

    for(int i = 0; i < tam; i++) {
        if(strcmp(nome, vetor[i].nome) == 0) {
            printf(" Digite o novo nome     ");
            scanf("%s", vetor[i].nome);
            verif = 1;
            break;
        }
    }
}

// EXCLUIR REGISTRO
void excluir() {
    char nome[30];
    int verif = 0;

    printf(" Nome a ser excluido   ");
    scanf("%s", &nome);

    for(int i = 0; i < tam; i++) {
        if(strcmp(nome, vetor[i].nome) == 0) {
            strcpy(vetor[i].nome, vetor[tam - 1].nome);
            tam--;
            verif = 1;
            break;
        }
    }
}

// SALVAR ARQUIVO
void salvarArquivo() {
    if(arquivo = fopen("arquivo.txt", "w")) {
        for(int i = 0; i < tam; i++) {
            fprintf(arquivo, "%s\n", vetor[i].nome);
        }
        fclose(arquivo);
        printf(" Salvo com sucesso\n");
    } else {
        printf("erro ao SALVAR o arquivo\n");
    }
}


void exec() {
    abrirAquivo();
    int op = 0;

    do {
        printf(" 1-INSERIR | 2-IMPRIMIR | 3-BUSCAR | 4-ALTERAR | 5-EXCLUIR | 0-SAIR    ");
        scanf("%d", &op);

        if(op == 1) {
            inserir();
        } else if(op == 2) {
            imprimirVetor();
        } else if(op == 3) {
            buscar();
        } else if(op == 4) {
            alterar();
        } else if(op == 5) {
            excluir();
        } else if(op < 0 || op > 5){
            printf(" OPERACAO INVALIDA \n");
        }
    } while(op != 0);

    salvarArquivo();
}


int main() {
    exec();

    return 0;
}
