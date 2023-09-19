#include <stdio.h>

void ler_arquivo(char* titulo){ //Escreve na tela o arquivo com index [0],[1]...
    FILE *arquivo;
    char linha[100];
    char *result;

    arquivo = fopen(titulo, "r");

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

void copiarConteudo(FILE *arquivo, FILE *arquivo2){ //Copia um Arquivo e Cola em Outro

    char leitor[100];  // Define o máxima de caractere de uma linha

    while(fgets(leitor, 100, arquivo) != NULL )


    fputs(leitor, arquivo2); //Coloca o que tem no arquivo 1 no arquivo 2
}



// ALTERAR A MAIN

int main(){
    FILE* arquivo_vendedores = fopen("vendedores.txt", "r"); // Abre os 3 txt's com função "read"
    FILE* arquivo_vendas = fopen("vendas.txt", "r");
    FILE* arquivo_produtos = fopen("produtos.txt", "r");

    FILE* arquivo_total = fopen("arquivosTotais.txt", "a"); //Abre o arquivo final com função "append"

    ler_arquivo("vendedores.txt");
    copiarConteudo(arquivo_vendedores, arquivo_total); //Copia o vendedores pro total
    copiarConteudo(arquivo_vendas, arquivo_total); //Copia a vendas pro total 
    copiarConteudo(arquivo_produtos, arquivo_total); //Copia produtos pro total

    fclose(arquivo_vendedores); //Fecha todos os arquivos
    fclose(arquivo_total);
    fclose(arquivo_vendas);
    fclose(arquivo_produtos);

    return 0;

}