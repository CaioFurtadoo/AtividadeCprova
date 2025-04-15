#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

No *push(No *topo, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

No *pop(No *topo, int *valor)
{
    if (!topo)
        return NULL;
    No *temp = topo;
    *valor = temp->dado;
    topo = topo->prox;
    free(temp);
    return topo;
}

void decimalParaBinario(int num)
{
    if (num == 0)
    {
        printf("Binário: 0\n");
        return;
    }

    No *pilha = NULL;

    while (num > 0)
    {
        int resto = num % 2;
        pilha = push(pilha, resto);
        num /= 2;
    }

    printf("Binário: ");
    int bit;
    while (pilha)
    {
        pilha = pop(pilha, &bit);
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{
    int numero;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);

    return 0;
}
