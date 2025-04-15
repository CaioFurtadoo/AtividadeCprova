#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

No *inserirInicio(No *lista, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = lista;
    return novo;
}

No *removerInicio(No *lista)
{
    if (!lista)
    {
        return NULL;
    }
    No *temp = lista;
    lista = temp->prox;
    free(temp);
    return lista;
}

No *inserirFinal(No *lista, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    if (!lista)
    {
        return novo;
    }

    No *temp = lista;
    while (temp->prox)
    {
        temp = temp->prox;
    }
    temp->prox = novo;
    return lista;
}

No *removerFinal(No *lista)
{
    if (!lista)
    {
        return NULL;
    }

    if (!lista->prox)
    {
        free(lista);
        return NULL;
    }

    No *temp = lista;
    while (temp->prox->prox)
    {
        temp = temp->prox;
    }
    free(temp->prox);
    temp->prox = NULL;
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
    else{
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

int contarElementos(No* lista){
    int contador = 0;
    No* temp = lista;
    while(temp){
        contador++;
        temp = temp->prox;
    }
    return contador;
}

int main()
{
    No *lista = NULL;
    lista = inserirInicio(lista, 1);
    lista = inserirFinal(lista, 2);
    lista = inserirInicio(lista, 3);
    lista = inserirFinal(lista, 4);
    lista = inserirInicio(lista, 6);
    lista = inserirFinal(lista, 5);
    lista = removerFinal(lista);
    lista = removerInicio(lista);
    lista = removerElemento(lista, 4);
    printf("Quantidade de elementos: %d\n", contarElementos(lista));

    imprimirLista(lista);

    return 0;
}
