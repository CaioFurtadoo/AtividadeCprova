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

No *pop(No *topo)
{
    if (!topo)
    {
        return NULL;
    }

    No *temp = topo;
    topo = temp->prox;
    free(temp);
    return topo;
}

void top(No *topo)
{
    if (!topo)
    {
        printf("valor do topo: NULL\n");
    }
    else
    {
        printf("valor do topo: %d\n", topo->dado);
    }
}

void isEmpty(No *topo)
{
    if (!topo)
    {
        printf("Esta vazia\n");
    }
    else
    {
        printf("Não esta vazia\n");
    }
}

void imprimirPilha(No *topo)
{
    No *temp = topo;
    while (temp)
    {
        printf("[%d]\n", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main()
{
    No *topo = NULL;
    topo = push(topo, 1);
    topo = push(topo, 2);
    topo = push(topo, 3);
    topo = push(topo, 4);
    topo = push(topo, 5);
    topo = push(topo, 6);

    topo = pop(topo);
    topo = pop(topo);

    top(topo);
    isEmpty(topo);
    imprimirPilha(topo);

    return 0;
}