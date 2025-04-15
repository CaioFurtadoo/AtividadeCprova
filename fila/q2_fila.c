#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    int dados[TAM];
    int inicio, fim, tamanho;
} FilaCircular;

void inicializar(FilaCircular *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int enqueue(FilaCircular *f, int valor)
{
    if (f->tamanho == TAM)
        return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
    f->tamanho++;
    return 1;
}

int dequeue(FilaCircular *f, int *valor)
{
    if (f->tamanho == 0)
        return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->tamanho--;
    return 1;
}

void imprimirFila(FilaCircular *f)
{
    printf("Fila: ");
    int i, pos = f->inicio;
    for (i = 0; i < f->tamanho; i++)
    {
        printf("%d ", f->dados[pos]);
        pos = (pos + 1) % TAM;
    }
    printf("\n");
}

int main()
{
    FilaCircular fila;
    inicializar(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    imprimirFila(&fila);

    int removido;
    dequeue(&fila, &removido);
    printf("Removido: %d\n", removido);
    imprimirFila(&fila);

    enqueue(&fila, 40);
    enqueue(&fila, 50);
    enqueue(&fila, 60);
    imprimirFila(&fila);

    return 0;
}
