#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

No *enqueue(No *fila, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    if (!fila)
    {
        return novo;
    }

    No *temp = fila;
    while (temp->prox)
    {
        temp = temp->prox;
    }
    temp->prox = novo;
    return fila;
}

No *dequeue(No *fila)
{
    if (!fila)
    {
        return NULL;
    }
    No *temp = fila;
    fila = temp->prox;
    free(temp);
    return fila;
}

void front(No *fila)
{
    if (!fila)
    {
        printf("\nPrimeiro elemento da fila: NULL\n");
    }
    else
    {
        printf("\nPrimeiro elemento da fila: %d\n", fila->dado);
    }
}

void isEmpty(No *fila)
{
    if (!fila)
    {
        printf("fila esta vazia!!\n");
    }
    else
    {
        printf("fila não esta vazia!!\n");
    }
}

void imprimirFila(No *fila)
{
    No *temp = fila;
    while (temp)
    {
        printf(" <- %d", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main()
{
    No *fila = NULL;
    fila = enqueue(fila, 1);
    fila = enqueue(fila, 2);
    fila = enqueue(fila, 3);
    fila = enqueue(fila, 4);
    fila = enqueue(fila, 5);
    fila = enqueue(fila, 6);

    front(fila);
    isEmpty(fila);
    imprimirFila(fila);

    fila = dequeue(fila);
    fila = dequeue(fila);

    front(fila);
    isEmpty(fila);
    imprimirFila(fila);

    fila = dequeue(fila);
    fila = dequeue(fila);
    fila = dequeue(fila);
    fila = dequeue(fila);

    front(fila);
    isEmpty(fila);
    imprimirFila(fila);
}