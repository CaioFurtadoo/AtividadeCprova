#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} No;

No *enqueue(No *fim, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (fim)
        fim->prox = novo;
    return novo;
}

No *dequeue(No **inicio, int *valor)
{
    if (!*inicio)
        return NULL;
    *valor = (*inicio)->valor;
    No *temp = *inicio;
    *inicio = (*inicio)->prox;
    free(temp);
    return *inicio;
}

void inverterFila(No **inicio)
{
    No *pilha = NULL;
    int valor;

    while (*inicio)
    {
        *inicio = dequeue(inicio, &valor);
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = pilha;
        pilha = novo;
    }

    No *fim = NULL;
    while (pilha)
    {
        No *novoFim = enqueue(fim, pilha->valor);
        if (!*inicio)
            *inicio = novoFim;
        fim = novoFim;

        No *temp = pilha;
        pilha = pilha->prox;
        free(temp);
    }
}

void imprimirFila(No *inicio)
{
    printf("Fila: ");
    while (inicio)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n");
}

int main()
{
    No *inicio = NULL;
    No *fim = NULL;

    for (int i = 1; i <= 5; i++)
    {
        No *novoFim = enqueue(fim, i);
        if (!inicio)
            inicio = novoFim;
        fim = novoFim;
    }

    printf("Fila original:\n");
    imprimirFila(inicio);

    inverterFila(&inicio);

    printf("Fila invertida:\n");
    imprimirFila(inicio);

    return 0;
}
