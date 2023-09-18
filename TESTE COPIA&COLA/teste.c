#include <stdio.h>

void copiarConteudo(FILE *arquivo, FILE *arquivo2){

    char leitor[100];

    while(fgets(leitor, 100, arquivo) != NULL )


    fputs(leitor, arquivo2);
}

int main(){
    
    FILE* arquivo = fopen("totaisdeprodutos.txt", "r");

    if (arquivo == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }

    FILE* arquivo2 = fopen("totais2.txt","w");
    
    copiarConteudo(arquivo, arquivo2);

    fclose(arquivo);
    fclose(arquivo2);
    return 0;
}
