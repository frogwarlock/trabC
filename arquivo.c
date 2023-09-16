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
#define LINHA_MAXIMA_TAMANHO 1000

typedef
    struct
    {
        int codigo;
        float valor;
        char nome[30];
    };
    

int matriz_produtos[3][3] = {
    {35, 25.00, 'Prato'},
    {60, 10.00, 'Garfo'},
    {89, 20.00, 'Faca'}
  };

int matriz_vendedores[2][2] = {
    {54, 'Marisa'},
    {71, 'Elis'},
    {88, 'Elza'}
};

 le_arquivo(){
    FILE *textfile;
    char line[LINHA_MAXIMA_TAMANHO];

    textfile = fopen("vendas.txt", "r");
    if(textfile == NULL){
        return 1;
    }

    while(fgets(line, LINHA_MAXIMA_TAMANHO, textfile)){
        printf(line);
    }
    
    fclose(textfile);
    return 0;
};

void main(){
    le_arquivo();
    return 0;
};

