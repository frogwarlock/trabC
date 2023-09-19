#include <stdio.h>

void ler_arquivo(char* titulo){
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

// ALTERAR A MAIN
int main(){
    int escolha;
    scanf("%d", &escolha);
    
    if (escolha == 1){
        ler_arquivo("vendas.txt");
    }
    else if (escolha == 2){
        ler_arquivo("produtos.txt");
    }
    else if (escolha == 3){
        ler_arquivo("vendedores.txt");
    }
    else{
        printf("Saindo do modo admin....");
    }
    
    return 0;
}