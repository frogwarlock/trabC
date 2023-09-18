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

// Produtos
typedef struct
{
    int codigo;
    float preco;
    char descricao[100];
} Produto;

// Vendedor
typedef struct
{
    int codigo;
    char nome[100];
} Vendedor;

// Vendas
typedef struct
{
    int codigo_vendedor;
    int codigo_produto;
    int unidades;
} Venda;




int main()
{
    Produto produtos[max_produtos];
    int num_produtos = 0;

    FILE *produtos_arq = fopen("produtos.txt", "r");
    if (produtos_arq == NULL)
    {
        printf("Um erro ocorreu ao abrir o arquivo produtos");
        return 1; 
    }

    while (fscanf(produtos_arq, "%d %f %[^\n]", &produtos[num_produtos].codigo, &produtos[num_produtos].preco, produtos[num_produtos].descricao) != EOF)
    {
        num_produtos++;
    }

    fclose(produtos_arq);

    Vendedor vendedores[max_vendedores];
    int num_vendedor = 0;

    FILE *vendedor_arq = fopen("vendedores.txt", "r");
    if (vendedor_arq == NULL)
    {
        printf("Um erro ocorreu ao abrir o arquivo vendedores ");
        return 1; 
    }

    while (fscanf(vendedor_arq, "%d %[^\n]", &vendedores[num_vendedor].codigo, vendedores[num_vendedor].nome) != EOF) // END OF FILE
    {
        num_vendedor++;
    }

    fclose(vendedor_arq);

    Venda vendas[max_vendas];
    int num_vendas = 0;

    FILE *vendas_arq = fopen("vendas.txt", "r");
    if (vendas_arq == NULL)
    {
        printf("Um erro ocorreu ao abrir o arquivo vendas");
        return 1; 
    }

    while (fscanf(vendas_arq, "%d %d %d", &vendas[num_vendas].codigo_vendedor, &vendas[num_vendas].codigo_produto, &vendas[num_vendas].unidades) != EOF)
    {
        num_vendas++;
    }

    fclose(vendas_arq);

    // Calc de vendas

    // Total de vendas dos vendedores
    float totalVendasxVendedores[max_vendedores] = {0};

    for (int i = 0; i < num_vendas; i++)
    {
        int codigo_vendedor = vendas[i].codigo_vendedor - 1;
        int codigo_produto = vendas[i].codigo_produto - 1;
        float preco = produtos[codigo_produto].preco;
        int unidades = vendas[i].unidades;
        totalVendasxVendedores[codigo_vendedor] += preco * unidades;
    }

    // Total de vendas por produtos
    float totalVendasxProdutos[max_produtos] = {0};
    for (int i = 0; i < num_vendas; i++)
    {
        int codigo_produto = vendas[i].codigo_produto - 1;
        float preco = produtos[codigo_produto].preco;
        int unidades = vendas[i].unidades;
        totalVendasxProdutos[codigo_produto] += preco * unidades;
    }

    float totalGeral = 0;

    for (int i = 0; i < num_produtos; i++)
    {
        totalGeral += totalVendasxProdutos[i];
    }

    // info vendas pro arquivo
    FILE *resultadoVendas = fopen("arquivosTotais.txt", "w");
    if (resultadoVendas == NULL)
    {
        printf("Erro ao criar o arquivo resumoVendas");
        return 1; 
    }
    
    fprintf(resultadoVendas, "TOTAL GERAL VENDIDO: %.2f\n", totalGeral);
    fprintf(resultadoVendas, "\n");
    fprintf(resultadoVendas, "\n");

    int j = 0;
    fprintf(resultadoVendas, "VENDAS POR PRODUTO: \n");
    for (int i = 0; i < num_produtos; i++)
    {
        fprintf(resultadoVendas, "[%d] %d %s: %.2f\n", j, produtos[i].codigo, produtos[i].descricao, totalVendasxProdutos[i]);
        j++;
    }
    fprintf(resultadoVendas, "\n");
    fprintf(resultadoVendas, "\n");

    int k = 0;
    fprintf(resultadoVendas, "TOTAL DE VENDAS DE CADA VENDEDOR: \n");
    for (int i = 0; i < num_vendedor; i++)
    {
        fprintf(resultadoVendas, "[%d] %d %s: %.2f\n", k, vendedores[i].codigo, vendedores[i].nome, totalVendasxVendedores[i]);
        k++;
    }
    fprintf(resultadoVendas, "\n");
    fprintf(resultadoVendas, "\n");

    fclose(resultadoVendas); 

    return 0; 
}

