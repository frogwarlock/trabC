#include <stdio.h>

#define LINHA_MAXIMA_TAMANHO 100


void leitura_produtos(){

    FILE* arquivo;
    char line[LINHA_MAXIMA_TAMANHO];

    arquivo = fopen("produtos.txt", "r");

    if(arquivo == NULL){
        perror("ERRO");
        exit(1);
    }

    while (fgets(line, LINHA_MAXIMA_TAMANHO, arquivo)){
        printf(line);
    }

    fclose(arquivo);
}

int main(){
    leitura_produtos();
    return 0;
}