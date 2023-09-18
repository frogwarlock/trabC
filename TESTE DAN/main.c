#include <stdio.h>


void ler_vendas(){
    FILE *arquivo;
    char linha[100];
    char *result;

    arquivo = fopen("vendas.txt", "rt");

    if (arquivo == NULL){
        printf("Problemas na abertura do arquivo \n");
        return;
    }

    int i = 1;
    while (!feof(arquivo)){
        result = fgets(linha, 50, arquivo);
        if (result) 
            printf("[%d] %s ", i, linha);
        i++;
    }
    fclose(arquivo);
}

void ler_vendedores(){
    FILE *arquivo;
    char linha[50];
    char *result;

    arquivo = fopen("vendedores.txt", "rt");

    if (arquivo == NULL){
        printf("Problemas na abertura do arquivo \n");
        return;
    }

    int i = 1;
    while (!feof(arquivo)){
        result = fgets(linha, 50, arquivo);
        if (result) 
            printf("[%d] %s ", i, linha);
        i++;
    }
    fclose(arquivo);
}

void ler_produtos(){
    FILE *arquivo;
    char linha[50];
    char *result;

    arquivo = fopen("produtos.txt", "rt");

    if (arquivo == NULL){
        printf("Problemas na abertura do arquivo \n");
        return;
    }

    int i = 1;
    while (!feof(arquivo)){
        result = fgets(linha, 50, arquivo);
        if (result) 
            printf("[%d] %s ", i, linha);
        i++;
    }
    fclose(arquivo);
}


int main(){
    int escolha;
    printf("MENU ADMIN DE LOGS \n");
    printf("VENDAS (1) \n");
    printf("FUNCIONÁRIOS (2) \n");
    printf("PRODUTOS (3) \n");
    printf("SAIR DO MENU (0) \n");
    printf("ESCOLHA: ");
    scanf("%d", &escolha);

    if (escolha == 1){
        ler_vendas();
    }
    else if (escolha == 2){
        ler_vendedores();
    }
    else if (escolha == 3){
        ler_produtos();
    }
    else{
        printf("Saindo do menu...");
    }
    return 0;
}