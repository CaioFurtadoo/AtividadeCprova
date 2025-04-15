#include <stdio.h>

typedef struct{
    char nome[30];
    int codigo;
    float preco;
} Produto;

void exibirStruct(Produto produto){
    printf("\nNome do produto: %s\n", produto.nome);
    printf("Código do produto: %d\n", produto.codigo);
    printf("Preço do produto: %.2f\n", produto.preco);
}

int main()
{
    Produto produto;
    printf("Digite o nome do Produto: ");
    scanf("%s", produto.nome);
    printf("Digite o código do Produto: ");
    scanf("%d", &produto.codigo);
    printf("Digite o preço do Produto: ");
    scanf("%f", &produto.preco);
    
    exibirStruct(produto);

    return 0;
}