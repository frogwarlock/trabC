#include <stdio.h>



int main(void){

    void copiarConteudo(FILE *arquivo, FILE *arquivo2);
    
    FILE* arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }

    FILE* arquivo2 = fopen("totaisdeprodutos.txt","w");
    
    copiarConteudo(arquivo, arquivo2);

    fclose(arquivo);
    fclose(arquivo2);
    return 0;
}


void copiarConteudo(FILE *arquivo, FILE *arquivo2){

    char leitor[100];

    while(fgets(leitor, 100, arquivo) != NULL )


    fputs(leitor, arquivo2);
}