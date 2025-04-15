#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

No *inserirElemento(No *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if (!lista || valor < lista->dado)
    {
        novo->prox = lista;
        return novo;
    }

    No *atual = lista;

    while (atual->prox && atual->prox->dado < valor)
    {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    return lista;
}

No *removerElemento(No *lista, int valor)
{
    if (!lista)
    {
        return NULL;
    }

    if (lista->dado == valor)
    {
        No *temp = lista;
        lista = lista->prox;
        free(temp);
        return lista;
    }

    No *atual = lista;
    No *anterior = NULL;

    while (atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual)
    {
        anterior->prox = atual->prox;
        free(atual);
    }
    else
    {
        printf("elemento não encontrado\n");
    }

    return lista;
}

void imprimirLista(No *lista)
{
    printf("Lista:\n");
    No *temp = lista;
    while (temp)
    {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

int contarElementos(No *lista)
{
    int contador = 0;
    No *temp = lista;
    while (temp)
    {
        contador++;
        temp = temp->prox;
    }
    return contador;
}

int main()
{
    No *lista = NULL;
    lista = inserirElemento(lista, 2);
    lista = inserirElemento(lista, 4);
    lista = inserirElemento(lista, 5);
    lista = inserirElemento(lista, 1);
    lista = inserirElemento(lista, 3);
    lista = inserirElemento(lista, 6);

    lista = removerElemento(lista, 4);
    printf("Quantidade de elementos: %d\n", contarElementos(lista));

    imprimirLista(lista);

    return 0;
}
