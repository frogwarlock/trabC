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

#define max_vendas 100
#define max_produtos 100
#define max_vendedores 100


//por que struct e não matriz? Matriz só suporta 
//um único tipo de entrada como temos INT, FLOAT, CHAR é 
// interessante usar o struct, a principal dificuldade aqui é
// COMO FAZ CONSULTA EM STRUCT?????


//produtos
typedef struct{
    int codigo;
    float preco;
    char descricao[100];
} Produto;


//vendedor
typedef struct{
    int codigo;
    char nome[100];
} Vendedor;

//vendas
typedef struct{
    int codigo_vendedor;
    int codigo_produto;
    int unidades;
} Venda;

// int diz respeito ao que ele retorna (como se fosse total de 
// indíces)
int main(){
    Produto produtos[max_produtos];
    int num_produtos = 0;

    FILE *produtos_arq = fopen("produtos.txt", "r");
    if (produtos_arq == NULL){
        perror("Um erro ocorreu ao abrir o arquivo produtos");
        return 1;
    }

    while(fscanf(produtos_arq, "%d %f %[^\n]", &produtos[num_produtos].codigo, produtos[num_produtos].descricao) != EOF ){
        num_produtos++;
    };

    fclose(produtos_arq);

    Vendedor vendedores[max_vendedores];
    int num_vendedor;

    FILE *vendedor_arq = fopen("vendedores.txt", "r");
    if (vendedor_arq = NULL) {
        perror("Um erro ocorreu ao abrir o arquivo vendedores ");
        return 1;
    }

    while (fscanf(vendedor_arq, "%d %[^\n]", &vendedores[num_vendedor].codigo, vendedores[num_vendedor].nome) != EOF) {
        num_vendedor++;
    }

    fclose(vendedor_arq);

    

}