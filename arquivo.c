// ler arquivo txt
// realizar operações necessárias (funcoes de leitura)
// colocar output em novo txt

// o que as funções fazem:
// imprime o log de vendas
// imprime catálogo de produtos 
// imprime lista de vendedores 
// mostra o total vendido
// mostra o total vendido por produto ex(p 35(prato): R$ 75.00)
// mostra o total vendido por vendedor ex.(v 54(Marisa): R$170.00)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINHA_MAXIMA_TAMANHO 1000


typedef
    struct
    {
        int codigo;
        float valor;
        char nome[30];
    };

 int le_arquivo(){
    FILE *textfile;
    char line[LINHA_MAXIMA_TAMANHO];

    textfile = fopen("vendas.txt", "r");
    if(textfile == NULL){
        return 1;
    }

    /*while(fgets(line, LINHA_MAXIMA_TAMANHO, textfile)){
        printf(line);
    }*/
    
    fclose(textfile);

    char *substring = strtok(line, " ");

    while(substring != NULL){
        int num = atoi(substring);
        printf("numero: %d\n", num);

        substring = strtok(NULL, " ");
    }
    
};

/*void consulta(){
    if(strcmp() )

};*/

void main(){
    le_arquivo();
};

