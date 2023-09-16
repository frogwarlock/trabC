#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHA_MAXIMA_TAMANHO 100


void leitura_vendas(){

    FILE* arquivo;
    char line[LINHA_MAXIMA_TAMANHO];

    arquivo = fopen("vendas.txt", "r");

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
    leitura_vendas();
    return 0;
}